//
// Created by danie on 14.06.2023.
//

#include <stdio.h>

struct card {
    int face;
    int shape;
    int color;
};

int main(){
    struct card deck[52] = {{1,0,0},{0,1,0},{0,0,1}};
    struct card singleCard = {1,1,1};
    singleCard.face = 25;

    for(int i = 0; i < 52; i++){
        printf("%d, ", deck[i].face);
        printf("%d, ", deck[i].shape);
        printf("%d\n", deck[i].color);
    }


    printf("%d, ", singleCard.face);
    printf("%d, ", singleCard.shape);
    printf("%d", singleCard.color);
    return 0;
}