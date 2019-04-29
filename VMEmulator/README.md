<h2> VMEmulator : A Process based VM emulator </h2>

 <b>--> </b>This is a very basic and probably one of the simplest example of how does a stack based Virtual Machine works, it simply emulates it's functioning.

<h3> [*] How does it Work ?</h3><hr>
 <b> --> </b>The working is explained in the steps as follows ( these will include many direct references to code , helps in explaining) : 
<br> 
<br> 

&emsp;&emsp; <b>1.</b> Arguments passed to `generateInstruction(operation , arg1 , arg2)` in `main.cpp` generates the entire instruction that can be directly executed on the stack VM. <br>

&emsp;&emsp; <b>2.</b> Now load the entire set of instructions that are supposed to be executed in the program data-structure(a 32bit array) and call `RunProgram()` on it.<br>

&emsp;&emsp; <b>3.</b> The `RunProgram()` internally executes those instructions serially in the same order in which they were inserted and at last calls the `HALT` instruction.<br>

&emsp;&emsp; <b>4.</b> The `loadProgram()` first changes the state of machine from <i>not running</i> to <i>running</i> and then load the instructions into memory for execution, now the <i>Program Counter(also called Instruction Pointer)</i> points to that instruction and invokes the `run()`.<br>

&emsp;&emsp; <b>5.</b> Now as soon as the `run()` is invoked it decrements the value of <i>Program Counter(also called Instruction Pointer)</i> and invokes `executeHelper()` which is the wrapper function responsible for the cycle of <b>`fetching -> Decoding -> Executing`</b> the instruction in that praticular order. <br>

&emsp;&emsp; <b>6.</b> The `fetch()` points the program counter to the instruction present in the memory which is to be execute and return it to caller.<br> 

&emsp;&emsp; <b>7.</b> The `decode(instruction)` uses the instruction and gets the corresponding opcode and operations form that instruction and pushes the operands onto the memory stack.<br> 

&emsp;&emsp; <b>8.</b> The `execute()` on the basis of opcode execute the necessary operation using the elements present on Stack (starting from top of stack).<br> 

&emsp;&emsp; <b>9.</b> Once every instruction in the loaded program is executed the stack-vm automatically executes the `HALT` instruction and <i>End of Program</i> is reached.<br> 


<br>

<h3> [*] Instruction Set</h3><hr>
<b><i>--> 32 bit - 4Byte RISC Instruction Set (fixed length) i.e every instruction must be of 32-bit. </i></b><br>
<br>
&emsp; &emsp; --> Every instruction consists of opcode for the operation and operands on which to execute.<br>
&emsp; &emsp; --> 4 Bits are reserved for opcodes, which means there can be at-max of 16 unique operations.<br>
&emsp; &emsp; --> 28 Bits are for operands which is further divided as 2 14-bits operands. <br>
&emsp; &emsp; --> In this we only use 6 operations as explained below along with their opcodes. <br>
&emsp; &emsp; --> Any value of opcode except from these will throw : Error "Unusual opcode not recognized". <br>
&emsp; &emsp; --> Operations along with their opcodes. (The opcode is) <br>
<br>

```bash
<Operation>  : <Opcode>

  ADD        : 0
  SUBTRACT   : 1
  MULTIPLY   : 2 
  DIVIDE     : 3
  MODULUS    : 4 
  HALT       : 5
```
<br>
<h3> [*] Future Scope</h3><hr>
&emsp; &emsp; 1. Instead of hard-coding the instruction to run in 'main.cpp', take input from user in the form then tokenise the input and generate the necessary instruction from it which will be actually executed.
<br>
 &emsp; &emsp; <strong>Example : </strong>
<br>

```bash
./stack-vm

[*] Arithmetic operations currently supported : '+' , '-' , '*' , '/' , '%'
[*] Maximum value of the 2 operands between which the operation is to be performed : '8191' # Restriction due to max size of operand being 14-bit
[*] Enter the string -
1234+123
[*] Pushing instruction : 23:46 32263456 onto program stack.
[*] Sending HALT instruction now
[*] Executing OPCODE : 5
[*] Current TOS : 0
[*] Executing OPCODE : 0
[*] Adding 1234 and 123 and storing on TOS 
[*] Current TOS : 1357
[*] Output : 1357

```
<br>
&emsp; &emsp; 2. Support for complex strings parsing and generating instruction from them and feeding the output of 1 instruction into other, in stack only and not explicitly passing.
</br>
 &emsp; &emsp; <strong>Example : </strong>
<br>

```bash
./stack-vm

[*] Arithmetic operations currently supported : '+' , '-' , '*' , '/' , '%'
[*] Maximum value of the 2 operands between which the operation is to be performed : '8191' # Restriction due to max size of operand being 14-bit
[*] Enter the string -
( 4 + 5) / (6*4 / (4-2)) * (7*4) + 3
```

<br>

<h3> [*] Resources|References </h3><hr>

 --> <a href="https://bartoszsypytkowski.com/simple-virtual-machine"> Simple VM </a>(takes into account CPU Registers too)<br>
 --> <a href="https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Introduction"> General guide to VM</a><br>
 --> <a href="https://www.codeproject.com/KB/recipes/B32Machine1/VMCS.pdf"> Code Project : VM </a><br>
 --> <a href="https://justinmeiners.github.io/lc3-vm"> VM implementing LC-3</a> <br>
 --> <a href="https://www.youtube.com/playlist?list=PLSiFUSQSRYAOFwfP-aMzXJlWKVyIuWfPU"> VM implementation</a>(along with assembler, tokenizer etc)<br>
 --> <a href="InfoQ : https://www.youtube.com/watch?v=OjaAToVkoTw"> InfoQ : VM</a><br>
