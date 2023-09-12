#include <bits/stdc++.h>
#include "functions.h"

int main()
{
  std::string line;
  std::cout << "enter line"<<std::endl;
  std::getline(std::cin,line);
  if (isValue(line)){
    std::cout << "result: " << swapAtoBorBtoA(line) << std::endl;
  }  
  return 0;
}