/*
    Sorts the strings in unsortedStrings into sortedStrings
*/
#include "alphabeticalSort.h"
#include <iostream>
#include <string>
#include <vector>
//for isupper()
#include <ctype.h>

alphabeticalSort::alphabeticalSort(std::list<std::string>& strings, std::list<std::string>& sorted) 
: chars({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[' , ']', ';', '\'', ',', '.', '/', '{', '}', ':', '"', '<', '>', '?', '\\', '|', ' ', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z'}),
  unsortedStrings(strings),
  sortedStrings(sorted)
{
    sort();
}

void alphabeticalSort::sort()
{
    bool found = 0;

    //if sortedStrings is empty pop unsortedStrings first value and put it in sortedStrings
    if(sortedStrings.size() == 0)
    {
        sortedStrings.push_back( unsortedStrings.front() );
        unsortedStrings.erase( unsortedStrings.begin() );
    }
    
    for(int count = unsortedStrings.size(); count != 0; count--){

        for(auto s = sortedStrings.begin(); s != sortedStrings.end(); s++)
        {
            if(compare(unsortedStrings.front(), *s))
            {
                sortedStrings.insert(s, unsortedStrings.front());
                unsortedStrings.erase(unsortedStrings.begin());
                found = true;
                break;
            }
        }
        
        //place value at the back of vector because nothing else to compare to
        if(!found)
        {
            sortedStrings.push_back(unsortedStrings.front());
            unsortedStrings.erase(unsortedStrings.begin());
        }
        
        found = false;
    }
      
}

//returns true if a is considered less than b
int alphabeticalSort::compare(std::string& a, std::string& b)
{
    int aLength = a.size();
    int bLength = b.size();

    //max in for loop must be the size of the smaller string
    int max = aLength > bLength ? bLength : aLength;

    int aNum;
    int bNum;

    for(int i = 0; i <= max; i++)
    {   
        aNum = numericValue(a[i]);
        bNum = numericValue(b[i]);

        if(aNum < bNum)
        {
            return 1;
        }
        else if(aNum > bNum)
        {
            return 0;
        }
    }

    //if one string either matches the other or it fits inside the other string
    //return the string that has less characters
    return aLength > bLength || aLength == bLength ? 0 : 1;
}

//returns the position that the variable a equals in the chars vector
int alphabeticalSort::numericValue(char a)
{
    int i = 0;

    for(auto e = chars.begin(); e != chars.end(); e++, i++){

        if(a == *e)
        {   
            //if uppercase return i as the lowercase position
            if(isupper(a)){

                return i-1;
            }
            else
            {
               return i; 
            }
            
        }
    }

    return -1;
}