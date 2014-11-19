/*
ID: jyjz2001
TASK: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>

using namespace std;

const int big = 110;

bool appeared[big];// 用于记录出现过的公司编号

int part[big][big];// row号公司控制col号公司的比例
bool control[big][big];// row号公司是否已经控制col号公司

void process(ifstream&, ofstream&, int);
void core(int, int);

int main(){
    ifstream fin("concom.in");
    ofstream fout("concom.out");

    int n;
    fin >> n;
    process(fin, fout, n);

    fin.close();
    fout.close();

    return 0;
}

void process(ifstream& fin, ofstream& fout, int n){
    int from;
    int to;
    int r;// ratio
    for(int i = 0;i < n;i++){
        fin >> from >> to >> r;

        appeared[from] = true;
        appeared[to] = true;
        part[from][to] = r;
    }

    const int half = 50;

    for(int row = 1;row < big;row++){
        if(appeared[row] == false)// 没有涉及这家公司
            continue;

        // 准则1
        control[row][row] = true;

        // 准则2 和 准则3
        for(int col = 1;col < big;col++){
            if(control[row][col] == false && part[row][col] > half){
                control[row][col] = true;
                core(row, col);
            }
        }

        for(int col = 1;col < big;col++){
            if(row == col)
                continue;

            if(control[row][col])
                fout << row << " " << col << endl;
        }
    }


}

void core(int master, int slave){
    for(int loop = 1;loop < big;loop++){
        if(control[master][loop] == false && part[slave][loop] > 0){
            part[master][loop] += part[slave][loop];
            if(part[master][loop] > 50){
                control[master][loop] = true;
                core(master, loop);
            }
        }
    }
}
