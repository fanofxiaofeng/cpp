#include <stdio.h>
#include <cstdlib>
#include <cstring>

const int magic = 10;

char p[magic];
char q[magic];

int convert(char *cp){
    bool dot_found = false;
    int pos = -1;
    for(int i = 0;i < magic;i++){
        if(cp[i] == '.'){
            dot_found = true;
            pos = i;
            break;
        }
    }

    if(dot_found){
        cp[pos] = '\0';
        if(!cp[pos + 2])
            cp[pos + 2] = '0';
        return 100 * atoi(cp) + atoi(cp + pos + 1);
    } else {
        int len = strlen(cp);
        cp[len] = '0';
        cp[len + 1] = '0';
        return atoi(cp);
    }
}

int main(){
    scanf("%s", p);
    scanf("%s", q);

    int low = convert(p);
    int high = convert(q);

    for(int i = 1;;i++){
        int start = i * low / 10000 + 1;
        int bound = i * high / 10000;

        if((i * high) % 10000 == 0)
            bound--;
        if(bound >= start){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
