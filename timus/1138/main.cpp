#include <stdio.h>

const int big = 10100;
int cnt[big];

int main(){
	int n;
	int s;
	scanf("%d %d", &n, &s);
	
	cnt[s] = 1;
	int opt = cnt[s];
	
	for(int i = s + 1;i <= n;i++){
		int cur = 0;
		for(int j = s;j < i;j++){
			if(cnt[j] < cur || cnt[j] == 0)
				continue;
			if(i * 100 % j == 0)
				cur = cnt[j] + 1;			
		}
		cnt[i] = cur;
		// printf("cnt[%d]: %d\n", i, cnt[i]);
		if(cnt[i] > opt)
			opt = cnt[i];
	}
	printf("%d\n", opt);	

	return 0;
}
