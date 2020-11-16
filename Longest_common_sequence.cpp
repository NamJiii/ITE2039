//2017029561_남지훈_알고리즘및문제해결(121525) 

#include <stdio.h>
#include <string.h>

int main() {
	
	char a[500], b[500];

   scanf("%s", a);
   scanf("%s", b);

   int i = 0;
   int j = 0;
   
   while(j<strlen(a)){
      if (a[j] == b[i]) {
         printf("%c", a[j]);
         i++;
         j++;
      }
      else
         j++;
	}
	
   return 0;
}
