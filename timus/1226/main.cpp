#include <iostream>
#include <cstdio>
#include <stack>
#include <cctype>

using namespace std;

int main(){
    int v;
    stack<char> cs;
    while(true){
        v = getchar();
        if(isalpha(v))
            cs.push(v);
        else{
            while(cs.empty() == false){
                putchar(cs.top());
                cs.pop();
            }
            if(v != EOF)
                putchar(v);
        }
        if(v == EOF)
            break;
    }

    return 0;
}
