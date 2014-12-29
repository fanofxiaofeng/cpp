#include <stdio.h>
#include <string.h>

const int N = 105000;

char cs[N];

int map[128];
int cnt[37];

void init(void);

int main(){
	init();

	while(scanf("%s", cs) != EOF){
        int len = strlen(cs);
		cs[len++] = '!';

        // printf("cs is: %s\n", cs);

        for(int i = 2;i <= 36;i++){
            int temp = 0;
            bool preValid = false;
            for(int j = 0;j < len;j++){
                char c = cs[j];
                if(map[c] >= i){
                    if(preValid)
                        temp++;
                    preValid = false;
                } else
                    preValid = true;
            }
            cnt[i] += temp;
        }

        for(int i = 0;i < len;i++)
            cs[i] = '\0';
	}

    int opt = -1;
    int k = -1;
    for(int i = 2;i <= 36;i++){
        if(cnt[i] > opt){
            opt = cnt[i];
            k = i;
        }
    }

	printf("%d %d\n", k, opt);

	return 0;
}

void init(void){
	for(int i = '0';i <= '9';i++)
		map[i] = i - '0';
	for(char c = 'A';c <= 'Z';c++)
		map[c] = c - 'A' + 10;
	map['!'] = 36;
}
