#include<stdio.h>
#include<stdlib.h>
//time comple : n*amt
//space :n*amt 
void dp_coinchange(int* deno,int amt,int* ans,int n){
    //take 2d arr of n*amt size
    int dp[n+1][amt+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=amt;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        int d=deno[i-1];
        for(int j=1;j<=amt;j++){
            if(i==1 && j<d)
                dp[i][j]=99999;
            else if(j<d)
                dp[i][j]=dp[i-1][j];
            else if(i==1)
                dp[i][j]=1+dp[i][j-d];
            else{
                if(dp[i-1][j]<1+dp[i][j-d]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=1+dp[i][j-d];
                }
            }
        }
    }
    //tracing solution 
    int i=n,j=amt,k=0;
    while(j>0){
        if(dp[i][j]==dp[i-1][j])
            i=i-1;
        else{
            j=j-deno[i-1];
            ans[k++]=deno[i-1];
        } 
    }
    printf("No. of coins: \n");
    printf("%d\n",dp[n][amt]);
    printf("Coins are :\n");
    for(i=0;i<k;i++){
        printf("%d ",ans[i]);
    }
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
    dp_coinchange(deno,amt,ans,n);
    
}