#include <stdio.h>
#include <time.h>
int main(){
    float time = 0.0;
    int T[10000], i, j, n, tmp;

    printf("Give the size n of T : ");
    scanf("%d", &n);

    printf("Reading the table : \n");
    for (i = 0; i < n; i++){
        T[i]=n-i;
        printf(" %d ", T[i]);
    }
    clock_t begin = clock();
    for (i = 1; i < n; i++){
        tmp = T[i];
        j = i - 1;
        while (tmp < T[j] && j >= 0){
            T[j + 1] = T[j];
            j--;
        }
        T[j + 1] = tmp;
    }
    clock_t end = clock();
    time = (float) (end - begin)/CLOCKS_PER_SEC;
    printf("\n Display after Insertion sort : \n ");
    for (i = 0; i < n; i++){
        printf(" %d ", T[i]);
    }
    printf("\n exec time= %f", time);
}