#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int a[101000];

void heapify(int);
void siftDown(int, int);

int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        int n;
        cin >> n;
        int heapsize = 0;
        for(int j = 0;j < n;j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 1){
                int number;
                scanf("%d", &number);
                // printf("number is: %d\n", number);
                a[++heapsize] = number;
                heapify(heapsize);
                /*
                for(int k = 1;k <= heapsize;k++)
                    printf("a[%d]: %d\n", k, a[k]);
                */
            } else {
                printf("%d\n", a[1]);
                a[1] = a[heapsize--];
                siftDown(1, heapsize);
            }
        }
    }

    return 0;
}

void heapify(int pos){
    while(pos != 1){
        if(a[pos] < a[pos / 2])
            swap(a[pos], a[pos / 2]);
        else
            return;
        pos /= 2;
    }
}

void siftDown(int pos, int heapsize){
    int record = pos;
    int l = pos * 2;
    int r = l + 1;
    if(l <= heapsize && a[l] < a[record])
        record = l;
    if(r <= heapsize && a[r] < a[record])
        record = r;
    if(record != pos){
        swap(a[pos], a[record]);
        siftDown(record, heapsize);
    }
}
