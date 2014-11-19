/*
ID: jyjz2001
TASK: sprime
LANG: C++
*/
#include <iostream>
#include <deque>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

bool isPrime(const int);

int main(){
    deque<int> idq;// integer deque
    deque<int> ldq;// length deeque

    idq.push_back(2);
    idq.push_back(3);
    idq.push_back(5);
    idq.push_back(7);

    for(int i = 0;i < idq.size();i++)
        ldq.push_back(1);

    ifstream f("sprime.in");
    ofstream of("sprime.out");

    int width;
    f >> width;

    while(ldq[0] < width){
        int v = idq[0];// value
        int l = ldq[0];// length

        idq.pop_front();
        ldq.pop_front();

        for(int i = 1;i < 10;i += 2){// 1, 3, 5, 7 ,9(其实5不合要求)
            if(isPrime(10 * v + i)){
                idq.push_back(10 * v + i);
                ldq.push_back(l + 1);
            }
        }
    }

    for(deque<int>::iterator it = idq.begin();it != idq.end();it++)
        of << (*it) << endl;

    f.close();
    of.close();

    return 0;
}

bool isPrime(const int n){
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
