
# ifndef STACK_VM_H // include gaurds to ensure that STACK_VM_H is only compiled once, pragma once can be used too 
# define STACK_VM_H // include gaurds to ensure that STACK_VM_H is only compiled once, pragma once can be used too    

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Type definitions
// Everything we use will be for 32 bit
typedef int32_t i32 ;

class StackVM {
  i32 pc ; // Program counter
  i32 sp ;   // Stack pointer
  i32 type; // Type of instruction
  i32 data; // Data of instruction
  bool running ;  // Current state running or not
  std::vector<i32> memory; // Stack memory

  // Private functions
  i32 getType (i32 instruction);
  i32 getData (i32 data);
  
  //  the cpu will continously call these functions(in-order) unless it termincates/halts.
  i32 fetch();
  void decode(i32 );
  void executeHelper();
  void execute();
  void doPrimitive(); // Helper function for executing instructions.
  void loadProgram (i32 prog);

  public:

  StackVM();
  void run();
  void RunProgram (std::vector<i32> prog);
};

// Automatically assigned numbers starting from 0.
enum opcode
{
  ADD ,
  SUB ,
  MUL ,
  DIV ,
  MOD ,
  HALT
};

#endif  // include gaurds to ensure that STACK_VM_H is only compiled once, pragma once can be used too 
