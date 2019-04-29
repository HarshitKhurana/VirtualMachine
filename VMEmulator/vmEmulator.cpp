
#include "vmEmulator.h"

// Define functions

/* Instruction format
 *
 * Starting 4 Bits : Operation|Opcode
 * Rest 28 bits : 2 14 bits Argument
 * arg2 = Upper 14 bits
 * arg1 = Lower 14 bits
 *
 */

// The program counter points to the next instruction to execute.
// Stack pointer in our case grows upwards as opposed to usual way of going downwards.
 
VMEmulator::VMEmulator()  {
  pc = 100 ; // Program counter
  sp = 0;   // Stack pointer
  type = 0; // Type of instruction
  data = 0; // Data of instruction
  running = true;  // Current state running or not
  memory.reserve(1000000);   // Memory size
}

// It will simply return the type of instruction i.e last 4 bits.
i32 VMEmulator::getType(i32 instruction)  {
  return instruction & 15;
}

// Everything except the last 4 bits is data
i32 VMEmulator::getData(i32 instruction)  {
  return instruction>>4;
}

// Read 32 bits from memory , which is pointed to by PC and return it after incrementing PC.
i32 VMEmulator::fetch()  {
  return memory[++pc];
}

// this function is the wrapper which internally calls getType & getData and push data on TOS.
void VMEmulator::decode(i32 instruction)  {
  type = getType(instruction);
  data = getData(instruction);
  memory[sp] = data >> 14; // arg1 pushed first i.e upper 14 bits of data.
  memory[++sp] = data & 0x0003fff ; // arg2 pushed  i.e lower 14 bits of data.
  return;
}

// Executes the instruction based on type|opcode and data and pushes result to TOS.
void VMEmulator::execute()  {
  // For opcodes refer to README.md
  std::cout << "[*] Executing OPCODE : "<< type<<std::endl;
  if (type==HALT)   {
    running = !running;
    return;
  }

  int arg1 = memory[sp--];
  int arg2 = memory[sp];

  // Simply push the result on TOS
  switch (type)
  {
    case ADD:
      std::cout << "[*] Adding " << arg1 <<" and "<<arg2 <<" and storing on TOS "<<std::endl;
      memory[sp] = arg1 + arg2;
      break;
      
    case SUB:
      std::cout << "[*] Subtracting " << arg1 <<" and "<<arg2 <<" and storing on TOS "<<std::endl;
      memory[sp] = arg1 - arg2;
      break;
      
    case MUL:
      std::cout << "[*] Multiplying " << arg1 <<" and "<<arg2 <<" and storing on TOS "<<std::endl;
      memory[sp] = arg1 * arg2;
      break;
      
    case DIV:
      std::cout << "[*] Dividing " << arg1 <<" and "<<arg2 <<" and storing on TOS "<<std::endl;
      memory[sp] = arg1 / arg2;
      break;
      
    case MOD:
      std::cout << "[*] Modulus of " << arg1 <<" and "<<arg2 <<" and storing on TOS "<<std::endl;
      memory[sp] = arg1 % arg2;
      break;

    default:
      std::cout <<"[#] ERROR : opcode: " << type<<" not recognised."<<std::endl;
      break;
  }
  return;
}

// Fetches next instruction to execute from memory and pass it to execute function.
void VMEmulator::executeHelper()  {
  i32 instruction = fetch();
  decode(instruction);
  execute();
  std::cout << "[*] Current TOS : "<<memory[sp]<<std::endl;
  return;
}

// It starts running the program inside VM.
void VMEmulator::run()   {
  pc --;  // As fetch increments.
  while (running)   {
    executeHelper(); // It internally calls fetch -> decode -> execute in that order.
    running = !running;
  }
}

void VMEmulator::loadProgram (i32 newInstr)   {
  running=!running;
  memory[pc] = newInstr;
//  cout <<"[*] Pc points to instruction : " << memory[pc]<<endl;
  run();
}

void VMEmulator::RunProgram (std::vector <i32> prog)   {
  for (uint i = 0 ; i < prog.size() ; i++)   {
    loadProgram(prog[i]);
  }
  cout << "[*] Sending HALT instruction now" <<endl;
  loadProgram(5);
}
