
32 bit - 4Byte RISC Instruction Set (fixed length)

Every instruction consists of opcode for the operation and operands on which to execute.
28 Bits are for operands which is further divided as 2 14-bits operands. 
4 Bits are reserved for opcodes, which means there can be at-max of 16 unique operations.
We only use 6 here.

Operations along with their opcodes. (Randomly assigned)

ADD : 0
SUBTRACT : 1
MULRIPLY : 2 
DIVIDE : 3
MODULUS : 4 
HALT : 5
