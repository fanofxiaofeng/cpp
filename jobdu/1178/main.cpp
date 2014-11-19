#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char str[10];

void insertionSort(vector<int>&, vector<int>&, vector<int>&);
bool lt(int, int, int, int);

int main(){
    int n;
    while(cin >> n){

        vector<int> avec;
        vector<int> bvec;
        vector<int> svec;

        for(int i = 0;i < n;i++){

            scanf("%s", str);

            if(str[0] == 'P'){
                // printf("case pop\n");
                if(avec.size() == 0){
                    printf("empty\n");
                    continue;
                }

                printf("%d+i%d\n", avec[avec.size() - 1], bvec[bvec.size() - 1]);
                avec.pop_back();
                bvec.pop_back();
                svec.pop_back();
                printf("SIZE = %d\n", avec.size());

            } else {// str[0] == 'I'
                int a;
                int b;

                scanf("%d+i%d", &a, &b);
                avec.push_back(a);
                bvec.push_back(b);
                svec.push_back(a * a + b * b);

                insertionSort(avec, bvec, svec);

                // printf("a:%d, b:%d\n", a, b);
                printf("SIZE = %d\n", avec.size());
            }
        }
    }

    return 0;
}

void insertionSort(vector<int>& avec, vector<int>& bvec, vector<int>& svec){
    for(int i = avec.size() - 1;i > 0;i--){
        if(lt(bvec[i], svec[i], bvec[i - 1], svec[i - 1])){
            swap(avec[i - 1], avec[i]);
            swap(bvec[i - 1], bvec[i]);
            swap(svec[i - 1], svec[i]);
        } else
            return;
    }
}

bool lt(int b1, int s1, int b2, int s2){
    if(s1 != s2)
        return s1 < s2;
    else
        return b1 > b2;
}
