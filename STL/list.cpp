#include <iostream>
#include <list> // for doubly linked list
using namespace std;
void print(list<int> l){
    list<int>::iterator itr= l.begin();
    while(itr!=l.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl;
}

int main() {
	// your code goes here
    list<int>l;
    for(int i=1;i<10;i++){
        l.push_back(i);  // adds the element at the end of linked list
    }
    
    print(l);

// it pushes the element at the beginning of the list
    l.push_front(10);
    print(l);

// sorting of the list
    l.sort();
    print(l);

// pop from the end of the list
    l.pop_back();
    print(l);

// pop from the front of the list
    l.pop_front();
    print(l);

// reverses the list
    l.reverse();
    print(l);

// size of the list
    cout<<"size: "<<l.size()<<endl;
	return 0;

}
