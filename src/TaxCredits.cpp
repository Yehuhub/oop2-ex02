#include "TaxCredits.h"

TaxCredits::TaxCredits(){
    insertValue(std::make_pair(1, "I have no other income"));
    insertValue(std::make_pair(2, "I request to receive tax credits for this income"));
    insertValue(std::make_pair(3, "I do not request to receive tax credits"));
}