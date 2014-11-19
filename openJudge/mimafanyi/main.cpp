#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


int main(){
    int n;
    cin >> n;
    getchar();

    string line;
    for(int i = 0;i < n;i++){
        getline(cin, line);
        for(int j = 0;j < line.size();j++){
            char c = line[j];
            if(c <= 'y' && c >= 'a')
                line[j] = c + 1;
            else if(c == 'z')
                line[j] = 'a';
            else if(c <= 'Y' && c >= 'A')
                line[j] = c + 1;
            else if(c == 'Z')
                line[j] = 'A';
        }
        cout << line << endl;
    }

    return 0;
}
