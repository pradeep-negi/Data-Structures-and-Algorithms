#include <iostream>
using namespace std;

int  linear_search(int arr[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int main() {
	// your code goes here
    int arr[]={1,2,5,6,12,8,97};
    int n=sizeof(arr)/sizeof(int);
    int index=linear_search(arr,n, 6);
    if(index!=-1)
        cout<<"the element is at index "<<index;
    else
        cout<<"element not found";
	return 0;
}
