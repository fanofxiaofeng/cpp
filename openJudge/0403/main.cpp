#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char s[1001000];
char t[1001000];

string f(void);

int main(){
    while(scanf("%s %s", s, t) == 2)
        cout << f() << endl;

    return 0;
}

string f(void){
    int sLen = strlen(s);
    int tLen = strlen(t);
    int pos = 0;
    for(int i = 0;i < sLen;i++){
        char c = s[i];
        bool found = false;
        for(int j = pos;j < tLen;j++){
            if(t[j] == c){
                found = true;
                pos = j + 1;
                break;
            }
        }
        if(!found)
            return "No";
    }
    return "Yes";
}
