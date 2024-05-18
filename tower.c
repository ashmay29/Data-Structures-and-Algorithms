#include <stdio.h>
int towers(int,char,char,char);

int main(){
    int num;
    printf("Enter the no of Disks\n");
    scanf("%d",&num);
    printf("The sequence of Moves involved are \n");
    towers(num,'A','B','C');
    return 0;
}

int towers(int num,char frompeg,char topeg,char auxpeg){
    if(num==1){
        printf("\n Move disl 1 from peg %c to %c", frompeg,topeg);
    }
    else{
        towers(num-1,frompeg,auxpeg,topeg);
        printf("\n Move disk %d from peg %c to %c",num,frompeg,topeg);
        towers(num-1,auxpeg,topeg,frompeg);
    }
    return 0;

}
