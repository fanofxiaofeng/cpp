#include <iostream>
#include <cstdio>

using namespace std;

int getValue(string &);

int main(){
    while(true){
        string s;
        int a = 0;
        int b = 0;

        cin >> s;
        a = getValue(s);

        cin >> s;
        if(getValue(s) != -1){
            int temp = getValue(s);
            a = 10 * a + temp;
            cin >> s;// "+"
            // printf("The value of a: %d\n", a);
        }

        cin >> s;
        b = getValue(s);

        cin >> s;
        if(getValue(s) != -1){
            int temp = getValue(s);
            b = 10 * b + temp;
            cin >> s;// "="
        }

        if(a + b == 0)
            break;

        cout << (a + b) << endl;
    }

    return 0;
}

int getValue(string &s){
    if(s[0] == 'z')
        return 0;
    else if(s[0] == 'o')
        return 1;
    else if(s == "two")
        return 2;
    else if(s == "three")
        return 3;
    else if(s == "four")
        return 4;
    else if(s == "five")
        return 5;
    else if(s == "six")
        return 6;
    else if(s == "seven")
        return 7;
    else if(s == "eight")
        return 8;
    else if(s == "nine")
        return 9;
    else// "+" or "="
        return -1;
}
