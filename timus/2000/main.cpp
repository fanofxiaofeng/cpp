#include <stdio.h>

const int big = 101000;

int a[big];

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int first;
    int second;
    scanf("%d %d", &first, &second);
    first--;
    second--;

    if(first == second){
        int left_sum = 0;
        int right_sum = 0;
        for(int i = 0;i <= first;i++)
            left_sum += a[i];
        right_sum = sum - (left_sum - a[first]);
        if(left_sum >= right_sum)
            printf("%d %d\n", left_sum, right_sum - a[first]);
        else
            printf("%d %d\n", right_sum, left_sum - a[first]);
    } else if(first < second) {
        int left_sum = 0;
        int mid = (first + second) / 2;
        for(int i = 0;i <= mid;i++)
            left_sum += a[i];
        printf("%d %d\n", left_sum, sum - left_sum);
    } else {
        int left_sum = 0;
        int mid = (first + second) / 2;
        if((first - second) % 2 == 0)
            mid--;
        for(int i = 0;i <= mid;i++)
            left_sum += a[i];
        printf("%d %d\n", sum - left_sum, left_sum);
    }


    return 0;
}

