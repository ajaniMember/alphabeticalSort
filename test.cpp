#include <iostream>
#include <vector>
#include <string>
#include "alphabeticalSort.h"

int main()
{
    std::vector<std::string> unsortedVector = {"davidosomething", "Toris", "Urchin", "cohokiller673", "jzl", "ludat", "ryaxnb", "Holzhaus", "nuncanda_", "shmalu", "Cabanossi", "Nagatosh", "blocky", "rindolf", "mackal", "SpacePenguin", "Loomy", "sewerrat", "Batze", "holodoc", "kicksled", "daey", "Adran", "peepsalot", "Guytest"};
    std::vector<std::string> sortedVector;

    for(auto& e : unsortedVector)
    {
        std::cout << e << std::endl;
    }

    alphabeticalSort(unsortedVector, sortedVector);

    return 0;
}