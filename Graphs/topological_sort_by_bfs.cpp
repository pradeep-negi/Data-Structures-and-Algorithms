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

	void addEdge(int i, int j){
		l[i].push_back(j);
		
	}

	void topological_sort(){

		vector<int>indegree(vertices, 0);
		for(int i=0;i<vertices;i++){
			for(auto node: l[i]){
				indegree[node]++;
			}
		}

		queue<int>q;
		for(int i=0;i<vertices;i++){
				if(indegree[i]==0)
					q.push(i);
		}

		while(!q.empty()){

			int f=q.front();
			cout<<f<<"->";
			q.pop();
			for(auto node: l[f]){
				indegree[node]--;
				if(indegree[node]==0)
					q.push(node);
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
	G.topological_sort();

	return 0;
}
