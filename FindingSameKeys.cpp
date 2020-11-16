//2017029561_남지훈_알고리즘및문제해결(121525) 

#include<stdio.h>
#include<algorithm>

using namespace std;
int main(){
	int* A;
	int* B;
	int M,N;
	int i,j;
	int same_key=0;
	
	scanf("%d %d",&N,&M);
	A = (int*)malloc(sizeof(int)*N);
	B = (int*)malloc(sizeof(int)*M);
	
	for(i=0; i<N ; i++){
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	
	for(i=0; i<M; i++){
		scanf("%d",&B[i]);
	}
	sort(B,B+M);
	
	i=0;
	j=0;
	while(i<N&&j<M){
		if(A[i]==B[j]){
			same_key++;
			i++;
		}
		else if(A[i]>B[j]){
			j++;
		}
		else i++;
	}
	
	printf("%d",same_key);
}
