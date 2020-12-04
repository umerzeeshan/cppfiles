#include "pch.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <set>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <queue>

using namespace std;
//*********************** typedefs *********************//

typedef vector< vector<bool> > twodbool;


//*********************** typedefs *********************//


//*********************** Structures *********************//
struct Edge
{
    int src;
    int dst;
    int weight;
    Edge(int s, int d, int w): src(s), dst(d), weight(w) {}
}; //struct Edge

//*********************** Structures *********************//

//*********************** Classes *********************//

class Graph
{
    int V;
    int E;
    list<Edge> *adj;
    list<Edge> *edge;
    int* dist;
    public:
    Graph(int v, int e)
    {
        this->V = v;
        this->E = e;
        adj = new list<Edge>[v];
        // edge = new list<Edge>[e];
       
    }
    void addEdge(int s, int d, int w)
    {
        Edge tmp = Edge(s,d,w);
        adj[s].push_back(tmp);
    }

    void BellmanFord(int s)
    {
        int dist[V];
        for (int k = 0; k<V; k++)
            dist[k] = INT32_MAX;
        dist[s] = 0;
        for(int i=0; i< V; i++)
        {
            for (auto j = adj[i].begin(); j!=adj[i].end(); j++)
            {
                int u = j->src;
                int v = j->dst;
                int weight = j->weight;
                if(dist[u]!=INT32_MAX && dist[u]+weight<dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (int i = 0; i<V; i++)
            cout<<dist[i]<<endl;

    }

    void testBellmanFord()
    {
        addEdge(0,1,5);
        addEdge(0,2,7);
        addEdge(1,2,-1);
        addEdge(1,3,1);
        addEdge(1,4,4);
        addEdge(2,3,-3);
        addEdge(2,4,1);
        addEdge(3,4,2);
        
        BellmanFord(0);
    }

}; //class Graph

class Matrix{
    int rows;
    int cols;
    twodbool arr;
    
    public:
    Matrix(int r, int c){
        rows = r;
        cols = c;
        arr.resize(r, vector<bool>(c) );
        for (auto i = 0; i<rows; i++)
        for (auto j = 0; j<cols; j++)
                arr[i][j] = 0;
        arr[0][0] = 1;
        arr[1][1] = 1;
    }
    void printarr()
    {
        for (auto i = 0; i<rows; i++)
        {
            for (auto j = 0; j<cols; j++)
                cout<<arr[i][j]<<" ";
            
            cout<<endl;
        }

        cout<<"size of array " <<arr.size();

    }

    void setRowsCols()
    {
        list<int> qrows, qcols;
        for(auto i = 0; i<rows; i++)
        for(auto j = 0; j<cols; j++)
        {
            if(arr[i][j] == 1)
            {
                qrows.push_back(i);
                qcols.push_back(j);
            }
        }

        for(auto i=qrows.begin(); i!=qrows.end(); i++)
        {
            for(auto j = 0;j<cols; j++)
            {
                arr[*i][j] = 1;
            }

            // arr[*i]assign(1, i + vector<bool>(cols));

        }
        for(auto j=qcols.begin(); j!=qcols.end(); j++)
        {
            for(auto i = 0;i<rows; i++)
            {
                arr[i][*j] = 1;
            }

        }        

        
    }


};  //class Matrix


//*********************** Classes *********************//

int main()
{
    // Graph test(5,8);
    // test.testBellmanFord();

    Matrix m(4,4);
    m.setRowsCols();
    m.printarr();
    return 0;
}