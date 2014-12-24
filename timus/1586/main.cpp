#include <stdio.h>

const int N = 1000;
const int M = 10000 * 100000 + 9;

bool table[N];// prime number table below 1000 (and above 100)
int cnt[2][N];// counter for answer
int primes[200];// big enough to hold all prime numbers below 1000 (and above 100)

void init(void);

int main(){
	init();
	int n;
	scanf("%d", &n);
	for(int i = 4;i <= n;i++){
		for(int pos = 0;primes[pos] != 0;pos++)
			cnt[1 - i % 2][primes[pos]] = 0;
		for(int pos = 0;primes[pos] != 0;pos++){
			int value = primes[pos];// e.g. value is 107
			int tempCnt = cnt[i % 2][value];
			value = value % 100;// e.g. 107 -> 7
			for(int d = 0;d < 10;d++){
				int cur = value * 10 + d;
				if(table[cur]){
					cnt[1 - i % 2][cur] += tempCnt;
					if(cnt[1 - i % 2][cur] >= M)
						cnt[1 - i % 2][cur] -= M;
				}
			}
		}
	}
	int total = 0;
	for(int pos = 0;primes[pos] != 0;pos++){
		int value = primes[pos];
		total += cnt[1 - n % 2][value];
		if(total >= M)
			total -= M;
	}
	
	printf("%d\n", total);
	return 0;
}

void init(void){
	int pos = 0;
	for(int i = 100;i < 1000;i++){
		// note that we only care about 3-digit prime numbers
		bool isPrime = true;
		for(int j = 2;j * j <= i;j++){
			if(i % j == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			table[i] = true;
			cnt[0][i] = 1;
			primes[pos++] = i;
		}
	}
}