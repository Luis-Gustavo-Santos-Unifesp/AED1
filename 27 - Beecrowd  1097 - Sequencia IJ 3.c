#include <stdio.h>

int main() {
    int i, j, k, l;
    k = 7;
    l = 5;
    for(i=1;i<=9;i+=2){
        for(j=k;j>=l;j--){
            printf("I=%d J=%d\n", i, j);
        }
        k+=2;
        l+=2;
    }
    return 0;
}