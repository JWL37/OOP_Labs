#include <iostream>
#include "FiveDigitArray.h"
// #include "func.h"


int main(){
    std::cout<<"Введите два пятиричных числа:"<<std::endl;
    std::string num1,num2;
    std::cin>>num1>>num2;
    TryCheckCorrectInput(num1,num2);
    FiveDigitArray first(num1);
    FiveDigitArray second(num2);
    FiveDigitArray resultSum=first+second;
    std::cout<<"Сумма : ";
    resultSum.print(std::cout)<<std::endl;

    FiveDigitArray resultSubtract;
    if (num1==num2){
        std::cout<<"первое число равно второму"<<std::endl;
    }
    else if (num1>num2){
        std::cout<<"первое число больше второго"<<std::endl;
        resultSubtract=first-second;
    }
    else if (num1<num2){
        std::cout<<"первое число меньше второго"<<std::endl;
        resultSubtract=second-first;
    }
    
    std::cout<<"Вычитание : ";
    resultSubtract.print(std::cout)<<std::endl;
    
    return 0;
}