#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n;

    while(cin >> n){
        map<int, int> imap;

        for(int i = 0;i < n;i++){
            int from;
            int to;
            cin >> from >> to;

            if(imap.count(to) == 0)
                imap[to] = from;
            else if(imap[to] < from)
                imap[to] = from;
        }

        int opt = 0;
        int pre = -1;

        for(map<int, int>::iterator it = imap.begin();it != imap.end();it++){
            // printf("from: %d, to: %d, pre: %d\n", it->second, it->first, pre);
            if(it->second >= pre){
                opt++;
                pre = it->first;
            }
        }

        cout << opt << endl;
    }
}
