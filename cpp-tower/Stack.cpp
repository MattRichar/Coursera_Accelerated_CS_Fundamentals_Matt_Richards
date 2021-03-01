/**
 * C++ class for a "stack" of cubes in a Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 * @editor
 *   Matt Richards <matt.richards042@gmail.com>
 */

#include "Stack.h"

#include <exception>
#include <iostream>
using std::cout;
using std::endl;

void Stack::push_back(const Cube & cube) {
  // Ensure that we do not push a cube on top of a smaller cube:
  if ( size() > 0 && cube.getLength() > peekTop().getLength() ) {
    //size() is defined to return the size of the current cube called in push_back.
    std::cerr << "A smaller cube cannot be placed on top of a larger cube." << std::endl;
    std::cerr << "  Tried to add Cube(length=" << cube.getLength() << ")" << std::endl;
    std::cerr << "  Current stack: " << *this << std::endl;

    throw std::runtime_error("A smaller cube cannot be placed on top of a larger cube.");
    // A C++ exception is a response to an exceptional circumstance that 
    //arises while a program is running, such as an attempt to divide by zero.
    
    //The throw keyword throws an exception in the program when a problem shows up.
    //A throw expression accepts one parameter (in this case have a runtime error of quote),
    //which is passed as an argument to the exception handler.
    
    //In this case, the exception is the conditional.
    //The conditional is that the size of the current cube is positive and that the current cubes
    //length is greater than size of the previous cube on the stack (i.e. peekTop()).
    
    //A handle can be anything from an integer index to a pointer to a resource in kernel space.
    //The idea is that they provide an abstraction of a resource, 
    //so you don't need to know much about the resource itself to use it.
    
    //Here we are creating a handler within the push_back function that will make sure,
    //we are properly stacking the cubes for each Stack[] placement in Game.
    //If the condition isn't met, the exception isn't called, and we simply push_back onto
    //the current vector of Cubes.
  }

  cubes_.push_back(cube);
}

Cube Stack::removeTop() {
  Cube cube = peekTop();
  //We declare cube to be a Cube class that has the address of the top cube on the
  //vector of Cubes cubes_
  cubes_.pop_back();
  //Removes the last element in the vector, effectively reducing the container size by one.
  //Opposite of push_back()
  return cube;
  
  //Essentially, we are defining an object that is a Cube which has an address given by
  //the top cube of the current stack, reducing that current stacks size by 1, and then
  //returning the result of that.
}

Cube & Stack::peekTop() {
  //Accesses the memory address of the top cube, without removing it from the Stack[].
  return cubes_[cubes_.size() - 1];
}

unsigned Stack::size() const {
  return cubes_.size();
}

std::ostream& operator<<(std::ostream & os, const Stack & stack) {
  for (unsigned i = 0; i < stack.size(); i++) {
    os << stack.cubes_[i].getLength() << " ";
  }
  os << endl;
  return os;
}