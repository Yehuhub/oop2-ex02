#pragma once

#include "FormValidator.h"
#include "Field.h"
#include "ValuesToNames.h"
#include "IncomeOptions.h"
#include "OtherIncomes.h"

//class for a specific form validator
class IncomesAndOtherIncomesValidator : public FormValidator<Field<ValuesToNames<IncomeOptions>>,Field<ValuesToNames<OtherIncomes>>>{
public:
    
    using FormValidator::FormValidator;

    virtual bool validate()const override;
    virtual std::string getErrorPrompt()const override;
};

