Custom C++ Vector Implementation
A lightweight, template-based dynamic array 
implementation built to understand manual memory management and container internals. 
This project focuses on the core mechanics of how a vector grows and manages its own lifecycle on the heap.

Features

Dynamic Growth Strategy: Automatically doubles its capacity when the internal size reaches the limit to maintain efficient insertion.

Template Support: Uses C++ templates to allow storage of any data type (int, std::string, custom objects, etc.).

Manual Heap Management: Direct control over memory allocation and deallocation using new[] and delete[].

The Rule of Three: Full implementation of the Destructor, Copy Constructor, and Copy Assignment Operator to ensure deep copies and prevent memory leaks.

Operator Overloading: Provides standard index-based access via operator[] (supporting both mutable and const access) and operator=.

Safety & Exceptions: Includes bounds checking for indexing and prevents invalid operations like popping from an empty vector using standard C++ exceptions.

Core Methods

push_back(T value): Adds an element to the end, triggering a resize if necessary.

pop_back(): Removes the last element or throws a runtime_error if empty.

erase(): Resets the vector size to zero.

index_of(T value): Performs a linear search for a value and returns its index.
