#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> ivec;
    while(true){
        int temp;
        scanf("%d", &temp);

        if(temp == -1)
            break;
        ivec.push_back(temp);
    }

    map<int, int> imap;
    for(int i = 0;i < m;i++)
        imap[ivec[i]]++;

    printf("%d\n", imap.rbegin()->first);
    for(int i = m;i < ivec.size();i++){
        int value = ivec[i];
        imap[value]++;

        value = ivec[i - m];
        imap[value]--;
        if(imap[value] == 0)
            imap.erase(value);

        printf("%d\n", imap.rbegin()->first);
    }

    return 0;
}
