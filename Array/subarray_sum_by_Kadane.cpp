#include <iostream>
#include<climits>
using namespace std;
// linear time algorithm
int subarray_sum(int *arr, int n)
{
    int cs=0,ms=INT_MIN;
    for(int i=0;i< n; i++)
    {
        cs+=arr[i];
        ms=max(ms,cs);
        if(cs<0)
            cs=0;
    }
    return ms;
}
int main() {
	// your code goes here
    int arr[]={-2,-1,-12};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subarray_sum(arr, n);
	return 0;
}
