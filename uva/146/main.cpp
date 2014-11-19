#include <iostream>

using namespace std;

int main(){
    string s;

    while(cin >> s){
        if(s == "#")
            break;

        int pos = -1;
        for(int i = s.size() - 1;i > 0;i--){
            if(s[i - 1] < s[i]){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No Successor" << endl;
            continue;
        }

        int swap_pos;
        for(int i = s.size() - 1;i >= pos;i--){
            if(s[i] > s[pos - 1]){
                swap_pos = i;
                break;
            }
        }

        for(int i = 0;i < pos;i++){
            if(i == pos - 1)
                cout << s[swap_pos];
            else
                cout << s[i];
        }

        for(int i = s.size() - 1;i >= pos;i--){
            if(i == swap_pos)
                cout << s[pos - 1];
            else
                cout << s[i];
        }
        cout << endl;
    }

    return 0;
}
