# Runs one program for a test.
#
#   cmake -DPROGRAM=<exe> [-DINPUT=<file>] [-DEXPECTED=<file>] [-DARGS_FILE=<file>]
#         [-DEXIT_FILE=<file>] [-DDATA_DIR=<dir>] [-DWORK_DIR=<dir>] -P run_program.cmake
#
# The program runs in WORK_DIR. Data files (*.txt, *.csv, *.dat) from DATA_DIR are copied there first.
# The program reads INPUT as if it were typed (nothing, when the file does not exist).
# It must exit with code 0, or with the number written in EXIT_FILE.
# With EXPECTED, what it prints must match that file. Spaces at the end of a line and
# blank lines at the end of the output are ignored.

cmake_minimum_required(VERSION 3.21)

if(NOT DEFINED WORK_DIR)
    set(WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}")
endif()

file(MAKE_DIRECTORY "${WORK_DIR}")
if(DEFINED DATA_DIR AND IS_DIRECTORY "${DATA_DIR}")
    file(GLOB data_files "${DATA_DIR}/*.txt" "${DATA_DIR}/*.csv" "${DATA_DIR}/*.dat")
    list(FILTER data_files EXCLUDE REGEX "/prediction\\.txt$")
    if(data_files)
        file(COPY ${data_files} DESTINATION "${WORK_DIR}")
    endif()
endif()

set(program_args "")
if(DEFINED ARGS_FILE AND EXISTS "${ARGS_FILE}")
    file(READ "${ARGS_FILE}" raw_args)
    string(STRIP "${raw_args}" raw_args)
    separate_arguments(program_args NATIVE_COMMAND "${raw_args}")
endif()

set(expected_exit 0)
if(DEFINED EXIT_FILE AND EXISTS "${EXIT_FILE}")
    file(READ "${EXIT_FILE}" expected_exit)
    string(STRIP "${expected_exit}" expected_exit)
endif()

if(DEFINED INPUT AND EXISTS "${INPUT}")
    set(input_file "${INPUT}")
else()
    set(input_file "${WORK_DIR}/.no-input")
    if(NOT EXISTS "${input_file}")
        file(WRITE "${input_file}" "")
    endif()
endif()

execute_process(
    COMMAND "${PROGRAM}" ${program_args}
    WORKING_DIRECTORY "${WORK_DIR}"
    INPUT_FILE "${input_file}"
    RESULT_VARIABLE exit_code
    OUTPUT_VARIABLE printed
    ERROR_VARIABLE error_text
    TIMEOUT 30)

function(tidy out_var text)
    string(REPLACE "\r\n" "\n" text "${text}")
    string(REGEX REPLACE "[ \t]+\n" "\n" text "${text}")
    string(REGEX REPLACE "[ \t\n]+$" "" text "${text}")
    set(${out_var} "${text}" PARENT_SCOPE)
endfunction()

if(NOT "${exit_code}" STREQUAL "${expected_exit}")
    message("---- the program printed ----\n${printed}\n${error_text}\n-----------------------------")
    message(FATAL_ERROR "The program ended with '${exit_code}' (expected ${expected_exit}). "
                        "A number other than 0 usually means a crash or a failed check; "
                        "'timeout' means it kept running or waited for more input.")
endif()

if(DEFINED EXPECTED)
    file(READ "${EXPECTED}" expected_text)
    tidy(expected_text "${expected_text}")
    tidy(printed_text "${printed}")
    if(NOT "${printed_text}" STREQUAL "${expected_text}")
        message("---- expected ----\n${expected_text}\n---- your program printed ----\n${printed_text}\n------------------")
        message(FATAL_ERROR "The output is different from what is expected.")
    endif()
endif()
