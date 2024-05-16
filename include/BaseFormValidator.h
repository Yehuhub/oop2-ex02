#pragma once

#include <string>

//pure virtual base class for form validators
//only for polymorphism uses
class BaseFormValidator{
public:
    virtual ~BaseFormValidator() = default;
    virtual bool validate()const = 0;
    virtual std::string getErrorPrompt() const = 0;
    
};