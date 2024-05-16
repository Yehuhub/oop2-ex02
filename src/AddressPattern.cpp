#include "AddressPattern.h"

std::string AddressPattern::getPattern(){
    return R"(^[a-zA-Z]+-\d+-[a-zA-Z]+$)";
}