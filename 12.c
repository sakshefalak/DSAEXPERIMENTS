#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50

int binary_search(char arr[MAX_STUDENTS][NAME_LENGTH], int size, char target[NAME_LENGTH]) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int comparison = strcmp(arr[mid], target);

        if (comparison == 0) {
            return mid;
        } else if (comparison < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    char students[MAX_STUDENTS][NAME_LENGTH] = {
        "Alice", "Bob", "Charlie", "David", "Eva",
        "Frank", "Grace", "Helen", "Isaac", "John"
    };

    char target[NAME_LENGTH];

    printf("Welcome to the Student Search System!\n");
    printf("Available students:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%s ", students[i]);
    }
    printf("\n");

    printf("Enter the name of the student you want to search for: ");
    fgets(target, NAME_LENGTH, stdin);
    target[strcspn(target, "\n")] = 0;

    int result = binary_search(students, MAX_STUDENTS, target);

    if (result != -1) {
        printf("%s is enrolled in the class at index %d.\n", target, result);
    } else {
        printf("%s is not found in the class.\n", target);
    }

    return 0;
}