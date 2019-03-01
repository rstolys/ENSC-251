#include <iostream> 

using namespace std; 

//Linked list library Solutions

struct list 
{
    int payload;
    list* tail;
};


//These are the same but with different name
int get_data(list* input)
{
    return input -> payload;
}
int car(list* input)
{
    return get_data(input);
}


//These are the same but with different name
list* get_tail (list* input)
{
    return input->tail;
}
list* cdr(list* input)
{
    return get_tail(input);
}



list* cons(int payload, list* tail)
{
    list* output = new list;
    output->payload = payload;
    output->tail = tail;
    return output;
}

//


int length(list* input)
{
    if (input == NULL)
    {
        return 0;
    }
    else 
    {
        return 1 + length(cdr(input));      //Recursive Method
    }
}
// Will run of of stack space for large lists


void set_nth(list* input, int index, int payload)
{
    if (index == 0)
    {
        input->payload = payload;
    }
    else 
    {
        set_nth(cdr(input), index -1, payload);     //Done by recursion
    }
    return;
}



int main()
{
     //To test linkned list Libaray 

     list* first = cons(6, NULL);
     cout << first << endl;
     cout << car(first) << endl;
     cout << cdr(first) << endl;    

    return 0;
}




