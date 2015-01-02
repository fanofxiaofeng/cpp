#include <stdio.h>

const int N = 200000;
const int M = 15100;

bool primes[N];
int data[M];
void sieve(void);

int main(){
	sieve();
	int pos = 0;
	for(int i = 2;pos != M;i++){
		if(primes[i])
			data[pos++] = i;
	}
	int n;
	scanf("%d", &n);
	for(int temp;scanf("%d", &temp) != EOF;)
		printf("%d\n", data[temp - 1]);

	return 0;
}

void sieve(void){
	for(int i = 2;i < N;i++)
		primes[i] = true;
	int cnt = N - 2;
	for(int i = 2;i * i < N;i++){
		if(!primes[i])
			continue;
		int j = i + i;
		while(j < N){
			if(primes[j]){
				primes[j] = false;
				cnt--;
			}
			j += i;
		}
	}
	// printf("%d\n", cnt);
	/*
	for(int i = 2;i < N;i++){
		if(primes[i])
			printf("%d\n", i);
	}
	*/
}
