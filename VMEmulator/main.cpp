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
  i32 arg1 ,arg2 ;
  cout << "[*] Enter first number : ";
  cin>>arg1;
  cout << "[*] Enter second number : ";
  cin>>arg2;
  cout << endl<<"[*] Select an operation to perform :"<<endl;
  cout << "\t1. Addition "<<endl;
  cout << "\t2. Subtraction "<<endl;
  cout << "\t3. Multiplication "<<endl;
  cout << "\t4. Division"<<endl;
  cout << "\t5. Modules  - For Remainder"<<endl;
  int option , temp;
  cin>>option;
  switch(option)
  {
    case 1:
      temp = generateInstruction(ADD, arg1, arg2);
      break;
    case 2:
      temp = generateInstruction(SUB, arg1, arg2);
      break;
    case 3:
      temp = generateInstruction(MUL, arg1, arg2);
      break;
    case 4:
      temp = generateInstruction(DIV, arg1, arg2);
      break;
    case 5:
      temp = generateInstruction(MOD, arg1, arg2);
      break;
    default:
      cerr<<"[#] Error option selected not available" <<endl;
      return 1;
  }

  cout <<"[*] Arguments : " <<arg1<<":"<< arg2<< endl;
  cout <<"[*] Instrucion to execute : "<< temp<< endl;
  prog.push_back(temp);
 
  vm.RunProgram(prog);
}
