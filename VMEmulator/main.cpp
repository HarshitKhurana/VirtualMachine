#include"stack-vm.cpp"

// operation : 1st 4bits + val1 next 14 bits + val2 last 14 bits
i32 generateInstruction(int  operation , int val1, int val2)
{
  return operation | (val1<<4) | (val2 <<18);
}

int main( int argc,  char *argv[]){

  StackVM vm;
  std :: vector<i32> prog;

  /*
   * 11+12
   * 13*14
   * 35-13
   * 15/3
   */

  // For every statement you want to execute first create the corresponding instruction and then put it in a vector and call RunProgram on it.

  // The numbers should be less than pow(2,14) i.e 16384.


  // Adding commands to our program.
  i32 temp = 0;
  for (int i = 23 ; i < 24  ; i++)  {
  
      temp = generateInstruction(SUB , i*2 , i);
      std::cout <<"[*] Pushing instruction : " <<i<<":"<<i*2<<" "<<temp<< " onto program stack."<<std::endl;
      prog.push_back(temp);
  }
  //
  //    temp = generateInstruction(MUL , i , i*2);
  //    std::cout <<"[*] Pushing instruction : " <<i<<":"<<i*2<<" "<<temp<< " onto program stack."<<std::endl;
  //    prog.push_back(temp);
  //      
  //    temp = generateInstruction(DIV , i , i*2);
  //    std::cout <<"[*] Pushing instruction : " <<i<<":"<<i*2<<" "<<temp<< " onto program stack."<<std::endl;
  //    prog.push_back(temp);
  //    
  //    temp = generateInstruction(MOD , i , i*2);
  //    std::cout <<"[*] Pushing instruction : " <<i<<":"<<i*2<<" "<<temp<< " onto program stack."<<std::endl;
  //    prog.push_back(temp);
  // int i = 12;
  //   temp = generateInstruction(HALT, i*2 , i*2);
  //   std::cout <<"[*] Pushing instruction : " <<i<<":"<<i*2<<" "<<temp<< " onto program stack."<<std::endl;
  //   prog.push_back(temp);
  vm.RunProgram(prog);
}
