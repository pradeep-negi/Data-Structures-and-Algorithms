#include <iostream>
using namespace std;

int subarray_sum(int *arr, int n)
{
    int psum[n];
    psum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        psum[i]=psum[i-1]+arr[i];
    }
    int maxsum=psum[n-1];
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum=i>0? psum[j]-psum[i-1] : psum[j];
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

int main() {
	// your code goes here
    int arr[]={10,20,-2,-7,12,36,-1,40};
    int n=sizeof(arr)/sizeof(int);
    cout<<subarray_sum(arr,n);
	return 0;
}
