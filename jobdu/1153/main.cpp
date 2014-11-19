#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string f(string&);

int main(){
    string s;
    while(cin >> s){
        string result = f(s);
        cout << s << endl;
        cout << result << endl;
    }
}

string f(string& s){
    vector<char> cvec(s.size(), ' ');

    stack<int> istack;
    stack<char> cstack;

    for(int i = 0;i < s.size();i++){
        char c = s[i];

        if(c == '('){
            istack.push(i);
            cstack.push(c);
        }
        if(c == ')'){
            if(cstack.size() != 0 && cstack.top() == '('){
                cstack.pop();
                istack.pop();
            } else {
                istack.push(i);
                cstack.push(c);
            }
        }
    }
    while(cstack.size() != 0){
        char temp = cstack.top();
        if(temp == '(')
            cvec[istack.top()] = '$';
        else
            cvec[istack.top()] = '?';
        cstack.pop();
        istack.pop();
    }
    string result = "";
    for(int i = 0;i < cvec.size();i++)
        result += cvec[i];
    return result;
}

