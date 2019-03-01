//Notes from lecture 17
/*
Talking about graphs
    discrete math, where there are verticies and they are connected by edges, think binary tree

Notes done on paper for drawing 
    done with vertexes and edges 

Now that we have the graph we want to print it 
    we have some graph, we want to visit every point
        remember which points we have visited -- bool visited

*/

#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class vertex;         //This declartion allows you to use the edge class before is is defined, acts a prototype

class edge {
public: 
    edge (double cost, vertex* first, vertex* second) {
        this->cost = cost;
        this->first = first; 
        this->second = second;
    }

    double cost;    //route travelled may have a cost of travelling, many applications, bus fare, time, starin (up/down hill)
    vertex* first;
    vertex* second; 

};

class vertex {
public:
    vector<edge*>* connections;

    bool visited;
    string location;

    vertex(string location) {
        connections = new vector<edge*>;
        this->location = location;
    }

    void connect_to(vertex* other, double cost) {
        edge* new_edge = new edge(cost, this, other);
        connections->push_back(new_edge);
        other->connections->push_back(new_edge);
    }

    void print_this() {
        cout << this->location << " is connected to ";
        int current = 0;
        while (current != connections->size()) {
            
            edge* current_edge = connections->at(current);        //How to access element in vector

            if (current_edge->first != this) {
                 cout << current_edge->first->location << " ";
            }
            else {
                 cout << current_edge->second->location << " ";
            }
        
            current = current + 1;
        }
        cout << endl;
    }
    
    void print_graph() {
        if (this->visited) {
            return;
        }
        else {
            this->visited = true;
            this->print_this();

            int current = 0;
            while (current != connections->size()) {
                
                edge* current_edge = connections->at(current);        //How to access element in vector

                if (current_edge->first != this) {
                    current_edge->first->print_graph();
                }
                else {
                    current_edge->second->print_graph();
                }
                current = current + 1;
            }
        }
    }

    ~vertex() {
        delete connections;
    }

};


int main() 
{
    //Creating vertexes for node
    vertex* aq_NE = new vertex("aq_NE");
    vertex* aq_NW = new vertex("aq_NW");
    vertex* aq_SE = new vertex("aq_SE");
    vertex* aq_SW = new vertex("aq_SW");
    vertex* asb = new vertex("ASB");
    vertex* res = new vertex("RES");
    vertex* rotunda = new vertex("Rotunda");
    vertex* library = new vertex("Library");
    vertex* benston = new vertex("Maggie Benston");
    vertex* convo = new vertex("Convo Mall");
    vertex* saywell = new vertex("Saywell Hall");

    //Notice connections are only in 1 direction, this is bc our connections work both directions
                        //We are calling the cost to be walking time in minutes
    aq_NE->connect_to(aq_NW, 3);           
    aq_NW->connect_to(aq_SW, 3);
    aq_SW->connect_to(aq_SE, 3);
    aq_SE->connect_to(aq_NE, 3);

    res->connect_to(rotunda, 5);
    rotunda->connect_to(convo, 3);
    library->connect_to(convo, 1);
    benston->connect_to(convo, 1);

    saywell->connect_to(aq_NE, 2);
    asb->connect_to(aq_SE, 4);

    aq_NW->connect_to(convo, 7);        //construction
    aq_SW->connect_to(convo, 3);

    aq_SE->print_graph();               //This will print the whole graph
    




}