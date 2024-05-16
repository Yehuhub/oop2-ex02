#pragma once

#include <vector>

#include "BaseField.h"
#include "BaseFormValidator.h" 


//form class 
//holds fields and form validators in vectors
class Form{
public:
    Form() = default;

    const std::vector<BaseField*>& getFields()const;
    const std::vector<std::string>& getFormErrors() const;
    void addField(BaseField *);
    void addValidator(BaseFormValidator*);
    bool validateForm();
    void fillForm();


private:
    std::vector<BaseField*> m_fields;
    std::vector<BaseFormValidator*> m_formValidators;
    std::vector<std::string> m_formErrors;
};

std::ostream& operator<<(std::ostream& os, const Form & obj);