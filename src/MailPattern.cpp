#include "MailPattern.h"

std::string MailPattern::getPattern(){
    return R"(\w[\w.-]*@\w[\w.-]*\.[A-Za-z]{2,})";
}