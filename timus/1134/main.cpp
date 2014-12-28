#include <stdio.h>
#include <assert.h>

const int N = 1050;

int cnt[N];
bool used[N];

bool isValid(int);

int main(){
	int n;
	int m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0;i < m;i++){
		int value;
		scanf("%d", &value);
		if(!(value >= 0 && value <= n)){
			printf("NO\n");
			return 0;
		}
		cnt[value]++;
	}
	if(isValid(n))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

bool isValid(int n){
	// deal with the cards that appear at least twice
	for(int i = 0;i <= n;i++){
		if(cnt[i] > 2){
			return false;
		} else if (cnt[i] == 2){
			if(i == 0 || i == n)
				return false;
			// now,  1 <= i <= n - 1
			int c1 = i;
			int c2 = i + 1;
			if(used[c1] || used[c2])
				return false;
			// deal with it	
			used[c1] = true;
			used[c2] = true;
			cnt[i] = 0;
		}
	}
	// deal with the cards that appear exactly once
	if(cnt[0] == 1){
		if(used[1])
			return false;
		used[1] = true;
		cnt[0] = 0;
	}
	if(cnt[n] == 1){
		if(used[n])
			return false;
		used[n] = true;
		cnt[n] = 0;
	}
	for(int i = 0;i <= n;i++){
		if(cnt[i] != 1){
			assert(cnt[i] == 0);
			continue;
		}
		// cnt[i] == 1
		int c1 = i;
		int c2 = i + 1;
		if(used[c1] && used[c2])
			return false;
		if(used[c1] == false){
			used[c1] = true;
		} else {
			used[c2] = true;
		}
		cnt[i] = 0;
	}
	return true;
}
