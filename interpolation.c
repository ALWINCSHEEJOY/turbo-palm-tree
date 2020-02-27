#include<stdio.h>
#include<time.h>
#define max 100000

int interpolationSearch(int arr[], int n, int x) 
{ 
	// Find indexes of two corners 
	int lo = 0, hi = (n - 1); 

	// Since array is sorted, an element present 
	// in array must be in range defined by corner 
	while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
	{ 
		if (lo == hi){ 
			if (arr[lo] == x) return lo; 
			return -1; 
		} 
		// Probing the position with keeping 
		// uniform distribution in mind. 
		int pos = lo + (((double)(hi-lo) / 
			(arr[hi]-arr[lo]))*(x - arr[lo])); 

		// Condition of target found 
		if (arr[pos] == x) 
			return pos; 

		// If x is larger, x is in upper part 
		if (arr[pos] < x) 
			lo = pos + 1; 

		// If x is smaller, x is in the lower part 
		else
			hi = pos - 1; 
	} 
	return -1; 
} 
int main() 
{ 
	// Array of items on which search will 
	// be conducted.
	clock_t startt,endt; 
	double totalt;
	int i,arr[max];
	for(i=0;i<max;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	/////////// 
	int x=(arr[max-1]+1)/2;

	 // Element to be searched
	///////////		
			
	startt=clock(); 
	int index = interpolationSearch(arr, n, x); 
	endt=clock();
	totalt=(float)(endt-startt)/CLOCKS_PER_SEC;
	// If element was found 
	if (index != -1) 
		{printf("Element found at index %d\n", index);
		printf("%f\n\t",totalt); }
	else
		{		printf("Element not found."); }
	return 0; 
} 

