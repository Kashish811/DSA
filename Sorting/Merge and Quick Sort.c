#include <stdio.h> 
 
// Swap two integers 
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
// Partition using given pivot index 
int partition(int arr[], int low, int high, int pivot_index) { 
    swap(&arr[low], &arr[pivot_index]);  
    int pivot = arr[low]; 
    int i = low, j = high; 
 
    while (i <= j) { 
        while (i <= j && arr[j] > pivot) { 
            j--; 
        } 
        while (i <= j && arr[i] < pivot) { 
            i++; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
            i++; 
            j--; 
        } else { 
            break; 
        } 
    } 
    swap(&arr[low], &arr[j]); 
    return j; 
} 
 
// Quick Sort  
void quick_sort(int arr[], int low, int high, int pivot_index) { 
    if (low < high) { 
        int pivotPos = partition(arr, low, high, pivot_index); 
        quick_sort(arr, low, pivotPos - 1, low); 
        quick_sort(arr, pivotPos + 1, high, pivotPos + 1); 
    } 
} 
 
// Merge two sorted halves 
void merge(int arr[], int l, int m, int r) { 
    int n1 = m - l + 1, n2 = r - m; 
    int L[n1], R[n2]; 
    int i, j, k; 
 
    for (i = 0; i < n1; i++) { 
        L[i] = arr[l + i]; 
    } 
    for (j = 0; j < n2; j++) { 
        R[j] = arr[m + 1 + j]; 
    } 
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k++] = L[i++]; 
        } else { 
            arr[k++] = R[j++]; 
        } 
    } 
    while (i < n1) { 
        arr[k++] = L[i++]; 
    } 
    while (j < n2) { 
        arr[k++] = R[j++]; 
    } 
} 
 
// Merge Sort 
void merge_sort(int arr[], int l, int r) { 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        merge_sort(arr, l, m); 
        merge_sort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
 
// Print array 
void print_array(int arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
int main() { 
    int n, choice, pivot_choice, pivot_index; 
    char res; 
    int i; 
 
    do { 
        printf("Enter number of elements: "); 
        scanf("%d", &n); 
 
        int arr[n]; 
        for (i = 0; i < n; i++) { 
            printf("Enter element %d: ", i + 1); 
            scanf("%d", &arr[i]); 
        } 
 
        printf("\nChoose sorting algorithm:\n1. Quick Sort\n2. Merge Sort\nEnter choice: 
"); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1:  
   { 
                printf("\nChoose pivot type:\n1. First\n2. Last\n3. Middle\nEnter choice: 
"); 
                scanf("%d", &pivot_choice); 
 
                switch (pivot_choice)  
    { 
                    case 1: 
                        pivot_index = 0; 
           break; 
                    case 2: 
     pivot_index = n - 1; 
     break; 
                    case 3: 
     pivot_index = n / 2; 
     break; 
                    default:  
     printf("Invalid pivot choice.\n");  
                } 
 
                printf("Unsorted Array:\n"); 
                print_array(arr, n); 
                printf("Pivot element: %d\n", arr[pivot_index]); 
 
                quick_sort(arr, 0, n - 1, pivot_index); 
 
                printf("Sorted array (Quick Sort):\n"); 
                print_array(arr, n); 
                break; 
            } 
 
            case 2:  
   { 
                printf("Unsorted Array:\n"); 
                print_array(arr, n); 
 
                merge_sort(arr, 0, n - 1); 
 
                printf("Sorted array (Merge Sort):\n"); 
                print_array(arr, n); 
                break; 
            } 
 
            default: 
                printf("Invalid choice.\n"); 
        } 
 
        printf("Continue? (y/n): "); 
        scanf(" %c", &res); 
    } while (res == 'y' || res == 'Y'); 
 
    return 0; 
} 

