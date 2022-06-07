#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> rooms, int key, vector<bool> & visited){
    
        visited[key]=true;
        int m=rooms[key].size();
        for(int j=0;j<m;j++){
            int newkey=rooms[key][j];
            if(!visited[newkey]){
                dfs(rooms, newkey, visited);
            }
        }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
     // your code goes here
    int key=0;
    int n=rooms.size();
    vector<bool>visited(n,false);
    dfs(rooms, key, visited);
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            return false;
    }
    return true;
}

int main(){
    vector<vector<int>> rooms{{1,3},{3,0,1},{2},{0}};
    cout<<canVisitAllRooms(rooms);
    return 0;
}
