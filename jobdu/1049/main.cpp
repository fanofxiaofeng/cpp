#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    char c;
    while(cin >> s >> c){
        for(string::iterator it = s.begin();it != s.end();it++){
            if(*it == c)
                continue;
            putchar(*it);
        }
        cout << endl;
    }

    return 0;
}
