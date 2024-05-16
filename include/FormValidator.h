#pragma once

#include <string>

#include "BaseFormValidator.h"



//template abstract class for form validators
//derived class will be able to compare different ValuesToNames types
template <typename T1, typename T2>
class FormValidator : public BaseFormValidator{

public:
    FormValidator(T1*, T2*);
    virtual ~FormValidator() = default;

    virtual bool validate()const = 0;
    virtual std::string getErrorPrompt() const = 0;
    
    const T1* getFirst()const;
    const T2* getSecond()const;

    //uses a dummy to overload functions
    //not sure if its clean, could have found a better way probably
    T1* getFirst(int)const;
    T2* getSecond(int)const;

private:
    T1* m_first;
    T2* m_second;
};

template<typename T1, typename T2>
FormValidator<T1,T2>::FormValidator(T1* first, T2* second): m_first(first), m_second(second){};

template<typename T1, typename T2>
const T1* FormValidator<T1, T2>::getFirst()const{
    return m_first;
}

template<typename T1, typename T2>
const T2* FormValidator<T1, T2>::getSecond()const{
    return m_second;
}

template<typename T1, typename T2>
T1* FormValidator<T1, T2>::getFirst(int dummy)const{
    return m_first;
}

template<typename T1, typename T2>
T2* FormValidator<T1, T2>::getSecond(int dummy)const{
    return m_second;
}