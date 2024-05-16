#pragma once

#include <string>
#include <vector>


//Base class for field
class BaseField{
public:
    BaseField(std::string);
    virtual ~BaseField() = default;

    virtual bool validate() = 0 ;
    virtual void fillField() = 0;
    virtual void out(std::ostream& os)const = 0;

    void setValidity(bool);
    bool getValidity()const;
    std::string getPrompt()const;

private:
    std::string m_prompt; //type of field as string
    bool m_validity; //saves us from checking validity even when all good(default is false)
    
};