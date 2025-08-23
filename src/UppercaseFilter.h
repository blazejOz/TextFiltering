#pragma once
#include "BaseFilter.h"

class UppercaseFilter : public BaseFilter
{
public:
    const std::string apply(const std::string& in) override;

};
