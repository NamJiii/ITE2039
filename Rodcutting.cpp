//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>

int main(){
	int DP[101], cutting[101], i, j, a[101],N;
	int result[101];
	int temp = -2100000000;
	
	scanf("%d",&N);
	
	for(i= 1 ;i<=N;++i){
		scanf("%d",&a[i]);
	}
	
//	
	DP[0] = 0;
   for ( int i = 1; i <= N; ++i )
   {
      int temp = -2100000000;
      for ( int j = 1; j <= i; ++j )
      {
         if ( temp < a[j] + DP[i - j] )
         {
            temp = a[j] + DP[i - j];
            cutting[i] = j;
         }
      }
      DP[i] = temp;
   }

	printf("%d\n",DP[N]);

	
	while ( N > 0 )
   {
      printf("%d ", cutting[N]);
      N = N - cutting[N];
   }
   printf("\n");

	return 0;
}


