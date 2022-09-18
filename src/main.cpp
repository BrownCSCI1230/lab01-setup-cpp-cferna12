#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <numbers>

// Task 3, Task 4: timesTwo() here
auto timesTwo(auto x){
    return x+x;
}


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
    double calculatePerimeter(){
        return (length*2) + (width*2);
    }
};

// Task 6: struct Circle here
struct Circle{
    float radius;

    float calculateArea(){
        return (std::numbers::pi*(radius*radius));
    }

    float calculatePerimeter(){
        return (2*std::numbers::pi*radius);
    }
};

// Task 7:
void printShape(auto shape) {
    // Your code here
    std::cout<< "Area: " << shape.calculateArea() << std::endl;
    std::cout<< "Perimeter: " << shape.calculatePerimeter() << std::endl;
}

// Task 9:
void inplaceTimesTwo(auto y) {
    // Your code here
    *y = *y + *y;
}

// Task 10:
void doubleEachElement(auto cont) {
    // Your code here
    for(auto& element : cont){
        element += element;
        std::cout << element << std::endl;
    }

}

int main() {
    // Task 2: write "Hello World!" in an std::cout << "" << std::endl; call
    std::cout<< "Hello World!" << std::endl;

    // Task 3:
     std::cout << timesTwo(21) << std::endl;

    // Task 4:
     std::cout << timesTwo(123) << std::endl;
     std::cout << timesTwo(3.14) << std::endl;
     std::cout << timesTwo(std::string{ "abc" }) << std::endl;

    // Task 5:
     std::cout << Rectangle{ 7, 8 }.calculatePerimeter() << std::endl;

    // Task 6: create a few instances of Circle, and call their member functions
    // Tip: to use pi, use std::numbers::pi
    std::cout << Circle{2}.calculatePerimeter() << std::endl;
    std::cout << Circle{1}.calculateArea() << std::endl;

    // Task 7: call printShape with different Rectangle and Circle objects
    printShape(Rectangle{2});

    // Task 8: create a container of strings, fill the container with some strings
    //         apply timesTwo to each string element in the container, print each string element in the container
    auto x = std::vector<std::string>{};
    x.push_back("Hi there");
    x.push_back("What up");
    x.push_back("B");

    for(auto element : x){
        std::cout << timesTwo((element)) << std::endl;
    }

    // Task 9:
     auto z = 21;
     auto y = std::string{ "abcd" };
     inplaceTimesTwo(&z);
     inplaceTimesTwo(&y);
     std::cout << z << std::endl; // you should see 42 here
     std::cout << y << std::endl; // you should see "abcdabcd" here

    // Task 10: pass different std::array and std::vector objects to doubleEachElement
    //          print the results after doubleEachElement calls
    doubleEachElement((x));
    auto wut = std::array<int, 3>{};
    int w = 2;
    for(int i = 0; i < wut.size(); i++){

        wut[i] = w*w;
        w = w*w;
    }
//    std::cout << wut[1] << std::endl;
    doubleEachElement((wut));

}
