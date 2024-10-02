#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindromeRecursive(char str[], int start, int end) {
    if (start >= end) { /*If only one character left return true */
        return true;
    }

    if (str[start] != str[end]) {
        return false;  // Not a palindrome
    }

    return isPalindromeRecursive(str, start + 1, end - 1); /*start+1 & end+1 to go 
    through each char, then compare them using the two if statements*/
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    if (isPalindromeRecursive(str, 0, len - 1)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    return 0;
}
