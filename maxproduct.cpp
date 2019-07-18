#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, arr[n],i;
    cout<<"Enter size of array";
    cin>>n;
    cout<<"Enter elements in an array";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int mul=arr[n-1]*arr[n-2];
    cout<<"Maximum product is:"<<mul;
    return 0;
}
