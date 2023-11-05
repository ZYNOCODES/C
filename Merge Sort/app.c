#include <stdio.h>
#include <time.h>

void triFusion(int T1[], int size1, int T2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (T1[i] < T2[j]) {
            result[k] = T1[i];
            k++;
            i++;
        } else {
            result[k] = T2[j];
            k++;
            j++;
        }
    }
    while (i < size1) {
        result[k] = T1[i];
        k++;
        i++;
    }
    while (j < size2) {
        result[k] = T2[j];
        k++;
        j++;
    }
}

int main() {
    
    int T1[100], T2[100];
    int size1, size2;
    float time = 0.0;

    printf("Give the size of T1: \n");
    scanf("%d", &size1);
    printf("Give the size of T2: \n");
    scanf("%d", &size2);

    printf("Give the elements of T1: \n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &T1[i]);
    }

    printf("Give the elements of T2: \n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &T2[i]);
    }

    int result[size1 + size2];

    clock_t begin = clock();
    triFusion(T1, size1, T2, size2, result);
    clock_t end = clock();

    time = (float) (end - begin)/CLOCKS_PER_SEC;

    printf("Display after Merge sort: \n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n exec time= %f", time);

    return 0;
}
