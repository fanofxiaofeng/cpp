#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    string s;

    while(true){
        cin >> s;
        if(s == "E")
            break;

        int z = 0;
        int o = 0;
        int j = 0;
        for(string::iterator it = s.begin();it != s.end();it++){
            char c = *it;
            if(c == 'Z')
                z++;
            else if(c == 'O')
                o++;
            else
                j++;
        }

        int total = s.size();
        while(total > 0){
            if(z != 0){
                putchar('Z');
                z--;
                total--;
            }
            if(o != 0){
                putchar('O');
                o--;
                total--;
            }
            if(j != 0){
                putchar('J');
                j--;
                total--;
            }
        }
        putchar('\n');
    }



    return 0;
}
