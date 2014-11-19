#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char* T = haystack;
        char* P = needle;
        int lenP = strlen(P);// length of pattern
        int lenT = strlen(T);// length of text
        if(lenP == 0)
            return T;

        // printf("The value of lenP: %d\n", lenP);
        // printf("The value of lenT: %d\n", lenT);

        // calculation of failure
        vector<int> failure(lenP, -1);
        for(int i = 1, j = -1;i < lenP;i++){
            while(j >= 0 && P[j + 1] != P[i])
                j = failure[j];

            if(P[j + 1] == P[i])
                j++;

            failure[i] = j;
        }
        /*
        for(int i = 0;i < failure.size();i++)
            printf("failure[%d]: %d\n", i, failure[i]);
        */
        for(int i = 0, j = -1;i < lenT;i++){
            // printf("Loop with i: %d\n", i);
            while(j >= 0 && P[j + 1] != T[i])
                j = failure[j];
            // printf("In line: %d, j: %d\n", __LINE__, j);
            if(P[j + 1] == T[i])
                j++;
            // printf("Now j: %d\n\n", j);
            if(j == lenP - 1)
                return T + (i - j);

        }
        return NULL;
    }
};

int main(){
    char* T = "mississippi";
    char* P = "issip";
    Solution s;
    printf("%s\n", s.strStr(T, P));
    return 0;
}
