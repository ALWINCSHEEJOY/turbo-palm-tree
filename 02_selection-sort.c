#include<stdio.h>

#include <time.h>
#define MAXELE 100000

void main(){
	int i, j, ar[MAXELE], n, min, t;
	
	clock_t start_t, end_t;
	float total_t;
	
	n = MAXELE;
	
	for(i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	start_t = clock();
	
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(ar[min] > ar[j]){
				min = j;
			}
		}
		if(min != i){
			t = ar[i];
			ar[i] = ar[min];
			ar[min] = t;
		}
	}
	
	end_t = clock();
	total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;
	
	printf("%f\n", total_t);
}
