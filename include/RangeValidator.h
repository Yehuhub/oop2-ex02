#pragma once

#include "Validator.h"

//class to validate if a type is within range for given range.
//type T have to implement < > operators
template <typename T>
class RangeValidator : public Validator<T>{

public:
    RangeValidator(T, T);
    RangeValidator(int, T);

    virtual bool validate(T) const override;
    virtual std::string getErrorPrompt()const override;

private:
    T m_lowBounds;
    T m_upperBounds;
};

template <typename T>
RangeValidator<T>::RangeValidator(T lowBounds, T upperBounds) 
    : m_lowBounds(lowBounds), m_upperBounds(upperBounds){};

template <typename T>
RangeValidator<T>::RangeValidator(int lowBounds, T upperBounds) 
    : m_lowBounds(lowBounds), m_upperBounds(upperBounds){};

template <typename T>
bool RangeValidator<T>::validate(T value) const{
    if(value < m_lowBounds || value > m_upperBounds){
        return false;
    }
    return true;
}

template <typename T>
std::string RangeValidator<T>::getErrorPrompt()const{
    return " Error: Out of range.";
}