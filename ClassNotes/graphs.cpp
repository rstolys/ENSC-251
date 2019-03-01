#include <iostream>
#include <vector>

using namespace std;

struct vertex;

struct edge {
  double cost;
  vertex* first;
  vertex* second;

  edge(double cost, vertex* first, vertex* second) {
    this->cost = cost;
    this->first = first;
    this->second = second;
  }
};

struct vertex {
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

  void print_just_this_one() {
    cout << this->location << " is connected to ";
    int current = 0;
    while (current != connections->size()) {

      edge* current_edge = connections->at(current);

      if (current_edge->first != this) {
	cout << current_edge->first->location << " ";
      } else {
	cout << current_edge->second->location << " ";
      }
      
      current = current + 1;
      
    }
    
    cout << endl;
  }
  
  
  void print_graph() {
    if (this->visited) {
      return;
    } else {
      this->visited = true;
      this->print_just_this_one();

      int current = 0;
      while (current != connections->size()) {

	edge* current_edge = connections->at(current);
	
	if (current_edge->first != this) {
	  current_edge->first->print_graph();
	} else {
	  current_edge->second->print_graph();
	}
	
	current = current + 1;

      }
      
    }
  }
  
  
};


int main() {
  vertex* aq_NE = new vertex("AQ_NE");
  vertex* aq_NW = new vertex("AQ_NW");
  vertex* aq_SE = new vertex("AQ_SE");
  vertex* aq_SW = new vertex("AQ_SW");
  vertex* ASB = new vertex("ASB");
  vertex* res = new vertex("res");
  vertex* rotunda = new vertex("rotunda");
  vertex* library = new vertex("library");
  vertex* bensTon = new vertex("bensTon");
  vertex* convo = new vertex("convo");
  vertex* saywell = new vertex("saywell");

  aq_NE->connect_to(aq_NW, 3);
  aq_NW->connect_to(aq_SW, 3);
  aq_SW->connect_to(aq_SE, 3);
  aq_SE->connect_to(aq_NE, 3);
  
  res->connect_to(rotunda, 5);
  library->connect_to(convo, 1);
  bensTon->connect_to(convo, 1);
  
  saywell->connect_to(aq_NE, 2);
  ASB->connect_to(aq_SE, 4);

  aq_NW->connect_to(convo, 7); //Roadwork!
  aq_SW->connect_to(convo, 3);

  aq_SE->print_graph();
  
  return 0;
}
