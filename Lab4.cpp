//AA Trees
//
//By: Ryan Stolys 
//Last Edit: Oct 20, 2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "heap.cpp"
#include "AA_Tree.cpp"

using namespace std; 


int main()
{
    int max_depth = 0;

    double AATree_sec;
    clock_t start_AA_Time;
    clock_t  end_AA_Time;
    clock_t clockTicks_AA;
    int AA_changes = 0; 
    
    double heap_sec;
    clock_t start_heap_Time;
    clock_t end_heap_Time;
    clock_t clockTicks_heap;
    int heap_changes = 0;




    //AA TREE
    //Start timing for AA_Tree fill
    start_AA_Time = clock();
    
    //Inintailze random number generator
    srand(time(0));

    //Create first root 
    node* top_root = new node(rand() % 10000); 
    int random;

   //Fill AA Tree
   for (int i = 0; i < 10000; i++){
        random = rand() % 10000;
        top_root = insertion(top_root, random, &AA_changes);
   }

    end_AA_Time = clock();
    clockTicks_AA = end_AA_Time - start_AA_Time;
    AATree_sec = clockTicks_AA / (double) CLOCKS_PER_SEC;       //Calculate time for AA_Tree
    //End timing of AA tree

    max_depth =  find_depth(top_root);              //Find max depth of tree


    //Select element to delete
    int find = 23;
    top_root = deletion(top_root, find, &AA_changes);  

    //HEAP
    start_heap_Time = clock();

    int items = 10000;
    //Find layers of tree 
    int layers = ceil(log(items - 1)/log(2));
    int array_size = pow(2,layers);

    //This will allocate array of the full size of a binary tree
    int* heap = new int[array_size];

    //Fill array with 10000 random numbers
    random_fill(heap, items);

    //Call sorting algorithm to arrange heap into largest to smallest
    heap_sort(heap, items, &heap_changes);

    end_heap_Time = clock();
    clockTicks_heap = end_heap_Time - start_heap_Time;
    heap_sec = clockTicks_heap / (double) CLOCKS_PER_SEC;
    
    
    //Report statistics 
    cout << "The total time to fill the AA Tree was: " << endl;
    cout << AATree_sec << " seconds "<< endl;
    cout << "The total time to fill the heap was: " << endl;
    cout<< heap_sec << " seconds " << endl << endl;

    cout << "The total number of tree rotations/ operations was: " << endl;
    cout << AA_changes << endl;
    cout << "The total number of swaps made in the heap sort was: " << endl;
    cout << heap_changes << endl;

    cout << endl << "The depth of the AA Tree is: " << endl;
    cout << max_depth << endl;


    //Release AA Tree
    release(top_root);

    //Deallocate heap 
    delete[] heap; 

    return 0; 
}




