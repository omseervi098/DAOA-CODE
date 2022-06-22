#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char a[100];
    char b[100];
    int dp[1000][1000],i,j,m,n,k=0;
    char c[100];
    printf("Enter first string: ");
    scanf("%s",a);
    m=strlen(a);
    printf("Enter second string: ");
    scanf("%s",b);
    n=strlen(b);
    for(i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(i=1;i<=n;i++){
        dp[0][i]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    i=m,j=n;
    k=dp[m][n];
    c[k]='\0';
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            c[k-1]=a[i-1];
            i--;j--;k--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    printf("longest common subseq size: %d\n",dp[m][n]);
    printf("LCS is : %s \n",c);
}