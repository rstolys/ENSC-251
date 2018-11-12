//AA Tree
//
//By: Ryan Stolys 
//Last Edit: Oct 21, 2018

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

class node {        //This defined the structure of each node 
    public: 

    int level;
    int key;
    node* left; 
    node* right; 

    node(int value) {
        this->key = value;
        this->level = 1;            //Every node created starts as a leaf at level 1
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* insertion(node* root, int key, int* count);   //This is the main function which places elements into the AA TREE
node* deletion(node* root, int key, int* count);    //This will remove an element with the value indicicated in data
node* skew(node* root, int* count);                 // Left children have to have a level value less than their parent
node* split(node* root, int* count);                // Right grandchildren, must have a level less than their grandparent. 
void release(node* root);                           //Release all allocated memory
void print_tree(node* root);                        //Will print elements in sorted order
int find_depth(node* root);                         //Will determine the maximum depth of the tree
bool isBST(node* root);                             //Will confirm tree is a binary sorted tree




node* insertion(node* root, int key, int* count) {

    if (key >= root->key)        //For equal case, continue left
    {
        if (root->right != nullptr)     //There is a node to the left 
        {     
            //Move to right side continue process
            root->right = insertion(root->right, key, count);
        }
        else 
        {
            root->right = new node(key);
        }
    }
    else
    {
        if (root->left != nullptr)
        {
            //Move to left side
            root->left = insertion(root->left, key, count);
        }
        else 
        {
            root->left = new node(key);
        }
    }

    //Do AA tree checks
    root = skew(root, count);
    root = split(root, count);
    return root;
}

node* deletion(node* root, int key, int* count)
{
    bool remove = false;         

    //go in top and do comparison to find node you are looking for
    if (root == nullptr)        //This means key is not found in the tree
    {
        cout << "The key was not found in the tree" << endl;
        return root;    
    } 
    if (key == root->key)
    {
        remove = true;      //Found key, now have to remove it
    }
    else if (key > root->key)
    {
        //If the key is larger, move right down tree 
        root->right = deletion(root->right, key, count);
    }
    else if (key < root->key)
    {
        //if key is smaller, move left down tree
        root->left = deletion(root->left, key, count);
    }

    if (remove)         //These statements will only execute when at node being removed
    {
        //Find replacement node
        node* replacement; 
        node* parent = root;        //This is where we start to find the replacement node
        
        if (parent->left != nullptr)
        {
            replacement = parent->left;     //set replacement to left node, then keep going right
            while (replacement->right != nullptr)       //Keep going until at end of tree
            {
                parent = replacement;               //move parent down to next node
                replacement = replacement->right;   //move replacement down to next node
            }               //This will result in the replacment node being at the bottom of the tree
        }
        else if (parent->right != nullptr)              //Need to check other side in case left is end of tree already
        {                                          
             replacement = parent->right;     
            while (replacement->left != nullptr)       
            {
                parent = replacement;              
                replacement = replacement->left;   
            }  
        }
        else            //This will mean both children are null and this node is a leaf, can delete it and make it null
        {
           delete root;         
           return nullptr;          //This will end this function and it will rebalance in the other recursive steps
        }

        //To this point we have found a replacment node saved in replacement 
            //and we have the node to be deleted 
        //Now switch the values and remove the replacememt node 

        root->key = replacement->key;       //values switched 

        if (parent->left == replacement)
        {
            parent->left = nullptr;
        }
        else        //The other child must be replacement
        {
            parent->right = nullptr;
        }

        // release memory for replacement 
        delete replacement; 
    }

    //Now we need to balance the function on the way back through recusion to top of tree
    //Code adapted from A. Andersson paper on AA Trees, 1993
    if (root->left != nullptr && root->right != nullptr)        //Ensure input is valid for tests
    {
        if ((root->left->level < root->level - 1) || (root->right->level < root->level - 1))
        {
            root->level = root->level - 1;
            if (root->right->level > root->level)
            {
                root->right->level = root->level;
            }
            root = skew(root, count);
            root->right = skew(root->right, count);
            root->left = skew(root->left, count);
            root = split(root, count);
            root->right = split(root->right, count);
        }
    }
    return root;
}

node* skew(node* root, int* count){

    if (root->left == nullptr || root == nullptr){
        return root;        
    }

    if (root->level <= root->left->level){          //compare levels of 'root' and left child
        node* temp = root->left;                
        root->left = temp->right;
        temp->right = root;
        (*count)++;
        return temp;        //If swap is made then return new top node
    }
    return root;
} 

node* split(node* root, int* count){

    if (root == nullptr || root->right == nullptr || root->right->right == nullptr) {
        return root;      //Ensures all inputs are valid 
    }
   
    if (root->right->right->level >= root->level){
        node* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        temp->level = temp->level + 1;
        (*count)++;
        return temp;
    }
    return root;
}

void release(node* root){
    
    if(root != nullptr)
    {
        release(root->right);
        release(root->left);
        delete root;
    }
}

void print_tree(node* root){
    //First print left tree
    //Then print right
    
    if (root == nullptr){
        return;
    }

    print_tree(root->left);         //Go to left subtree
    cout << root->key << " ";      //Print data element 
    print_tree(root->right);        //Go to right subtree
}

int find_depth(node* root){
    int depthl;
    int depthr; 

    if (root == nullptr)
    {
        return 0;
    }
    else 
    {
        depthl = find_depth(root->left);
        depthr = find_depth(root->right);
    }

    if (depthl >= depthr)
    {
        return depthl + 1;
    }
    else 
    {
        return depthr + 1;
    }
}


//This is found online to check tree -- not my code
bool isBST(node* root) {  
  if (root == nullptr)  return true;  
      
  //false if left is > than node 
  if (root->left != nullptr && root->left->key > root->key)  
    return false;  
      
  //false if right is < than node 
  if (root->right != NULL && root->right->key < root->key)  
    return false;  
    
  //false if, recursively, the left or right is not a BST 
  if (!isBST(root->left) || !isBST(root->right))  
    return false;  
      
  //passing all that, it's a BST
  return true;  
}
