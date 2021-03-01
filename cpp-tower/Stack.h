/**
 * C++ class for a "stack" of cubes in a Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 * @editor
 *   Matt Richards <matt.richards042@gmail.com>
 */

#pragma once

#include <vector>
#include "uiuc/Cube.h"
using uiuc::Cube;

class Stack {
  public:
    void push_back(const Cube & cube);
    //This borrows terminology from the vector template.
    //It pushes an element to the last element of a Stack.
    Cube removeTop();
    //This returns a Cube by value, so it returns a copy
    //of a Cube created earlier.
    Cube & peekTop();
    //This returns a Cube by reference, and it only returns 
    //the memory address of the Cube on top, without
    //removing that Cube from the internal data structure.
    unsigned size() const;
    //The size() function returns the size of each stack
    //in a similar manner to the vector template.

    // An overloaded operator<<, allowing us to print the stack via `cout<<`:
    friend std::ostream& operator<<(std::ostream & os, const Stack & stack);
    //A friend function of a class is defined outside that class' scope 
    //but it has the right to access all private and protected 
    //members of the class.
    
    //It allows us to cout an object.
    
    //It will take on the std::ostream& operator and it will take in
    //itself and a constant type of the class it is in.
  private:
    std::vector<Cube> cubes_;
};