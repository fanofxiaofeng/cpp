#include <stdio.h>

const int big = 22 * 10000;
/*从10万到21万之间大致有11万个6位数,如果这些六位数都出现的话,至少占用11万位,超过了输入字符串的总长
这样的话,说明在21万之前一定有未曾出现的值.所以开辟一个bool数组来记录就可以了.
*/


char cs[101000];// char s
bool appeared[big];// whether this integer appeared
int num[] = {1, 10, 100, 1000, 10000, 100000};

void convert(int);

int main(){
    for(int i = 0;i < 6;i++)
        cs[i] = '0';
    scanf("%s", cs + 6);

    for(int pos = 6;cs[pos];pos++)
        convert(pos);

    int i;
    for(i = 1;appeared[i];i++)
        ;

    printf("%d\n", i);

    return 0;
}

void convert(int pos){
    int value = 0;
    for(int delta = 0;delta < 6;delta++){
        int temp = cs[pos - delta] - '0';
        value = num[delta] * temp + value;
        // printf("~%d\n", value);
        if(value < big)
            appeared[value] = true;
    }
}
