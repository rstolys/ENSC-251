//Heap functions 
//
//Made by: Ryan Stolys
//Last Revision: Oct. 21, 2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void random_fill (int* array, int items);                           //This function will fill an array with "items" number of elements
void print_heap(int* heap, int size);                               //This function will print the heap
void heap_sort(int* heap, int items, int* count);                                //This is the main heap sort function 
void max_heap(int* heap, int items, int index, int* count);         //This function is used in heap_sort
void my_swap(int* heap, int index1, int index2, int* count);                    //This perfoms the swaps of the elements in the heap


void random_fill (int* array, int items){
    srand(time(0));

    for (int i =0; i < items; i++)
    {
        array[i] = rand() % 10000;
    }
    return;             //function only has pointer to array and thus 
                        //the array will still be accessible with changes in main fucntion
}

void print_heap(int* heap, int size){
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    return;
}

void heap_sort(int* heap, int items, int* count){
    //Create max heap from array 

    //Only need to do for n/2 elements since all leaves are max heaps
    for (int i = items/ 2 ; i >= 0 ; i--)
    {
        max_heap(heap, items, i, count);
    }
    //This will result in the largets elements being moved to top end of array and smallest at the bottom end 

    //This will reuslt in the array being in heao order

    return;
}

void max_heap(int* heap, int items, int index, int* count){
    //Look at parent, if either children are larger, place children in parent postion
    //call max_heap to run on swapped location if swap is made

    int parent = index; 
    int right = 2*index + 1;
    int left = 2*index + 2;

    if (right < items && heap[right] > heap[parent])
    {
        parent = right; 
    }

    if (left < items && heap[left] > heap[parent])
    {
        parent = left; 
    }

    if (parent != index)
    {
        my_swap(heap, index, parent, count);

        //Call max_heap for parent and children below
        max_heap(heap, items, parent, count);
    }

}

void my_swap(int* heap, int index1, int index2, int* count){
    int hold;

    hold = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = hold;
    (*count)++;
    return;
}