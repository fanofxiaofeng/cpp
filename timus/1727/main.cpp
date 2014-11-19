#include <stdio.h>

const int big = 10100;

int a[big];

int sum_of_digits(int);
void process(int, int &);

int main(){
    int n;
    scanf("%d", &n);

    int pos = 0;
    for(int num = 99999;;num--){
        int sum = sum_of_digits(num);
        if(sum >= n)
            break;
        n -= sum;
        a[pos++] = num;
    }

    if(n != 0)
        process(n, pos);

    printf("%d\n%d", pos, a[0]);
    for(int i = 1;i < pos;i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}

void process(int remain, int &pos){
    if(remain >= 32){
        a[pos++] = 88880;
        remain -= 32;
    }
    if(remain >= 16){
        a[pos++] = 88000;
        remain -= 16;
    }
    for(int i = 8;i != 0;i /= 2){
        if(remain >= i){
            a[pos++] = i;
            remain -= i;
        }
    }
}

int sum_of_digits(int a){
    int s = 0;
    while(a != 0){
        s += a % 10;
        a /= 10;
    }
    return s;
}
