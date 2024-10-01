#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxLEN 20

typedef struct {
    int x, y;
    char name[maxLEN + 1];
}Garage;

double calcDistance(Garage gar1, Garage gar2){
    return sqrt(pow(gar1.x - gar2.x, 2) + pow(gar1.y - gar2.y, 2));
}


int main(){
    int n;
    scanf("%d", &n);

    Garage garages[2*n];
    for(int i = 0; i < 2*n; i++){
        scanf("%d %d %s", &garages[i].x, &garages[i].y, garages[i].name);
    }

    return 0;
}