#include <stdio.h>

const int big = 130000;

int a[big];

void max_heapify(int, int);
void swap(int &, int &);
void show_median(int);
void swim(int);

int main(){
	int n;
	scanf("%d", &n);

	int capacity = n / 2 + 1;// 有效元素有capacity这么多个

	for(int i = 1;i <= capacity;i++)
		scanf("%d", &a[i]);
    for(int i = capacity / 2;i >= 1;i--)
        max_heapify(i, capacity);

	for(int i = capacity + 1;i <= n;i++){
		scanf("%d", &a[capacity + 1]);
		swim(capacity + 1);
		swap(a[1], a[capacity + 1]);
		max_heapify(1, capacity);
	}

	show_median(n);

	return 0;
}

void swim(int pos){
	while(pos != 1){ // not root
		int parent = pos / 2;
		if(a[parent] < a[pos]){
			swap(a[parent], a[pos]);
			pos /= 2;
		} else
            return;
	}
}

void show_median(int n){
	int capacity = n / 2 + 1;
	if(n % 2 == 1){// 总的元素个数为奇数个, 刚好不用特殊处理
		printf("%d.0\n", a[capacity]);
	} else {
		int v1 = a[1];
		int v2 = (a[2] >= a[3])?a[2]:a[3];// 如果n恰为2, 则a[3]在范围外,但是a[3]一开始值为0,这样刚好没有影响

		if(v1 % 2 == v2 % 2)
			printf("%d.0\n", (v1 / 2 + v2 / 2 + (v1 % 2)));
		else
			printf("%d.5\n", (v1 / 2 + v2 / 2));
	}
}

void max_heapify(int pos, int n){
	int record = pos;
	int left = 2 * pos;
	int right = left + 1;

	if(left <= n && a[left] > a[record])
		record = left;

	if(right <= n && a[right] > a[record])
		record = right;

	if(record != pos){
		swap(a[pos], a[record]);
		max_heapify(record, n);
	}
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
