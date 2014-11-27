#include <stdio.h>

const int BIG = 1010000;
const int LIMIT = 30;

bool appeared[BIG];
int queue[BIG];
int parent[BIG];// 记录父节点下标
bool fork_with_one[BIG];// 记录如何由父节点得到子节点(甲:乘以10后加1, 乙:乘以10后加2)
int result[LIMIT + 10];// 记录最终数据

int main(){
	int head = 0;
	int tail = 0;

	int n;
	scanf("%d", &n);

	queue[tail++] = 0;

	int ends_with[3];
	bool found = false;
	while(head != tail){
		int temp = queue[head++];
		// printf("Head element: %d\n", temp);
		for(int i = 1;i <= 2;i++){// 得到两个子节点
			ends_with[i] = (10 * temp + i) % n;
			// printf("Number calculated: %d\n", ends_with[i]);
		}

		for(int i = 1;i <= 2;i++){
			if(!appeared[ends_with[i]]){
				appeared[ends_with[i]] = true;
				queue[tail++] = ends_with[i];
				parent[ends_with[i]] = temp;
				fork_with_one[ends_with[i]] = (i == 1);
			}
			if(appeared[0]){
                found = true;
                break;
			}
		}
		if(found)// 如果找到目标则跳出while循环
            break;
	}

	if(!found) {// 没有找到
		printf("Impossible\n");
	} else {// 如果找到的话, 还需要进一步判定数据长度是否合乎要求
		int len = 0;
		int current = 0;
		while(len <= LIMIT){
			result[len] = fork_with_one[current]?1:2;
			// printf("len: %d, result[len]: %d\n", len, result[len]);
			current = parent[current];
			len++;
			if(current == 0)
				break;
		}
		if(len > LIMIT){
			printf("Impossible\n");
		} else {
			for(int i = len - 1;i >= 0;i--)
				printf("%d", result[i]);
            putchar('\n');
		}
	}

	return 0;
}
