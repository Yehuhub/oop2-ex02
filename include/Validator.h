#pragma once

#include <string>

//template base class for validators
//needs to be template for validate() to get different types of parameters
template <typename T>
class Validator{
public:

    virtual ~Validator() = default;
    virtual bool validate(T) const = 0;
    virtual std::string getErrorPrompt()const = 0;
};