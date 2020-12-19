#include <stdio.h>

int count;

void toh(int n, int A, int B, int C){
    if(n==1){
        count++;
        printf("Move disc from peg %d to peg %d\n", A, C);
    }
    else{
        toh(n-1, A, C, B);
        toh(1, A, B, C);
        toh(n-1, B, A, C);
    }
}

int main(){
    int n;
    printf("Enter number of discs: ");
    scanf("%d", &n);
    int A=1, B=2, C=3;
    toh(n, A, B, C);
    printf("Total Count = %d\n", count);
    return 0;
}
