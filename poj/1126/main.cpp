#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

string f(string&);
void manipulate(vector<char>&);
bool isCDEI(char);
bool p2z(char);

int main(){
    string s;
    while(cin >> s)
        cout << f(s) << endl;
    return 0;
}

string f(string& s){
    vector<char> cvec;
    for(string::iterator it = s.begin();it != s.end();it++){
        char c = *it;
        cvec.push_back(c);
        manipulate(cvec);
    }

    if(cvec.size() == 1 && p2z(cvec[0]))
        return "YES";
    else
        return "NO";
}

void manipulate(vector<char>& cvec){// 操纵栈
    while(true){
        if(cvec.empty())// 栈空
            return;

        char c = cvec.back();

        if(!p2z(c))// 栈顶为操作符
            return;

        if(cvec.size() >= 2 && p2z(c) && cvec[cvec.size() - 2] == 'N'){
            cvec.pop_back();
            cvec.pop_back();
            cvec.push_back('p');// 具体是哪个操作数并不重要
        } else if(cvec.size() >= 3 && p2z(c) && p2z(cvec[cvec.size() - 2]) && isCDEI(cvec[cvec.size() - 3])) {
            cvec.pop_back();
            cvec.pop_back();
            cvec.pop_back();
            cvec.push_back('p');// 具体是哪个操作数并不重要
        } else
            return;
    }
}

bool isCDEI(char c){// The char is one of 'C' 'D' 'E' 'I'
    return (c >= 'C' && c <= 'E') || (c == 'I');
}

bool p2z(char c){// The char is in 'p' to 'z'
    return (c >= 'p' && c <= 'z');
}
