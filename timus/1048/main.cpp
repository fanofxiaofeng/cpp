#include <stdio.h>

int a[2][1010000];
char c[1010000];

int main(){
    int n;

    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d %d", &a[0][i], &a[1][i]);

    int carry = 0;
    int sum = 0;
    for(int i = n;i >= 0;i--){
        a[0][i] += carry + a[1][i];
        carry = (a[0][i] >= 10);
        if(a[0][i] >= 10)
            a[0][i] -= 10;
        c[i] = a[0][i] + '0';
    }

    if(a[0][0] != 0)
        printf("%s\n", c);
    else
        printf("%s\n", c + 1);

    return 0;
}
