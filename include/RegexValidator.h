#pragma once

#include <string>
#include <regex>

#include "Validator.h"

//class to validate a string using regex
//class gets regex pattern as a string in the c-tor
class RegexValidator : public Validator<std::string>{
public:
    RegexValidator(std::string);
    
    virtual bool validate(std::string) const override;
    virtual std::string getErrorPrompt()const override;

private:
    std::regex m_regex;
};