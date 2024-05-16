#pragma once

#include "FormValidator.h"
#include "Field.h"
#include "ValuesToNames.h"
#include "TaxCredits.h"
#include "OtherIncomes.h"

//class for a specific form validator
class OtherIncomesAndTaxCreditsValidator : public FormValidator<Field<ValuesToNames<OtherIncomes>>,Field<ValuesToNames<TaxCredits>>>{
public:
    
    using FormValidator::FormValidator;

    virtual bool validate()const override;
    virtual std::string getErrorPrompt()const override;
};

