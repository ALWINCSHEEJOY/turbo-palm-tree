#include<stdio.h>

#include <time.h>
#define MAXELE 100000

void main(){
	int i,j,k,ar[MAXELE],n,key;
	
	clock_t start_t, end_t;
	float total_t;
	
	n = MAXELE;
	
	for(i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	start_t = clock();
	
	for(i=1;i<n;i++){
		key=ar[i];
		for(j=i;j>-1;j--){
			if((key<ar[j-1])&&(j!=0)){
				ar[j]=ar[j-1];
			}else{
				ar[j]=key;
				break;
			}
		}
	}
	
	end_t = clock();
	total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;
	
	printf("%f\n", total_t);
}
