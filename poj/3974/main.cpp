#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str[1010000];
char cs[2010000];
int r[2010000];// radius

int main(){
    int cnt = 0;

    while(true){
        scanf("%s", str);
        if(str[0] == 'E')
            break;

        cnt++;
        int len = strlen(str);
        for(int i = 0;i < len;i++)
            cs[2 * i + 2] = str[i];

        cs[0] = '^';
        cs[2 * len + 2] = '$';

        int rightMostReached = 0;
        int withPos = 0;
        int rOpt = 1;

        len = 2 * len + 3;
        for(int i = 1;i < len - 1;i++){
            int temp;
            if(i <= rightMostReached)
                temp = min(rightMostReached - i + 1, r[2 * withPos - i]);
            else
                temp = 1;

            while(cs[i + temp] == cs[i - temp])
                temp++;

            r[i] = temp;

            if(i + temp - 1 > rightMostReached){
                rightMostReached = i + temp - 1;
                withPos = i;
            }

            if(r[i] > rOpt)
                rOpt = r[i];
        }

        int palindromeLen = (2 * rOpt - 1) / 2;

        printf("Case %d: %d\n", cnt, palindromeLen);
    }
    return 0;
}
