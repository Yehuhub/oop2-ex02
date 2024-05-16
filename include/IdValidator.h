#pragma once

#include "Validator.h"
#include <cstdint>

//class to check if type uint32_t is a valid id
class IdValidator : public Validator<uint32_t>{
public:
    IdValidator() = default;

    virtual bool validate(uint32_t id) const override;
    virtual std::string getErrorPrompt()const override;
};