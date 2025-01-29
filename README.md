# CustomVector
A C++ implementation of a dynamic array (vector).


# Dynamic Array Implementation in C++

This repository contains a C++ implementation of a dynamic array (vector) that supports various common operations.

## Features

This dynamic array implementation provides the following features:

### Constructors

*   **`Vector()`**: Default constructor that creates a vector with an initial capacity of 8.
*   **`Vector(T* _data, size_t len, size_t cap)`**: Constructor that initializes the vector from a given array `_data` with a specified length `len` and capacity `cap`.
*   **`Vector(const Vector& other)`**: Copy constructor that creates a copy of another vector.

### Data Manipulation Methods

*   **`void set_coords(T* _data, size_t len, size_t cap)`**: Sets the vector's data from a provided array `_data`.
*   **`void push_back(T val)`**: Adds an element `val` to the end of the vector, resizing if necessary.
*   **`void push_front(T val)`**: Adds an element `val` to the beginning of the vector, resizing if necessary.
*   **`void pop_back()`**: Removes the last element of the vector.
*   **`void pop_front()`**: Removes the first element of the vector.
*   **`void insert(size_t index, T val)`**: Inserts an element `val` at the specified `index`.
*   **`void remove(size_t index)`**: Removes the element at the specified `index`.
*   **`void clear()`**: Clears the vector, resetting it to its initial state (capacity 8, size 0).
*   **`void resize(size_t new_capacity)`**: Changes the capacity of the vector to `new_capacity`.

### Information Methods

*   **`size_t capacity() const noexcept`**: Returns the current capacity of the vector.
*   **`size_t size() const noexcept`**: Returns the current number of elements in the vector.
*   **`bool empty() const noexcept`**: Checks if the vector is empty.

### Operators

*   **`Vector& operator+=(const Vector& other)`**: Appends the elements of another vector to the current vector.
*   **`Vector operator+(const Vector& right) const`**: Returns a new vector that is the result of the addition of two vectors.
*   **`Inner operator[](size_t index)`**: Overload of the `[]` operator for mutable access to the vector's elements.
*   **`const T& operator[](size_t index) const`**: Overload of the `[]` operator for read-only access to the vector's elements.

### Inner Class

*   The `Inner` class is a helper class used to implement the overloaded `[]` operator for both reading and writing of elements.

### Exceptions

This dynamic array implementation throws exceptions in the following situations:

*   **`VectorIndexError`**: Thrown when trying to access an invalid index.
*   **`VectorMemoryError`**: Thrown when there is an error during memory allocation.
