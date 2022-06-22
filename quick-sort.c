#include<stdio.h>
#include<stdlib.h>
//avg time : nlogn (T(k)+T(n-k-1)+n)
//worst case : (sorted arr) n^2
//best case:(when it divides arr in two half) (nlogn) (2T(n/2)+n)
//space : const
void swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int *arr,int st,int end){
    int pi=st,cnt=0,i=st,j=end;
    for(i=st+1;i<=end;i++){
        if(arr[i]<arr[pi]){
            cnt++;
        }
    }
    swap(arr,pi,cnt+st);
    pi=cnt+st;
    i=st;
    while(i<cnt+st && j>cnt+st){
        if(arr[i]<arr[pi])
            i++;
        else if(arr[j]>=arr[pi])
            j--;
        else {
            swap(arr,i,j);
            i++;j--;
        }
    }
    return pi;
}
void quicksort(int* arr,int st,int end){
    if(st>=end)
    return;
    int pi=partition(arr,st,end);
    quicksort(arr,st,pi-1);
    quicksort(arr,pi+1,end);
}
int main(){
    int n,arr[1000],i;
    printf("Enter size of arr :");
    scanf("%d",&n);
    printf("Enter elements of arr : ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted Arr: ");
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}