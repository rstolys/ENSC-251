//Implementation of ID3 algorthm for classifying objects 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std; 

//Class prototypes
class data_item; 
class tree_node;

//Function protptypes 
void read_data(vector<data_item>* data_set, string filename); 
double entropy(double pYes, double pNo);
double gain(double etpyDecision, double pUp, double etpyUp, double pDown, double etpyDown);
void probability(vector<data_item>* data_set, int index, int attribute, double* probs);
double* find_split(vector<data_item>* data_set);
vector<data_item>** make_split(vector<data_item>* data_set, int index, int att);
void make_tree(tree_node* root);
int node_num();


//Create data structure to store data from file 
class data_item {
public: 
    data_item () {}

    void add_attribute(double value) {
        attribute.push_back(value); 
    }

    void add_class(string name) {
        classification = name;
    }

    double get_att(int index) {
        return attribute[index];
    }

    string get_class() {
        return classification;
    }

    int num_atts() {
        return attribute.size();
    }

    //Used for testing -- is not called
    void print() {
        for (int i = 0; i < attribute.size(); i++) {
            cout << attribute[i] << " "; 
        }
        cout << classification << endl;
    }

    ~data_item() {}

private: 
    vector<double> attribute; 
    string classification;
};

class tree_node {
public: 
    tree_node(vector<data_item>* data_set, int level) {
        this->data_set = data_set; 
        elements = data_set->size(); 
        misclassified = bad_class();
        error = (double)misclassified/elements;
        get_split();
        Left = nullptr; 
        Right = nullptr; 
        this->level = level;
        this->node = node_num(); 
    }

    void set_branches () {
        vector<data_item>** new_sets;
        new_sets = make_split(data_set, line_of_split, att_of_split);

        Right = new tree_node(new_sets[0], level + 1);
        Left = new tree_node(new_sets[1], level + 1);
    }

    void get_split() {
        double* split_index = new double[3]; 
        split_index = find_split(data_set); 
        line_of_split = split_index[0]; 
        att_of_split = split_index[1];
        split = data_set->at(line_of_split).get_att(att_of_split); 
    }

    int bad_class() {           //Count number of elements are not in correct class
        //This will be decided by which ever element has more of that classifier 
        int count_yes = 0, count_no = 0;
        string yes = data_set->at(0).get_class();         //Set first class in data set to be yes
        for (int i = 0; i < data_set->size(); i++) {
            if (data_set->at(i).get_class() == yes) {
                count_yes++;
            }
            else {
                count_no++;
            }
        }

        if (count_yes >= count_no) {
            return count_no;    //# misclassified
        }
        else {
            return count_yes;   //# misclassified
        }
    }

    tree_node* L_branch() {
        return Left; 
    }

    tree_node* R_branch() {
        return Right; 
    }

    vector<data_item>* get_set() {
        return data_set; 
    }

    int get_node() {
        return node;
    }

    double get_error() {
         return error;
    }

    void print_me() {
        cout << "node:" << node << " "; 
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }

        if (Left != nullptr && Right != nullptr) {
            cout << "V" << (att_of_split + 1) << " >= " << split;
        }
        cout << "      elements: " << elements;
        cout << "      error: " << (error*100) << "%";
        if(Left == nullptr && Right == nullptr) {
            cout << "      classification: " << data_set->at(0).get_class();
        }
    
        if (Left != nullptr && Right != nullptr) {
            cout << "      True->Node: " << Right->get_node() << "  False->Node: " << Left->get_node(); 
        }
        cout << endl; 


        if (Left != nullptr) { 
            Left->print_me();        //Print left set
        }
        
         if (Right != nullptr) {
            Right->print_me();        //Print right set
        }
    }
    

    ~tree_node() {
        if (Left != nullptr) {
            delete Left; 
        }
        if (Right != nullptr) {
            delete Right; 
        }
    }


private:
    vector<data_item>* data_set;
    tree_node* Left;        //Data set to left
    tree_node* Right;       //Data set to right
    double split; 
    int line_of_split; 
    int att_of_split;
    int misclassified; 
    int elements; 
    double error; 
    int level;
    int node; 
};

