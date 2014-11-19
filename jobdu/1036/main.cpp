#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;

    while(cin >> n){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        int mid = 100 * x + 10 * y + z;
        for(int a = 9;a >= 0;a--){
            for(int b = 9;b >= 0;b--){
                if((a * 10000 + 10 * mid + b) % n == 0){
                    cout << a  << " " << b << " " << ((a * 10000 + 10 * mid + b) / n) << endl;
                    goto out;
                }
            }
        }
        cout << "0" << endl;
        continue;

        out:
            ;
    }

    return 0;
}
