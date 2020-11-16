//2017029561_남지훈_알고리즘및문제해결기법(12525)
 #include<stdio.h>
 main(){
 	int n, i, j, tmp;
 	int a[30000];
 	scanf("%d",&n);
 	
 	for(i=0;i<n;i++){
 		scanf("%d",&a[i]);
 	}
 	
 	for(i=1;i<n;i++){
 		tmp=a[i];
 		for(j=i-1;j>=0;j--){
 			if(tmp>a[j])a[j+1]=a[j];
 			else break;
 		}
 		a[j+1]=tmp;
 	}
 	
	for(i=0;i<n;i++){
 		printf("%d\n",a[i]);
 	} 	
 	
 }
