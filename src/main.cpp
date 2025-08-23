#include <vector>
#include <iostream>
#include "BaseFilter.h"
#include "CensorFilter.h"
#include "UppercaseFilter.h"

int main(int argc, char** argv) {
    std::vector<BaseFilter*> filters;
    filters.push_back(new CensorFilter({
                "walk"
                }));
    filters.push_back(new UppercaseFilter());
    for (int i = 1; i<argc; i++)
    {
        std::string original = std::string(argv[i]);
        std::string transformed = original;
        for (auto* f : filters)
        {
            transformed = f->apply(transformed);
        }
        std::cout<<"Original input: \""<<original<<"\" Transformed to: \"" <<transformed<<"\"" <<std::endl;
    }
    return 0;
}
