#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int main(){
    string s;
    bool head(true); // head of a sentence
    while(getline(cin, s)){
        for(int i = 0;i < s.size();i++){
            char c = s[i];
            if(isalpha(c)){
                if(head){
                    putchar(toupper(c));
                    head = false;
                } else {
                    putchar(tolower(c));
                }
            } else if(c == '?' || c == '.' || c == '!'){
                putchar(c);
                head = true;
            } else {
                putchar(c);
            }
        }
        putchar('\n');
    }

    return 0;
}
