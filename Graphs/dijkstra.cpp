#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Graph{

	list<pair<int,int> >*l;
	int vertices;
	public:
	Graph(int v){
		vertices=v;
		l=new list<pair<int, int> >[v];
	}

	void addEdge(int i, int j, int wt, bool undir=true){
		l[i].push_back({j, wt});
		if(undir){
			l[j].push_back({i, wt});
		}
		
	}

	vector<int> dijkstra(int source){

		vector<int>dis(vertices, INT_MAX);
		dis[source]=0;
		set<pair<int, int> >s;
		s.insert({dis[source], source});

		while(!s.empty()){
			auto it=s.begin();
			int i= it->second;
			s.erase(it);
			for(auto node: l[i]){
				int nbr=node.first;
				int edgewt=node.second;
				int newdis=edgewt + dis[i];
				if(dis[nbr]> newdis){
					
					// delete old node from set
					auto itr=s.find({dis[nbr], nbr});
					if(itr!=s.end()){
						s.erase(itr);
					}

					// insert new updated node in set
					s.insert({newdis, nbr});

					//update the distance vector
					dis[nbr]=newdis;
				}  
			}
		}

		return dis;
	}
};

int main() {
	// your code goes here
	Graph G(5);
	G.addEdge(0,1,1);
	G.addEdge(0,3,7);
	G.addEdge(0,2,4);
	G.addEdge(1,2,1);
	G.addEdge(3,2,2);
	G.addEdge(3,4,3);

	int source=0;
	vector<int> dis= G.dijkstra(0);
	int n=dis.size();
	cout<<"Distance of source node to all other nodes:"<<endl;
	for(int i=0;i<n;i++){
		cout<<source<<"->"<<i<<"="<<dis[i]<<endl;
	}
	return 0;
}
