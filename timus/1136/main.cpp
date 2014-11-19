#include <stdio.h>

const int big = 5000;
int data[big];

struct node{
    int value;
    int left;
    int right;
};

struct node a[big];
int pos = 0;

int f(int s, int e){
    // start and end are the starting position and end position respectively
    // return a node
    // printf("Line number: %d, s: %d, e: %d\n", __LINE__, s, e);
    int root = pos++;
    a[root].value = data[e];
    a[root].left = -1;
    a[root].right = -1;

    // printf("Line number: %d, value: %d\n", __LINE__, a[root].value);

    if(s == e)
        return root;

    bool hasLeft = (data[s] < a[root].value);
    bool hasRight = (data[e - 1] > a[root].value);

    if(!hasLeft){
        a[root].right = f(s, e - 1);
        return root;
    }
    if(!hasRight){
        a[root].left = f(s, e - 1);
        return root;
    }
    // both left child and right right exist
    int low = s;
    int high = e - 1;
    int mid;
    while(true){
        mid = (low + high) / 2;
        if(data[mid] < a[root].value)
            low = mid + 1;
        else if(data[mid - 1] > a[root].value)
            high = mid - 1;
        else
            break;
    }
    a[root].left = f(s, mid - 1);
    a[root].right = f(mid, e - 1);
    return root;
}

void mirrorPre(int root){
    if(a[root].right != -1)
        mirrorPre(a[root].right);
    if(a[root].left != -1)
        mirrorPre(a[root].left);
    printf("%d ", a[root].value);
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0;i < n;i++)
        scanf("%d", &data[i]);

    int root = f(0, n - 1);
    // printf("The value of root is: %d\n", root);
    mirrorPre(root);

    return 0;
}
