#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int big = 15;

int matrix[big][big];

void init(void);

int main(){
    init();
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int apple;
        int plate;
        cin >> apple >> plate;
        cout << matrix[apple][plate] << endl;
    }
    return 0;
}

void init(void){

    for(int apple = 0;apple <= 10;apple++){
        for(int plate = 1;plate <= 10;plate++){
            if(plate == 1 || apple == 1){
                matrix[apple][plate] = 1;
            } else {
                int sum = 0;
                for(int firstPlateCnt = 0;;firstPlateCnt++){
                    int remainApple = apple - plate * firstPlateCnt;
                    if(remainApple >= 0)
                        sum += matrix[remainApple][plate - 1];
                    else
                        break;
                }
                matrix[apple][plate] = sum;
            }
        }
    }
}
