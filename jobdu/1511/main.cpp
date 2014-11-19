#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){

    vector<int> ivec;
    while(true){
        int temp;
        scanf("%d", &temp);
        if(temp == -1)
            break;

        ivec.push_back(temp);
    }
    for(int i = ivec.size() - 1;i >= 0;i--)
        printf("%d\n", ivec[i]);


    return 0;
}
