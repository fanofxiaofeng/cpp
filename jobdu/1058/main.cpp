#include <iostream>
#include <cstdio>

using namespace std;

char cs[5];

int main(){
    while(scanf("%s", cs) > 0){
        swap(cs[0], cs[3]);
        swap(cs[1], cs[2]);
        printf("%s\n", cs);
    }

    return 0;
}
