#include<stdio.h>

int Isort(){
 int a[100],n,x,i,t,j;
printf("AANSHUVI SHAH 60009220168\n");
 printf("Enter the no of Elements in the array:");
 scanf("%d",&n);
 printf("\nStart entering Elements in the array:" );
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("ARRAY BEFORE SORTING:\n");
for(i=0;i<n;i++){
    printf(" %d\n",a[i]);
}
for(i=0;i<n;i++){
    t=a[i];
    j=i-1;
    while(j>=0 && a[j]>t){
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=t;
}
printf("ARRAY AFTER SORTING:\n");
for(i=0;i<n;i++){
    printf(" %d\n",a[i]);
}
return 0;
}

int main(){
    Isort();
    return 0;
}