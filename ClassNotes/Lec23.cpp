//Notes from lecture 23 
/*
    final lecture -- exam review 
    50 questions all MC
    cheat sheet double sided, two pages (4 sides)

    testing commands for testing code should be known 
    coverge testing use 
    fuzz testing - use -- programing with random inputs 
    static analysis 
    command line things talked about in class 
    object files?


    using command line input on linu called: zzuf -- what is Amibroker Formula Language(AFL) zzuf
    fuzz is a method used to input large amounts of data into a program
        with the hope of making it crash 
        if crash is caused software tool called fuzzer can be use to identify causes
        This large amount of data is called fuzz  

    Coverage testing is used to determine if the test case sufficiently covers the code
        a gcov result will show if each line executed. 
        100% coverage does not mean there are no errors since the code could be within range
        of allowable values that don't cause an error while still executing the line

    Static analysis
        examining the code without executing it  
        allows us to understand code structure and ensure it adheres to industry standards
        can use automated tools to do this 
        can also look at printouts, this is referred to program understanding/ program comprehension






big-end-d-end vs little-end-d-end

these are two types of data storage methods for pointers where the MSB are stored last 
    this is determined by the processor

Purpose of showing this is that data is all bytes and that you can represent all data with bytes 



*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std; 


int main() {
    int num = 1; 
    int* num_ptr;
    printf("%d\n", num);
    printf("%p\n", num_ptr);


    char one_letter = 'a';
    char* data_pointer = &one_letter;
    printf("%c\n", one_letter); 
    printf("%p\n", data_pointer);
    printf("%p\n", &data_pointer);
    //cout << data_pointer << endl;
    // cout << one_letter << endl;


    int one_num = 7; 
    int destination = -1; 
    char* source_ptr = (char*) &one_num; 
    char* destination_ptr = (char*) &destination; 

    printf("%p\n", source_ptr); 


    //Copies integer bit by bit 
    // int bytes_in_int = sizeof(one_num);

    // for (int i = 0; i < bytes_in_int; i++) {
    //     destination_ptr[i] = source_ptr[i];
    // }
    // cout << destination << endl;

 
    return 0; 
}

