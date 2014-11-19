#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int main(){
    int n;
    while(cin >> n){
        int x;
        int y;
        cin >> x >> y;
        for(int i = 1;i < n;i++){
            int temp_x;
            int temp_y;
            cin >> temp_x >> temp_y;
            if(temp_x < x || (temp_x == x && temp_y < y)){
                x = temp_x;
                y = temp_y;
            }
        }
        cout << x << " " << y << endl;
    }

    return 0;
}
