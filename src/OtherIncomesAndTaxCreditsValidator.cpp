#include "OtherIncomesAndTaxCreditsValidator.h"

bool OtherIncomesAndTaxCreditsValidator::validate()const{
    int other = (getFirst()->getValue()).getChoice();
    int tax = (getSecond()->getValue()).getChoice();

    if((other != 1 && tax == 1) || 
        ((other < 2 || other > 4) && tax == 2)){
        getFirst(1)->setValidity(false);
        getSecond(1)->setValidity(false);
        return false;
    }
    return true;
}

std::string OtherIncomesAndTaxCreditsValidator::getErrorPrompt() const{
    return "Other incomes report and tax credits report don't match";
}