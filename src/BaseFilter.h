#pragma once
#include <string>

class BaseFilter {
public:
    virtual std::string apply(const std::string& in) const = 0;
};
