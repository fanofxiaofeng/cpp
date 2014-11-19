#include<stdio.h>

int pos[1050];
int order[2][101000];

int main(){
    int n;
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < m;i++)
        scanf("%d %d", &order[0][i], &order[1][i]);

    int temp;
    for(int i = 1;i <= n;i++){
        scanf("%d", &temp);
        pos[temp] = i;
    }

    for(int i = 0;i < m;i++){
        int former = order[0][i];
        int latter = order[1][i];
        if(pos[former] >= pos[latter]){
            //printf("i: %d, former: %d, latter: %d\n", i, former, latter);
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}