//Function to read data from file
void read_data(vector<data_item>* data_set, string filename) {
    ifstream inFile;


    inFile.open(filename); 
    if (!(inFile.good())) {
        cerr << "ERROR: File could not be opened" << endl;
    }
    //File was properly opened

    int line_count = 0; 
    //for each line in file
    while (!(inFile.eof())) {
        string line; 
        string interest; 
        string comma = ",";
        int location_l = 0;             //location of last comma found
        int location_n  = 0;            //location of next comma found
        bool flag_class = false; 
        bool make_item = true;

        getline(inFile, line);          //Get line of file 

        line = line + comma;

        while (location_l < line.size()) {
            location_n = location_l + 1;
            for (int i = location_l; i < line.find_first_of(",", location_l) && i < (line.size() - 1); i++) {
                location_n++;
                interest.push_back(line[i]);
                if (i == line.size() - 2) {
                    flag_class = true;      //This means next characters are classification 
                }
            }
            if (flag_class) {
                data_set->at(line_count).add_class(interest);
            }
            else {
                if (!(interest.size() == 0)){
                    //Turn interest string into floating point number 
                    double value = stod(interest);
                    if (make_item) {
                        data_set->push_back(data_item()); 
                        make_item = false;
                    }
                    data_set->at(line_count).add_attribute(value); 
                }
                else {
                    break;
                }
            }
        
            location_l = location_n; 
            interest.clear(); 
        }
        line_count++;
    }

    return; 
}


//Find Entropy
double entropy(double pYes, double pNo) {
    double entropy_calc = 0.0; 
    
    if (pYes == 0 || pNo == 0) {
        if (pYes != 0) {                //Deals with 0*log(0) for pYes
            entropy_calc = (-1)*pYes*(log2(pYes));
        }
        else if (pNo != 0) {            //Deals with 0*log(0) for pNo
            entropy_calc = (-1)*pNo*(log2(pNo));
        }
        else {
            entropy_calc = 0; 
        }
    }
    else {
        entropy_calc = (-1)*pNo*(log2(pNo)) - pYes*(log2(pYes));
    }

    return entropy_calc; 
}


//Find Gain
double gain(double etpyDecision, double pUp, double etpyUp, double pDown, double etpyDown) {
    //Up/ Down refers to probability above/ below the split value 
    
    return etpyDecision - pUp*etpyUp - pDown*etpyDown; 
}


//Function to find probability of a potential split
void probability(vector<data_item>* data_set, int index, int attribute, double* probs) {
    //Function will modify the pointer to a six element array of doubles 
        //element 0 is pYesA, element 1 is pNoA, element 2 is pA, element 3 is pYesB element 4 is pNoB, element 5 is pB 
    //index refers to data line 
    //attribute refers to data attribute in question

    int total = data_set->size(); 
    int num_A = 0;              //number of elements above split
    int num_yesA = 0;           //number of elements with yes classification above split
    int num_noA = 0;            //number of elements with no classification above split
    int num_B = 0;              //number of elements below split
    int num_yesB = 0;           //number of elements with yes classification below split
    int num_noB = 0;            //number of elements with no classification below split
    double split = data_set->at(index).get_att(attribute);    //Will return value of split
    string yes = data_set->at(index).get_class();             //Will return classification of split node
        //Yes classification means it agrees with split node
        //this choice of yes or no being comparator has no impact on probabilities

    double element; 
    string classif; 
    for (int i = 0; i < total; i++) {
        element = data_set->at(i).get_att(attribute);
        classif = data_set->at(i).get_class(); 
        if (element >= split) {
            if (classif == yes) {
                num_yesA++;
            }
            else {
                num_noA++;
            }
        }
        else {
            if (classif == yes) {
                num_yesB++;
            }
            else {
                num_noB++;
            }
        }
    }

    //Set probabilities
    probs[0] = (double)num_yesA/total;  
    probs[1] = (double)num_noA/total; 
    probs[2] = (double)(num_yesA + num_noA)/total; 
    probs[3] = (double)num_yesB/total; 
    probs[4] = (double)num_noB/total; 
    probs[5] = (double)(num_yesB + num_noB)/total; 

    return;
}

//Function to find best split
double* find_split(vector<data_item>* data_set) {
    double* best = new double[3];        //best[0] = line index, best[1] = att index,  best[2] = gain
    best[0] = 0.0;  best[1] = 0.0;  best[2] = 0.0;
    double* probs = new double[6];        //Will save probabilitiy results for each split checked
    //element 0 is pYesA, element 1 is pNoA, element 2 is pA, element 3 is pYesB element 4 is pNoB, element 5 is pB 

    int num_lines = data_set->size();
    int num_att = data_set->at(0).num_atts();
    double entropy_set = 0.0;
    double pYes, pNo; 
    
    //find pYes and pNo of data set
    string yes = data_set->at(0).get_class();
    int yes_set = 0;
    int no_set = 0;
    for (int i = 0; i < num_lines; i++) {
        if (data_set->at(i).get_class() == yes) {
            yes_set++;
        }
        else {
            no_set++;
        }
    }
    
    pYes = (double)yes_set/num_lines;
    pNo = (double)no_set/num_lines;
    entropy_set = entropy(pYes, pNo);

   
    double etpyUp, etpyDown, gain_element;
    double second_best = -1.0; 
    int secBest_line = 0, secBest_att = 0; 
    bool set_flag = false;
    //find gain for each element 
    for (int i = 0; i < num_lines; i++) {
        for (int a = 0; a < num_att; a++) {
            probability(data_set, i, a, probs); 
            etpyUp = entropy(probs[0], probs[1]);       //entropy of elements above split
            etpyDown = entropy(probs[3], probs[4]);     //entropy of element below split
            gain_element = gain(entropy_set, probs[2], etpyUp, probs[5], etpyDown);
            if (gain_element > best[2]) {
                best[0] = i;                //Set line index of best split
                best[1] = a;                //Set att index of best split
                best[2] = gain_element;     //Set gain of best split
                set_flag = true;
            }
            if (gain_element < 0 && gain_element > second_best) {
                secBest_line = i;
                secBest_att = a; 
                second_best = gain_element; 
            }
        }
    }

    //This is done since we do not want to acheieve a gain of 0
    //if we can't gain anything, we want to lose the least amount of information
    if (!set_flag) {        
        best[0] = secBest_line;                 //Set line index of next best split
        best[1] = secBest_att;                  //Set att index of next best split
        best[2] = second_best;                  //Set gain of next best split
    }

    return best;
}


