#include <stdio.h>

void ListPermutations(char str[]);
void RecursivePermute(char strp[], int k);
void ExchangeCharacters(char str[], int i, int k);

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

void RecursivePermute(char str[], int k){
    int j;
    /*Base Case*/
    if(k == strlen(str)){
        printf("%s\n", str);
    } else {
        for(j = k; j < strlen(str); j++){
            /*Place char stored in index j in location k*/
            ExchangeCharacters(str, k, j);
            /*Print out all permutations with that character*/
            RecursivePermute(str, k+1);
            /*Put the original character back in its place*/
            ExchangeCharacters(str, j, k);
        }
    }
}

void ExchangeCharacters(char str[], int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

