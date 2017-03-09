#ifndef ALPHABETICAL_SORT
#define ALPHABETICAL_SORT

#include <string>
#include <list>
#include <vector>

class alphabeticalSort{

    public:
        //this is the definition
        alphabeticalSort(std::list<std::string>&, std::list<std::string>&);
    private:
        
        const std::vector<char> chars;
        std::list<std::string>& unsortedStrings;
        std::list<std::string>& sortedStrings;

        void sort();
        int compare(std::string&, std::string&);
        int numericValue(char);
};

#endif