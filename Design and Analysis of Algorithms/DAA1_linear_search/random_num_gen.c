#include <stdio.h>
#include <stdlib.h>

void gen_rand_array(int arr[], int n);
void printf_gen_rand_array();

int main(){
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
               printf_gen_rand_array();
        }
        return 1; 
}

void gen_rand_array(int arr[], int n){
        for(int i=0; i<n; i++){
                arr[i] = rand()%100000;
        }
        return;
}

void printf_gen_rand_array(){
        int n;
        scanf("%d", &n);
        int arr[n];
        gen_rand_array(arr, n);
        printf("%d\n", n);        
        for(int i=0; i<n; i++){
                printf("%d ", arr[i]);
        }
        printf("\n");
        int k = arr[rand()%(n-1)];
        if(k % 13 == 0)
                printf("%d\n", rand()%100000);
        else
                printf("%d\n", k);
        printf("\n");
        return;
}
