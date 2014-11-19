/*
ID: jyjz2001
TASK: hamming
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

const int big = 260;

int table[big][big];

int howMany(int);// 计算有多少数据在考虑范围内, 2的b次幂个
int countOne(int);// 计算一个数字的二进制表示中有多少个1
void fillTable(int);// 向table中填入合适的值
bool coreFun(const int, const int, const int, vector<int> &, vector<int> &);// 起核心作用的递归函数
void output(vector<int> &, ofstream &);

int main(){
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    int n;// 数量
    int b;// 位数
    int d;// 距离

    fin >> n >> b >> d;

	// 计算(所需范围内的)任意两个数hamming距离
    int size = howMany(b);
    fillTable(size);

	// 将结果保存在result中, 相当于一个栈的功能
    vector<int> result;

	// 当前备选数据保存在data中
    vector<int> data;
    for(int i = 0;i < size;i++)
        data.push_back(i);

	// 计算	
    coreFun(n, size, d, result, data);

	// 输出结果	
    output(result, fout);

    fin.close();
    fout.close();

    return 0;
}

bool coreFun(const int n, const int size, const int d, vector<int> &result, vector<int> &choice){
    // n 需要选出的数字个数
    // size
    // d 两两之间的距离都要大于等于d
    for(int i = 0;i < choice.size();i++){
        int cur = choice[i];// 当前挑中的值        
        result.push_back(cur);
        if(result.size() == n)// 已经挑选出了足够多的元素            
            return true;        

		// 计算新的备选数据(是原有备选数据的一个真子集)
        vector<int> newChoice;
        for(int j = i + 1;j < choice.size();j++){
            if(countOne(choice[j] ^ cur) >= d)
                newChoice.push_back(choice[j]);            
        }
		
        bool judge = coreFun(n, size, d, result, newChoice);
        if(judge)// 本分支下可以完成
            return true;
        else// 当前值下的所有分支都非所求, 只能继续下一个for循环
            result.pop_back();
    }
    return false;
}

void fillTable(int size){
    for(int row = 0;row < size;row++){
        for(int col = 0;col < size;col++)
            table[row][col] = countOne(row ^ col);
    }
}

int howMany(int k){
    if(k == 0)
        return 1;
    else
        return 2 * howMany(k - 1);
}

int countOne(int a){
    int total = 0;
    while(a != 0){
        total += a % 2;
        a /= 2;
    }
	
    return total;
}

void output(vector<int> &result, ofstream &fout){
	// 大致的要求是每行输出10个
    for(int i = 0;i < result.size();i++){
        fout << result[i];
        if(i + 1 == result.size()){
            fout << endl;
            return;
        }
        if(i % 10 != 9)
            fout << " ";
        else
            fout << endl;
    }
}
