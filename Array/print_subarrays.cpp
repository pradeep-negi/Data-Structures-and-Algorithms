#include <iostream>
using namespace std;

void printSubarrays(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
int main() {
	// your code goes here
    int arr[]={10,20,30,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    printSubarrays(arr, n);

	return 0;
}
