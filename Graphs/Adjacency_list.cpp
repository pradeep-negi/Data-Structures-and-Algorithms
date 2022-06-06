#include <iostream>
#include <list>
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

	void print(){
		for(int i=0;i<vertices;i++){
			cout<<i<<"-->";
			for(auto itr=l[i].begin(); itr!=l[i].end(); itr++){
				cout<<*itr<<",";
			}
			cout<<endl;
		}
	}
};

int main() {
	// your code goes here
	Graph G(5);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(0,3);
	G.addEdge(1,2);
	G.addEdge(1,4);
	G.addEdge(3,4);
	G.print();
	return 0;
}
