/*

Minimum Spanning Tree adapted from:
https://www.softwaretestinghelp.com/minimum-spanning-tree-tutorial/

Adjacency Matrix adapted from:
https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix

Dijkstra's Algorithm adapted from:
https://www.includehelp.com/cpp-tutorial/dijkstras-algorithm.aspx

Sean Collins & Gareth Miller

*/

#include <iostream>
#include <cstring>

/*Used for INT_MAX*/
#include<climits>

using namespace std;

/* graph contains 5 vertices*/
#define vertex 8

/* the adjacency matrix initially 0 */
int vertArr[100][100];

/* an array G that stores adjacency matrix for input graph */
int graph[vertex][vertex] = {
    {0, 4, 1, 0, 0, 0, 0, 0},
    {4, 0, 2, 4, 0, 0, 0, 0},
    {1, 2, 0, 0, 0, 9, 0, 0},
    {0, 4, 0, 0, 6, 7, 0, 0},
    {0, 0, 0, 6, 0, 0, 8, 0},
    {0, 0, 9, 7, 0, 0, 3, 0},
    {0, 0, 0, 0, 8, 3, 0, 6},
    {0, 0, 0, 0, 0, 0, 6, 0},
};

void prims_algorithm(int graph[vertex][vertex]){
    /*number of edge*/
    int num_edge;
    /*mst_vertex - array to track vertices selected for spanning tree*/
    int mst_vertex[vertex];
    /*set selected false initially*/
    memset(mst_vertex, false, sizeof (mst_vertex));
    /*set number of edge to 0*/
    num_edge = 0;
    /*let 0th vertex be the first to be selected*/
    mst_vertex[0] = true;
    /*row*/
    int x;
    /*col*/
    int y;
    while (num_edge < vertex - 1){
        /*Prim's algorithm code*/
        int min = INT_MAX; x = 0; y = 0;
        for (int i = 0; i < vertex; i++){
            if (mst_vertex[i]){
                for (int j = 0; j < vertex; j++){
                    if (!mst_vertex[j] && graph[i][j]){ /*not in mst_vertex and there is an edge*/
                        if (min > graph[i][j]){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        };
                    };
                };
            };
        };
        cout<<x<<" - "<<y<<" :  "<<graph[x][y];
        cout<<endl;
        mst_vertex[y]=true;
        num_edge++;
    };
};

/*A method to find the vertex with minimum distance which is not yet included in Dset*/
int minimumDist(int dist[], bool Dset[]){
    /*initialize min with the maximum possible value as infinity does not exist */
	int min=INT_MAX,index;
	for(int v=0;v<vertex;v++){
		if(Dset[v]==false && dist[v]<=min){
			min=dist[v];
			index=v;
		};
	};
	return index;
};

/*Method to implement shortest path algorithm*/
void dijkstra(int graph[vertex][vertex],int src){
	int dist[vertex];
	bool Dset[vertex];
    /*Initialize distance of all the vertex to INFINITY and Dset as false*/  
	for(int i=0;i<vertex;i++){
		dist[i]=INT_MAX;
		Dset[i]=false;
	};
    /*Initialize the distance of the source vertec to zero*/
	dist[src]=0;                                   
	for(int c=0;c<vertex;c++){
        /*u is any vertex that is not yet included in Dset and has minimum distance*/
		int u=minimumDist(dist,Dset);
        /*If the vertex with minimum distance found include it to Dset*/ 
		Dset[u]=true;
        /*Update dist[v] if not in Dset and their is a path from src to v through u,
        that has distance minimum than current value of dist[v]*/
		for(int v=0;v<vertex;v++){
			if(!Dset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
		};
	};
	cout<<"Vertex\t\tDistance from source"<<endl;
    /*will print the vertex with their distance from the source to the console */
	for(int i=0;i<vertex;i++){
		char c=65+i;
		cout<<c<<"\t\t"<<dist[i]<<endl;
	};
};

int main(){
    int start_node = 0;
    /* print details of MST*/
    cout<<"The Minimum Spanning Tree as per Prim's Algorithm:"<<endl;
    cout<<"Edge"<<" : "<<"Weight";
    cout<<endl;
    prims_algorithm(graph);
	cout<<"The Shortest Path to access each other node according to Dijkstra's Algorithm starting at node "<< start_node << "."<<endl;
	dijkstra(graph, start_node);
    return 0;
};
