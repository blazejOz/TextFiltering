#pragma once
#include "BaseFilter.h"
#include <vector>

class CensorFilter : public BaseFilter
{
public:
    CensorFilter(const std::vector<std::string>& _filtered_words) : filtered_words(_filtered_words) {} 
    virtual std::string apply(const std::string& in) const override;

private:
    const std::vector<std::string> filtered_words;
};
