#include <iostream>
#include <forward_list> // for singly linked list
using namespace std;
void print(forward_list<int> l){
    forward_list<int>::iterator itr= l.begin();
    while(itr!=l.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl;
}

int main() {
	// your code goes here
    forward_list<int>l;

/*
These functions are not present in forward list

 1 push_back()
 2 pop_back()
 3 size()

*/
    for(int i=1;i<10;i++){
        l.push_front(i);  // adds the element at the front of linked list
    }
    
    print(l);

// sorting of the list 
    l.sort();
    print(l);

// pop from the front of the list
    l.pop_front();
    print(l);

// reverses the list
    l.reverse();
    print(l);

	return 0;

}
