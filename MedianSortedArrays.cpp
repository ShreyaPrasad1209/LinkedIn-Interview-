// CPP code for median with case of returning 
// double value when even number of elements are 
// present in both array combinely 
#include<bits/stdc++.h> 
using std::cout; 

int maximum(int a, int b); 
int minimum(int a, int b); 

// Function to find median of two sorted arrays 
double findMedianSortedArrays(int *a, int n, 
							int *b, int m) 
{ 
	
	int min_index = 0, max_index = n, i, j, median; 
	
	while (min_index <= max_index) 
	{ 
		i = (min_index + max_index) / 2; 
		j = ((n + m + 1) / 2) - i; 
	
		// if i = n, it means that Elements from a[] in 
		// the second half is an empty set. and if j = 0, 
		// it means that Elements from b[] in the first 
		// half is an empty set. so it is necessary to 
		// check that, because we compare elements from 
		// these two groups. 
		// Searching on right 
		if (i < n && j > 0 && b[j - 1] > a[i])		 
			min_index = i + 1; 
				
		// if i = 0, it means that Elements from a[] in 
		// the first half is an empty set and if j = m, 
		// it means that Elements from b[] in the second 
		// half is an empty set. so it is necessary to 
		// check that, because we compare elements 
		// from these two groups. 
		// searching on left 
		else if (i > 0 && j < m && b[j] < a[i - 1])		 
			max_index = i - 1; 

		// we have found the desired halves. 
		else
		{ 
			// this condition happens when we don't have any 
			// elements in the first half from a[] so we 
			// returning the last element in b[] from 
			// the first half. 
			if (i == 0)			 
				median = b[j - 1];			 
			
			// and this condition happens when we don't 
			// have any elements in the first half from 
			// b[] so we returning the last element in 
			// a[] from the first half. 
			else if (j == 0)			 
				median = a[i - 1];			 
			else			
				median = maximum(a[i - 1], b[j - 1]);			 
			break; 
		} 
	} 
	
	// calculating the median. 
	// If number of elements is odd there is 
	// one middle element. 
	if ((n + m) % 2 == 1) 
		return (double)median; 
		
	// Elements from a[] in the second half is an empty set.	 
	if (i == n) 
		return (median+b[j]) / 2.0; 
		
	// Elements from b[] in the second half is an empty set. 
	if (j == m) 
		return (median + a[i]) / 2.0; 
	
	return (median + minimum(a[i], b[j])) / 2.0; 
} 

// Function to find max 
int maximum(int a, int b) 
{ 
	return a > b ? a : b; 
} 

// Function to find minimum 
int minimum(int a, int b) 
{ 
	return a < b ? a : b; 
} 

// Driver code 
int main() 
{ 
	int a[] = {900}; 
	int b[] = { 10, 13, 14}; 
	int n = sizeof(a) / sizeof(int); 
	int m = sizeof(b) / sizeof(int); 
	
	// we need to define the smaller array as the 
	// first parameter to make sure that the 
	// time complexity will be O(log(min(n,m))) 
	if (n < m) 
		cout << "The median is : "
			<< findMedianSortedArrays(a, n, b, m); 
	else
		cout << "The median is : "
			<< findMedianSortedArrays(b, m, a, n); 

	return 0; 
} 
