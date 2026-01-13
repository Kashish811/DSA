 
#include <stdio.h> 
#include <stdbool.h> 
 
//Bubble Sort  
void BubbleSort(int arr[], int n) { 
    bool swapped; 
    int i, j; 
    for (i = 0; i < n; i++) { 
        swapped = false; 
        for (j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                int temp; 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
                swapped = true; 
            } 
        } 
        if (!swapped) 
            break; 
    } 
} 
 
//Bubble Sort using pointers 
void BubbleSortPointer(int *arr, int n) { 
    bool swapped; 
    int i, j; 
    for (i = 0; i < n; i++) { 
        swapped = false; 
        for (j = 0; j < n - i - 1; j++) { 
            if (*(arr + j) > *(arr + j + 1)) { 
                int temp = *(arr + j); 
                *(arr + j) = *(arr + j + 1); 
                *(arr + j + 1) = temp; 
                swapped = true; 
            } 
        } 
        if (!swapped) 
            break; 
    } 
} 
 
//Selection Sort  
void SelectionSort(int arr[], int n) { 
    int i, j, min_index, temp; 
 
    for (i = 0; i < n - 1; i++) { 
        min_index = i; 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_index]) { 
                min_index = j; 
            } 
        } 
        if (min_index != i) { 
            temp = arr[min_index]; 
            arr[min_index] = arr[i]; 
            arr[i] = temp; 
        } 
    } 
} 
 
//Selection Sort using pointers 
void SelectionSortPointer(int *arr, int n) { 
    int i, j, min_index, temp; 
 
    for (i = 0; i < n - 1; i++) { 
        min_index = i; 
        for (j = i + 1; j < n; j++) { 
            if (*(arr + j) < *(arr + min_index)) { 
                min_index = j; 
            } 
        } 
        if (min_index != i) { 
            temp = *(arr + i); 
            *(arr + i) = *(arr + min_index); 
            *(arr + min_index) = temp; 
        } 
    } 
} 
 
//Insertion Sort  
void InsertionSort(int arr[], int n) { 
    int i, j, key; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
//Insertion Sort using pointers 
void InsertionSortPointer(int *arr, int n) { 
    int i, j, key; 
    for (i = 1; i < n; i++) { 
        key = *(arr + i); 
        j = i - 1; 
 
        while (j >= 0 && *(arr + j) > key) { 
            *(arr + j + 1) = *(arr + j); 
            j--; 
        } 
        *(arr + j + 1) = key; 
    } 
} 
 
//Print unsorted array (array-based) 
void PrintUnsorted(int arr[], int n) { 
 int i; 
    printf("UnSorted Array:\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
} 
 
//Print unsorted array (pointer-based) 
void PrintUnsortedPointer(int *arr, int n) { 
 int i; 
    printf("UnSorted Array:\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d ", *(arr + i)); 
    } 
} 
 
//Print sorted array (array-based) 
void PrintSorted(int arr[], int n) { 
 int i; 
    printf("\nSorted Array:\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
} 
 
//Print sorted array (pointer-based) 
void PrintSortedPointer(int *arr, int n) { 
 int i; 
    printf("\nSorted Array:\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d ", *(arr + i)); 
    } 
} 
 
int main() { 
    int n, i, choice; 
    char ans; 
 
    do { 
        printf("Enter the array size: "); 
        scanf("%d", &n); 
        int arr[n]; 
 
        printf("Enter %d array elements:\n", n); 
        for (i = 0; i < n; i++) { 
            printf("Enter element %d: ", i + 1); 
            scanf("%d", &arr[i]); 
        } 
 
        printf("Choose a Sorting Technique:"); 
        printf("\n1) Bubble Sort"); 
        printf("\n2) Bubble Sort Using Pointer"); 
        printf("\n3) Selection Sort"); 
        printf("\n4) Selection Sort Using Pointer"); 
        printf("\n5) Insertion Sort"); 
        printf("\n6) Insertion Sort Using Pointer"); 
        printf("\nEnter your choice (1-6): "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("You have entered Bubble Sort!\n"); 
                PrintUnsorted(arr, n); 
                BubbleSort(arr, n); 
                PrintSorted(arr, n); 
                break; 
 
            case 2: 
                printf("You have entered Bubble Sort using Pointers!\n"); 
                PrintUnsortedPointer(arr, n); 
                BubbleSortPointer(arr, n); 
                PrintSortedPointer(arr, n); 
                break; 
 
            case 3: 
                printf("You have entered Selection Sort!\n"); 
                PrintUnsorted(arr, n); 
                SelectionSort(arr, n); 
                PrintSorted(arr, n); 
                break; 
 
            case 4: 
                printf("You have entered Selection Sort using Pointers!\n"); 
                PrintUnsortedPointer(arr, n); 
                SelectionSortPointer(arr, n); 
                PrintSortedPointer(arr, n); 
                break; 
 
            case 5: 
                printf("You have entered Insertion Sort!\n"); 
                PrintUnsorted(arr, n); 
                InsertionSort(arr, n); 
                PrintSorted(arr, n); 
                break; 
 
            case 6: 
                printf("You have entered Insertion Sort using Pointers!\n"); 
                PrintUnsortedPointer(arr, n); 
                InsertionSortPointer(arr, n); 
                PrintSortedPointer(arr, n); 
                break; 
 
            default: 
                printf("Please enter a valid choice!"); 
                break; 
        } 
 
        printf("\nDo you want to continue? (y/n): "); 
        scanf(" %c", &ans); 
 
    } while (ans == 'y' || ans == 'Y'); 
 
    return 0; 
}
