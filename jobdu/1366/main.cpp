#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

string process(int, vector<int>&, vector<int>&);

int main(){
    int n;

    while(cin >> n){
        vector<int> given(n);
        vector<int> target(n);

        for(int i = 0;i < n;i++)
            cin >> given[i];
        for(int i = 0;i < n;i++)
            cin >> target[i];

        cout << process(n, given, target) << endl;
    }

    return 0;
}

string process(int n, vector<int>& given, vector<int>& target){
    stack<int> istack;
    int j = 0;// given中已经消耗的元素数量
    bool fail = false;

    for(int i = 0;i < n;i++){
        while(istack.empty() == true || istack.top() != target[i]){
            if(j == n){
                fail = true;
                // printf("The value of i: %d\n", i);
                goto failure;
            }
            istack.push(given[j++]);
        }
        istack.pop();
    }
    return "Yes";

failure:
    return "No";
}
