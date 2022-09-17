#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <numbers>

// Task 3, Task 4: timesTwo() here

struct Rectangle {
    double length; // Data member, also known as a field
    double width = 1; // Field can have a default value
    // Fields must be explicitly typed, you cannot use type deduction here

    // Member function, also known as a method
    double calculateArea() {
        return length * width;
    }

    // Member function that modifies the state of an object
    void makeItASquare(double sideLength) {
        length = sideLength;
        width = sideLength;
    }

    // Task 5: calculatePerimeter() here
};

// Task 6: struct Circle here

// Task 7:
void printShape(auto shape) {
    // Your code here
}

// Task 9:
void inplaceTimesTwo(/* ??? pointerToSomeVariable */) {
    // Your code here
}

// Task 10:
void doubleEachElement(/* ??? container */) {
    // Your code here
}

int main() {
    // Task 2: write "Hello World!" in an std::cout << "" << std::endl; call

    // Task 3:
    // std::cout << timesTwo(21) << std::endl;

    // Task 4:
    // std::cout << timesTwo(123) << std::endl;
    // std::cout << timesTwo(3.14) << std::endl;
    // std::cout << timesTwo(std::string{ "abc" }) << std::endl;

    // Task 5:
    // std::cout << Rectangle{ 7, 8 }.calculatePerimeter() << std::endl;

    // Task 6: create a few instances of Circle, and call their member functions
    // Tip: to use pi, use std::numbers::pi

    // Task 7: call printShape with different Rectangle and Circle objects

    // Task 8: create a container of strings, fill the container with some strings
    //         apply timesTwo to each string element in the container, print each string element in the container

    // Task 9:
    // auto x = 21;
    // auto y = std::string{ "abcd" };
    // inplaceTimesTwo(&x);
    // inplaceTimesTwo(&y);
    // std::cout << x << std::endl; // you should see 42 here
    // std::cout << y << std::endl; // you should see "abcdabcd" here

    // Task 10: pass different std::array and std::vector objects to doubleEachElement
    //          print the results after doubleEachElement calls
}
