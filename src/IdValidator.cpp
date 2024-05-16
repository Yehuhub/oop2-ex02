#include "IdValidator.h"

#include <string>


bool IdValidator::validate(uint32_t id) const{
    std::string idAsString = std::to_string(id);
    int sum = 0;
    int incNum;

    if(idAsString.size() != 9){
        return false;
    }

    for(int i = 0; i < idAsString.size(); i++){
        incNum = (idAsString[i] - '0') * ((i % 2) + 1);
        (incNum > 9) ? (sum += incNum - 9) : (sum += incNum);
    }

    return (sum % 10 == 0);
}

std::string IdValidator::getErrorPrompt()const {
    return " Error: Wrong control digit";
}