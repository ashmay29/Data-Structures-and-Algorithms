#include <stdio.h>
#include <stdlib.h>

int smallest(int arr[], int k, int n);
void selection_sort(int arr[], int n);

int main(int argc, char *argv[]) {
    int arr[10], i, n;
    
    printf("Aanshuvi shah 60009220168");
    
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("The array before sorting is: \n");
    for(i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    
    selection_sort(arr, n);
    
    printf("\nThe array after sorting is: \n");
    for(i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    
    return 0;
}

int smallest(int arr[], int k, int n) {
    int pos = k, small = arr[k], i;
    for(i = k + 1; i < n; i++) {
        if(arr[i] < small) {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selection_sort(int arr[], int n) {
    int k, pos, temp;
    for(k = 0; k < n - 1; k++) {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}
