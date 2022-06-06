#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph{
	
	list<int>*l;
	int vertices;
	public:
	Graph(int v){
		vertices=v;
		l=new list<int>[v];
	}

	void addEdge(int i, int j, bool undir=true){
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
		
	}

	void BFS(int source){

		queue<int>q;
		q.push(source);
		vector<bool>visited(vertices,0);
		visited[source]=true;
		while(!q.empty()){

			int f=q.front();
			q.pop();
			cout<<f<<" ";
			for(auto nbrs: l[f])
			{
				if(!visited[nbrs])
				{
					q.push(nbrs);
					visited[nbrs]=true;
				}
			}
		}
	}
};

int main() {
	// your code goes here
	Graph G(7);
	G.addEdge(0,1);
	G.addEdge(1,2);
	G.addEdge(0,4);
	G.addEdge(3,2);
	G.addEdge(3,5);
	G.addEdge(3,4);
	G.addEdge(5,4);
	G.addEdge(5,6);
	G.BFS(1);
	return 0;
}
