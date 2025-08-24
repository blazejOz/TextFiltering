#include "UppercaseFilter.h"
#include <algorithm>
#include <cctype>

std::string UppercaseFilter::apply(const std::string& in) 
{
    std::string out = in;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return out;
}