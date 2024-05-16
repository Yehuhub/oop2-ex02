#pragma once

#include <string>
#include <iostream>

//template class for representation of Options subclasses as a choice and options
//choice is user chosen option
template <typename T>
class ValuesToNames{
public:
    ValuesToNames();
    ValuesToNames(int choice);

    std::string valuesAndNames()const;
    void setChoice(int choice);
    int getChoice()const;
    const T& getOptions()const;


private:
    T m_options;
    int m_choice;
};


//---------------------------------------------
//------------------functions------------------

template <typename T>
ValuesToNames<T>::ValuesToNames() : m_options(), m_choice(0){};

template <typename T>
ValuesToNames<T>::ValuesToNames(int choice) : m_options(), m_choice(choice){};

template <typename T>
std::string ValuesToNames<T>::valuesAndNames()const{
    return m_options.valuesAndNames();
}


template <typename T>
void ValuesToNames<T>::setChoice(int choice){
    m_choice = choice;
}

template <typename T>
int ValuesToNames<T>::getChoice()const{
    return m_choice;
}

template <typename T>
const T& ValuesToNames<T>::getOptions()const{
    return m_options;
}

template <typename T>
std::istream& operator>>(std::istream& is, ValuesToNames<T>& obj){
    int choice;
    is >> choice;
    obj.setChoice(choice);
    
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& obj){

    if(obj.getOptions().isChoiceValid(obj.getChoice())){
        os << obj.getOptions().getValue(obj.getChoice());
    }
    else{
        os << obj.getChoice();
    }

    return os;
}

template <typename T>
bool operator<(const ValuesToNames<T>& l, const ValuesToNames<T>& r){
    return (l.getChoice() < r.getChoice());
}

template <typename T>
bool operator>(const ValuesToNames<T>& l, const ValuesToNames<T>& r){
    return (l.getChoice() > r.getChoice());
}