#include<stdio.h>
#include<stdlib.h>
//time : o(nlogn) --sorting
//space : o(n)
void sort(double* arr,int *val,int *wet,int* item,int n){
    for (int j=0;j<n-1;j++){
        for(int i=0;i<n-j-1;i++){
            if(arr[i]<arr[i+1]){
                int temp;
                double temp1=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp1;
                temp=val[i];
                val[i]=val[i+1];
                val[i+1]=temp;
                temp=wet[i];
                wet[i]=wet[i+1];
                wet[i+1]=temp;
                temp=item[i];
                item[i]=item[i+1];
                item[i+1]=temp;
            }
        }
    }
}
int main(){
    int item[1000],value[1000],weight[1000],maxw,i,j=0,n,ans[1000],wesum=0,copy;
    double valbywe[1000],part[1000]={0},profit=0;
    printf("Max weight: ");
    scanf("%d",&maxw);
    copy=maxw;
    printf("Enter no of items: ");
    scanf("%d",&n);
    printf("Enter value of items: ");
    for(i=0;i<n;i++){
        item[i]=i+1;
        scanf("%d",&value[i]);
    }
    printf("Enter weight of items: ");
    for(i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    for(i=0;i<n;i++){
        valbywe[i]=(double) value[i]/weight[i];
    }
    sort(valbywe,value,weight,item,n);
    
    for(i=0;i<n;i++){
        
        if(weight[i]<=maxw){
            maxw-=weight[i];
            profit+=value[i];
            ans[j]=item[i];
            part[j]=1.0;
            wesum+=weight[i];
            j++;
        }
        else {
            part[j]=(double) (copy-wesum)/weight[i];
            profit+=value[i]*part[j];
            ans[j]=item[i];
            j++;
            maxw=0;
            break;
        }
    }
    for(i=0;i<n;i++){
        printf("%d %d %d %f\n",item[i],value[i],weight[i],valbywe[i]);
    }
    printf("Included item: \n");
    for(i=0;i<j;i++){
        printf("%d %f\n",ans[i],part[i]);
    }
    printf("max profit : %d",printf);
}