#include <iostream>
#include <cstdio>

using namespace std;

struct time{
    int h;
    int m;
    int s;
};

bool earlier_than(struct time, struct time);

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int k;
        cin >> k;

        string first_id;
        string last_id;
        struct time first_time;
        struct time last_time;

        cin >> first_id;
        last_id = first_id;

        scanf("%d:%d:%d", &first_time.h, &first_time.m, &first_time.s);
        scanf("%d:%d:%d", &last_time.h, &last_time.m, &last_time.s);

        for(int j = 1;j < k;j++){
            string temp_id;
            cin >> temp_id;
            struct time temp_time;
            scanf("%d:%d:%d", &temp_time.h, &temp_time.m, &temp_time.s);
            if(earlier_than(temp_time, first_time)){
                first_id = temp_id;
                first_time = temp_time;
            }

            scanf("%d:%d:%d", &temp_time.h, &temp_time.m, &temp_time.s);
            if(earlier_than(last_time, temp_time)){
                last_id = temp_id;
                last_time = temp_time;
            }
        }
        cout << first_id << " " << last_id << endl;
    }

    return 0;
}

bool earlier_than(struct time a, struct time b){
    if(a.h != b.h)
        return a.h < b.h;
    if(a.m != b.m)
        return a.m < b.m;
    return a.s < b.s;
}
