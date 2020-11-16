//2017029561_남지훈_알고리즘및문제해결기법(12525)
 #include<stdio.h>

void MergeSort(int a[] ,int p,int r);
void Merge(int a[],int p,int q,int r);

int main(){
 	int n, i;
 	int a[100000];
 	
 	scanf("%d",&n);
 	
 	for(i=0;i<n;i++){
 		scanf("%d",&a[i]);
 	}
 	
 	MergeSort(a,0,n-1);
 	
 	for(i=0;i<n;i++){
 		printf("%d\n",a[i]);
 	}
 	
 	return 0;
 }
 
void MergeSort(int a[] ,int p,int r){
	int q;
	if(p<r){
		q = (p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
}

void Merge(int a[],int p,int q,int r)
{
    int tmp[100000];
    int i=p,j=q+1,n=0;
    
    while(i<=q && j<=r){
        if(a[i]>a[j])
            tmp[n++]=a[i++];
        else
            tmp[n++]=a[j++];
    }
    
    if(i<=q){
	    while(i<=q){
	    tmp[n++]=a[i++];
		}	
	}
        
    else{
		while(j<=r){    
	        tmp[n++]=a[j++];
	    }	
	}
	
    for(i=p;i<=r;i++)
        a[i]=tmp[i-p];
}
