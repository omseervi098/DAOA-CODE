#include<stdio.h>
#include<stdlib.h>
//time complexity(worst case):nlogn+max(amt,n) (all coins of 1)
//best case:nlogn +const (coins = amt)
//space : o(amt)
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}
int main(){
    int deno[1000],ans[1000],amt,i=0,n,curramt=0,k=0;
    printf("Enter no of denomination: ");
    scanf("%d",&n);
    printf("Enter denomination: ");
    for(i=0;i<n;i++){
        scanf("%d",&deno[i]);
    }
    printf("Enter amount u need to make up: ");
    scanf("%d",&amt);
    qsort(deno,n,sizeof(int),cmpfunc);
    for(i=0;i<n;i++){
        while(amt>=deno[i]){
            amt-=deno[i];
            ans[k++]=deno[i];
        }
    }
    for(i=0;i<k;i++){
        printf("%d ",ans[i]);
    }
}