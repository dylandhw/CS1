#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate permutations
void permute(char *s, int l, int r) {
   int i;
   if (l == r) {
     // Base case: when all characters have been swapped, print the result
     printf("%s\n", s);
   } else {
       for (i = l; i <= r; i++) {
          // Swap the current character with the starting character
          swap(&s[l], &s[i]);
          
          // Recursively permute the remaining part of the string
          permute(s, l + 1, r);
          
          // Swap back to restore the original string (backtracking)
          swap(&s[l], &s[i]);
       }
   }
}

int main() {
    char str[] = "CAT";  // Example string
    int n = strlen(str); // Get the length of the string
    permute(str, 0, n-1); // Call the permutation function
    return 0;
}
