#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int m;
    while(true){
        scanf("%d", &n);// number of nodes
        if(n == 0)
            break;
        scanf("%d", &m);// number of edges

        vector<vector<int> > relation(n);

        int a;
        int b;
        for(int i = 0;i < m;i++){
            scanf("%d %d", &a, &b);
            a--;
            b--;
            relation[a].push_back(b);
            relation[b].push_back(a);
        }

        int cnt = 0;
        vector<bool> visited(n);
        for(int i = 0;i < n;i++){
            if(visited[i])
                continue;
            cnt++;
            deque<int> idq;
            idq.push_back(i);
            visited[i] = true;
            while(idq.size() != 0){
                int temp = idq.front();
                idq.pop_front();

                for(int j = 0;j < relation[temp].size();j++){
                    if(visited[relation[temp][j]] == false){
                        visited[relation[temp][j]] = true;
                        idq.push_back(relation[temp][j]);
                    }
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
