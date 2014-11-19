#include <iostream>
#include <cstdio>

using namespace std;

const int big = 1001000;

int v1[big];
int v2[big];

int v3[big * 2];

int f(const int, const int);

int main(){
    int s1;
    int s2;
    while(cin >> s1){
        for(int i = 0;i < s1;i++)
            scanf("%d", &v1[i]);

        cin >> s2;
        for(int i = 0;i < s2;i++)
            scanf("%d", &v2[i]);

        cout << f(s1, s2) << endl;
    }

    return 0;
}

int f(const int s1, const int s2){
    int p1 = 0;
    int p2 = 0;
    int total = s1 + s2;
    for(int i = 0;i < total;i++){
        if(p1 == s1){
            v3[i] = v2[p2++];
        } else if(p2 == s2) {
            v3[i] = v1[p1++];
        } else if(v1[p1] <= v2[p2]) {
            v3[i] = v1[p1++];
        } else {
            v3[i] = v2[p2++];
        }
    }
    return v3[(total - 1)/ 2];
}
