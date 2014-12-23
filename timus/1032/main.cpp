#include <stdio.h>

const int big = 11000;

int data[big];
int record[big];

void show(int, int);

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &data[i]);
	int sum = 0;
	for(int i = 1;i <= n;i++){
		sum = (sum + data[i]) % n;
		if(sum == 0){
			show(1, i);
			break;
		}
		// sum != 0
		if(record[sum] != 0){
			show(record[sum] + 1, i);
			break;
		} else {
			record[sum] = i;
		}
	}
	return 0;
}

void show(int start, int end){
	printf("%d\n", (end - start + 1));
	for(int i = start;i <= end;i++)
		printf("%d\n", data[i]);
}
