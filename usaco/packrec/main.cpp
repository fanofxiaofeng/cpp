/*
ID: jyjz2001
TASK: packrec
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

void generateAllPerm(vector<vector<int> > &);
void generateAll(vector<vector<int> > &);
void fun(vector<vector<int> > &, vector<vector<int> > &, vector<vector<int> > &);
void process(const int, const int, int &, vector<vector<int> > &);

int way = -1;

int main(){
    ifstream f("packrec.in");

    vector<vector<int> > data;// 用于存储矩形尺寸

    // 将所有的矩形尺寸信息存储在data中
    for(int i = 0;i < 4;i++){
        vector<int> rec;
        for(int j = 0;j < 2;j++){
            int temp;
            f >> temp;
            rec.push_back(temp);
        }
        data.push_back(rec);
    }

    vector<vector<int> > allPerm;
    generateAllPerm(allPerm);
    // cout << allPerm.size() << endl;

    vector<vector<int> > ivv;
    generateAll(ivv);
    /*
    for(int row = 0;row < ivv.size();row++){
        for(int col = 0;col < ivv[row].size();col++)
            cout << ivv[row][col];
        cout << endl;
    }
    */
    fun(allPerm, ivv, data);
    f.close();
    return 0;
}

void generateAllPerm(vector<vector<int> > &ivv){
    ivv.clear();

    vector<int> ivec;
    for(int i = 0;i < 4;i++)
        ivec.push_back(i);

    // now, ivec = [0, 1, 2, 3]
    do{
        ivv.push_back(ivec);
    } while(next_permutation(ivec.begin(), ivec.end()));
}

void generateAll(vector<vector<int> > &ivv){
    ivv.clear();

    for(int i = 0;i < 16;i++){

        vector<int> ivec;

        for(int j = 0;j < 4;j++)
            ivec.push_back((i >> j) % 2);

        ivv.push_back(ivec);
    }
}

void fun(vector<vector<int> > &allPerm, vector<vector<int> > &ivv, vector<vector<int> > &data){
    int opt = 10000 * 10000;
    vector<vector<int> > result;

    vector<int> couple;

    vector<vector<int> > copy;
    for(int i = 0;i < 4;i++)
        copy.push_back(data[i]);

    // printf("The size of allPerm is:%d\n", allPerm.size());
    // printf("The size of ivv is:%d\n", ivv.size());
    // printf("The size of data is:%d\n", data.size());

    for(int i = 0;i < allPerm.size();i++){

        for(int pos = 0;pos < 4;pos++)
            data[pos] = copy[allPerm[i][pos]];
        /*
        for(int pos = 0;pos < 4;pos++)
            printf("%d%d ", data[pos][0], data[pos][1]);
        printf("\n");
        */

        for(int j = 0;j < ivv.size();j++){
            int h[4];
            int d[4];

            for(int k = 0;k < 4;k++){
                h[k] = data[k][(ivv[j][k] == 0)?0:1];
                d[k] = data[k][(ivv[j][k] == 0)?1:0];
            }

            int width;
            int height;


            way = 1;
            // 方法1
            width = 0;
            height = 0;
            for(int k = 0;k < 4;k++){
                width += d[k];
                height = (h[k] > height)?h[k]:height;
            }
            process(height, width, opt, result);

            way = 2;
            // 方法2
            width = 0;
            height = 0;

            width = d[0] + d[1] + d[2];
            width = (d[3] > width)?d[3]:width;

            for(int k = 0;k < 3;k++)
                height = (h[k] > height)?h[k]:height;

            height += h[3];
            process(height, width, opt, result);

            // 方法3
            way = 3;
            width = 0;
            height = 0;

            width = d[0] + d[1];
            width = (d[2] > width)?d[2]:width;
            width += d[3];

            height = (h[0] >= h[1])?h[0]:h[1];
            height += h[2];
            height = (h[3] > height)?h[3]:height;
            process(height, width, opt, result);

            // 方法4
            way = 4;
            width = 0;
            height = 0;

            width = d[0] + d[3];
            width += (d[1] >= d[2])?d[1]:d[2];

            height = (h[0] >= h[3])?h[0]:h[3];
            height = (h[1] + h[2] > height)?(h[1] + h[2]):height;
            process(height, width, opt, result);

            // 方法5
            way = 5;
            width = 0;
            height = 0;

            width = (d[0] >= d[1])?d[0]:d[1];
            width += d[2] + d[3];

            height = (h[2] >= h[3])?h[2]:h[3];
            height = (h[0] + h[1] > height)?(h[0] + h[1]):height;
            process(height, width, opt, result);

            // 方法6
            if((h[3] >= h[1]) && (d[0] + d[2] <= d[1] + d[3]) && (d[0] <= d[1])){
                way = 6;
                width = 0;
                height = 0;

                width = d[1] + d[3];

                height = h[0] + h[1];
                height = (h[2] + h[3] > height)?(h[2] + h[3]):height;
                process(height, width, opt, result);
            }
        }
    }
    ofstream of("packrec.out");
    of << opt << endl;
    map<int, int> imap;
    for(int i = 0;i < result.size();i++){
        if(result[i][0] <= result[i][1])
            imap[result[i][0]] = result[i][1];
        else
            imap[result[i][1]] = result[i][0];
    }
    for(map<int, int>::iterator it = imap.begin();it != imap.end();it++)
        of << (it->first) << " " << (it->second) << endl;
    of.close();
}

void process(const int height, const int width, int & opt, vector<vector<int> > &result){
    int cur = height * width;
    if(cur < opt){
        // cout << __LINE__ << endl;
        // cout << "WAY:" << way << endl;
        // cout << "!!!!!!!!!!!!!!" << endl;
        // cout << cur << endl;

        opt = cur;

        result.clear();

        vector<int> couple;
        couple.push_back(height);
        couple.push_back(width);
        result.push_back(couple);
    } else if (cur == opt){
        vector<int> couple;
        couple.push_back(height);
        couple.push_back(width);
        result.push_back(couple);
    }
}
