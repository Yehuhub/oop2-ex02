#include "RegexValidator.h"

RegexValidator::RegexValidator(std::string reg) : m_regex(reg){}
    
bool RegexValidator::validate(std::string toValidate)const{
    return std::regex_match(toValidate, m_regex);
}

std::string RegexValidator::getErrorPrompt()const {
    return " Error: The input does not adhere to the expected format.";
}