#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int p, int q, int r);
void mergesort(int array[], int p, int r);

int main() {
    int i, n;
    int array[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Start entering elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Array before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    mergesort(array, 0, n - 1);
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    return 0;
}

void merge(int array[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int LeftHalf[n1], RightHalf[n2];
    for (i = 0; i < n1; i++) {
        LeftHalf[i] = array[p + i];
    }
    for (j = 0; j < n2; j++) {
        RightHalf[j] = array[q + j + 1];
    }
    LeftHalf[n1] = 9999;
    RightHalf[n2] = 9999;
    i = 0;
    j = 0;
    for (k = p; k <= r; k++) {
        if (LeftHalf[i] <= RightHalf[j]) {
            array[k] = LeftHalf[i];
            i++;
        } else {
            array[k] = RightHalf[j];
            j++;
        }
    }
}

void mergesort(int array[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(array, p, q);
        mergesort(array, q + 1, r);
        merge(array, p, q, r);
    }
}


