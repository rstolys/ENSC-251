//Notes from lecture 19
/*
Discussion about ID3
    how to find a split point 
        Check every attribute and get entropy for that attribute 
        Find best choice and split there -- exaustive search and split there
Dataset will be handwriting recognition -- 1000 lines, 5000 attributes each -- not important on coding but good to know

Topic for today: 
Hash Tables: 
    Take input and create a unqiue identifier to find the element in question 
    To create the unqiue ID you insert data into has function which gives the resulting key
    Hash function -- takes input and produces index to array 
                Example: f(x) = x % (size of array);
        in cases where the same key is created you can from a linked list in the array element that leads 
            to all the elements with that key
    To delete item: 

    Radix tree: Is a hash table in each element of the array coming from the first hash table
        massive structure and complex, very good perfromance 


Complexity: 
    Engineering has requirment for instant speed: where complexity is important 
        changing algorthm will allow for reduction in complexity
            changing implementation of algorithm has small impact 
    
    How to measure: 
        same as talked about in cmpt 128 
            do not care about constants
        Types of complexity:                        Big O complexity
            exponentinal complexity -- very bad     O(2^n)
            logorithmic complexity -- very good     O(log(n))
            constant runtime -- best                O(1)
            polynomial runtime -- average           O(n^3)
            polynomial/ log runtime -- good         O(nlog(n))
        
        n^3 is worst complexity that you would want to deal with 

        Is about how long program will take as you add more elements of data


Graph algorithm: to create least spanning tree
    start at point and take the cheapest edge that joins to rest of structure 
        complexity  O(?)-- will be discussed tomorrow 
    



    *** someone cheated on the SAT assignment *** 
        -- TAs could tell bc it was very fast and professional 
        -- would takes months to create
        -- Funny part was that it was the first submission made
*/

#include <iostream> 
#include <fstream>

using namespace std;

int main () {
    ofstream jayden; 

    jayden.open("Nov19lec"); 

    jayden << " " << endl;

    jayden.close(); 


    return 0; 
}