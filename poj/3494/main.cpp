#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char> > &);
int largestRectangleArea(vector<int> &);

int main(){
    int m;
    int n;
    while(cin >> m >> n){
        vector<vector<char> > matrix(m);
        vector<char> rowvec(n);
        for(int row = 0;row < m;row++)
            matrix[row] = rowvec;

        for(int row = 0;row < m;row++){
            for(int col = 0;col < n;col++){
                int c = '\0';
                do{
                    c = getchar();
                }while(c != '0' && c != '1');
                matrix[row][col] = c;
            }
        }

        int opt = maximalRectangle(matrix);
        cout << opt << endl;
    }
    return 0;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.size() == 0)
        return 0;

    vector<vector<int> > record(matrix.size());
    vector<int> rowvec(matrix[0].size());

    for(int i = 0;i < record.size();i++)
        record[i] = rowvec;

    for(int row = 0;row < record.size();row++){
        for(int col = 0;col < record[0].size();col++){
            if(matrix[row][col] == '0')
                record[row][col] = 0;
            else// '1'
                record[row][col] = (row == 0)?(1):(record[row - 1][col] + 1);
        }
    }

    int opt = 0;
    for(int row = 0;row < record.size();row++){
        int temp = largestRectangleArea(record[row]);
        if(temp > opt)
            opt = temp;
    }

    return opt;
}

int largestRectangleArea(vector<int> &height) {
    vector<int> hstack;
    vector<int> self;

    vector<int> lpos(height);
    vector<int> rpos(height);

    for(int i = 0;i < height.size();i++){
        while(hstack.empty() == false && hstack[hstack.size() - 1] >= height[i]){
            hstack.pop_back();
            self.pop_back();
        }

        if(hstack.empty())
            lpos[i] = 0;
        else// hstack[hstack.size() - 1] < height[i]
            lpos[i] = self[self.size() - 1] + 1;

        self.push_back(i);
        hstack.push_back(height[i]);
    }

    hstack.clear();

    for(int i = height.size() - 1;i >= 0;i--){
        while(hstack.empty() == false && hstack[hstack.size() - 1] >= height[i]){
            hstack.pop_back();
            self.pop_back();
        }

        if(hstack.empty())
            rpos[i] = height.size() - 1;
        else
            rpos[i] = self[self.size() - 1] - 1;

        self.push_back(i);
        hstack.push_back(height[i]);
    }

    int opt = 0;

    for(int i = 0;i < height.size();i++){
        int temp = height[i] * (rpos[i] - lpos[i] + 1);
        if(temp > opt)
            opt = temp;
    }

    return opt;
}
