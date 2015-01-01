#include <stdio.h>

int calc(int n){
	int cnt = 0;

	for(int i = 1;i * i <= n;i++){
		if(n % i == 0)
			cnt++;
	}
	return cnt;
}

int main(){
    int m;
    int n;
    int k;
    while(scanf("%d %d %d", &m, &n, &k) != EOF){
        bool exist = false;
        for(int l = k + 1;l <= 10000;l++){
            int cnt1 = calc(l);
            if(cnt1 != n)
                continue;
            int cnt2 = calc(l - k);
            if(cnt2 != m)
                continue;
            exist = true;
            printf("%d\n", l);
            break;
        }
        if(!exist)
            printf("0\n");
    }
    return 0;
}
