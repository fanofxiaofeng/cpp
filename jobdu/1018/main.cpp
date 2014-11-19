#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0)
            break;
        vector<int> ivec(n);
        for(int i = 0;i < n;i++)
            cin >> ivec[i];
        int target;
        cin >> target;
        int cnt = 0;
        for(vector<int>::iterator it = ivec.begin();it != ivec.end();it++){
            if(*it == target)
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}


