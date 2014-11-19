/*
ID: jyjz2001
TASK: pprime
LANG: C++
*/
#include <iostream>
#include <deque>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

const int n = 4;

int choice[] = {1, 3, 7, 9};
//            0   1   2  3   4   5    6    7     8
int map[] = {-1, -1, -1, 1, 10, 10, 100, 100, 1000};

bool isPrime(const int);
void fill(vector<vector<int> > &, const int);
int reverse(int, const int);

int main(){
    ifstream f("pprime.in");
    ofstream of("pprime.out");

    vector<vector<int> > matrix(9);

    // 长度为1者
    matrix[1].push_back(5);
    matrix[1].push_back(7);

    matrix[2].push_back(11);

    for(int i = 3;i < 9;i++){
        fill(matrix, i);
    }
    int kan = 6;

    int a;
    int b;
    f >> a >> b;
    bool over = false;
    for(int i = 1;i < 9;i++){
        for(int j = 0;j < matrix[i].size();j++){
            int temp = matrix[i][j];
            if(temp < a)
                continue;
            if(temp > b){
                over = true;
                break;
            }
            // temp >= a && temp <= b
            if(isPrime(temp))
                of << temp << endl;
        }
        if(over)
            break;
    }
    f.close();
    of.close();

    return 0;
}

bool isPrime(const int n){
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

void fill(vector<vector<int> > &matrix, const int width){
    if(width % 2 == 0){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < map[width];j++){
                int value = choice[i] * map[width] * map[width] * 10;
                value += j * map[width] * 10;
                int r = reverse(j, width / 2 - 1);
                value += r * 10;
                value += choice[i];
                matrix[width].push_back(value);
            }
        }
    } else {// width % 2 == 1
        for(int i = 0;i < n;i++){
            for(int j = 0;j < map[width];j++){
                int r = reverse(j, width / 2 - 1);
                for(int mid = 0;mid < 10;mid++){
                    int value = choice[i] * map[width] * map[width] * 10 * 10;
                    value += j * map[width] * 10 * 10;
                    value += mid * map[width] * 10;
                    value += r * 10;
                    value += choice[i];
                    matrix[width].push_back(value);
                }
            }
        }
    }
}

int reverse(int value, const int width){
    int r = 0;
    for(int i = 0;i < width;i++){
        r = 10 * r + (value % 10);
        value /= 10;
    }
    return r;
}
