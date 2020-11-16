// 2017029561_남지훈_알고리즘및문제해결(121525) 

#include <stdio.h>
#include<algorithm>
#include<stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, index;
int graph[1001][1005], sorted[1001];

using namespace std;

void make_graph(){
	int v, u;
   scanf("%d", &n);

   while (scanf("%d %d", &v, &u)!=EOF) {
      int i = 2;
      while (graph[v][i] != 0)  i++;
      graph[v][i] = u;
      graph[v][1]++;
   }
}

void TopSort(int V) {
   if (graph[V][0] == WHITE) {
      graph[V][0] = GRAY;
      for (int i = 2; graph[V][i] != 0; i++) {
         int n = graph[V][i];
         graph[V][1]--;
         
         if (graph[n][0] == BLACK)
            continue;
         
         TopSort(n);
      }
      if (graph[V][1] == 0) {
         graph[V][0] = BLACK;
         sorted[index++] = V;
      }
      
   }
   else if (graph[V][0] == GRAY) {
    	printf("0");
    	exit(0);
   }
}

void swap(int* a, int* b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

int main() {
	
	make_graph();
	
   for (int k = 1; k <= n; k++) {
      sort(graph[k]+2,graph[k]+2+graph[k][1]);
   }

   for (int k = 1; k <= n; k++) {
      TopSort(k);
   }

      printf("1\n");
      for (int i = 0; i < n; i++) {
         printf("%d ", sorted[n-i-1]);
      }

   return 0;
}

