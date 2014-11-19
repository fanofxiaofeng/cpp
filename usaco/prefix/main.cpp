/*
ID: jyjz2001
TASK: prefix
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct superChar{
    bool someWordEndsHere;
    int children[26];
};

char primitive[100];
char sequence[201000];
bool endsWith[201000];

const int bigEnough = 30000;
struct superChar a[bigEnough];

void init(int &);
void generate(int &);
int calc(const int, const int);

int main(){
    FILE *fin = fopen("prefix.in" , "r");
    FILE *fout = fopen("prefix.out" , "w");

    int pos = 0;
    init(pos);
    while(true){
        fscanf(fin, "%s", primitive);
        if(primitive[0] == '.')
            break;
        generate(pos);
    }

    int len = 0;
    int curLen = -1;
    while(true){
        if(fscanf(fin, "%s", sequence + len) != 1)
            break;

        curLen = strlen(sequence + len);
        len += curLen;
    }
    // printf("The value of len is: %d\n", len);
    // printf("The value of pos: %d\n", pos);
    // printf("sq is: %s\n", sequence);

    int result = calc(pos, len);

    fprintf(fout, "%d\n", result + 1);

    fclose(fin);
    fclose(fout);

    return 0;
}

int calc(const int pos, const int len){
    int opt = -1;
    for(int i = 0;i < len;i++){
        if(i >= opt + 2)
            return opt;

        // i <= opt + 1
        if(i == 0 || endsWith[i - 1]){// if its previous position (which means i - 1) is a "good" position
            int delta = 0;// length of newly matched string
            int cur = 0;// position in dictionary tree

            while(true){
                char c = sequence[i + delta];// current char

                if(c == '\0')// out of sequence
                    break;
                if(a[cur].children[c - 'A'] == 0)// no such child
                    break;

                cur = a[cur].children[c - 'A'];
                delta++;
                if(a[cur].someWordEndsHere){
                    endsWith[i - 1 + delta] = true;
                    opt = (i - 1 + delta > opt)?(i - 1 + delta):opt;
                }
            }
        }
    }

    return opt;
}

void init(int &pos){
    a[pos].someWordEndsHere = false;
    pos++;
}

void generate(int &pos){
    int len = strlen(primitive);
    // printf("the word is: %s\n", primitive);
    int cur = 0;
    for(int i = 0;i < len;i++){
        char c = primitive[i];
        if(a[cur].children[c -  'A'] == 0){
            a[cur].children[c - 'A'] = pos;
            cur = pos;

            pos++;
        } else {
            cur = a[cur].children[c - 'A'];
        }

        if(i + 1 == len){
            a[cur].someWordEndsHere = true;
        }
    }
}
