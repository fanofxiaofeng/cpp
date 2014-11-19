#include <iostream>
#include <cstdio>

using namespace std;

const int big = 100;

int cnt[2][big];

int main(){
    for(int i = 0;i < 10;i++)
        cnt[0][i] = 1;

    for(int loop = 0;loop < 8;loop++){
        for(int i = 0;cnt[0][i] != 0;i++){
            for(int delta = 0;delta < 10;delta++)
                cnt[1][i + delta] += cnt[0][i];
        }

        for(int i = 0;cnt[1][i] != 0;i++)
            cnt[0][i] = cnt[1][i];

        for(int i = 0;cnt[1][i] != 0;i++)
            cnt[1][i] = 0;
    }

    cnt[0][0]--;// 0 not inclueded
    cnt[0][1]++;// 1,000,000,000 included

    int query;
    while(cin >> query)
        cout << cnt[0][query] << endl;

    return 0;
}
