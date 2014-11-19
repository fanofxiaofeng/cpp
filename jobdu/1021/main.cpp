#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    string target;
    string line;
    while(true){
        getline(cin, target);
        if(target == "#")
            break;
        getline(cin, line);
        // cout << target << endl;
        // cout << line << endl;
        vector<int> cnt(target.size());
        for(string::iterator it = line.begin();it != line.end();it++){
            for(string::iterator inner = target.begin();inner != target.end();inner++){
                if(*inner == *it){
                    cnt[inner - target.begin()]++;
                    break;
                }
            }
        }
        for(string::iterator it = target.begin();it != target.end();it++){
            cout << (*it) << " " << cnt[it - target.begin()] << endl;
        }
    }

    return 0;
}


