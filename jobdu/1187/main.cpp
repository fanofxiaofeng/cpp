#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct info{
    int id;
    string name;
    int age;
};

struct info a[40];

bool lt(int, int);
void swap(int, int);

int main(){
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++)
            cin >> a[i].id >> a[i].name >> a[i].age;
        for(int i = 0;i < min(3, n);i++){
            int index = i;
            for(int j = i + 1;j < n;j++){
                if(lt(j, index))
                    index = j;
            }
            swap(i, index);
            cout << a[i].id << " " << a[i].name << " " << a[i].age << endl;
        }
    }

    return 0;
}

bool lt(int x, int y){
    if(a[x].age != a[y].age)
        return a[x].age < a[y].age;
    else if(a[x].id != a[y].id)
        return a[x].id < a[y].id;
    else
        return a[x].name < a[y].name;
}

void swap(int x, int y){
    int tempId = a[x].id;
    a[x].id = a[y].id;
    a[y].id = tempId;

    int tempAge = a[x].age;
    a[x].age = a[y].age;
    a[y].age = tempAge;

    string tempName = a[x].name;
    a[x].name = a[y].name;
    a[y].name = tempName;
}
