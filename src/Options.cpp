#include "Options.h"

void Options::insertValue(std::pair<int, std::string> val){
    m_options.insert(val);
}
std::string Options::valuesAndNames() const{
    std::string names = "";

    if (!m_options.empty()) {
        auto it = m_options.begin();

        names += std::to_string(it->first) + " - " + it->second;
        ++it; 

        for (; it != m_options.end(); ++it) {
            names += ", " + std::to_string(it->first) + " - " + it->second;
        }
    }

    if (!names.empty()) {
        names.back() = ' ';
    }

    return names;
}
bool Options::isChoiceValid(int choice)const{
    if(m_options.find(choice) == m_options.end()){
        return false;
    }
    return true;
}
std::string Options::getValue(int index) const{
    auto it = m_options.find(index);
    if(it == m_options.end()){
        return "";
    }
    return it->second;//string
}