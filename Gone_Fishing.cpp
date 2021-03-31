#include<bits/stdc++.h>
using namespace std;
const int N = 27;
int t[N],f[N],d[N];
int Ltime[N][N];

struct Node{
    int id,f,d;
    bool operator <(const Node a)const{
        if(this->f == a.f) return this->id > a.id;
        return this->f < a.f;
    }
};

Node fish[N];

int main(){
    int n,h;
    int enter = 0;
    while(cin >> n && n){
        if(enter++) cout << endl;
        memset(Ltime,0,sizeof(Ltime));
        cin >> h;
        h *= 12;
        for(int i = 0; i < n; i++) cin>>fish[i].f,fish[i].id = i;
        for(int i = 0; i < n; i++) cin>> fish[i].d;
        for(int i = 0; i < n-1; i++) cin >> t[i];
        int ans = 0,pos = 0;
        for(int i = 0; i < n; i++){
            int wt = 0;
            for(int j = 0; j < i; j++) wt+=t[j];
            priority_queue<Node> lake;
            for(int j = 0; j <= i; j++) lake.push(fish[j]);
            int tmp = 0,ft = h - wt;
            for(int j = 0; j < ft; j++){
                Node now = lake.top();
                tmp+=now.f;
                Ltime[i][now.id]+=5;
                lake.pop();
                lake.push(Node{now.id,max(now.f-now.d,0),now.d});
            }
            if(ans < tmp){
                ans = tmp;
                pos = i;
            }
        }
        cout << Ltime[pos][0];
        for(int i = 1; i < n; i++) cout << ", " << Ltime[pos][i];
        cout << endl;
        cout <<  "Number of fish expected: "<< ans << endl;
    }
}
