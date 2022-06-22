#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//naive solution: o(m*n)
//kmp: time o(n+m)-->o(n) strictly it is not linear  
//space:O(m)
void KMPsearch(char *b,char *a,int * lps){
    int m=strlen(b);
    int n=strlen(a),i=0,j=0;
    printf("Pattern found at index : ");
    while(i<n){
        if(a[i]==b[j]){
            i++;j++;
        }else{
            if(j!=0)
               j=lps[j-1];
            else
                i++;
        }
        if(j==m){
            printf("%d",(i-j)+1);
            j=lps[j-1];
        }
    }
    
}
int main(){
    char a[100],b[100];
    printf("Enter string: ");
    scanf("%s",a);
    printf("Enter pattern: ");
    scanf("%s",b);
    int x=strlen(a),y=strlen(b),k=0,i,j=0;
    int lps[1000];//longest profer prefixs that also a suffix
    lps[0]=0;
    for(i=1;i<y;){
        if(b[i]==b[j])
            lps[i++]=++j;
        else {
            if(j!=0)
                j=lps[j-1];//this is making us to loopup to extra values
            else
                lps[i++]=0;
        }       
    }
    KMPsearch(b,a,lps);
}