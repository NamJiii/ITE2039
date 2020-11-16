// 2017029561_남지훈_알고리즘및문제해결(12525) 

#include <stdio.h>
#include <algorithm>
#include <vector>
#define maxint 2100000000
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y)) 

using namespace std;

int n;
int d[5000], f[5000], e[5000];
int src, dst, w;
vector<pair<int, int>*> logs;

void set(){
	scanf("%d", &n);

   for (int i = 1; i <= n; i++) {
      d[i] = maxint;
   }
   d[1]=0;
}

void edge_set(){
	int Ew;
	scanf("%d %d", &src, &Ew);
	e[src] = Ew;
	pair<int, int> *p = (pair<int,int>*)malloc(sizeof(pair<int,int>)*Ew);
	for (int j = 0; j < Ew; j++) {
		scanf("%d %d", &dst, &w);
		p[j] = make_pair(dst, w);
	}
	logs.push_back(p);
}

void run(int v){
	f[v] = 1;
	pair<int, int> *pt = logs.at(v - 1);
	for (int j = 0; j < e[v]; j++) {
		d[pt[j].first] = MIN(d[pt[j].first] , d[v] + pt[j].second);
	}
}

int main() {
   int min, select;
	set();
	
   for (int i = 0; i < n; i++) {
		edge_set();
   }

   for (int i = 0; i < n; i++) {
      min = maxint;
      for (int j = 1; j <= n; j++) {
         if (f[j] == 0 && min > d[j]) {
            min = d[j];
            select = j;
         }
      }
      run(select);
   }

   sort(d+1, d+n+1);
   printf("%d", d[n]);
   
   return 0;
}
