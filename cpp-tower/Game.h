/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 * @editor
 *   Matt Richards <matt.richards042@gmail.com>
 */

#pragma once

#include "Stack.h"
#include <vector>

class Game {
  public:
    Game();
    //Constructor initilizating the game
    void solve();
    //Functions that solves the game
    void Step1();
    void Step2();
    void Step3();
    // An overloaded operator<<, allowing us to print the stack via `cout<<`:
    friend std::ostream& operator<<(std::ostream & os, const Game & game);

  private:
    std::vector<Stack> stacks_;
    //Private vector of Stacks that we call stacks_
};
