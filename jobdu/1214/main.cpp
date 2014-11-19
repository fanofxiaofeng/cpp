#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main(){
    vector<unsigned int> uivec;
    set<unsigned int> uiset;

    uiset.insert(1);

    while(uivec.size() < 1500){
        unsigned int temp = *(uiset.begin());
        uiset.insert(temp * 2);
        uiset.insert(temp * 3);
        uiset.insert(temp * 5);
        uiset.erase(temp);
        uivec.push_back(temp);
    }

    int query;
    while(cin >> query)
        cout << uivec[query - 1] << endl;

    return 0;
}
