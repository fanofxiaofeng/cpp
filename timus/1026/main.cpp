#include <iostream>
#include <stdio.h>

using namespace std;

const int big = 5100;

int a[big];
int s[big];

void f(int);

int main(){
    int n;

    scanf("%d", &n);
    int temp;
    for(int i = 0;i < n;i++){
        scanf("%d", &temp);
        a[temp]++;
    }

    for(int i = 1;i < big;i++)
        s[i] = s[i - 1] + a[i];

    string str;
    cin >> str;

    int m;
    scanf("%d", &m);
    for(int i = 0;i < m;i++){
        scanf("%d", &temp);
        f(temp);
    }

    return 0;
}

void f(int n){
    // printf("query is: %d\n", n);
    for(int i = 1;;i++){
        if(s[i] >= n){
            printf("%d\n", i);
            return;
        }
    }
}
