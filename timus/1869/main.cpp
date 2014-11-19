#include <stdio.h>

const int big = 120;
const int N = 36;

int a[big][big];
int in[big];
int out[big];

void acc(int);
int calc(int);
void rotate(int);

int main(){
	// read data
    int n;
    scanf("%d", &n);
    for(int row = 0;row < n;row++){
        for(int col = 0;col < n;col++){
            scanf("%d", &a[row][col]);
        }
    }

	acc(n);
    int record = calc(n);

    rotate(n);

	acc(n);
    int temp = calc(n);
    if(temp > record)
        record = temp;

	// printf("The value of record is: %d\n", record);
    printf("%d\n", (record / N) + (record % N != 0));

    return 0;
}

void rotate(int n){
    for(int row = 0;row < n;row++){
        for(int col = row + 1;col < n;col++){
            a[row][col] = a[n - 1 - row][n - 1 - col];
        }
    }
}

int calc(int n){
	// 计算到从任意一站发车时,车上的总人数,并返回这个总人数的最大值
    int cnt = 0;
    int record = 0;
    for(int i = 0;i < n;i++){
        cnt += in[i] - out[i];
		// printf("The value of cnt: %d\n", cnt);
        if(cnt > record)
            record = cnt;
    }
	// printf("Line number: %d, return value: %d\n", __LINE__, record);
    return record;
}

void acc(int n){
	// in[i] 中记录从i站出发的人数(需要满足到某站j,且j > i)
    for(int row = 0;row < n;row++){
        in[row] = 0;
        for(int col = row + 1;col < n;col++){
            in[row] += a[row][col];
        }
		// printf("in[%d]: %d\n", row, in[row]);
    }

	// out[i] 中记录在i到站的人数(需要满足从某站j出发,且j < i)
    for(int col = 0;col < n;col++){
        out[col] = 0;
        for(int row = 0;row < col;row++){
            out[col] += a[row][col];
        }
		// printf("out[%d]: %d\n", col, out[col]);
    }

}
