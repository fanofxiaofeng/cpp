#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node{
    int value;
    int left;
    int right;
};

vector<struct node> nvec;
deque<int> idq;

void preOrder(int);

int main(){
    int num;
    cin >> num;
    struct node root;
    root.value = num;
    root.left = -1;
    root.right = -1;

    nvec.push_back(root);
    struct node n;
    while(cin >> num){
        int pos = 0;
        bool exist = false;
        while(true){
            int v = nvec[pos].value;
            if(v == num){
                exist = true;
                break;
            } else if(num < v){
                if(nvec[pos].left == -1)
                    break;
                else
                    pos = nvec[pos].left;
            } else {
                // num > v
                if(nvec[pos].right == -1)
                    break;
                else
                    pos = nvec[pos].right;
            }
        }
        if(exist)
            continue;
        // exist == false
        n.value = num;
        n.left = -1;
        n.right = -1;
        nvec.push_back(n);
        if(num < nvec[pos].value)
            nvec[pos].left = nvec.size() - 1;
        else
            nvec[pos].right = nvec.size() - 1;
    }

    // preOrder(0);

    idq.push_back(0);
    while(idq.empty() == false){
        int temp = idq.front();
        idq.pop_front();
        if(temp == 0)
            printf("%d", nvec[temp].value);
        else
            printf(" %d", nvec[temp].value);
        if(nvec[temp].left != -1)
            idq.push_back(nvec[temp].left);
        if(nvec[temp].right != -1)
            idq.push_back(nvec[temp].right);
    }
    return 0;
}

void preOrder(int pos){
    printf("%d ", nvec[pos].value);
    if(nvec[pos].left != -1)
        preOrder(nvec[pos].left);
    if(nvec[pos].right != -1)
        preOrder(nvec[pos].right);
}
