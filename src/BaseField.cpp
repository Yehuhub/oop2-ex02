#include "BaseField.h"

BaseField::BaseField(std::string prompt) : m_prompt(prompt), m_validity(false){};

std::string BaseField::getPrompt()const{
    return m_prompt;
}

void BaseField::setValidity(bool validity){
    m_validity = validity;
}

bool BaseField::getValidity()const{
    return m_validity;
}