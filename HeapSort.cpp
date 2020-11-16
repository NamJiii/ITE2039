//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>

int a[100000];
	
void Heapify(int i, int n){
	int tmp;
    int go_up=1;
    int LeftC=i*2;
    int RightC=i*2+1;
    if(LeftC<=n && a[LeftC]>a[i]) go_up=LeftC;
    else go_up=i;

    if(RightC<=n && a[RightC]>a[go_up]) go_up=RightC;

    if (go_up!=i){
        tmp=a[i];
        a[i]=a[go_up];
        a[go_up]=tmp;
        Heapify(go_up,n);
    }
    else return;
    
}

int extract_max(int n)
{
	int tmp;
	
	tmp = a[n];
	a[n] = a[1];
	a[1] = tmp;
	
	Heapify(1, n - 1);
	return a[n];
}


void BuildHeap( int n)
{
	int i;
	for(i = n/2; i >= 1; i--){
		Heapify(i, n);
	}
}

int main()
{
	int N, k,i;
	scanf("%d %d",&N,&k);
	for(i = 1; i <= N; i++)
	{
		scanf("%d",&a[i]);
	}

	BuildHeap(N);
	
 	for(i = 0 ; i< k ; i ++){
 		printf("%d ",extract_max(N-i));
	 }

	 printf("\n");
	 for(i=1; i<= N-k ; i++){
	 	printf("%d ",a[i]);
	 }
	 printf("\n");
	return 0;
}
