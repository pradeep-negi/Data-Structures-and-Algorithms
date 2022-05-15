#include <iostream>
using namespace std;

bool duplicate(string str){
	char ch='0';
	int count=0,total=0;
	int n=str.length();
	for(int i=0;i<n;i++){
		if(str[i]!='(' && str[i]!=')')
		{
			ch='1';
		}
		else if(ch=='1'){
			ch='0';
			count++;
		}
	}

	for(int i=0;i<n;i++)
	{
		if(str[i]=='(')
			total++;
	}
	return !(count==total) ;
}

int main() {
	// your code goes here
	string str="((e)e)";
	cout<<duplicate(str);
	return 0;
}
