#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define V 5
//O(ElogV)
int main()
{
    int selected[V];
    memset(selected,0,sizeof(selected));
    int graph[V][V] = {
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}};
    int cnt=0,mincost=0;
    selected[0]=1;
    printf("Included edges are: ");
    while (cnt<V-1)
    {
        int min=9999;
        int x=0,y=0;
        for(int i=0;i<V;i++){
            if(selected[i]){
                for(int j=0;j<V;j++){
                    if(!selected[j] && graph[i][j]){
                        if(graph[i][j]<min){
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("%d - %d :%d \n",x,y,graph[x][y]);
        mincost+=graph[x][y];
        selected[y]=1;
        cnt++;
    }
    printf("\nMin cost: %d",mincost);
    
}