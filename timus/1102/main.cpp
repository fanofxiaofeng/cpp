/*
 * File:   main.cpp
 * Author: jinyang
 *
 * Created on 2014年8月20日, 下午 8:03
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

void process(string &);
bool safeCheck(string &, int, char);

/*
 *
 */
int main(int argc, char** argv) {
    int rubbish;
    cin >> rubbish;

    string s;
    while(cin >> s)
        process(s);

    return 0;
}

bool safeCheck(string &s, int a, char c){
    if(a < 0)
        return false;
    return s[a] == c;
}

void process(string &s){
    bool ok = true;
    int cur = s.length() - 1;
    while(cur >= 0){
        char c = s[cur];
        if(c == 'e'){
            if(safeCheck(s, cur - 1, 'n') && safeCheck(s, cur - 2, 'o')){// one
                cur -= 3;
            } else {// ??e
                ok = false;
                break;
            }
        } else if(c == 'n'){
            if(safeCheck(s, cur - 1, 'i')){// in
                cur -= 2;
            } else if(safeCheck(s, cur - 1, 'o')){
                if(safeCheck(s, cur - 2, 't') && safeCheck(s, cur - 3, 'u') && safeCheck(s, cur - 4, 'p')){// puton
                    cur -= 5;
                } else {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }
        } else if(c == 't'){
            if(!safeCheck(s, cur - 1, 'u')){
                ok = false;
                break;
            }
            if(safeCheck(s, cur - 2, 'o')){// out
                cur -= 3;
            } else if(safeCheck(s, cur - 2, 'p')){
                if(safeCheck(s, cur - 3, 't')){
                    if(safeCheck(s, cur - 4, 'u') && safeCheck(s, cur - 5, 'o')){// output
                        cur -= 6;
                    } else {
                        ok = false;
                        break;
                    }
                } else if(safeCheck(s, cur - 3, 'n')){
                    if(safeCheck(s, cur - 4, 'i')){// input
                        cur -= 5;
                    } else {
                        ok = false;
                        break;
                    }
                } else {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }
        } else {
            ok = false;
            break;
        }
    }

    if(ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

