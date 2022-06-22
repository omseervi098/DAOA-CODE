#include<stdio.h>
#include<stdlib.h>
//time complexity:O(n^2) we can use max heap to do it in O(nlogn)
//space: o(n)
//Heap method:
//Sort the jobs based on their deadlines.
// Iterate from the end and calculate the available slots between every two consecutive deadlines. Include the profit, deadline, and job ID of ith job in the max heap.
// While the slots are available and there are jobs left in the max heap, include the job ID with maximum profit and deadline in the result.
// Sort the result array based on their deadline
void sort(int* arr,int *val,int* item,int n){
    for (int j=0;j<n-1;j++){
        for(int i=0;i<n-j-1;i++){
            if(arr[i]<arr[i+1]){
                int temp;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                temp=val[i];
                val[i]=val[i+1];
                val[i+1]=temp;
                temp=item[i];
                item[i]=item[i+1];
                item[i+1]=temp;
            }
        }
    }
}
int main(){
    int jobs[1000],profit[1000],deadline[1000],ans[1000],i,j,profits=0,n,chart[10000];
    printf("No. of jobs: ");
    scanf("%d",&n);
    printf("Enter profit of jobs: ");
    for(i=0;i<n;i++){
        scanf("%d",&profit[i]);
        jobs[i]=i+1;
    }
    printf("Enter deadline of jobs: ");
    for(i=0;i<n;i++){
        scanf("%d",&deadline[i]);
        
    }
    sort(profit,jobs,deadline,n);
    int mx=0;
    for(i=0;i<n;i++){
        if(deadline[i]>mx){
            mx=deadline[i];
        }
    }
    for(i=0;i<=mx;i++){
        chart[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=deadline[i];j>=0;j--){
            if(chart[j]==0){
                chart[j]=jobs[i];
                profits+=profit[i];
                break;
            }
        }
    }
    for(i=0;i<=mx;i++){
        printf("%d ->",chart[i]);
    }
    printf("\nMax Profit: %d\n",profits);
}