#include <stdio.h>
// time complexity: 2^n but it is faster than recursive one
//Compiler version gcc  6.3.0
void printt(int arr[],int n){
  for(int i=0;i<n;i++){
    printf ("%d ",arr[i]);
  }printf ("\n");
}
void subset(int arr[],int ans[],int st,int k,int n ){
  if(n==0){
    if(k==0){
      printt(ans,st);
      return;
    }else{
      return;
    }
  }
  //not including
  subset(arr+1,ans,st,k,n-1);
  //including
  if(k-arr[0]>=0) {
  ans[st++]=arr[0];//bounding condition
  subset(arr+1,ans,st,k-arr[0],n-1);
  }
}
int main()
{
  int arr[1000],ans[1000],n,k,i;
  printf("Enter array size : ");
  scanf("%d",&n);
  printf("Enter array : ");
  for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
  }
  printf ("Enter sum: ");
  scanf("%d",&k);
  subset(arr,ans,0,k,n);
  return 0;
}