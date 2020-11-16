//2017029561_남지훈_알고리즘및문제해결기법(12525)

#include<stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define IFMIN(a,b) (((a)<(b))?(1):(0))
	
int leftB[101];
int rightB[101];
int points[101][101];
	
void find(int i, int k, int f){
	if(k==0) return;
	if(i==k&& f==k+1){
		leftB[i-1]++;
		rightB[f]++;
		return;
	}
	if(i!=k&&k+1!=f){
	leftB[i-1]++;
	rightB[k]++;
	leftB[k]++;
	rightB[f]++;}
	
	int left_k = points[i][k];
	int right_k = points[k+1][f];
	
	find(i,left_k,k);
	find(k+1,right_k,f);
}

int main(){
	int m[101][101];
	int numbers[101];

	
	int i, gap,j, N, min=214000000;
	int tmp;
	
	scanf("%d",&N);
	
	for(i=0;i<=N;i++){
		scanf("%d",&numbers[i]);
	}
	
	for(gap=0;gap<N;gap++){
		for(i=1;i<=N;i++){
			if(i+gap>N) continue;
			else if(gap==0) m[i][i+gap] = 0;
			else{
				min = 2140000000;
				for(j=i;j<i+gap;j++){
					if(IFMIN(m[i][j]+m[j+1][i+gap]+numbers[i-1]*numbers[j]*numbers[i+gap],min)){
						min = m[i][j]+m[j+1][i+gap]+numbers[i-1]*numbers[j]*numbers[i+gap];
						tmp = j;
					}
				}
				m[i][i+gap]=min;
				points[i][i+gap]=tmp;
			}
		}
	}
	
	printf("%d\n",m[1][N]);
	
	find(1,points[1][N],N);
	leftB[0]++;
	rightB[N]++;
	
	for(i=1;i<=N;i++){
		for(j=0;j<leftB[i-1];j++){
			printf("(");
		}
		
		printf("%d",i);
		
		for(j=0;j<rightB[i];j++){
			printf(")");
		}
	}
}
