#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        for(int x = 0;15 * x <= 3 * n;x++){
            for(int y = 0;9 * y <= 3 * n;y++){
                if(100 - x - y >= 0){
                    int z = 100 - x - y;
                    if(3 * n >= 15 * x + 9 * y + z){
                        printf("x=%d,y=%d,z=%d\n", x, y, z);
                    }
                }
            }
        }
        // cout << "over" << endl;
    }
    return 0;
}
