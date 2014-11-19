#include <stdio.h>

using namespace std;

int a[10100];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);

    for(int i = 1;i < n;i++)
        a[i] += a[i - 1];

    int k;
    scanf("%d", &k);
    int s;
    int e;
    for(int i = 0;i < k;i++){
        scanf("%d %d", &s, &e);
        s--;
        e--;
        if(s < 0)
            s = 0;
        if(e >= n)
            e = n - 1;
        if(s == 0)
            printf("%d\n", a[e]);
        else
            printf("%d\n", (a[e] - a[s - 1]));
    }

    return 0;
}

