#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

vector<int> data;

int temp;

void showVec(vector<int> &);

int main(){
	int n;
	scanf("%d", &n);
	if(n == 0)
		return 0;
	
	for(int i = 0;i < n;i++){
		scanf("%d", &temp);
		data.push_back(temp);
	}

	for(int loop = 0;loop < 2;loop++){
		sort(data.begin(), data.end());

		int max = data[data.size() - 1];
		vector<int> cnt(max + 1);
		vector<int> over(cnt);

		for(int i = 0;i < data.size();i++)
			cnt[data[i]]++;
		
		for(int i = max - 1;i >= 0;i--)
			over[i] = over[i + 1] + cnt[i + 1];
		
		int sum = data.size();
			
		data.clear();
		data.push_back(sum);
		for(int i = 1;over[i] != 0;i++)
			data.push_back(over[i]);
		// showVec(cnt);
		// showVec(over);
		// showVec(data);
	}

	for(int i = 0;i < data.size();i++)
		printf("%d\n", data[i]);
	
	return 0;
}

void showVec(vector<int> &ivec){
	printf("begin\n");
	for(vector<int>::iterator it = ivec.begin();it != ivec.end();it++)
		printf("%d\n", (*it));
	printf("end\n");
}

