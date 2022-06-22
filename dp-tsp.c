#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//time complexity:n^2*2^n
//space: n*2^n
//we can optimise it using greedy in n^2*log(n)
int tsp(int **dist,int **dp,int n,int mask,int pos,int visited_all,int *ans,int st){
    if(mask==visited_all){
        ans[st++]=pos+1;
        ans[st]=1;
        return dist[pos][0];
    }
    ans[st++]=pos+1;
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int min=9999;

    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0){
           int ans1=dist[pos][i]+tsp(dist,dp,n,(mask|(1<<i)),i,visited_all,ans,st);
            if(ans1<min){
                min=ans1;
                
            }
        }
    }
    
    return min;
}
int main(){
    int n,i,j;
    printf("Enter no of cities: ");
    scanf("%d",&n);
    printf("Enter Cost Matrix: \n");
    int **dist=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        dist[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            scanf("%d",&dist[i][j]);
        }
    }
    int x=(1<<n);
    int y=n;
    int **dp=(int**)malloc(x*sizeof(int*));
    int *ans=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<x;i++){
        dp[i]=(int*)malloc(y*sizeof(int));
        for(j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    int visited_all=(1<<n)-1;
    int cost=tsp(dist,dp,n,1,0,visited_all,ans,0);
    printf("Minimum cost: %d Units\n",cost);
    printf("One of the Path: ");
    for(i=0;i<n;i++){
        printf("%d -> ",ans[i]);
    }
    printf("%d",ans[i]);
}