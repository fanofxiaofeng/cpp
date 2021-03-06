#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<string, set<string> > smap;
    map<string, int> step;
    for(int i = 0;i < n;i++){
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        for(int j = 0;j < 3;j++){
            step[s[j]] = -1;
            for(int k = 0;k < 3;k++){
                if(j != k){
                    smap[s[j]].insert(s[k]);
                }
            }
        }
    }

    queue<string> sq;
	if(step.count("Isenbaev") != 0){
		step["Isenbaev"] = 0;
		sq.push("Isenbaev");
	}
    while(sq.empty() == false){
        string temp = sq.front();
        sq.pop();
        for(set<string>::iterator it = smap[temp].begin();it != smap[temp].end();it++){
            if(step[*it] == -1){
                step[*it] = step[temp] + 1;
                sq.push(*it);
            }
        }
    }

    for(map<string, int>::iterator it = step.begin();it != step.end();it++){
        cout << (it->first) << " ";
        if(it->second == -1)
            cout << "undefined" << endl;
        else
            cout << (it->second) << endl;
    }

    return 0;
}