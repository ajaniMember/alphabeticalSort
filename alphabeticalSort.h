#ifndef ALPHABETICAL_SORT
#define ALPHABETICAL_SORT

#include <string>
#include <vector>

class alphabeticalSort{

    public:
        //this is the definition
        alphabeticalSort(std::vector<std::string>&, std::vector<std::string>&);
    private:
        
        const std::vector<char> chars;
        std::vector<std::string>& unsortedStrings;
        std::vector<std::string>& sortedStrings;

        void sort();
        int compare(std::string&, std::string&);
        int numericValue(char);
};

#endif