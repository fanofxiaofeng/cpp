/*
ID: jyjz2001
TASK: sort3
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int process(vector<int> &);

int matrix[3][3];

int main(){
    ifstream f("sort3.in");
    ofstream of("sort3.out");

    int n;

    f >> n;

    vector<int> ivec;
    for(int i = 0;i < n;i++){
        int temp;
        f >> temp;
        ivec.push_back(temp - 1);
    }
    of << process(ivec) << endl;

    f.close();
    of.close();

    return 0;
}

int process(vector<int> &ivec){
    vector<int> sortedIvec(ivec);
    int cnt[] = {0, 0, 0};
    for(vector<int>::iterator it = ivec.begin();it != ivec.end();it++){
        cnt[*it]++;
    }

    for(int i = 0;i < cnt[0];i++)
        sortedIvec[i] = 0;
    for(int i = cnt[0];i < cnt[0] + cnt[1];i++)
        sortedIvec[i] = 1;
    for(int i = cnt[0] + cnt[1];i < ivec.size();i++)
        sortedIvec[i] = 2;

    for(int i = 0;i < ivec.size();i++)
        matrix[ivec[i]][sortedIvec[i]]++;
		
    int opt = 0;
    opt += min(matrix[0][1], matrix[1][0]);
    opt += min(matrix[0][2], matrix[2][0]);
    opt += min(matrix[1][2], matrix[2][1]);
    opt += abs(matrix[0][1] - matrix[1][0]) * 2;
	
    return opt;
}
