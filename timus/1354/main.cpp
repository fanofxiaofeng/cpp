#include <iostream>
#include <cstdio>

using namespace std;

const int big = 21000;

char cs[big];// chars
int r[big];// radius

void process(string &);

int main(){
    string s;
    while(cin >> s)
        process(s);

    return 0;
}

void process(string &s){
    cs[0] = '^';
    cs[2 * s.length() + 2] = '$';
    for(int i = 0;i < s.length();i++)
        cs[2 * i + 2] = s[i];

    int rightMostReached = 0;
    int withPos = 0;
    for(int i = 1;i < 2 * s.length() + 2;i++){
        int temp;
        if(i <= rightMostReached)
            temp = min(rightMostReached - i + 1, r[2 * withPos - i]);
        else
            temp = 1;

        while(cs[i + temp] == cs[i - temp])
            temp++;

        r[i] = temp;

        if(i + r[i] - 1 > rightMostReached){
            rightMostReached = i + r[i] - 1;
            withPos = i;
        }
    }

    int record = -1;
    for(int i = s.length() + 1 + 1;;i++){
        if(i + r[i] - 1 == 2 * s.length() + 1){
            record = i;
            break;
        }
    }

    for(int i = 1;i <= record;i++){
        if(cs[i] != '\0')
            putchar(cs[i]);
    }
    for(int i = record - 1;i >= 1;i--){
        if(cs[i] != '\0')
            putchar(cs[i]);
    }
    putchar('\n');
}
