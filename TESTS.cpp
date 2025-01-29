#include "dinamicArray.h"
#include <bits/stdc++.h>

int main() {
    try {
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::cout << "After push_back: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        // Test push_front
        vec.push_front(5);
        std::cout << "After push_front(5): ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        // Test pop_back
        vec.pop_back();
        std::cout << "After pop_back: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        // Test pop_front
        vec.pop_front();
        std::cout << "After pop_front: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        // Test insert
        vec.insert(1, 15);
        std::cout << "After insert(1, 15): ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        // Test remove
        vec.remove(1);
        std::cout << "After remove(1): ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << #include "Vector.h"ec2;
        vec2.push_back(40);
        vec2.push_back(50);

        Vector<int> vec3 = vec + vec2;
        std::cout << "After vec + vec2: ";
        for (size_t i = 0; i < vec3.size(); ++i) {
            std::cout << vec3[i] << " ";
        }
        std::cout << std::endl;

        // Test operator +=Vector
        std::cout << std::endl;

        // Test access to a non-existent index (should throw an exception)
        try {
            std::cout << "Trying to access vec[10]: ";
            std::cout << vec[10] << std::endl;
        } catch (const VectorIndexError& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Test clearing the vector
        vec.clear();
        std::cout << "After clear: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
