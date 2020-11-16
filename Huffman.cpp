//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>

int a[30001];

void Heapify(int i, int n){
	int tmp;
    int go_up=1;
    int LeftC=i*2;
    int RightC=i*2+1;
    if(LeftC<=n && a[LeftC]<a[i]) go_up=LeftC;
    else go_up=i;

    if(RightC<=n && a[RightC]<a[go_up]) go_up=RightC;

    if (go_up!=i){
        tmp=a[i];
        a[i]=a[go_up];
        a[go_up]=tmp;
        Heapify(go_up,n);
    }
    else return;
    
}

int extract_min(int n)
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
	char value[30001][4];

	
	int N, k,i;
	int result1=0;
	int total;
	int result = 0;
	int tmp=0;
	
	// input
	scanf("%d",&N);
	
	for(i = 1; i <= N; i++)
	{
		scanf("%s %d",&value[i],&a[i]);
	}

	scanf("%d",&total);

	// calculate result 1
	tmp=N-1;
	if(tmp==0) result1 = total;
	while(tmp>0){
		tmp/=2;
		result1+=total;
	}
	
	// calculate result	
	BuildHeap(N);

	while(N>1){
		tmp = 0;
		tmp += extract_min(N);
		tmp += extract_min(N-1);
		N--;
		a[N]=tmp;
		if(N>=2) Heapify(N/2,N);
		result+=tmp;
	}
	
	printf("%d\n",result1);
	printf("%d",result);
	return 0;
}
