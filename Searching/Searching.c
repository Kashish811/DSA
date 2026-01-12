#include <stdio.h>  
int binarySearch(int arr[], int n, int key);

// Linear Search Function
int linearSearch(int arr[], int n, int key) {
	int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("The element %d is found at index %d of the given array.\n", key, i);
            return 1;
        }
    }
    return 0;
}

// Binary Search Function (for sorted arrays)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(key == arr[mid]) {
            printf("The element %d is found at index %d of the given array.\n", key, mid);
            return 1;
        }
        if(key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

int main() {
    int n, i, key, choice, result = 0;

    // Input array size and elements
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the %d array elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter the element to be searched (key): ");
    scanf("%d", &key);

    printf("Choose a search algorithm (1/2):\n");
    printf("1) Linear Search\n");
    printf("2) Binary Search\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have entered Linear Search Algorithm!\n");
            result = linearSearch(arr, n, key);
            if(result == 0) {
                printf("The element %d was NOT found in the given array.\n", key);
            }
            break;

        case 2:
            printf("You have entered Binary Search Algorithm!\n");
            result = binarySearch(arr, n, key);
            if(result == 0) {
                printf("The element %d was NOT found in the given array.\n", key);
            }
            break;

        default:
            printf("Please enter a valid choice.\n");
    }

    return 0;
}
