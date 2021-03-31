#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 2000005;

struct Node{
    LL time;
    int tag;
}Act[N];

bool cmp(const struct Node &a, const struct Node &b){
    return a.time == b.time? (a.tag > b.tag) : (a.time < b.time);
}

int main(){
    int n;
    cin >> n;
    int num = 0, ret = 0;
    LL st = 0,ed = 0;
    for(int i = 0; i < n; i++){
        cin >> st >> ed;
        Act[num].time = st,Act[num++].tag = -1;
        Act[num].time = ed,Act[num++].tag = 1;
    }
    sort(Act,Act+num,cmp);
    int tmp = 0;
    for(int i = 0; i < num; i++){
        if(Act[i].tag == -1) tmp++;
        else tmp--;
        ret = max(ret,tmp);
    }
    cout << ret << endl;
}