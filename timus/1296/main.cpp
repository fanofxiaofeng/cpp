#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << n << endl;
        return 0;
    }

    int data;
    cin >> data;

    int opt = 0;
    int acc_sum = data;
    int pre_least = 0;

    if(data > opt)
        opt = data;

    for(int i = 1;i < n;i++){
        if(acc_sum < pre_least)
            pre_least = acc_sum;

        int temp;
        cin >> temp;
        acc_sum += temp;

        temp = acc_sum - pre_least;
        if(temp > opt)
            opt = temp;
    }
    cout << opt << endl;

    return 0;
}
