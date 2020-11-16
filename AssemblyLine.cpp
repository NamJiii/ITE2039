//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>

int main(){
	int trace[110][3];
	int a[110][3];
	int t[110][3];
	int e[3];
	int x[3];
	int trace_s;
	
	int DP[110][3];
	int resultA[110];
	int N, i, j, result;
	
	scanf("%d",&N);
	scanf("%d %d",&e[1],&e[2]);
	scanf("%d %d",&x[1],&x[2]);
	
	for(i=1; i<=N ; i++){
		scanf("%d",&a[i][1]);	
	}
	for(i=1; i<=N ; i++){
		scanf("%d",&a[i][2]);
	}
	for(i=1; i<N ; i++){
		scanf("%d",&t[i][1]);
	}
	for(i=1; i<N ; i++){
		scanf("%d",&t[i][2]);
	}
	// INPUT

	DP[1][1] = e[1] + a[1][1];
	DP[1][2] = e[2] + a[1][2];
	
	
	
	for(i=2; i<=N ; i++){
		trace[i][2]=1;
		trace[i][1]=1;
		
		if(DP[i-1][1]+t[i-1][1]>DP[i-1][2]){
			DP[i][2]=DP[i-1][2]+a[i][2];
			trace[i][2] = 2;
		}
		else DP[i][2] = DP[i-1][1]+t[i-1][1] + a[i][2];
		
		if(DP[i-1][2]+t[i-1][2]>=DP[i-1][1]) DP[i][1]=DP[i-1][1]+a[i][1];
		else{
			DP[i][1] = DP[i-1][2]+t[i-1][2] + a[i][1];
			trace[i][1] = 2;
		}
	}
	
	if(DP[N][1]+x[1]<=DP[N][2]+x[2]){
		result = DP[N][1]+x[1];
		trace_s = 1;
	}
	else{
		result = DP[N][2]+x[2];
		trace_s = 2;	
	}

	printf ("%d\n",result);
	i=0;
	for(i=0;i<N;i++){
		resultA[N-i]=trace_s;
		trace_s	= trace[N-i][trace_s];
	}
	
	for(i=1 ; i<=N ; i++){
		printf("%d %d\n",resultA[i],i);
	}
}
