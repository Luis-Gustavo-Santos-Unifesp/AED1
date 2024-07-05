#include <stdio.h>
#include <math.h>

int main() {
    float i, j, k, l;
    k = 1;
    l = 3.01;
    for(i=0;i<=2.01;i+=0.2){
        for(j=k;j<=l;j++){
            if (fabs(i - (int)i) < 0.00001){
                printf("I=%.0f J=%.0f\n", i, j);
            } else {
                printf("I=%.1f J=%.1f\n", i, j);
            }
        }
        k+=0.2;
        l+=0.2;
    }
    return 0;
}