#include<stdio.h>
#include<stdlib.h>
//TIME: O(ElogE)
//space: O(E)
typedef struct edge{
    int u,v,w;
}edge;
int compare(const void *a,const void *b){
    edge *A=(edge*)a;
    edge *B=(edge*)b;
    return (A->w-B->w);
}
int find(int *parent,int v){
    if(parent[v]==v)
    return v;
    return find(parent,parent[v]);
}
int main(){
    struct edge list[100];
    struct edge out[100];
    int n,e,i,j;
    printf("Enter no of vertex and edges :");
    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++){
        printf("Enter edge in (u,v,w) format:");
        scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
    }
    qsort(list,n,sizeof(edge),compare);
    int cnt=0,mincost=0;
    int parent[n];
    for(i=0;i<n;i++){
        parent[i]=i;
    }i=0;

    while(cnt<n-1){
        edge curr=list[i];
        int parent_u=find(parent,curr.u);
        int parent_v=find(parent,curr.v);
        if(parent_u!=parent_v){
            out[cnt++]=curr;
            mincost+=curr.w;
            parent[parent_u]=parent_v;
        }
        i++;
    }
    printf("Min cost: %d\n",mincost);
    printf("MST: \n");
    for(i=0;i<n-1;i++){
        printf("%d %d %d\n",out[i].u,out[i].v,out[i].w);
    }

}