#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

string process(int, int, int);

int main(){
    int a;
    int b;
    int c;
    while(cin >> a >> b >> c){
        cout << process(a, b, c) << endl;
    }

    return 0;
}

string process(int a, int b, int c){
    vector<int> ivec;
    ivec.push_back(a);
    ivec.push_back(b);
    ivec.push_back(c);
    sort(ivec.begin(), ivec.end());
    int result = ivec[0] * ivec[0] + ivec[1] * ivec[1] - ivec[2] * ivec[2];
    if(result > 0)
        return "锐角三角形";
    if(result == 0)
        return "直角三角形";
    if(result < 0)
        return "钝角三角形";
}
