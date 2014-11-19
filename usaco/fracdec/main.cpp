/*
ID: jyjz2001
TASK: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

void f(ifstream&, ofstream&);

int gcd(const int, const int);
int calc(int);
void specialOutput(ofstream&, int&, const char);

int main(){
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");

    f(fin, fout);

    fin.close();
    fout.close();

    return 0;
}

int gcd(const int a, const int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int calc(int a){// 返回值的意义: a的正规写法中数字的位数
    if(a == 0)
        return 1;
    int cnt = 0;
    while(a != 0){
        a /= 10;
        cnt++;
    }
    return cnt;
}

void f(ifstream& fin, ofstream& fout){// 核心函数
    // 读入分子a和分母b
    int a;
    int b;
    fin >> a >> b;

    // a能被b整除的情形, 例如8/4这类
    if(a % b == 0){
        fout << (a / b) << ".0" << endl;
        return;
    }

    // 其他情形
    fout << (a / b) << ".";

    // 变量cnt中记录已经输出的字符数
    int cnt = 0;
    cnt += 1 + calc(a / b);// 1是小数点占据的那个位置

    a %= b;

    int d = gcd(a, b);
    a /= d;
    b /= d;

    map<int, int> rpmap;// "remainder to position" map
    vector<int> qvec;// quotient vector
    rpmap[a] = 0;

    int pos = 0;

    a *= 10;

    bool finite = false;// 是否为有限长度的

    int s = -1;// start of 循环节
    int t = -1;// terminal of 循环节

    while(true){
        int q = a / b;
        int r = a % b;

        qvec.push_back(q);

        if(r == 0){// 能够除尽
            finite = true;
            break;
        }

        pos++;

        if(rpmap.count(r) > 0){
            s = rpmap[r] + 1;
            t = pos;
            // printf("The value of s: %d, t: %d\n", s, t);
            break;
        }

        rpmap[r] = pos;
        a = r * 10;
    }

    // 能除尽的情形
    if(finite){
        for(vector<int>::iterator it = qvec.begin();it != qvec.end();it++)
            specialOutput(fout, cnt, '0' + (*it));
        fout << endl;
        return;
    }

    // 除不尽的情形
    for(int i = 1;i < s;i++)
        specialOutput(fout, cnt, '0' + qvec[i - 1]);

    // 按照特殊格式输出循环节
    specialOutput(fout, cnt, '(');
    for(int i = s;i <= t;i++)
        specialOutput(fout, cnt, '0' + qvec[i - 1]);
    specialOutput(fout, cnt, ')');

    fout << endl;
}

void specialOutput(ofstream& fout, int& cnt, const char c){
    const int W = 76;// width
    fout << c;
    cnt++;
    if(cnt % W == 0)
        fout << '\n';
    return;
}
