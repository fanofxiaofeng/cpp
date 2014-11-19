#include <iostream>

using namespace std;

int main(){
    int n;
    string s;

    cin >> n >> s;

    int result;
    for(result = 1;n > 0;n -= s.size())
        result *= n;

    cout << result << endl;

    return 0;
}
