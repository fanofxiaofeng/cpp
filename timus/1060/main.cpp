#include <stdio.h>

char board[6][6];
char temp[6][6];
char cs[100];

int num[100];

bool isValid(void){
	bool allB = true;
	bool allW = true;
	for(int r = 1; r <= 4;r++){
		for(int c = 1;c <= 4;c++){
			if(temp[r][c] != 'b')
				allB = false;
			if(temp[r][c] != 'w')
				allW = false;
            if(!allB && !allW)
                return false;
		}
	}
	return true;
}

void flip(int r, int c){
	for(int dr = -1;dr <= 1;dr++){
		for(int dc = -1;dc <= 1;dc++){
			if(dr * dr + dc * dc > 1)
				continue;
			temp[r + dr][c + dc] = ((temp[r + dr][c + dc] == 'b')?('w'):('b'));
		}
	}
}

void convert(int a){
    for(int i = 0;i < 16;i++){
        num[i] = a % 2;
        a /= 2;
    }
}

int main(){
    for(int r = 1;r <= 4;r++){
        scanf("%s", cs);
        for(int c = 1;c <= 4;c++)
            board[r][c] = cs[c - 1];
    }

    int opt = 100;
    for(int i = 0;i < 65536;i++){
        // copy
        for(int r = 1;r <= 4;r++){
            for(int c = 1;c <= 4;c++)
                temp[r][c] = board[r][c];
        }

        convert(i);
        int cnt = 0;
        for(int j = 0;j < 16;j++){
            if(num[j] == 0)
                continue;
            int r = j / 4 + 1;
            int c = j % 4 + 1;
            flip(r, c);
            cnt++;
        }
        if(isValid()){
            if(cnt < opt)
                opt = cnt;
        }
    }
    if(opt == 100)
        printf("Impossible\n");
    else
        printf("%d\n", opt);

    return 0;
}
