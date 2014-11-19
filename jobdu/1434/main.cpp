#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n;

    while(true){
        cin >> n;
        if(n == 0)
            break;

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
            // 循环不变式: 每次执行到这里时, opt给出(-无穷,it->second]上最多可以完整参与的活动数量.
            // pre的意义: 诸最优解中最后一个活动的结束时间有最早的(记这个活动为last_one),last_one所对应的结束时间是pre
        }

        cout << opt << endl;
    }

    return 0;
}
