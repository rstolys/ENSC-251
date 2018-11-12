//Heaps upon heaps 
//
//Made by: Ryan Stolys
//Last Revision: Oct. 16, 2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void random_fill (int* array, int items);
void print_heap(int* heap, int size);
void heap_sort(int* heap, int items);
void max_heap(int* heap, int items, int index);
void my_swap(int* heap, int index1, int index2);

int main()
{
   int items = 10000;

   //Find layers of tree 
    int layers = ceil(log(items - 1)/log(2));
    int array_size = pow(2,layers);

    //This will allocate array of the full size of a binary tree
    
    int* heap = new int[array_size];
   
    //Fill array with 10000 random numbers
    random_fill(heap, items);


    //Call sorting algorithm to arrange heap into largest to smallest
    heap_sort(heap, items);


    //Call print funciton on loop to print heap arms to check if it is sorted
    print_heap(heap, items);

    //Deallocate memory 
    delete[] heap; 
    

    return 0;
}


//This function will fill an array with "items" number of elements
void random_fill (int* array, int items)
{
    srand(time(0));

    for (int i =0; i < items; i++)
    {
        array[i] = rand() % 50000;
    }
    return;             //function only has pointer to array and thus 
                        //the array will still be accessible with changes in main fucntion
}


//This function will print the heap
void print_heap(int* heap, int size)
{
    for (int i = (size - 1), g = 0; i >= 0; i--)
    {
        cout << heap[i] << " ";

        g++;
        if (g > 20)
        {
            cout << endl;
            g = 0;
        }
    }
    return;
}


//This is the main heap sort function 
void heap_sort(int* heap, int items)
{
    //Create max heap from array 
    //Only need to do for n/2 elements since all leaves are max heaps
    for (int i = items/ 2 ; i >= 0 ; i--)
    {
        max_heap(heap, items, i);
    }
    //This will result in the largets elements being moved to top end of array and smallest at the bottom end 


    //Now need to order array such that the largest elements are places at end of array
    for (int i = items - 1 ; i >= 0; i--)
    {
        //move largest element to bottom of list 
        my_swap(heap, 0, i);

        //Call max_heap to move small element back down to bottom
        //This will leave the top most element in the 0th position to be placed into array
        max_heap(heap, i, 0);
    }

    return;
}


void max_heap(int* heap, int items, int index)
{
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
        my_swap(heap, index, parent);

        //Call max_heap for parent and children below
        max_heap(heap, items, parent);
    }

}


void my_swap(int* heap, int index1, int index2)
{
    int hold;

    hold = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = hold;

    return;
}