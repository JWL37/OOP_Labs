#include <iostream>
#include "functions.h"

bool isValue(std::string line){
    for (char elemLine :line){
        if (elemLine!='a' and elemLine!='b' and elemLine!='c'){
            std::cout<<"Another Symbol"<<std::endl;
            return false;
        }
    }
    return true;
}

std::string swapAtoBorBtoA(std::string line){
    std::string result_line {""};
    for (char elemLine :line){
        switch (elemLine)
        {
        case 'a':
            result_line+='b';
            break;
        case 'b':
            result_line+='a';
            break;
        default:
            result_line+=elemLine;
            break;
        }
    }
    return result_line;
}