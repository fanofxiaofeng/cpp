#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool get(int, vector<int>&);

int main(){
    int n;

    cin >> n;
    vector<int> ivec1(n);
    for(int i = 0;i < n;i++)
        scanf("%d", &ivec1[i]);

    cin >> n;
    vector<int> ivec2(n);
    for(int i = 0;i < n;i++)
        scanf("%d", &ivec2[i]);

    sort(ivec1.begin(), ivec1.end());
    sort(ivec2.begin(), ivec2.end());

    for(vector<int>::iterator it = ivec1.begin();it != ivec1.end();it++){
        bool judge = get(10000 - (*it), ivec2);
        if(judge){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}

bool get(int target, vector<int>& ivec){
    int low = 0;
    int high = ivec.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ivec[mid] == target){
            return true;
        } else if(ivec[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}
