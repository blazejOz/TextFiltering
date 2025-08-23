#include <vector>
#include <iostream>
#include "BaseFilter.h"
#include "CensorFilter.h"

int main(int argc, char** argv) {
    std::vector<BaseFilter*> filters;
    filters.push_back(new CensorFilter({
                "walk"
                }));
    for (int i = 1; i<argc; i++)
    {
        std::string transformed = std::string(argv[i]);
        std::string original = transformed;
        for (auto* f : filters)
        {
            transformed = f->apply(transformed);
        }
        std::cout<<"Original input: "<<transformed<<" Transformed to: " <<transformed<<std::endl;
    }
    return 0;
}
