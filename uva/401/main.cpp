#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<char, char> cmap;

void init(void);
bool isPalindrome(string &);
bool isMirror(string &);

int main(){
    init();
    string str;
    while(cin >> str){
        bool judge1 = isPalindrome(str);
        bool judge2 = isMirror(str);
        if(judge1 && judge2)
            cout << str << " -- is a mirrored palindrome." << endl;
        else if(judge1)
            cout << str << " -- is a regular palindrome." << endl;
        else if(judge2)
            cout << str << " -- is a mirrored string." << endl;
        else
            cout << str << " -- is not a palindrome." << endl;
        cout << endl;
    }

    return 0;
}

bool isPalindrome(string &str){
    int len = str.size();
    int low = 0;
    int high = len - 1;
    while(low <= high){
        if(str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

bool isMirror(string &str){
    int len = str.size();
    int low = 0;
    int high = len - 1;
    while(low <= high){
        if(cmap.count(str[low]) == 0 || cmap[str[low]] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void init(void){
    cmap['A'] = 'A';
    cmap['E'] = '3';
    cmap['H'] = 'H';
    cmap['I'] = 'I';
    cmap['J'] = 'L';
    cmap['L'] = 'J';
    cmap['M'] = 'M';
    cmap['O'] = 'O';
    cmap['S'] = '2';
    cmap['T'] = 'T';
    cmap['U'] = 'U';
    cmap['V'] = 'V';
    cmap['W'] = 'W';
    cmap['X'] = 'X';
    cmap['Y'] = 'Y';
    cmap['Z'] = '5';
    cmap['1'] = '1';
    cmap['2'] = 'S';
    cmap['3'] = 'E';
    cmap['5'] = 'Z';
    cmap['8'] = '8';
}
