#include <stdio.h>

int sumEvenValues(int* values, int k) {
    // Base case: if k is 0, return 0
    if (k == 0) {
        return 0;
    }
    
    int currentValue = 0; // Initialize currentValue to 0

    // Check if the last element (at index k-1) is even
    if (values[k - 1] % 2 == 0) {
        currentValue += values[k - 1];
    }

    // Recursive call for the rest of the array
    return currentValue + sumEvenValues(values, k - 1);
}




int main() {
    int values[] = {3, 5, 2, 9, 4, 8, 7};
    int k = 5;
    
    int result = sumEvenValues(values, k);
    printf("Sum of even values: %d\n", result); // Output should be 6

    return 0;
}