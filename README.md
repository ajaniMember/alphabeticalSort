# alphabeticalSort
A class that sorts a vector of strings into alphabetical order.

The compare function evaluates which value is less than the other by looking at each word character by character and assessing which of the numbers returned by findNumericValue() is less than the other.
if the unsorted string is (considered)less than the sorted string it gets placed in front of the sorted string in question, other wise it moves on to evaluate the next sorted string, and if there is none the unsorted string gets placed at the back of the vector.