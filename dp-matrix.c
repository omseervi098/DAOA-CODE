#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,matsize[1000],i,j,k,l,cost,dp[1000][1000];
    printf("Enter no of matrix: ");
    scanf("%d",&n);
    n=n+1;
    printf("Enter sizes of matrix: ");
    for(i=0;i<n;i++){
        scanf("%d",&matsize[i]);
    }
    n--;
    for(i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(l=2;l<=n;l++){
        for(i=1;i<n-l+1;i++){
            j=i+l-1;
            dp[i][j]=99999;
            for(k=i;k<j;k++){
                int temp=dp[i][k]+dp[k+1][j]+matsize[i-1]*matsize[k]*matsize[j];
                if(temp < dp[i][j]){
                    dp[i][j]=temp;
                }
            }
        }
    }

}