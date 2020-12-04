#include "pch.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <list>

using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}
	bool hasPath(int a, int b)
	{
		list<int>::iterator i;
		for (i = adj[a].begin(); i != adj[a].end(); i++)
		{
			if (*i == b)
			{
				return true;
			}
		}
		return false;
	}
	void BFS(int s) {
		bool *visited = new bool[V];
		for (auto a = 0; a < V; a++) {
			visited[a] = false;  // mark all visited vertices to zero
		}
		list<int>::iterator i;
		list<int> queue;
		visited[s] = true;
		queue.push_back(s);
		while (!queue.empty())
		{
			s = queue.front();
			cout << s << " ";
			queue.pop_front();
			for (i = adj[s].begin(); i != adj[s].end(); ++i)
			{
				if (visited[*i] != true)
				{
					queue.push_back(*i);
					visited[*i] = true;
				}
			}
		}

	}
	void DFSUtil(int v, bool visited[])
	{
		visited[v] = true;
		cout << v << " ";
		list<int>::iterator i;

		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if(!visited[*i])
				DFSUtil(*i, visited);
		}
	}

	void DFS(int s)
	{
		bool *visited = new bool[V];
		// set all visited vertices to zero
		for (int a = 0; a < V; a++)
		{
			visited[a] = 0;
		}
		DFSUtil(s, visited);

	}

};

int main()
{
	Graph G(7);
	G.addEdge(1, 4);
	G.addEdge(1, 5);
    G.addEdge(1, 2);
    G.addEdge(1, 3);

	G.addEdge(2, 5);
	G.addEdge(3, 5);
	G.addEdge(4, 6);
	G.addEdge(4, 5);
	G.addEdge(5, 6);
	G.BFS(1);
    cout<<endl<<"new BFS search"<<endl;
    G.BFS(4);

	cout << "\nPath exists between 3 and 5 ="<<G.hasPath(3, 5)<<endl;
	cout << "\nPath exists between 0 and 4 =" << G.hasPath(0, 4) << endl;

	cout << "\n DFS traversal\n";
	G.DFS(1);
}