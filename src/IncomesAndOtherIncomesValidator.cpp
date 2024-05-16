#include "IncomesAndOtherIncomesValidator.h"

bool IncomesAndOtherIncomesValidator::validate()const {
    int income = (getFirst()->getValue()).getChoice();
    int other = (getSecond()->getValue()).getChoice();

    if((income == 3 && other == 5) || 
        (income == 4 && other == 6) ||
        ((other == 3) && (income != 2 && income != 1))){
        getFirst(1)->setValidity(false);
        getSecond(1)->setValidity(false);
        return false;
    }
    return true;

}

std::string IncomesAndOtherIncomesValidator::getErrorPrompt() const{
    return "Incomes report and other incomes report don't match";
}