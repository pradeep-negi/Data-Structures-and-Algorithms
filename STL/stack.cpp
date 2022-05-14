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
int main() {
	// your code goes here
    stack<int>s;
    
    // push elements at the top of the stack
    for(int i=1;i<10;i++){
        s.push(i);
    }
    print(s);
    cout<<endl;
    
// printing the size of stack
    cout<<"size of stack is "<<s.size()<<endl;
	return 0;
}
