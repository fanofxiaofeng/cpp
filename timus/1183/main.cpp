#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int big = 110;

int opt[big][big];// 用于记录至少要插入几个字符
int pos[big][big];

string str;

int safeAccess(const int, const int);
void process(const int, const int);

int main(){

    cin >> str;

    int len = str.size();
    for(int row = 0;row < len;row++){
        for(int col = 0;col < len;col++){
            pos[row][col] = -1;
            opt[row][col] = -1;
        }
    }

    for(int i = 0;i < len;i++)
        opt[i][i] = 1;

    for(int delta = 1;delta < len;delta++){
        for(int row = 0;row + delta < len;row++){
            int col = row + delta;
            opt[row][col] = opt[row][col - 1] + 1;// 上限为此
            if(str[col] == ']' || str[col] == ')'){
                for(int i = row;i < col;i++){
                    if((str[col] == ']' && str[i] == '[') || (str[col] == ')' && str[i] == '(')){// 括号匹配
                        int temp = safeAccess(row, i - 1) + safeAccess(i + 1, col - 1);
                        if(temp < opt[row][col]){
                            opt[row][col] = temp;
                            pos[row][col] = i;
                            break;
                        }
                    }
                }
            }
            // 若str[col] == '[' || str[col] == '(' 则不用再多做计算
        }
    }

    process(0, len - 1);
    printf("\n");
    /*
    for(int row = 0;row < len;row++){
        for(int col = 0;col < len;col++){
            printf("%3d", opt[row][col]);
        }
        printf("\n");
    }
    */

    return 0;
}

int safeAccess(const int row, const int col){
    return ((row > col)?(0):(opt[row][col]));
}

void process(const int s, const int e){
    if(s > e)
        return;
    if(pos[s][e] == -1){
        process(s, e - 1);
        if(str[e] == ')' || str[e] == '(')
            printf("()");
        else
            printf("[]");
    } else {
        process(s, pos[s][e] - 1);
        putchar(str[pos[s][e]]);
        process(pos[s][e] + 1, e - 1);
        putchar(str[e]);
    }
}
