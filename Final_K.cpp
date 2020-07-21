/*

Minimum Spanning Tree adapted from:
https://www.softwaretestinghelp.com/minimum-spanning-tree-tutorial/

Adjacency Matrix adapted from:
https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix

Sean Collins & Gareth Miller

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

#define graph_edge pair<int,int>

/* the adjacency matrix initially 0 */
int vertArr[100][100];

class Graph{
    private:
        /* number of nodes in graph */ 
        int Graph_Verticies;
        /* vector for graph */
        /* These vectors are defined such that the first integer is the wieght of the edge,
        while the pair of integers are the nodes connecting the edge. */
        vector<pair<int, graph_edge>> Graph_Vector;
        /* vector for mst */
        vector<pair<int, graph_edge>> Tree_Vector;
        int *parent;
    public:
        Graph(int Graph_Verticies);
        void AddEdge(int u, int v, int wt);
        int find_set(int iterator);
        void union_set(int u, int v);
        void kruskal_algorithm();
        void display_mst();
};

Graph::Graph(int Graph_Verticies){
    parent = new int[Graph_Verticies];
    for (int iterator = 0; iterator < Graph_Verticies; iterator++)
    parent[iterator] = iterator;
    Graph_Vector.clear();
    Tree_Vector.clear();
};

void displayMatrix(int v){
    int iterator, jitterator;
    for(iterator = 0; iterator < v; iterator++){
        for(jitterator = 0; jitterator < v; jitterator++){
            cout<<vertArr[iterator][jitterator]<<" ";
        };
        cout<<endl;
    };
};

void Graph::AddEdge(int u, int v, int wt){
    Graph_Vector.push_back(make_pair(wt, graph_edge(u, v)));
    vertArr[u][v] = wt;
    vertArr[v][u] = wt;
};

int Graph::find_set(int iterator){
    /* If i is the parent of itself */
    if (iterator == parent[iterator])
        return iterator;
    /* else recursively find the parent of i */
    else
        return find_set(parent[iterator]);
};

void Graph::union_set(int u, int v){
    parent[u] = parent[v];
};

void Graph::kruskal_algorithm(){
    int iterator, u_value_start, v_value_end;
    /* sort the edges ordered on increasing weight */
    sort(Graph_Vector.begin(), Graph_Vector.end()); 
    for (iterator = 0; iterator < Graph_Vector.size(); iterator++){
        u_value_start = find_set(Graph_Vector[iterator].second.first);
        v_value_end = find_set(Graph_Vector[iterator].second.second);
        if (u_value_start != v_value_end){
            /* add to mst vector */
            Tree_Vector.push_back(Graph_Vector[iterator]);
            union_set(u_value_start, v_value_end);
        };
    };
};

void Graph::display_mst(){
    cout<<"Edge :"<<" Weight"<<endl;
    for (int iterator = 0; iterator < Tree_Vector.size(); iterator++){
        cout<<Tree_Vector[iterator].second.first<<" - "
            <<Tree_Vector[iterator].second.second<<" : "
            <<Tree_Vector[iterator].first;
        cout<<endl;
    };
};

int main(){
    Graph gmst(8);
    gmst.AddEdge(0,1,4);
    gmst.AddEdge(0,2,1);
    gmst.AddEdge(1,2,2);
    gmst.AddEdge(1,3,4);
    gmst.AddEdge(2,5,9);
    gmst.AddEdge(3,4,6);
    gmst.AddEdge(3,5,7);
    gmst.AddEdge(4,6,8);
    gmst.AddEdge(5,6,3);
    gmst.AddEdge(6,7,6);

    cout<<"The Adjacency Matrix is:"<<endl;
    displayMatrix(8);

    gmst.kruskal_algorithm();
    cout<<"The Minimum Spanning Tree according to Kruskal's Algorithm:"<<endl;
    gmst.display_mst();

    return 0;
};


/*
User Input, haven't gotten to work yet but will if need be.

    bool response = false;
    bool user_input = false;

    cout<<"Would you like to add an Edge or Node to the Graph? Enter true to add an Edge or Node or false to end the program."<<endl;
    cin>>response;

    if (response = true){
        cout<<"Node or Edge? Enter true for Edge, false for Node."<<endl;
        cin>>user_input;
    };

    if (user_input = true){
        int user_u, user_v, user_wt;
        cout<<"Enter the Nodes that the Edge attaches to followed by a weight one at a time pressing enter after each number. "<<endl;
        cin>>user_u;
        cin>>user_v;
        cin>>user_wt;
        Graph gmst(9);
        gmst.AddEdge(user_u, user_v, user_wt);
        gmst.AddEdge(0,1,4);
        gmst.AddEdge(0,2,1);
        gmst.AddEdge(1,2,2);
        gmst.AddEdge(1,3,4);
        gmst.AddEdge(2,5,9);
        gmst.AddEdge(3,4,6);
        gmst.AddEdge(3,5,7);
        gmst.AddEdge(4,6,8);
        gmst.AddEdge(5,6,3);
        gmst.AddEdge(6,7,6);
        gmst.AddEdge(user_u,user_v,user_wt);

        cout<<"The Adjacency Matrix is:"<<endl;
        displayMatrix(9);

        gmst.kruskal_algorithm();
        cout<<"The Minimum Spanning Tree according to Kruskal's Algorithm:"<<endl;
        gmst.display_mst();
    };

*/