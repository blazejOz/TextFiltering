#pragma once
#include "BaseFilter.h"
#include <vector>

class UppercaseFilter : public BaseFilter
{
public:
    virtual std::string apply(const std::string& in) override;

};
