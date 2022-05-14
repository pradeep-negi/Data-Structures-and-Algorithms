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

void use_tempStack(stack<int> &s, stack<int> & temp){

     while(!s.empty()){
        int x=s.top();
        temp.push(x);
        s.pop();
    }
}

void enter_at_bottom2(stack<int> &s, int key){
    stack<int>temp;
    use_tempStack(s, temp);
    temp.push(key);
    use_tempStack(temp, s);

}

void enter_at_bottom1(stack<int> &s, int key){
    if(s.empty()){
         s.push(key);
         return ;
    }

    int x=s.top(); // returns the element present at the top of stack
    s.pop(); // it removes the topmost element
    enter_at_bottom1(s, key);
    s.push(x);
}

int main() {
	// your code goes here
    stack<int>s;

    for(int i=1;i<10;i++){
        s.push(i);
    }
    print(s);
    cout<<endl;
    
// entering the element at the bottom of stack --- way 1 "using recursion"
    enter_at_bottom1(s,10);
    print(s);
    cout<<endl;

//  entering the element at the bottom of stack --- way 2 "using another stack"
    enter_at_bottom2(s,11);
    print(s);
    cout<<endl;
	return 0;
}
