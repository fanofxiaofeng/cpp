#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

void f(void);

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        f();

    return 0;
}

void f(void){
    map<int, int> imap;
    for(int i = 0;i < 2;i++){
        while(true){
            int xishu;
            int zhishu;
            cin >> xishu >> zhishu;
            if(zhishu < 0)
                break;
            imap[zhishu] += xishu;
        }
    }
    bool head = true;
    for(map<int, int>::reverse_iterator rit = imap.rbegin();rit != imap.rend();rit++){
        if(rit->second != 0){
            if(!head)
                cout << " ";
            cout << "[ " << (rit->second) << " " << (rit->first) << " ]";
            head = false;
        }
    }
    if(head)
        cout << "[ 0 0 ]";
    cout << endl;
}
