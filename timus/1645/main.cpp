#include <stdio.h>

const int big = 2010;

int pos[big];
int data[big];

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0;i < n;i++){
		scanf("%d", &data[i]);
		pos[data[i]] = i;
	}

	for(int i = 1;i <= n;i++){
		int temp = pos[i];
		int cnt = 0;
		for(int j = 0;j < temp;j++){
			if(data[j] > i)
				cnt++;
		}
		printf("%d ", cnt + 1);
		cnt = 0;
		for(int j = temp + 1;j < n;j++){
			if(data[j] < i)
				cnt++;
		}	
		printf("%d\n", n - cnt);
	}

    return 0;
}

