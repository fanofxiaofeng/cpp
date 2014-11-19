#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<string>&);
bool lt(string& , string&);
void swap(vector<string>&, int, int);

int main(){
    int n;
    while(cin >> n){
        vector<string> svec(n);
        for(int i = 0;i < n;i++)
            cin >> svec[i];

        selectionSort(svec);

        for(int i = 0;i < n;i++)
            cout << svec[i] << endl;
    }

    return 0;
}

void selectionSort(vector<string> &svec){
    for(int i = 0;i < svec.size();i++){
        int record = i;
        for(int j = i + 1;j < svec.size();j++){
            if(lt(svec[j], svec[record]))
                record = j;
        }
        swap(svec, i, record);
    }
}

bool lt(string& a, string& b){
    if(a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}

void swap(vector<string>& svec, int a, int b){
    string temp = svec[a];
    svec[a] = svec[b];
    svec[b] = temp;
}
