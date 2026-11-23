cmake_minimum_required(VERSION 3.21)
project(cpp_course LANGUAGES CXX)

# One build for the whole course.
#
#   cmake -B build                                            configure (once)
#   cmake --build build                                       build every lesson example
#   ctest --test-dir build -L examples                        run every lesson example
#   ctest --test-dir build -R ex-03-02 --output-on-failure    check exercise 2 of chapter 03
#
# The folder and file conventions this file relies on are described in CONTRIBUTING.md.

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug)
endif()

option(COURSE_WERROR "Treat warnings in lesson examples as errors" OFF)
option(COURSE_SANITIZE "Build with AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

if(MSVC)
    set(COURSE_WARNINGS /W4 /permissive- /utf-8)
    set(COURSE_WERROR_FLAG /WX)
else()
    set(COURSE_WARNINGS -Wall -Wextra -Wpedantic)
    set(COURSE_WERROR_FLAG -Werror)
endif()
if(COURSE_SANITIZE AND NOT MSVC)
    add_compile_options(-g -fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

enable_testing()
set(COURSE_RUNNER "${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake/run_program.cmake")

# "03-control-flow" + "05-for-loops" -> "03-05"; folders without a number keep their name.
function(course_number out_var name)
    string(REGEX MATCH "^[0-9][0-9]" number "${name}")
    if(number STREQUAL "")
        set(number "${name}")
    endif()
    set(${out_var} "${number}" PARENT_SCOPE)
endfunction()

# Every program runs in its own scratch folder, so that running tests never writes into the
# course folders. The runner copies the data files (*.txt, *.csv, *.dat) there first.
function(course_run_dir out_var name)
    set(run_dir "${CMAKE_BINARY_DIR}/run/${name}")
    file(MAKE_DIRECTORY "${run_dir}")
    set(${out_var} "${run_dir}" PARENT_SCOPE)
endfunction()

# ---------------------------------------------------------------- lesson examples

# One example program. The end of its name says what to expect:
#   name            builds without warnings and runs
#   name_bug        builds, has a bug on purpose, is not run
#   name_nocompile  must fail to build
function(course_add_example target name folder)
    set(sources ${ARGN})
    course_run_dir(run_dir "${target}")
    if(name MATCHES "_nocompile$")
        add_executable(${target} EXCLUDE_FROM_ALL ${sources})
        add_test(NAME ${target}
                 COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${target} --config $<CONFIG>)
        set_tests_properties(${target} PROPERTIES WILL_FAIL TRUE LABELS examples RESOURCE_LOCK course_build)
        return()
    endif()
    add_executable(${target} ${sources})
    target_compile_options(${target} PRIVATE ${COURSE_WARNINGS})
    if(name MATCHES "_bug$")
        return()
    endif()
    if(COURSE_WERROR)
        target_compile_options(${target} PRIVATE ${COURSE_WERROR_FLAG})
    endif()
    add_test(NAME ${target}
             COMMAND ${CMAKE_COMMAND}
                     -DPROGRAM=$<TARGET_FILE:${target}>
                     -DINPUT=${folder}/${name}.in
                     -DARGS_FILE=${folder}/${name}.args
                     -DEXIT_FILE=${folder}/${name}.exitcode
                     -DDATA_DIR=${folder}
                     -DWORK_DIR=${run_dir}
                     -P ${COURSE_RUNNER})
    set_tests_properties(${target} PROPERTIES LABELS examples TIMEOUT 60)
endfunction()

function(course_add_lesson chapter lesson)
    set(folder "${CMAKE_CURRENT_SOURCE_DIR}/${chapter}/${lesson}")
    course_number(chapter_number "${chapter}")
    course_number(lesson_number "${lesson}")
    set(id "${chapter_number}-${lesson_number}")

    file(GLOB single_files "${folder}/*.cpp")
    foreach(source IN LISTS single_files)
        cmake_path(GET source STEM LAST_ONLY name)
        course_add_example("${id}-${name}" "${name}" "${folder}" "${source}")
    endforeach()

    file(GLOB children "${folder}/*")
    foreach(child IN LISTS children)
        cmake_path(GET child FILENAME name)
        if(IS_DIRECTORY "${child}" AND NOT name MATCHES "^(tests|starter|exercises)$"
           AND NOT EXISTS "${child}/README.md" AND NOT EXISTS "${child}/Cargo.toml")
            file(GLOB sources "${child}/*.cpp")
            if(sources)
                course_add_example("${id}-${name}" "${name}" "${folder}" ${sources})
            endif()
        endif()
    endforeach()
endfunction()

# ---------------------------------------------------------------- exercises

# A program that is built on demand and checked against test cases.
#   id        test name, for example ex-03-02
#   label     exercises or solutions
#   task_dir  the task folder (holds tests/ and data files)
#   expected  a single expected-output file, or "" to use task_dir/tests/*.out
function(course_add_checked id label task_dir expected)
    set(sources ${ARGN})
    add_executable(${id} EXCLUDE_FROM_ALL ${sources})
    target_compile_options(${id} PRIVATE ${COURSE_WARNINGS})
    course_run_dir(run_dir "${id}")
    if(IS_DIRECTORY "${task_dir}/starter")
        set(data_dir "${task_dir}/starter")
    else()
        set(data_dir "${task_dir}")
    endif()

    add_test(NAME ${id}.build
             COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${id} --config $<CONFIG>)
    set_tests_properties(${id}.build PROPERTIES FIXTURES_SETUP ${id} LABELS ${label} RESOURCE_LOCK course_build)

    set(case_names "")
    if(NOT expected STREQUAL "")
        add_test(NAME ${id}.prediction
                 COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:${id}> -DEXPECTED=${expected}
                         -DDATA_DIR=${data_dir} -DWORK_DIR=${run_dir} -P ${COURSE_RUNNER})
        list(APPEND case_names ${id}.prediction)
    else()
        file(GLOB cases "${task_dir}/tests/*.out")
        foreach(case IN LISTS cases)
            cmake_path(GET case STEM LAST_ONLY case_name)
            add_test(NAME ${id}.${case_name}
                     COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:${id}>
                             -DINPUT=${task_dir}/tests/${case_name}.in -DEXPECTED=${case}
                             -DDATA_DIR=${data_dir} -DWORK_DIR=${run_dir}/${case_name} -P ${COURSE_RUNNER})
            list(APPEND case_names ${id}.${case_name})
        endforeach()
        if(NOT cases)                      # the program checks itself and reports through its exit code
            add_test(NAME ${id}.run
                     COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:${id}> -DDATA_DIR=${data_dir}
                             -DWORK_DIR=${run_dir} -P ${COURSE_RUNNER})
            list(APPEND case_names ${id}.run)
        endif()
    endif()
    set_tests_properties(${case_names} PROPERTIES FIXTURES_REQUIRED ${id} LABELS ${label} TIMEOUT 60)
endfunction()

# One task folder: the student's program, and the solution when solutions/ is present.
function(course_add_task id task_dir)
    file(RELATIVE_PATH relative "${CMAKE_CURRENT_SOURCE_DIR}" "${task_dir}")
    if(EXISTS "${task_dir}/prediction.txt")
        if(EXISTS "${task_dir}/program.cpp")
            course_add_checked(ex-${id} exercises "${task_dir}" "${task_dir}/prediction.txt" "${task_dir}/program.cpp")
        endif()
        return()
    endif()
    if(IS_DIRECTORY "${task_dir}/starter")
        file(GLOB sources "${task_dir}/starter/*.cpp")
    elseif(EXISTS "${task_dir}/exercise.cpp")
        set(sources "${task_dir}/exercise.cpp")
    else()
        return()                            # not a C++ task (for example a Rust one)
    endif()
    if(NOT sources)
        return()
    endif()
    course_add_checked(ex-${id} exercises "${task_dir}" "" ${sources})

    file(GLOB solution "${CMAKE_CURRENT_SOURCE_DIR}/solutions/${relative}/*.cpp")
    if(solution)
        course_add_checked(sol-${id} solutions "${task_dir}" "" ${solution})
    endif()
endfunction()

# ---------------------------------------------------------------- walk the course

file(GLOB chapters RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
     "${CMAKE_CURRENT_SOURCE_DIR}/[0-9][0-9]-*" "${CMAKE_CURRENT_SOURCE_DIR}/appendix")
list(SORT chapters)
foreach(chapter IN LISTS chapters)
    set(chapter_dir "${CMAKE_CURRENT_SOURCE_DIR}/${chapter}")
    if(NOT IS_DIRECTORY "${chapter_dir}")
        continue()
    endif()
    course_number(chapter_number "${chapter}")
    file(GLOB lessons RELATIVE "${chapter_dir}" "${chapter_dir}/*")
    list(SORT lessons)
    foreach(lesson IN LISTS lessons)
        if(IS_DIRECTORY "${chapter_dir}/${lesson}" AND NOT lesson STREQUAL "exercises"
           AND EXISTS "${chapter_dir}/${lesson}/README.md")
            course_add_lesson("${chapter}" "${lesson}")
        endif()
    endforeach()
    file(GLOB tasks RELATIVE "${chapter_dir}/exercises" "${chapter_dir}/exercises/*")
    list(SORT tasks)
    foreach(task IN LISTS tasks)
        if(IS_DIRECTORY "${chapter_dir}/exercises/${task}")
            course_number(task_number "${task}")
            course_add_task("${chapter_number}-${task_number}" "${chapter_dir}/exercises/${task}")
        endif()
    endforeach()
endforeach()

# projects/<name>/<NN-step>/ : each step is checked like an exercise, as proj-<name>-<NN>.
file(GLOB projects RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/projects" "${CMAKE_CURRENT_SOURCE_DIR}/projects/*")
list(SORT projects)
foreach(project IN LISTS projects)
    set(project_dir "${CMAKE_CURRENT_SOURCE_DIR}/projects/${project}")
    if(NOT IS_DIRECTORY "${project_dir}")
        continue()
    endif()
    file(GLOB steps RELATIVE "${project_dir}" "${project_dir}/*")
    list(SORT steps)
    foreach(step IN LISTS steps)
        if(IS_DIRECTORY "${project_dir}/${step}")
            course_number(step_number "${step}")
            course_add_task("${project}-${step_number}" "${project_dir}/${step}")
        endif()
    endforeach()
endforeach()
