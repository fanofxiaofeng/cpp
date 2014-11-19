#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ivec(n);
    for(int i = 0;i < n;i++){
        cin >> ivec[i];
    }

    vector<int> opt(ivec);
    for(int i = 1;i < n;i++){
        int temp = opt[i];
        for(int j = 0;j < i;j++){
            if(ivec[j] < ivec[i] && opt[j] + ivec[i] > temp){
                temp = opt[j] + ivec[i];
            }
        }
        opt[i] = temp;
    }

    for(int i = 1;i < n;i++){

        opt[i] = max(opt[i - 1], opt[i]);
    }
    cout << opt[n - 1] << endl;

    return 0;
}
