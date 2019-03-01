//Notes from lecture 18
/*
Algorithm to find minimal spanning tree, must be of lowest cost (cost can be any metric)


Algorithm 1: prim    (grow single group by adding branches)
Start at any vertex, add cheapest branch to next vertex 
    go to next vertex and add cheapest edge that stems from edge 
Repeat until all vertexs have 1 edge stemming from it 


Algorithm 2: kruskal (grow by adding cheaping branches until all vertex's are connected)
Look at cheapest edges and find what components are brought together
    identify which verticies are brought together 
    only cares about cheapest edges, when you add edges make verticies of same team, meaning they are connected
    Before connecting edges, need to check if edge connects the two members of a team together 
    Do this for all edges, 
Whenever you connect two vertex's, you have to make sure all linking vertex's become same team 


Trying to get from point A to point B on cheapest path
Algorithm 1: dijkstra
    Start at A and expand until you reach B 
        record the cost to reach a vertex from A, if you reach a vertex again, save lowest cost
    Expand until all vertex's have been reached and eventually the cost for B will be determined and you can save this





ID3: This is the final project, to implement this algorithm 
In the data sets the final variable is dependent on those previously listed in the line

Project workload suggestion:
    week 1: be able to read in the data (wont know number of variables or lines) -- read into data structures then deal with it
    week 2: Find all the splits
    week 3: Produce the output

Look at ID3 tutorial : sefiks.com/2017/11/20/a-step-by-step-id3-decision-tree-example/
    We will not have any 3-way splits

Entropy -- is once score assigned 
    Entropy = -p(YES)*log2p(YES) - p(NO)*log2p(NO); 
        When entropy is 1 they split is 50-50
        When entropy is 0 split is  perfect -- want this
Gain -- What is advatage of split to different decision
    Gain = Entropy - 
    ** see website
    The highest gain factor is the the decision you want to make 

Attribute can be slected multiple times 


Cutoff points - Choose a point, send everything to one side or the other depending on location relative to split
    Calculate the quality of the split for each split done 
    Pick the best split choice (based on the score assigned using formula)
    This needs to be done for every attribute
        Find the best split to make 

Tree depth - Keep splitting until there is no more error 

To present results 
    first decision is at top and left justified, each decision is indented once to indicate it is a soltuon 
    Order of yes and no is decision, below : yes on top, no below

    Example of output
V1 > 7 
    V3 < 4.5 
        result 1
        result 2
    V2 < 3
        result 3 
        result 2
*/ 

//#include "Lec17.cpp" 
#include <iostream>
#include <fstream>
using namespace std;
//Has all graph code from class prior

int main() {
    ofstream jayden; 

    jayden.open("WedLec"); 

    jayden << " " << endl;

    jayden.close();
    return 0;
}