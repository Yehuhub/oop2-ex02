#pragma once

#include <string>
#include <map>


//base class for the different type of income options/tax credits
class Options{

public:
    Options() = default;

    bool isChoiceValid(int choice)const;
    void insertValue(std::pair<int, std::string>);
    std::string valuesAndNames() const;
    std::string getValue(int index) const;

private:
    std::map<int, std::string> m_options;

};