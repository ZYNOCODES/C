#include <stdio.h>
#include <time.h>

int partition(int T1[], int First, int Last) {
    int pivot = T1[Last];  
    int i = (First - 1);      
    for (int j = First; j < Last; j++) {
        if (T1[j] < pivot) {
            i++;
            int temp = T1[i];
            T1[i] = T1[j];
            T1[j] = temp;
        }
    }

    int temp = T1[i + 1];
    T1[i + 1] = T1[Last];
    T1[Last] = temp;

    return (i + 1);
}

void quickSort(int T1[], int First, int Last) {
    if (First < Last) {
        int pi = partition(T1, First, Last);
        quickSort(T1, First, pi - 1);
        quickSort(T1, pi + 1, Last);
    }
}

int main() {
    int T1[100];
    int size1;
    float time = 0.0;

    printf("Give the size of T1: \n");
    scanf("%d", &size1);

    printf("Give the elements of T1: \n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &T1[i]);
    }

    printf("Display after Quick sort: \n");

    for (int i = 0; i < size1; i++) {
        printf("%d ", T1[i]);
    }
    printf("\n");\

    clock_t begin = clock();
    quickSort(T1, 0, size1 - 1);
    clock_t end = clock();

    time = (float) (end - begin)/CLOCKS_PER_SEC;

    for (int i = 0; i < size1; i++) {
        printf("%d ", T1[i]);
    }
    printf("\n exec time= %f", time);

}
