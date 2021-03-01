#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)

//Algorithm
//1. Make the legal move between Stack[0], and Stack[1] (in either direction)
//2. Make the legal move between Stack[0], and Stack[2] (in either direction)
//3. Make the legal move between Stack[1], and Stack[2] (in either direction)
//Repeat

void Game::Step1(){

  Stack s0=stacks_[0];
  Stack s1=stacks_[1];
  
  Cube dflt(0, uiuc::HSLAPixel::DEFAULT);
  
  if(s1.size()<1){
    stacks_[1].push_back(dflt);
  }
  if(s0.size()<1){
    stacks_[0].push_back(dflt);
  }
  Cube & s1top=stacks_[1].peekTop();
  Cube & s0top=stacks_[0].peekTop();
  
  if(s0top.getLength() > s1top.getLength() && s1top.getLength()==0){
    stacks_[1].removeTop();
    stacks_[1].push_back(s0top);
    stacks_[0].removeTop();
    return;
  }
  
  if(s0top.getLength() < s1top.getLength() && s0top.getLength()==0){
    stacks_[0].removeTop();
    stacks_[0].push_back(s1top);
    stacks_[1].removeTop();
    return;
  }
  
  if(s0top.getLength() < s1top.getLength() && s1top.getLength()!=0){
    stacks_[1].push_back(s0top);
    stacks_[0].removeTop();
    return;
  } else {
    stacks_[0].push_back(s1top);
    stacks_[1].removeTop();
    return;
  }
    
}

void Game::Step2(){
  
  Stack s0=stacks_[0];
  Stack s2=stacks_[2];
  
  Cube & s0top=s0.peekTop();
  
  Cube dflt(0, uiuc::HSLAPixel::DEFAULT);
  
  if(s2.size()<1){
    stacks_[2].push_back(dflt);
  }
  Cube & s2top=stacks_[2].peekTop();
  
  if(s0top.getLength() > s2top.getLength() && s2top.getLength()==0){
    stacks_[2].removeTop();
    stacks_[2].push_back(s0top);
    stacks_[0].removeTop();
    return;
  }
  
  if(s0top.getLength() < s2top.getLength() && s2top.getLength()!=0){
    stacks_[2].push_back(s0top);
    stacks_[0].removeTop();
    return;
  } else {
    stacks_[0].push_back(s2top);
    stacks_[2].removeTop();
    return;
  }
    
}
  
void Game::Step3(){
  
  Stack s1=stacks_[1];
  Stack s2=stacks_[2];
  
  Cube & s1top=s1.peekTop();
  Cube & s2top=stacks_[2].peekTop();

  
  if(s1top.getLength() < s2top.getLength() && s2top.getLength()!=0){
    stacks_[2].push_back(s1top);
    stacks_[1].removeTop();
    return;
  } else {
    stacks_[1].push_back(s2top);
    stacks_[2].removeTop();
    return;
  }
    
}
  
void Game::solve() {
  
  if(stacks_[2].size()<3){
    Step1();
    cout << "Step1"<< endl;
    cout << *this << endl;
    Step2();
    cout << "Step2"<< endl;
    cout << *this << endl;
    Step3();
    cout << "Step3"<< endl;
    cout << *this << endl;
    solve();
  }

}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }
  
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
