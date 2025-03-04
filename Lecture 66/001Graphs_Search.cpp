/*
Implementation of graph search using

  1. depth first search   (dfs)
  2. breadth first search (bfs)

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {

	map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

public :

	graph(bool isDirected = false) {
		this->isDirected = isDirected;
	}

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);

		if (!isDirected) {
			neighbourMap[v].push_back(u);
		}

	}

	void dfsHelper(T s, unordered_set<T>& visited) {

		// mark 's' as visited

		visited.insert(s);

		cout << s << " ";

		// visited unvisited vertices reachable from 's'

		list<T> neighbours = neighbourMap[s];

		for (T neighbour : neighbours) {
			if (visited.find(neighbour) == visited.end()) {
				dfsHelper(neighbour, visited);
			}
		}

	}

	void dfs(T s) {
		unordered_set<T> visited; // to keep track of visited vertices
		cout << "dfs(" << s << ") : ";
		dfsHelper(s, visited);
		cout << endl;
	}

	void bfs(T s) {

		cout << "bfs(" << s << ") : ";

		unordered_set<T> visited; // to keep track of visited vertices
		queue<T> q; // to keep track of visited & un-explored vertices

		// mark 's' as visited
		visited.insert(s);
		q.push(s);

		while (!q.empty()) {
			T front = q.front();
			q.pop();

			// explore 'front'

			cout << front << " ";

			list<T> neighbours = neighbourMap[front];
			for (T neighbour : neighbours) {
				if (visited.find(neighbour) == visited.end()) {
					visited.insert(neighbour);
					q.push(neighbour);
				}
			}

		}

		cout << endl;

	}
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');

	// g.addEdge('A', 'J');
	// g.addEdge('A', 'K');

	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('C', 'E');
	g.addEdge('C', 'F');
	g.addEdge('D', 'G');
	g.addEdge('E', 'G');
	g.addEdge('E', 'H');
	g.addEdge('F', 'H');
	g.addEdge('G', 'I');
	g.addEdge('H', 'I');

	// g.addEdge('J', 'L');
	// g.addEdge('K', 'M');

	g.dfs('A');

	g.bfs('A');

	return 0;
}