#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> graph, int node, vector<int>path, vector<vector<int>> & v){
    
    int n=graph.size();
    path.push_back(node);
    if(node==n-1){
        v.push_back(path);
        return;
    }
    
    int m=graph[node].size();
    for(int i=0;i<m; i++){
        int nbr=graph[node][i];
        dfs(graph, nbr, path, v);
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    // your code goes here
    vector<int>path;
    vector<vector<int>> v;
    dfs(graph, 0, path, v);
    return v;
}


int main(){
    vector<vector<int>> graph{{1,2,3},{2,3},{3},{}};
    vector<vector<int>>v= allPathsSourceTarget(graph);
    int n=v.size();
    for(int i=0;i<n;i++){
        int m=v[i].size();
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
