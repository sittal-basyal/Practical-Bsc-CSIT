#include <stdio.h>

int main() {
    int arr[100], n, i, index, element;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the index where you want to insert (0 to %d): ", n);
    scanf("%d", &index);

    if(index < 0 || index > n) {
        printf("Invalid index!\n");
        return 0;
    }

    // Shift elements to the right
    for(i = n; i > index; i--) {
        arr[i] = arr[i-1];
    }

    // Insert the new element
    arr[index] = element;
    n++;  // Increase array size

    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}