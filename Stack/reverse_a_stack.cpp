#include <iostream>
#include <stack>
using namespace std;

void print(stack<int>s){
    if(s.empty())
        return ;

    int x=s.top(); // returns the element present at the top of stack
    s.pop(); // it removes the topmost element
    print(s);
    cout<<x<<" ";
    s.push(x);
}

void enter_at_bottom(stack<int> &s, int key){
    if(s.empty()){
         s.push(key);
         return ;
    }

    int x=s.top(); // returns the element present at the top of stack
    s.pop(); // it removes the topmost element
    enter_at_bottom(s, key);
    s.push(x);
}

void reverse(stack<int> &s){
    if(s.empty())
        return;

    int x=s.top();
    s.pop();
    reverse(s);
    enter_at_bottom(s, x);
}

int main() {
	// your code goes here
    stack<int>s;

    for(int i=1;i<10;i++){
        s.push(i);
    }
    print(s);
    cout<<endl;
    
    reverse(s);
    print(s);
    cout<<endl;
	return 0;
}
