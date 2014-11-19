#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        for(string::iterator it = s.begin();it != s.end();it++){
            char c = *it;

            if(c != ' ')
                putchar(c);
            else
                printf("%%20");
        }
        putchar('\n');
    }

    return 0;
}
