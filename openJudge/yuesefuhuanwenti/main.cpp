#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node{
    int pre;
    int next;
    int value;
};

const int big = 320;

struct node a[big];

void init(int);

int main(){
    int n;
    int m;
    cin >> n >> m;
    init(n);
    int current = n;
    int numel = n;
    while(numel != 1){
        int cnt = m % numel;
        for(int j = 0;j < cnt;j++){
            current = a[current].next;
        }
        // printf("current is: %d\n", current);
        a[a[current].pre].next = a[current].next;
        a[a[current].next].pre = a[current].pre;
        numel -= 1;
        current = a[current].pre;
    }
    cout << a[current].value << endl;

    return 0;
}

void init(int n){
    for(int i = 1;i <= n;i++){
        a[i].value = i;
        a[i].next = (i == n)?(1):(i + 1);
        a[i].pre = (i == 1)?(n):(i - 1);
    }
}
