#include "CensorFilter.h"

std::string CensorFilter::apply(const std::string& in) 
{
    std::string out = in;
    for (const auto& w : filtered_words) {
        std::string replace;
        while (out.find(w) != std::string::npos)
        {
            out.replace(out.find(w), w.size(), std::string(w.size(), '*'));
        }
    }
    return out;
}
