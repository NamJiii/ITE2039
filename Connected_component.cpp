//2017029561_������_�˰���׹����ذ���(12525)
#include<stdio.h>

int main(){
	int n,m,i,j,tmp ;
	int a[30000];
	int min = 30001,min_num;
	
	scanf("%d %d",&n,&m);
	
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	
	for(j=0; j < m ; j++){
		for(i=j;i<n;i++){
			if(min>a[i]){
				min = a[i];
				min_num = i;
			}
		}
		tmp = a[j];
		a[j] = a[min_num];
		a[min_num] = tmp;
		min = 30001;
	}
	
	for(i=0; i<n ; i++){
		printf("%d\n",a[i]);
	}
}
