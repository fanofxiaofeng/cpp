#include <stdio.h>
#include <string.h>

const int big = 1050;
char cs[big];

void f(const int);

int main(){
	int n;
	scanf("%d", &n);
	while(scanf("%s", cs) != EOF){
		f(n);
		printf("%s\n", cs);
		// clear
		for(int d = 1;d <= 3;d++)
			cs[strlen(cs) - d] = '\0';
	}
	return 0;
}

void f(const int n){
	int len = strlen(cs);

	int sum = 0;
	int ones = 0;
	for(int i = 0;i < len;i++){
		if(cs[i] == '1'){
			sum += (i + 1);
			ones++;
		}
	}
	sum %= (n + 1);

	if(len == n) {
		// printf("equal\n");
		cs[sum - 1] = '0';
	} else if(len < n) {
		int cnt = 0;
		char deleted = '?';
		int r;
		for(int i = 0;;i++){
			if((sum + ones - cnt) % (n + 1) == 0){
				// 0 deleted
				deleted = '0';				
				r = i;
				break;
			} else if((sum + ones - cnt + i + 1) % (n + 1) == 0){
				// 1 deleted
				deleted = '1';
				r = i;
				break;
			}			
			if(cs[i] == '1')
				cnt++;
		}
		for(int j = len;j > r;j--)
			cs[j] = cs[j - 1];
		cs[r] = deleted;
	} else {
		sum += (n + 1);
		int cnt = 0;
		int r;
		for(int i = 0;i < len;i++){			
			if(cs[i] == '1'){
				cnt++;
				if((sum - (i + 1) - (ones - cnt)) % (n + 1) == 0){
					r = i;
					break;
				}
			} else {
				if((sum - (ones - cnt)) % (n + 1) == 0){
					r = i;
					break;
				}
			}
		}
		for(int j = r;j < len - 1;j++)
			cs[j] = cs[j + 1];
		cs[n] = '\0';
	}	
}