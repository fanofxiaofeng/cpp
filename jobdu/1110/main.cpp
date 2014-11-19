#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int big = 110;

int main(){
    int n;
    while(cin >> n){
        vector<string> svec(big);
        int pos;
        string s;
        for(int i = 0;i < n;i++){
            cin >> pos;
            cin >> s;
            svec[pos] = s;
        }

        for(vector<string>::reverse_iterator rit = svec.rbegin();rit != svec.rend();rit++){
            if((*rit).size() != 0)
                cout << (*rit) << endl;
        }

    }

    return 0;
}
