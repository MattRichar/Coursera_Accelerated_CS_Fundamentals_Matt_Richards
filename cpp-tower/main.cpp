/**
 * Simple main to create and solve a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 * @editor
 *   Matt Richards <matt.richards042@gmail.com>
 */

#include "Game.h"
#include <iostream>

int main() {
  Game g;
  Stack s;

  std::cout << "Initial game state: " << std::endl;
  std::cout << g << std::endl;

  g.solve();

  std::cout << "Final game state: " << std::endl;
  std::cout << g << std::endl;

  return 0;
}