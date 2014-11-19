/*
ID: jyjz2001
TASK: combo
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");

bool valid(int, int, int);

int main(){
    int n;

    fin >> n;

    vector<int> ivec[2];

    for(int loop = 0;loop < 2;loop++){
        for(int i = 0;i < 3;i++){
            int temp;
            fin >> temp;
            ivec[loop].push_back(temp - 1);
        }
    }

    vector<int> guess(3);
    int cnt = 0;
    for(guess[0] = 0;guess[0] < n;guess[0]++){
        for(guess[1] = 0;guess[1] < n;guess[1]++){
            for(guess[2] = 0;guess[2] < n;guess[2]++){
                // 符合第一个
                bool judge = true;
                for(int pos = 0;pos < 3;pos++){
                    if(!valid(guess[pos], ivec[0][pos], n)){
                        judge = false;
                        break;
                    }
                }
                if(judge){
                    cnt++;
                    continue;
                }
                // 符合第二个
                judge = true;
                for(int pos = 0;pos < 3;pos++){
                    if(!valid(guess[pos], ivec[1][pos], n)){
                        judge = false;
                        break;
                    }
                }
                if(judge)
                    cnt++;
            }
        }
    }
    fout << cnt << endl;

    fin.close();
    fout.close();

    return 0;
}

bool valid(int a, int b, int n){
    return (a == b || (a + 1) % n == b || (a + 2) % n == b || a == (b + 1) % n || a == (b + 2) % n);
}
