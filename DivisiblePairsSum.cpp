#include <bits/stdc++.h> 
using namespace std; 
  
// Program to count pairs whose sum divisible 
// by 'K' 
int countKdivPairs(int A[], int n, int K) 
{ 
    // Create a frequency array to count 
    // occurrences of all remainders when 
    // divided by K 
    int freq[K] = { 0 }; 
  
    // Count occurrences of all remainders 
    for (int i = 0; i < n; i++) 
        ++freq[A[i] % K]; 
  
    // If both pairs are divisible by 'K' 
    int sum = freq[0] * (freq[0] - 1) / 2; 
  
    // count for all i and (k-i) 
    // freq pairs 
    for (int i = 1; i <= K / 2 && i != (K - i); i++) 
        sum += freq[i] * freq[K - i]; 
    // If K is even 
    if (K % 2 == 0) 
        sum += (freq[K / 2] * (freq[K / 2] - 1) / 2); 
    return sum; 
} 
  
// Driver code 
int main() 
{ 
    int n,A[n];
    cout<<"Enter elements in array:";
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    int n = sizeof(A) / sizeof(A[0]); 
    int K = 4; 
    cout << countKdivPairs(A, n, K); 
  
    return 0; 
} 
