#include "Form.h"

#include <iostream>

void Form::addField(BaseField *field){
    m_fields.push_back(field);
}

void Form::addValidator(BaseFormValidator* validator){
    m_formValidators.push_back(validator);
}

bool Form::validateForm(){
    bool fieldValidation = true, formValidation = true;
    std::vector<std::string> currentErrors;

    //check input validity
    for(auto& field : m_fields){
        if(!(field->validate()))
            fieldValidation = false;
    }

    //check form logic validity
    for(auto & formValidator : m_formValidators){
        if(!(formValidator->validate())){
            formValidation = false;
            currentErrors.push_back(formValidator->getErrorPrompt());
        }
    }

    m_formErrors = currentErrors;
    return (fieldValidation && formValidation);
}

void Form::fillForm(){
    for(auto& field : m_fields){
        field->fillField();
    }
}

const std::vector<BaseField*>& Form::getFields()const{
    return m_fields;
}

const std::vector<std::string>& Form::getFormErrors() const{
    return m_formErrors;
}

std::ostream& operator<<(std::ostream& os, const Form & obj){

    for(auto& field : obj.getFields()){
        field->out(os);
    }
    for(auto& error : obj.getFormErrors()){
        std::cout << error << std::endl;
    }

    return os;
}