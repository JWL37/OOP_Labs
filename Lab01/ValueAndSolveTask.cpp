#include <iostream>
#include "ValueAndSolveTask.h"

std::string trySwapAtoBorBtoA(std::string line){
    try
    {
        return swapAtoBorBtoA(line);
    }
    catch(const std::invalid_argument& e)
    {
        return  e.what();
    }
    
}

bool isCorrectLine(std::string line){
    for (char elemLine :line){
        if (elemLine!='a' and elemLine!='b' and elemLine!='c'){
            throw std::invalid_argument( "Received another symbol!!!" );
            return false;
        }
    }
    return true;
}

std::string swapAtoBorBtoA(std::string line){
    if (!isCorrectLine(line))
        throw std::invalid_argument( "Received another symbol!!!" );
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