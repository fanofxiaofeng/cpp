#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int gcd(int, int);

void f(const int, vector<char> &, vector<bool> &, vector<char> &);

int main(){
    string s;
    while(cin >> s){
        vector<char> cvec;
        for(int i = 0;i < s.size();i++)
            cvec.push_back(s[i]);

        vector<char> result;
        vector<bool> occupied(cvec.size(), false);

        f(0, cvec, occupied, result);
        cout << endl;
    }

    return 0;
}

void f(const int k, vector<char> &cvec, vector<bool> &occupied, vector<char> &result){
    if(k == cvec.size()){
        for(int i = 0;i < result.size();i++)
            putchar(result[i]);
        putchar('\n');
        return;
    }

    for(int i = 0;i < occupied.size();i++){
        if(occupied[i] == false){
            occupied[i] = true;
            result.push_back(cvec[i]);

            f(k + 1, cvec, occupied, result);

            result.pop_back();
            occupied[i] = false;
        }
    }
}
