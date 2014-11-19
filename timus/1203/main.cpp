#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int big = 30100;

int record[big];
int opt[big];

int main(){
    int n;
    scanf("%d", &n);

    int last_minute = -1;
    for(int i = 0;i < n;i++){
        int ts;
        int te;
        scanf("%d %d", &ts, &te);

        if(te >= last_minute)
            last_minute = te;

        if(record[te] < ts)
            record[te] = ts;
    }

    for(int i = 1;i <= last_minute;i++){
        if(record[i] == 0)
            opt[i] = opt[i - 1];
        else {// record[i] > 0
            int temp = opt[record[i] - 1] + 1;
            opt[i] = (opt[i - 1] >= temp)?opt[i - 1]:temp;
        }
    }

    printf("%d\n", opt[last_minute]);

    return 0;
}
