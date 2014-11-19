/*
ID: jyjz2001
TASK: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void process(const int, const int, vector<int> &, vector<int> &, ofstream &);
void buttonFun(vector<bool> &, int, int);
bool isValid(vector<bool> &, vector<int> &, vector<int> &);
void output(const vector<bool> &, ofstream &);

int main(){
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    int n;
    int c;

    fin >> n >> c;

    vector<int> on;
    while(true){
        int temp;
        fin >> temp;
        if(temp == -1)
            break;
        on.push_back(temp);
    }

    vector<int> off;
    while(true){
        int temp;
        fin >> temp;
        if(temp == -1)
            break;
        off.push_back(temp);
    }

    process(n, c, on, off, fout);

    fin.close();
    fout.close();

    return 0;
}

void buttonFun(vector<bool> &lights, int button, int times){
    if(times == 0)
        return;

    if(button == 1){
        for(int i = 0;i < lights.size();i++)
            lights[i] = !lights[i];
    } else if(button == 2){
        for(int i = 0;i < lights.size();i += 2)
            lights[i] = !lights[i];
    } else if(button == 3){
        for(int i = 1;i < lights.size();i += 2)
            lights[i] = !lights[i];
    } else {
        for(int i = 0;i < lights.size();i += 3)
            lights[i] = !lights[i];
    }
}

bool isValid(vector<bool> &lights, vector<int> &on, vector<int> &off){
    for(int i = 0;i < on.size();i++){
        if(lights[on[i] - 1] == false)
            return false;
    }

    for(int i = 0;i < off.size();i++){
        if(lights[off[i] - 1] == true)
            return false;
    }

    return true;
}

void process(const int n, const int c, vector<int> &on, vector<int> &off, ofstream &fout){
    vector<bool> lights(n, true);
    set<vector<bool> > lightsSet;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            for(int k = 0;k < 2;k++){
                for(int l = 0;l < 2;l++){
                    if((c >= i + j + k + l) && (c % 2 == (i + j + k + l) % 2)){
                        vector<bool> temp(lights);
                        buttonFun(temp, 1, i);
                        buttonFun(temp, 2, j);
                        buttonFun(temp, 3, k);
                        buttonFun(temp, 4, l);

                        if(isValid(temp, on, off))
                            lightsSet.insert(temp);
                    }
                }
            }
        }
    }

    if(lightsSet.empty()){
        fout << "IMPOSSIBLE" << endl;
    } else {
        for(set<vector<bool> >::iterator it = lightsSet.begin();it != lightsSet.end();it++)
            output(*it, fout);
    }
}

void output(const vector<bool> &lights, ofstream &fout){
    for(int i = 0;i < lights.size();i++)
        fout << lights[i];
    fout << endl;
}
