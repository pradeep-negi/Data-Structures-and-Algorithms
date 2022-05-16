#include <bits/stdc++.h>
using namespace std;

void firstnonrepeating(vector<char> & str){
    
    int n=str.size();
    int arr[26]={0};
    queue<char>q;

    for(int i=0;i<n;i++){
        
        char ch=str[i];
        if(arr[str[i]-97]>0){
    
            while(!q.empty() && (arr[q.front()-97]>1 || str[i]==q.front() ) )
                    q.pop();
            if(q.empty()) 
                str[i]='0';
            else{
                str[i]=q.front();
            }
        }
        
        else{
            q.push(str[i]);
            str[i]=q.front();
        }
        
        arr[ch-97]++;
        
    }
    
}

int main(){

    vector<char>str={'a','a','b','c','b','d','c'};
    firstnonrepeating(str);
    int n=str.size();
    for(int i=0;i<n;i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
