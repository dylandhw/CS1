#include <stdio.h>

void ListPermutations(char str[]);
void RecursivePermute(char strp[], int k);
voide ExchangeCharacters(char str[], int i, int k);

int main(){
    char word[20];
    printf("<<<Enter Word>>>\n");
    scanf("%s", word);
    /*Print out permutations*/
    printf("<<<Permutations>>>\n");
    ListPermutations(word);
    system("<<<PAUSE>>>\n");
    return 0;
}

void ListPermutations(char str[]){
    RecursivePermute(str, 0);
}