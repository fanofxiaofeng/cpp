#include <iostream>
#include <cstdio>

using namespace std;

int a[101000];

void swap(int, int);

int main(){
    int n;
    int m;

    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;

        for(int i = 0;i < n;i++)
            cin >> a[i];

        for(int i = 0;i < min(m, n);i++){
            int index = i;
            for(int j = i + 1;j < n;j++){
                if(a[j] > a[index])
                    index = j;
            }
            swap(i, index);
            if(i != 0)
                cout << " ";
            cout << a[i];
        }
        cout << endl;
    }

    return 0;
}

void swap(int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
