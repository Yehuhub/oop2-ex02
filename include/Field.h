#pragma once

#include <vector>
#include <iostream>

#include "BaseField.h"
#include "Validator.h"


//field template class
//vector of validators can contain different types of validations
template <typename T>
class Field : public BaseField{

public:
    Field(std::string prompt);

    virtual void fillField() override;
    virtual bool validate() override;

    //not operator<< so it can be polymorphic
    virtual void out(std::ostream& os)const override;

    void addValidator(Validator<T>*);
    const T& getValue()const;
    

private:
    T m_value;
    std::vector<Validator<T>*> m_validators;
    std::string m_currentError;
};


//----------------------------------------------
//functions implementation

template <typename T>
Field<T>::Field(std::string prompt) :  BaseField(prompt), m_currentError(""){};

template <typename T>
void Field<T>::fillField(){
    if(!getValidity()){
        std::cout<<getPrompt() <<std::endl;
        std::cin >> m_value;
    }
}

template <typename T>
void Field<T>::addValidator(Validator<T>* vali){
    m_validators.push_back(vali);
}

//suited for more than one validator
template <typename T>
bool Field<T>::validate(){
    m_currentError = "";
    for(auto& validator : m_validators){
        if(!(validator->validate(m_value))){
            m_currentError = validator->getErrorPrompt();
            return false;

        }
    }
    setValidity(true);
    return getValidity();
}

template <typename T>
const T& Field<T>::getValue()const{
    return m_value;
}

template <typename T>
void Field<T>::out(std::ostream& os)const {
    os<<"-----------------------------------"<<std::endl;
    os<< getPrompt() << " = " <<m_value <<" "<< m_currentError <<std::endl;
    os<<"-----------------------------------"<<std::endl;
}