vector<data_item>** make_split(vector<data_item>* data_set, int index, int att) {
    //split data for elements either above or below 
    vector<data_item>** new_sets = new vector<data_item>*[2];
    new_sets[0] = new vector<data_item>;        //Right set 
    new_sets[1] = new vector<data_item>;        //Left set

    int counterUp = 0, counterDn = 0; 
    int size = data_set->size();
    double split = data_set->at(index).get_att(att);
        
    double element; 

    //only elements above and below split will be filled. 
    //Will handle split elements after -- default location will be left split
    for (int i = 0; i < size; i++) {        //For left split
        element = data_set->at(i).get_att(att);
        if (element > split) {
            new_sets[0]->push_back(data_item());
            for (int a = 0; a < data_set->at(i).num_atts(); a++) {
                new_sets[0]->at(counterUp).add_attribute(data_set->at(i).get_att(a)); //Fill attributes
            }
            new_sets[0]->at(counterUp).add_class(data_set->at(i).get_class());        //Fill classification
            counterUp++;
        }
    }

    for (int i = 0; i < size; i++) {        //For left split
        element = data_set->at(i).get_att(att);
        if (element < split) {
            new_sets[1]->push_back(data_item());
            for (int a = 0; a < data_set->at(i).num_atts(); a++) {
                new_sets[1]->at(counterDn).add_attribute(data_set->at(i).get_att(a)); //Fill attributes
            }
            new_sets[1]->at(counterDn).add_class(data_set->at(i).get_class());        //Fill classification
            counterDn++;
        }
    }
    
    //Ensure split will result in elements in both sets 
    if (new_sets[1]->size() == 0) {     //Send split elements to this branch 
        for (int i = 0; i < size; i++) {
            element = data_set->at(i).get_att(att);
            if (element == split) {
                new_sets[1]->push_back(data_item());
                for (int a = 0; a < data_set->at(i).num_atts(); a++) {
                    new_sets[1]->at(counterDn).add_attribute(data_set->at(i).get_att(a)); //Fill attributes
                }
                new_sets[1]->at(counterDn).add_class(data_set->at(i).get_class());        //Fill classification
                counterDn++;
            }
        }
    }
    else {          //If bottom set is not empty then send splits to top
        for (int i = 0; i < size; i++) {
            element = data_set->at(i).get_att(att);
            if (element == split) {
                new_sets[0]->push_back(data_item());
                for (int a = 0; a < data_set->at(i).num_atts(); a++) {
                    new_sets[0]->at(counterUp).add_attribute(data_set->at(i).get_att(a)); //Fill attributes
                }
                new_sets[0]->at(counterUp).add_class(data_set->at(i).get_class());        //Fill classification
                counterUp++;
            }
        }
    }
    //**** 
    //NOTE: This last step takes care of case where split is chosen to be smallest valued element in set 
    //****
    return new_sets; 
}

int node_num() {
    static int node = -1;       //Will return node 0 on first iteration
    node++; 
    return node;
}

//Function to make complete decsion tree
void make_tree(tree_node* root) {
    if (root->get_error() == 0.0 ) {
        return;
    }
    root->set_branches();
    
    make_tree(root->L_branch());
    make_tree(root->R_branch()); 
}


int main(int argc, char** argv) {
    vector<data_item>* data_set = new vector<data_item>;        //create vector of data items that holds entire data set

    read_data(data_set, argv[1]);

    tree_node* root = new tree_node(data_set, 0);
    make_tree(root); 

    cout << "\n\n";
    root->print_me();
    cout << "\n\n";
    

    delete data_set;
    delete root;  
    

    return 0; 
}