/*
    Sorts the strings in unsortedStrings into sortedStrings
*/
#include "alphabeticalSort.h"
#include <iostream>
#include <string>
#include <vector>

alphabeticalSort::alphabeticalSort(std::vector<std::string>& strings, std::vector<std::string>& sorted) 
: unsortedStrings(strings), sortedStrings(sorted), chars({'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[' , ']', ';', '\'', ',', '.', '/', '{', '}', ':', '"', '<', '>', '?', '\\', '|'})
{
    sort();
}

void alphabeticalSort::sort()
{
    //unsorted string
    std::string us;

    //if sortedStrings is empty pop unsortedStrings first value and put it in sortedStrings
    if(sortedStrings.size() == 0)
    {
        sortedStrings.push_back( unsortedStrings[0] );
        unsortedStrings.erase( unsortedStrings.begin() );
    }
    else
    {
        int count = unsortedStrings.size();
        //using while instead of for so the now non-existant iterator doesn't get invalidated when I erase an element
        while(count != 0)
        {
            us = unsortedStrings[0];

            for(auto s : sortedStrings)
            {  
                //if returns 1, 'us' is less than 's'
                if( compare(us, *s) )
                {
                    //add the unsorted string into the sortedStrings array before the sortedString that
                    //'us' was compared to
                    sortedStrings.insert(s--, us);
                    unsortedStrings.erase(unsortedStrings.begin());

                    break;
                }

            }
            //unsorted String is not less than any other value so we place it at the back
            //then remove it from the unsortedStrings vector
            sortedStrings.push_back(us);
            unsortedStrings.erase(unsortedStrings.begin());

            count--;
        }
    }    
}

int alphabeticalSort::compare(std::string unsorted, std::string sorted)
{
    int usLength = unsorted.size();
    int sLength = sorted.size();

    //use the larger string to loop over to avoid accessing an undefined element
    if(usLength > sLength)
    {
        
        for(int i = 0; i <= usLength; i++)
        {

            //unsorted is considered less than sorted
            if( findNumericValue(unsorted[i]) < findNumericValue(sorted[i]) )
            {

                return 1;
                break;

            }
            //sorted is considered less than sorted
            else if( findNumericValue(unsorted[i]) > findNumericValue(sorted[i]) )
            {
                return 0;
                break;
            }

        }

    }
    else
    {
        for(int i = 0; i <= sLength; i++)
        {
            //unsorted is considered less than sorted
            if( findNumericValue(unsorted[i]) < findNumericValue(sorted[i]) )
            {

                return 1;
                break;

            }
            //sorted is considered less than sorted
            else if( findNumericValue(unsorted[i]) > findNumericValue(sorted[i]) )
            {
                return 0;
               

            }
        }
    }
    


}

int alphabeticalSort::findNumericValue(char a)
{
    int i = 1;

    for(auto e = chars.begin(); e != chars.end(); e++, i++){

        if(a == *e)
        {
            return i;
        }
    }

    return -1;
}