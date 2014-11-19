#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int cnt = 0;
    for(double n = 5;;n++){
        double k = (int)((sqrt(8 * n * n + 1) - (1 + 2 * n)) / 2);
        if((2 * n + k + 1) * k == n * n - n){
            cnt++;
            cout << ((int)n) << " " << ((int)k) << endl;
            if(cnt == 10)
                break;
        }
    }
    return 0;
}
