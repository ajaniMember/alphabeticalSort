/*
    Sorts the strings in unsortedStrings into sortedStrings
*/
#include "alphabeticalSort.h"
#include <iostream>
#include <string>
#include <vector>

alphabeticalSort::alphabeticalSort(std::vector<std::string>& strings, std::vector<std::string>& sorted) 
: unsortedStrings(strings), sortedStrings(sorted), chars({'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[' , ']', ';', '\'', ',', '.', '/', '{', '}', ':', '"', '<', '>', '?', '\\', '|', ' '})
{
    sort();
}

void alphabeticalSort::sort()
{
    //unsorted string
    std::string us;
    bool found = 0;

    //if sortedStrings is empty pop unsortedStrings first value and put it in sortedStrings
    if(sortedStrings.size() == 0)
    {
        sortedStrings.push_back( unsortedStrings[0] );
        unsortedStrings.erase( unsortedStrings.begin() );
    }
    
    //using while instead of for so the now non-existant iterator doesn't get invalidated when I erase an element
    int count = unsortedStrings.size();
    while(count != 0)
    {
        us = unsortedStrings[0];
        //std::cout << us << std::endl;
        
        for(auto s = sortedStrings.begin(); s != sortedStrings.end(); s++)
        {  

            //returns 1, 'us' is less than 's
            if(compare(us, *s))
            {
                //add the unsorted string into the sortedStrings array before the sortedString that
                //'us' was compared to
                sortedStrings.insert(s, us);
                unsortedStrings.erase(unsortedStrings.begin());
                found = true;
                break;
            }
            
        }
        
        if(!found)
        {
            found = false;
            //unsorted String is not less than any other value so we place it at the back
            //then remove it from the unsortedStrings vector
            sortedStrings.push_back(us);
            unsortedStrings.erase(unsortedStrings.begin());
        }

        count--;
    }
      
}

//returns true is a is considered less than b
int alphabeticalSort::compare(std::string& a, std::string& b)
{
    int aLength = a.size();
    int bLength = b.size();
    //max in for loop must be the size of the smaller string
    int max = aLength > bLength ? bLength : aLength;

    for(int i = 0; i <= max; i++)
    {   

        if(numericValue(a[i]) < numericValue(b[i]))
        {
            return 1;
        }
        else if(numericValue(a[i]) > numericValue(b[i]))
        {
            return 0;
        }
    }

    //if one string either matches the other or it fits inside the other string
    //return the string that has less characters
    return aLength > bLength || aLength == bLength ? 0 : 1;
}

int alphabeticalSort::numericValue(char a)
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