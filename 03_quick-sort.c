#include<stdio.h>

#include <time.h>
#define MAXELE 100000

int partition(int a[], int l, int h){
	int pivot = a[h];
	int i = l - 1, j, t;
	for(j = l; j < h; ++j){
		if(a[j] <= pivot){
			++i;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	++i;
	a[h] = a[i];
	a[i] = pivot;
	return i;
}

void quickSort(int a[], int l, int h){
	if(l < h){
		int p = partition(a, l, h);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, h);
	}
}


void main(){
	int ar[MAXELE], i, n;
	
	clock_t start_t, end_t;
	float total_t;
	
	n = MAXELE;
	
	for(i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	start_t = clock();
	
	quickSort(ar, 0, n - 1);
	
	end_t = clock();
	total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;
	
	printf("%f\n", total_t);
	
}
