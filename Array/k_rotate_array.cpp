#include <iostream>
using namespace std;

void reverse(int *arr, int l ,int u)
{
    while(l<u)
    {
        swap(arr[l],arr[u]);
        l++;
        u--;
    }
}

void k_rotate(int *arr, int n, int k)
{
    k=k%n;
    if(k<0)
        k=k+n;
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr, 0, n-1);
}

int main() {
	// your code goes here
    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    k_rotate(arr,n,-30);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}
