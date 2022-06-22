#include<stdio.h>
#include<stdlib.h>
//time complex:T(n^2)+n*T(n-1)     --N!
//space complexity:o(n^2)
int issafe(int **board,int row,int col,int n){
    for(int i=0;i<=col;i++){
        if(board[row][i]==1){
            return 0;
        }
    }
    for(int i=0;i<=row;i++){
        if(board[i][col]){
            return 0;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;){
        if(board[i--][j--]==1){
            return 0;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;){
        if (board[i--][j++]==1)
        {
            return 0;
        }
    }
    return 1;
}
int cnt=0;
int nqueen(int **board,int *ans,int st,int row,int n){
    if(row==n){
        if(st==n){
        for(int i=0;i<st;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        cnt++;
        }
        return 1;
    }
   
    for(int i=0;i<n;i++){
        if(issafe(board,row,i,n)){
            board[row][i]=1;
            ans[st]=i+1;
            int check=nqueen(board,ans,st+1,row+1,n);
            board[row][i]=0;
            ans[st]=0;
            //ans[st]=0;
        }
    }
    return 0;
}
int main(){
    int n,i,*ans,j;
    printf("Enter no of rows or cold :");
    scanf("%d",&n);
    int **board=(int**)malloc(n * sizeof(int*));
    ans=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        board[i]=(int*)malloc(n * sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    printf("Possible solution : \n");
    int check=nqueen(board,ans,0,0,n);
    printf("No of Solution: \n");
    printf("%d",cnt);
}