#include <stdio.h>
#include <time.h>
#include<math.h>

main(){
    float time = 0.0;
    int T[10000], i, j, n, pmin, per;

    printf("Give the size n of T : ");
    scanf("%d", &n);

    printf("Reading the table : \n");
    for (i = 0; i < n; i++){
        T[i]=n-i;
        printf(" %d ", T[i]);
    }

    clock_t begin = clock();
    for (i = 0; i < n-1; i++){
        pmin = i;
        for (j = i+1; j < n; j++){
            if (T[j] < T[pmin]){
                pmin = j;
            }
        }

        if (i != pmin){
            per = T[i];
            T[i] = T[pmin];
            T[pmin] = per;
        }
    }
    clock_t end = clock();
    
    time = (float) (end - begin)/CLOCKS_PER_SEC;

    printf("\n Display after Selection sort : \n ");
    for (i = 0; i < n; i++){
        printf(" %d ", T[i]);
    }
    printf("\n exec time= %f", time);
}