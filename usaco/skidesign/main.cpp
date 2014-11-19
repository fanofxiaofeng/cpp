/*
ID: jyjz2001
TASK: skidesign
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cstdio>
#include <algorithm>

using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

int main(){
    int n;

    fin >> n;

    vector<int> ivec(n);
    map<int, int> imap;

    int low = 100;
    int high = 0;

    for(int i = 0;i < n;i++){
        fin >> ivec[i];
        imap[ivec[i]]++;
        if(ivec[i] < low)
            low = ivec[i];
        if(ivec[i] > high)
            high = ivec[i];
    }

    int opt = 10000 * 10000;
    for(int i = low;i <= high;i++){
        int total = 0;
        for(map<int, int>::iterator it = imap.begin();it != imap.end();it++){
            if(it->first <= i){
                total += (i - it->first) * (i - it->first) * (it->second);
            } else if(it->first - i > 17){
                total += (it->first - 17 - i) * (it->first - 17 - i) * (it->second);
            }
        }
        if(total < opt){
            opt = total;
        }
    }

    fout << opt << endl;
    /*
    for(map<int, int>::iterator it = imap.begin();it != imap.end();it++){
        if(it->second != 0){
            cout << (it->first) << " " << (it->second) << endl;
        }
    }
    */
    fin.close();
    fout.close();


    return 0;
}
