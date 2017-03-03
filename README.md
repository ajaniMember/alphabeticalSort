# alphabeticalSort
A class that sorts a vector of strings into alphabetical order.

# Objective
I am using this project as a usefull tool for me to:
    
    a) learn more about c++ 
    b) how to solve problems in the most efficient manner both in terms of time and complexity.
    c) learn to write cleaner more robust and maintainable code

The compare function evaluates which value is less than the other by looking at each word character by character and assessing which of the numbers returned by findNumericValue() is less than the other.

If the unsorted string is (considered)less than the sorted string it gets placed in front of the sorted string in question, other wise it moves on to evaluate the next sorted string, and if there is none the unsorted string gets placed at the back of the vector.

# To Do
Requirements that need to be complete before I would consider it complete

    - = not started
    # = started
    * = complete

    [#] - clean and simplify code

#Compilation
clang++ -std=c++14 test.cpp alphabeticalSort.cpp
