#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int big = 20;

char str[big];

void reverse(int, int);

int main(){
    int rubbish;
    cin >> rubbish;

    for(int loop = 0;loop < rubbish;loop++){
        scanf("%s", str);
        int len = strlen(str);
        // cout << "len is:" << len << endl;
        sort(str, str + len);

        while(true){
            printf("%s\n", str);
            int pos = -1;
            for(int i = len - 1;i > 0;i--){
                if(str[i - 1] < str[i]){
                    pos = i;
                    break;
                }
            }

            if(pos == -1)
                break;

            int swap_pos;

            for(int i = len - 1;i >= pos;i--){
                if(str[i] > str[pos - 1]){
                    swap_pos = i;
                    break;
                }
            }

            char temp = str[pos - 1];
            str[pos - 1] = str[swap_pos];
            str[swap_pos] = temp;

            reverse(pos, len - 1);
        }
        printf("\n");
    }

    return 0;
}

void reverse(int low, int high){
    while(low < high){
        char temp = str[low];
        str[low] = str[high];
        str[high] = temp;
        low++;
        high--;
    }
}
