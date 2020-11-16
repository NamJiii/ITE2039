//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>

int t1[100000];

int main(){
	int N,M,K,i;
	int A[100000], B[100000], t[100000];
	
	scanf("%d %d %d",&N,&M,&K);
	for(i=0;i<K;i++){
		scanf("%d %d",&A[i],&B[i]);
	}
	
	for(i=0;i<N;i++){
		scanf("%d",&t[i]);
		t1[t[i]]++;
	}
	
	for(i=1; i<M;i++){
		t1[i]+=t1[i-1];
	}
	
	for(i=0;i<K;i++){
		printf("%d\n",t1[B[i]]-t1[A[i]-1]);
	}
}
