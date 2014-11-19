#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int cnt = 0;
    int record;
    int cur;

    for(int i = 0;i < n;i++){
        scanf("%d", &cur);

        if(cnt == 0)
            record = cur;

        if(record == cur)
            cnt++;
        else
            cnt--;
    }

    printf("%d\n", record);

    return 0;
}
