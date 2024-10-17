#include <stdio.h> 

void quickSort(int arr[], int low, int high); 
int partition(int arr[], int low, int high); 
void mergeSort(int arr[], int left, int right); 
void merge(int arr[], int left, int mid, int right); 
void printArray(int arr[], int size);

void menu() { 
    int choice, n, arr[100]; // Ensure array size is within limit
    do { 
        printf("\nMenu:\n"); 
        printf("1. Quick Sort\n"); 
        printf("2. Merge Sort\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter the number of elements (<= 100): "); 
                scanf("%d", &n); 
                if (n > 100) {
                    printf("Array size exceeds the limit of 100. Try again.\n");
                    break;
                }
                printf("Enter the elements: "); 
                for (int i = 0; i < n; i++) 
                    scanf("%d", &arr[i]); 
                quickSort(arr, 0, n - 1);
                printf("Sorted array using Quick Sort: "); 
                printArray(arr, n); 
                break; 
            case 2: 
                printf("Enter the number of elements (<= 100): "); 
                scanf("%d", &n); 
                if (n > 100) {
                    printf("Array size exceeds the limit of 100. Try again.\n");
                    break;
                }
                printf("Enter the elements: "); 
                for (int i = 0; i < n; i++) 
                    scanf("%d", &arr[i]); 
                mergeSort(arr, 0, n - 1); 
                printf("Sorted array using Merge Sort: "); 
                printArray(arr, n); 
                break; 
            case 3: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 3); 
} 

void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j < high; j++) { 
        if (arr[j] <= pivot) { 
            i++;
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
    } 
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp; 
    return (i + 1); 
}

void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    } 
}

void merge(int arr[], int left, int mid, int right) { 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int L[n1], R[n2]; 
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() { 
    menu(); 
    return 0; 
}