#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int cnt[100];

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0)
            break;
        memset(cnt, 0, sizeof(cnt));
        int temp;
        for(int i = 0;i < n;i++){
            scanf("%d", &temp);
            cnt[temp]++;
        }
        int total = 0;
        for(int i = 0;i < 100;i++){

            if(cnt[i] != 0){
                if(total != 0)
                    printf(" %d", i);
                else
                    printf("%d", i);
                total++;
                cnt[i]--;
                i--;
            }
            if(total == n)
                break;
        }
        putchar('\n');
    }
    return 0;
}
