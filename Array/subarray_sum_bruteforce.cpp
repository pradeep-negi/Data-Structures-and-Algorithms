#include <iostream>
using namespace std;
int subarray_sum(int *arr, int n)
{
    int maxsum=0;
    for(int i=0;i< n;i++)
    {
        maxsum+=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(sum>maxsum)
                maxsum=sum;
        }
    }
    return maxsum;
}
int main() {
	// your code goes here
    int arr[]={-10,20 , 300 ,-40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxsum=subarray_sum(arr, n);
    cout<<"the maxsum of subarray is "<<maxsum;
	return 0;
}
