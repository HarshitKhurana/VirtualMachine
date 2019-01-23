#include"vmEmulator.cpp"

// operation : 1st 4bits + val1 next 14 bits + val2 last 14 bits
i32 generateInstruction(int  operation , int val1, int val2)
{
  return operation | (val1<<4) | (val2 <<18);
}

int main( int argc,  char *argv[]){

  VMEmulator vm;
  std :: vector<i32> prog;

  /*
   * 11+12
   * 13*14
   * 35-13
   * 15/3
   */

  // Adding commands to our program.
  i32 arg1 = 123;
  i32 arg2 = 425;
  i32 temp = generateInstruction(ADD, arg1, arg2);
  cout <<"[*] Arguments : " <<arg1<<":"<< arg2<< endl;
  cout <<"[*] Instrucion to execute : "<< temp<< endl;
  prog.push_back(temp);
 
  vm.RunProgram(prog);
}
