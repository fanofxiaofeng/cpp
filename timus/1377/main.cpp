#include <stdio.h> 

const int big = 110;

char data[big][big];

void move(int, int, int &, int &, char &);

int main(){
	int R;
	int C;
	scanf("%d %d", &R, &C);

	for(int c = 0;c <= C + 1;c++)
		data[R + 1][c] = data[0][c] = 'b';// bound
	for(int r = 0;r <= R + 1;r++)
		data[r][C + 1] = data[r][0] = 'b';// bound
	
	for(int i = 0;i < 2;i++){
		int r;
		int c;
		scanf("%d %d", &r, &c);
		data[r][c] = 't';// target
	}
	
	int cnt = 0;
	int r = 1;
	int c = 0;
	char dir = 'r';
	int delta = 0;
	while(cnt != 2){
		// printf("cnt: %d\n", cnt);
		// printf("r: %d, c: %d\n", r, c);
		move(R, C, r, c, dir);	
		if(data[r][c] == 't')
			cnt++;
		if(cnt == 1)
			delta++;
	}
	printf("%d\n", delta);

	return 0;
}

void move(int R, int C, int &r, int &c, char &dir){
	data[r][c] = 'b';
	if(dir == 'r'){
		if(data[r][c + 1] == 'b'){
			r++;
			dir = 'd';
		} else {
			c++;
		}
	} else if(dir == 'd'){
		if(data[r + 1][c] == 'b'){
			c--;
			dir = 'l';
		} else {
			r++;
		}
	} else if(dir == 'l'){
		if(data[r][c - 1] == 'b'){
			r--;
			dir = 'u';
		} else {
			c--;
		}
	} else if(dir == 'u'){
		if(data[r - 1][c] == 'b'){
			c++;
			dir = 'r';
		} else {
			r--;
		}
	}
}
