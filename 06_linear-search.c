#include<stdio.h>

#include <time.h>
#define MAXELE 100000

int main(){
	int ar[MAXELE],i,n,s,found=0;
	
	s = 2144898183;
	
	clock_t start_t, end_t;
	float total_t;
	
	n = MAXELE;
	
	for(i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	//printf("Enter element to search:");
	//scanf("%d",&s);
	
	for(i=0;i<n;i++){
		if(ar[i]==s){
			printf("The element is at %d.\n",i);
			found=1;
			break;
		}
	}
	if(!found){
		printf("Not found.\n");
	}
	
	end_t = clock();
	total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;
	
	printf("%f\n", total_t);
}
