
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> v){
    int n=v.size(); // to check the number of elements present in vector
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> insert(vector<int> v){
    for(int i=1;i<10;i++)
        v.push_back(i); // to push the element at the last available index
    
    return v;
}

int main() {
// your code goes here
    vector<int>v;
    vector<int> v1=insert(v);
    print(v1);

    v1.pop_back(); // it deletes the last element
    print(v1);

    auto itr=v1.begin(); // it points to the first element of vector
    v1.insert(itr+1,10); // insert 10 at second position ie v1[1].
    print(v1);

    v1.erase(itr); // delete the first element
    print(v1);

// size and capacity before clearing the vector
    cout<<"size of vector is:"<<v1.size()<<endl;
    cout<<"capacity of vector is:"<<v1.capacity()<<endl;

    v1.clear(); // it deletes all the elements

// size and capacity after clearing the vector
    cout<<"size of vector is:"<<v1.size()<<endl;
    cout<<"capacity of vector is:"<<v1.capacity();
// only element values are deleted not allocated memory by clear() function.
return 0;
}

