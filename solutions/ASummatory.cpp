#include <stdio.h>
#define M 1000010

int t,c;
long long int sum[M];

int main(){
        long long int i, a = 0;
           for (i = 1; i < M; i++){
                     a = (a + i*i*i) % 1000000003;
                     sum[i] = (sum[i-1] + a) % 1000000003;
                     }
           scanf("%d", &t);
           while (t--){
                 scanf("%d", &c);
                 printf("%lld\n", sum[c]);
                 }
           return 0;
}