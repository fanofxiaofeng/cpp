#include <iostream>
#include <cstdio>

using namespace std;

const int big = 20;

char c[big];

void f(const int, const int, const int, const int);

int main(){
    int k;
    cin >> k;

    int n;
    int h;
    for(int i = 0;i < k;i++){
        cin >> n >> h;
        c[n] = '\0';
        for(int j = 0;j < n;j++)
            c[j] = '0';
        f(0, n, 0, h);
        if(i + 1 != k)
            cout << endl;
    }

    return 0;
}

void f(const int pos, const int bound, const int cur, const int target){
    if(pos == bound){
        if(cur == target)
            printf("%s\n", c);
        return;
    }

    // pos < bound
    c[pos] = '0';
    f(pos + 1, bound, cur, target);

    c[pos] = '1';
    f(pos + 1, bound, cur + 1, target);
}
