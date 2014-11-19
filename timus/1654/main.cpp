#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<char> cvec;
    for(int i = 0;i < str.size();i++){
        char c = str[i];
        if(cvec.size() > 0 && cvec[cvec.size() - 1] == c)
            cvec.pop_back();
        else
            cvec.push_back(c);
    }
    for(vector<char>::iterator it = cvec.begin();it != cvec.end();it++)
        putchar(*it);
    printf("\n");

    return 0;
}
