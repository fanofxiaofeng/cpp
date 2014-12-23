#include <stdio.h>

const int big = 1010000;
const int N = 36;

char cs[big];
int cnt[N + 5];

int main(){
	scanf("%s", cs);
	for(int i = 0;cs[i] != '\0';i++){
		char c = cs[i];
		if(c >= '0' and c <= '9')
			cnt[c - '0']++;
		else
			cnt[c - 'A' + 10]++;
	}
	int max;
	for(int i = N - 1;;i--){
		if(cnt[i] != 0){
			max = i;
			break;
		}
	}
	if(max == 0){
		printf("2\n");
		return 0;
	}
	
	int sum = 0;
	for(int i = 0;i <= max;i++)
		sum += cnt[i] * i;
	
	for(int i = max;i < N;i++){
		if(sum % i == 0){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("No solution.\n");

	return 0;
}
