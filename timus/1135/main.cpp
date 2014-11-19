#include <stdio.h>
#include <string.h>

const int big = 31000;

char cs[big];

int main(){
    /*
    本题的思路:
    朝左的人数和朝右的人数一直是固定的(因为每次转身, 相当于本来面对面的二人交换位置)
    这样最终结果一定是朝左的人全部站在队列的左侧, 朝右的人站在队列的右侧
    于是只要计算所有朝左的人需要"移动"到自己的目标位置所需要的步数的和.
    是自己想出来的, 感觉棒棒哒~(虽然是个简单题)
    */
    int n;
    scanf("%d", &n);

    int len = 0;
    while(scanf("%s", cs + len) != EOF)
        len += strlen(cs + len);

    int total = 0;
    int left_cnt = 0;

    for(int i = 0;cs[i];i++){
        if(cs[i] == '<')
            total += i - left_cnt++;
    }

    printf("%d\n", total);

    return 0;
}
