#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int opt_cnt = 0;
	int opt_pos = 1;
	
	int pos = 1;
	int cnt = 0;

	int current;
	scanf("%d", &current);

	for(int i = 2;i <= n;i++){
		int temp;
		scanf("%d", &temp);
		if(temp < current){
			current = temp;
			cnt = 1;
			pos = i;
		} else {
			cnt++;
		}

		if(cnt > opt_cnt){
			opt_cnt = cnt;
			opt_pos = pos;
		}
	}
	printf("%d\n", opt_pos);
	return 0;
}

