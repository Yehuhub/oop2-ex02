#include "IncomeOptions.h"

IncomeOptions::IncomeOptions(){
    insertValue(std::make_pair(1, "Monthly salary"));
    insertValue(std::make_pair(2, "Partial salary"));
    insertValue(std::make_pair(3, "Allowance"));
    insertValue(std::make_pair(4, "Scholarship"));
}