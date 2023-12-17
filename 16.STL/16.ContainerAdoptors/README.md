

# STL Container Adaptors in C++

## Introduction
Container adaptors in STL provide a different interface for standard container types. They are implemented using the existing STL containers but offer specific functionalities suited to particular use cases.

## Main Container Adaptors

### Stack
- **Description**: The `stack` adaptor provides a LIFO (Last In, First Out) data structure.
- **Underlying Container**: By default, it uses `deque`, but can also be implemented using `list` or `vector`.
- **Key Operations**: 
  - `push()`: Insert an element at the top.
  - `pop()`: Remove the top element.
  - `top()`: Access the top element.

### Queue
- **Description**: The `queue` adaptor provides a FIFO (First In, First Out) data structure.
- **Underlying Container**: Typically implemented using `deque`, but can also use `list`.
- **Key Operations**: 
  - `push()`: Insert an element at the end.
  - `pop()`: Remove the first element.
  - `front()`: Access the first element.
  - `back()`: Access the last element.

### Priority Queue
- **Description**: The `priority_queue` is a specialized queue that retrieves elements based on a priority, which is determined by their order in the container.
- **Underlying Container**: Usually implemented using `vector` and makes use of a heap.
- **Key Operations**:
  - `push()`: Insert an element with a certain priority.
  - `pop()`: Remove the element with the highest priority.
  - `top()`: Access the element with the highest priority.

## Usage Examples
(Provide examples demonstrating the creation and use of `stack`, `queue`, and `priority_queue`, such as pushing and popping elements, and accessing the top or front elements.)

## Best Practices
- Choose the appropriate container adaptor based on the required data handling pattern (LIFO, FIFO, or priority-based).
- Be aware that container adaptors do not support iterators, so you cannot iterate through their elements in the traditional sense.

## Further Reading
- Detailed documentation on STL container adaptors on [cppreference.com](https://en.cppreference.com/w/cpp/container)
- "The C++ Standard Library - A Tutorial and Reference" by Nicolai M. Josuttis for an in-depth understanding of container adaptors.
