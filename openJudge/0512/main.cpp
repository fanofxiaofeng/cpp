#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node{
    char name;
    int left;
    int right;
};

const int big = 120;
struct node a[big];

void f(void);
void preOrder(int);
void inOrder(int);
void postOrder(int);

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        if(i != 0)
            printf("\n");
        f();
    }

    return 0;
}


void f(void){
    memset(a, 0, sizeof(a));

    int line = 0;
    vector<string> svec;
    while(true){
        line++;
        string s;
        cin >> s;

        if(s[0] == '0')
            break;
        a[line].name = s[s.size() - 1];

        if(svec.empty() == false && s[s.size() - 1] != '*'){
            for(int i = svec.size() - 1;i >= 0;i--){
                if(svec[i].size() + 1 == s.size()){
                    int parentLine = i + 1;
                    int childLine = line;
                    if(parentLine + 1 == childLine)
                        a[parentLine].left = childLine;
                    else
                        a[parentLine].right = childLine;
                    break;
                }
            }
        }

        svec.push_back(s);
    }

    preOrder(1);
    printf("\n");
    postOrder(1);
    printf("\n");
    inOrder(1);
    printf("\n");
}

void preOrder(int current){
    putchar(a[current].name);
    if(a[current].left != 0)
        preOrder(a[current].left);
    if(a[current].right != 0)
        preOrder(a[current].right);
}

void postOrder(int current){
    if(a[current].left != 0)
        postOrder(a[current].left);
    if(a[current].right != 0)
        postOrder(a[current].right);
    putchar(a[current].name);
}

void inOrder(int current){
    if(a[current].left != 0)
        inOrder(a[current].left);
    putchar(a[current].name);
    if(a[current].right != 0)
        inOrder(a[current].right);
}
