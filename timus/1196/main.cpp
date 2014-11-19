#include <cstdio>
// 上面的头文件改成<stdio.h>真的能快好几倍(从将近2秒变成了0.3秒左右)

const int big = 16000;
int a[big];

int n;

int myfind(int);

int main(){
    scanf("%d", &n);

    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);

    int m;
    scanf("%d", &m);

    int cnt = 0;
    int temp;
    for(int i = 0;i < m;i++){
        scanf("%d", &temp);

        if(myfind(temp) != -1)
            cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}

int myfind(int target){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(a[mid] == target)
            return mid;
        else if(a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
