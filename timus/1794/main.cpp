#include <stdio.h>

const int big = 100010;

int a[big];

int main(){
    int n;
    scanf("%d", &n);
    int temp;
    int opt = 0;
    int pos = -1;
    for(int i = 1;i <= n;i++){
        scanf("%d", &temp);
        int start = -1;
        if(i >= temp)
            start = i - (temp - 1);
        else
            start = (i + n) - (temp - 1);
        // printf("start: %d\n", start);
        if(++a[start] > opt){
            pos = start;
            opt = a[start];
        }
    }

    printf("%d\n", pos);

    return 0;
}
