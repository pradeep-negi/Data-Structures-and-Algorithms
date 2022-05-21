#include <iostream>
using namespace std;

int binary_search(int *arr, int n, int key)
{
    int l=0,u=n-1;
    while(l<=u)
    {
        int mid=u+(l-u)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            u=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main() {
	// your code goes here
    int arr[]={10,13,19,29,39,52};
    int n=sizeof(arr)/sizeof(int);
    int index=binary_search(arr,n,52);
    if(index!=-1)
        cout<<"the element is at index "<<index;
    else
        cout<<"the element is not found";
	return 0;
}
