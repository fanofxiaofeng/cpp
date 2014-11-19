#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool ok[10010];

int process(int);

int main(){
    int n;

    while(cin >> n)
        cout << process(n) << endl;

    return 0;
}

int process(int n){

    vector<int> ivec;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        ivec.push_back(temp);
    }

    sort(ivec.begin(), ivec.end());

    ok[0] = true;
    int preMost = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= preMost;j++){
            if(ok[j])
                ok[j + ivec[i]] = true;
        }
        preMost += ivec[i];
    }

    int missing;
    for(missing = 1;ok[missing];missing++)
        ;

    // 收尾的清理工作
    for(int i = 0;i <= preMost;i++)
        ok[i] = false;

    return missing;
}
