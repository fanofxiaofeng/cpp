/*
ID: jyjz2001
TASK: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool fun(vector<int> &, vector<int> &, vector<vector<int> > &, int, int, int, vector<int> &);

int main(){
    ifstream f("holstein.in");
    ofstream of("holstein.out");

    int v;
    f >> v;

    vector<int> required;
    vector<int> current(v);
    for(int i = 0;i < v;i++){
        int temp;
        f >> temp;
        required.push_back(temp);
    }

    int g;
    f >> g;
    vector<vector<int> > data(g, required);
    for(int i = 0;i < g;i++){
        for(int j = 0;j < v;j++){
            int temp;
            f >> temp;
            data[i][j] = temp;
        }
    }

    vector<int> info;
    for(int i = 1;i <= g;i++){
        // printf("Choose %d from %d\n", i, g);
        bool found = fun(required, current, data, i, g, 0, info);
        if(found)
            break;
    }

    of << info.size();
    for(int i = 0;i < info.size();i++)
        of << " " << (info[i] + 1);
    of << endl;

    f.close();
    of.close();

    return 0;
}

bool fun(vector<int> &required, vector<int> &current, vector<vector<int> > &data, int pick, int remain, int pos, vector<int> &stack){
    // printf("Line number: %d. pick: %d, remain: %d\n", __LINE__, pick, remain);

    // pick this one
    for(int col = 0;col < current.size();col++)
        current[col] += data[pos][col];

    stack.push_back(pos);
    if(pick == 1){
        bool ok = true;
        for(int col = 0;col < current.size();col++){
            if(current[col] < required[col]){
                ok = false;
                break;
            }
        }
        if(ok)
            return true;
        else
            stack.pop_back();
    } else {// pick >= 2
        bool judge = fun(required, current, data, pick - 1, remain - 1, pos + 1, stack);
        if(judge)
            return true;
        else
            stack.pop_back();
    }

    // don't pick this one
    for(int col = 0;col < current.size();col++)
        current[col] -= data[pos][col];

    if(pick > remain - 1)
        return false;
    else
        return fun(required, current, data, pick, remain - 1, pos + 1, stack);
}
