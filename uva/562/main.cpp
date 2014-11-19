#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i = 0;i < n;i++){

        int m;
        cin >> m;

        vector<int> ivec;
        for(int j = 0;j < m;j++){
            int temp;
            cin >> temp;

            ivec.push_back(temp);
        }

        set<int> iset[2];
        iset[0].insert(0);

        for(int j = 0;j < m;j++){
            int cur = ivec[j];
            int loop = j % 2;
            for(set<int>::iterator it = iset[loop].begin();it != iset[loop].end();it++){
                int value = *it;
                iset[1 - loop].insert(value + cur);
                iset[1 - loop].insert((cur - value >= 0)?(cur - value):(value - cur));
            }
            iset[loop].clear();
        }
        cout << (*(iset[m % 2].begin())) << endl;
    }

    return 0;
}
