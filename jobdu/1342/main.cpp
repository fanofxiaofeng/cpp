#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int process(string &);

int main(){
    string s;

    while(cin >> s){
        cout << process(s) << endl;
    }

    return 0;
}

int process(string &s){
    int opt = 0;
    int cntLeft = 0;// counter of '('
    // int cntRight = 0;// counter of ')'

    for(int i = 0;i < s.size();i++){
        if(s[i] == '('){
            cntLeft++;
        }else{// s[i] == ')'
            // cntRight++;
            if(cntLeft > opt)
                opt++;
        }
    }
    return opt * 2;
}
