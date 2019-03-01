#include <iostream>
#include <bitset>
using namespace std;

class set
{
    public:

    int data;

    void insert(int item)
    {
        if (item > 31 || item < 0)
        {
            throw -1;   //Will crash program unless it is caught using catch
        }

        // going to set a bit equal to 1. 
        data = data | (1 << item);
    }

    void toggle(int item)
        {
            if (item > 31 || item < 0)
            {
                throw -1;   //Will crash program unless it is caught using catch
            }

            // will flip bit in location item
            data = data ^ (1 << item);
        }

    void remove(int item)
    {
        if (item > 31 || item < 0)
        {
            throw -1;   //Will crash program unless it is caught using catch
        }
        //set something equal to 0
        data = data & ~(1 << item);     //the ~ is a not, meaning it will flip the bit stream 
        //the ~ symbol will flip the bits while the ! only checks true vs false
    }

    bool check(int item)
    {
        if (item > 31 || item < 0)
        {
            throw -1;   //Will crash program unless it is caught using catch
        }

        if ((data & (1 << item)) != 0)    //This will check if there is a value in the data at location item 
        {                               //only if the data has a 1 in that location will the result != 0
            return true;
        }
        else 
        {
            return false;
        }
    }

    void print_set()
    {
        bitset<32> data_out(data);
        cout << data_out << endl; //using bitset library 
    }
};  //end of class set

int main()
{
    int first = 0;
    int second = 2;

    //1
    //Binary operations
    cout << (first & second) << endl;         //binary AND
    cout << (first | second) << endl;         //binary OR
    cout << (first ^ second) << endl;         //binary exclusive OR

    //2 
    cout << (second << 2) << endl;       //The << symbol inside the brakcets have different meaning to stream <<
                                        //<< in brackets means a bit-shift 

    //3
    //using set class
    set grouping; 
    grouping.data = 0;          //important to initalize memory
    grouping.insert(5);
    grouping.insert(1);
    grouping.insert(8);
    grouping.print_set();


    return 0;
}


/*
NOTES:
1. Binary opperations compare numbers in their binary form bit by bit

2. A bit-shift operator shifts the original number over '2' times to the left or right depending on direction of arrows
    starts at 00010 --> 01000 this goes from 2 --> 8
    Once bits move past the end of the binary number they are simply dropped 
    floats cannot be shifted, only ints can be shifted

3. 

4. When dealing with arrays as storing numbers usually you are storing more than just numbers 
    it is an entire structure that is accessed through some 'key' which can usually be represented
    as a number

5. binary seach tree, start with some number, 
    if it is larger go right if it is smaller go left, place in first open position. 
    This is helpful bc if the item is easy to find 
    removing item from biary tree
        if it is a leaf it can simply be removed 
        if it has a single child, remove item and then place child into old location 
            everything behind will follow
        if there are two children to the root, find the best option by going to the right once and keep going left
            this will give the next smallest item
            OR go to the left once and keep going right to find the next largest 
            both of these items will be leaves and can simply be placed in to removed loaction 
    To simplify searching it is better to have balanced tree
        with a perfectly balanaced tree search will be completity of log(n). 
            For a completely unbalanced tree you will have a linked like of search complexity n. 
    To balance the tree we need to place the items into the tree in a strategic way. 
    Create tree that will balance itself for whatever input you give it 
        This would be a self balacing binary search tree

*/