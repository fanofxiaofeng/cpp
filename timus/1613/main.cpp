#include <stdio.h>
#include <map>
#include <vector>

using std::map;
using std::vector;

void query(map<int, vector<int> > &, int, int, int);

int main(){
	int n;
	scanf("%d", &n);

	map<int, vector<int> > imap;
	int data;
	for(int i = 1;i <= n;i++){
		scanf("%d", &data);		
		imap[data].push_back(i);		
	}

	int q;
	scanf("%d", &q);

	int l, r;
	int target;
	for(int i = 0;i < q;i++){
		scanf("%d %d %d", &l, &r, &target);		
		query(imap, l, r, target);		
	}

	return 0;
}

void query(map<int, vector<int> > &imap, int l, int r, int target){
	if(imap.count(target) == 0){
		putchar('0');
		return;
	}
	vector<int> &temp = imap[target];
	int low = 0;
	int high = temp.size() - 1;
	int mid;
	while(low <= high){
		mid = (high + low) / 2;
		int value = temp[mid];
		if(value >= l && value <= r){
			putchar('1');
			return;
		} else if (value < r) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	putchar('0');
}
