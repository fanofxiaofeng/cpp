/*
ID: jyjz2001
TASK: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <deque>

using namespace std;

void qualify(deque<char> &);
void show(deque<char> &, ofstream &);
bool next(deque<char> &, deque<bool> &);
bool isValid(deque<char> &);

int main(){
    /*
    此题可以看做是生成下一个排列的问题
    */
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    string s;
    fin >> s;

    deque<char> cdq;
    for(string::iterator it = s.begin();it != s.end();it++)
        cdq.push_back(*it);

    qualify(cdq);

    deque<bool> occupied(10);
    for(deque<char>::iterator it = cdq.begin();it != cdq.end();it++){
        int delta = (*it) - '0';
        occupied[delta] = true;
    }

    while(true){
        next(cdq, occupied);
        if(isValid(cdq))
            break;
    }

    show(cdq, fout);

    fin.close();
    fout.close();

    return 0;
}

void show(deque<char> &cdq, ofstream &fout){
    for(deque<char>::iterator it = cdq.begin();it != cdq.end();it++)
        fout << (*it);
    fout << endl;
}

bool next(deque<char> &cdq, deque<bool> &occupied){
    // 输入参数 cdq 中是一个合法的排列
    // 输入参数 occupied 记录对应的字符占用情形

    bool ok = false;
    int cnt = 0;
    for(int i = cdq.size() - 1;i >= 0;i--){
        bool thisRunOk = false;
        char c = cdq[i];
        for(char temp = c + 1;temp <= '9';temp++){
            if(occupied[temp - '0'] == false){
                thisRunOk = true;
                occupied[temp - '0'] = true;
                occupied[c - '0'] = false;
                cdq[i] = temp;
                int pos = 1;
                int found = 0;
                while(found < cnt){
                    if(occupied[pos] == false){
                        found++;
                        occupied[pos] = true;
                        cdq[i + found] = (char)('0' + pos);
                    }
                    pos++;
                }
                return true;
            }
        }

        // thisRunOk == false
        occupied[c - '0'] = false;
        cnt++;
    }
    if(cdq.size() == 9)// cdq is "987654321"
        return false;

    int n = cdq.size();
    n++;
    cdq.clear();
    for(int i = 0;i < occupied.size();i++)
        occupied[i] = false;

    for(int i = 1;i <= n;i++){
        cdq.push_back('0' + i);
        occupied[i] = true;
    }

    return true;
}

bool isValid(deque<char> &cdq){
    int len = cdq.size();
    if(len == 1)
        return false;

    bool *p = new bool[len];

    for(int i = 0;i < len;i++)
        p[i] = false;
    int pos = 0;
    bool valid = true;
    for(int i = 0;i < len;i++){
        if(p[pos] == true){
            valid = false;
            break;
        }
        // p[pos] == false
        p[pos] = true;
        pos = (pos + (cdq[pos] - '0')) % len;
    }

    delete []p;

    return valid && pos == 0;
}

void qualify(deque<char> &cdq){
    const int N = 10;
    bool *p = new bool[N];

    p[0] = true;
    for(int i = 1;i < N;i++)
        p[i] = false;

    int record = -1;
    for(int i = 0;i < cdq.size() && record == -1;i++){
        int num = cdq[i] - '0';

        if(p[num] == false)
            p[num] = true;
        else
            record = i;
    }

    if(record == -1)// 没有出现重复的数字
        return;

    bool found = false;
    for(int i = cdq[record] - '0' + 1;i < 10;i++){
        if(p[i] == false){
            found = true;
            cdq[record] = '0' + i;
            p[i] = true;
            break;
        }
    }

    // 处理类似于 "6887" 这种情形
    if(found){
        for(int i = record + 1;i < cdq.size();i++){
            for(int j = 1;j < 10;j++){
                if(p[j] == false){
                    cdq[i] = '0' + j;
                    p[j] = true;
                    break;
                }
            }
        }
        return;
    }

    // not found, 类似于"979" 这种情形(979->981)
    bool ok = false;
    for(int i = record - 1;i >= 0;i--){
        int num = cdq[i] - '0';
        p[num] = false;
        for(int j = num + 1;j < 10;j++){
            if(p[j] == false){
                cdq[i] = j + '0';
                ok = true;
                p[j] = true;
                break;
            }
        }
        if(ok){
            // 类似于"898"这种情形(898->912)
            for(int k = i + 1;k < cdq.size();k++){
                for(int j = 1;j < 10;j++){
                    if(p[j] == false){
                        cdq[k] = j + '0';
                        p[j] = true;
                        break;
                    }
                }
            }
            return;
        }
    }
    // cout << "[898]" << endl;
    // ok == false, 类似于"998"这种情形(998->1234)
    cdq.push_front('1');
    for(int i = 0;i < cdq.size();i++)
        cdq[i] = '0' + (i + 1);
}
