//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>

int a[1000000],ext[1000000];

void Heapify(int i, int n){
	int tmp;
    int go_up=1;
    int LeftC=i*2;
    int RightC=i*2+1;
    if(LeftC<=n && a[LeftC]>a[i]) go_up=LeftC;
    else go_up=i;

    if(RightC<=n && a[RightC]>=a[go_up]) go_up=RightC;

    if (go_up!=i){
        tmp=a[i];
        a[i]=a[go_up];
        a[go_up]=tmp;
        Heapify(go_up,n);
    }
    
}

int extract_max(int n)
{
	int tmp;
	
	tmp = a[1];
	a[1] = a[n];
	
	Heapify(1, n - 1);
	return tmp;
}

void Func3_change(int n, int value, int idx){
	a[idx]=value;
	while(idx>=1){
		Heapify(idx,n);
		idx/=2;
	}
}

void Func1_insert(int n, int value){
	Func3_change(n,value,n);
}

int main()
{
	int m,value1,value2,n=0,i;
	int j=0;

	while(true){
		scanf("%d",&m);
		if(m==0){
			break;
		}
		if(m==1){	
			scanf("%d",&value1);
			n++;
			Func1_insert(n,value1);
		}
		if(m==2){
			if(n != 0 ){
				ext[j++]=extract_max(n);
				n--;
			}
		}
		if(m==3){
			scanf("%d %d",&value1,&value2);
			Func3_change(n, value2, value1);
		}		
	}
	for(i=0;i<j;i++){
		printf("%d ",ext[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}


