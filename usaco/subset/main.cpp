/*
ID: jyjz2001
TASK: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>

using namespace std;

int main(){

    ifstream fin("subset.in");
    ofstream fout("subset.out");

    int n;
    fin >> n;
    map<int, long> imap[2];
    imap[1][1] = 1;
    for(int i = 2;i <= n;i++){
        imap[i % 2].clear();
        for(map<int, long>::iterator it = imap[1 - i % 2].begin();it != imap[1 - i % 2].end();it++){
            int delta = it->first;
            imap[i % 2][delta + i] += it->second;
            imap[i % 2][delta - i] += it->second;
        }
    }
    if(imap[n % 2].count(0) == 0)
        fout << "0" << endl;
    else
        fout << (imap[n % 2][0]) << endl;

    fin.close();
    fout.close();

    return 0;
}
