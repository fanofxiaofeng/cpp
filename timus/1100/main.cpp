#include <iostream>
#include <cstdio>

const int inf = 10000 * 10000;

int id[151000];
int id1[151000];
int id2[151000];
int num[151000];
int num1[151000];
int num2[151000];

void specialMergeSort(const int, const int);

int main(){
    int k;
    scanf("%d", &k);

    for(int i = 0;i < k;i++)
        scanf("%d %d", &id[i], &num[i]);

    specialMergeSort(0, k - 1);

    for(int i = 0;i < k;i++)
        printf("%d %d\n", id[i], num[i]);

    return 0;
}

void specialMergeSort(const int low, const int high){
    if(low == high)
        return;
    int mid = low + (high - low) / 2;

    specialMergeSort(low, mid);
    specialMergeSort(mid + 1, high);

    for(int i = low;i <= mid;i++){
        id1[i - low] = id[i];
        num1[i - low] = num[i];
    }
    num1[mid + 1 - low] = -inf;

    for(int i = mid + 1;i <= high;i++){
        id2[i - (mid + 1)] = id[i];
        num2[i - (mid + 1)] = num[i];
    }
    num2[high + 1 - (mid + 1)] = -inf;

    int pos1 = 0;
    int pos2 = 0;

    for(int i = low;i <= high;i++){
        if(num1[pos1] >= num2[pos2]){
            id[i] = id1[pos1];
            num[i] = num1[pos1];
            pos1++;
        } else {
            id[i] = id2[pos2];
            num[i] = num2[pos2];
            pos2++;
        }
    }
}
