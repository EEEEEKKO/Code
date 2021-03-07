#include<bits/stdc++.h>
using namespace std;
int read(){//读入优化
	int x=0;bool f=0;char c=getchar();
	while (c<'0'||c>'9'){if (c=='-')f=1;c=getchar();}
	while (c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
priority_queue<int,vector<int> > q1;//大根堆
priority_queue<int,vector<int>,greater<int> > q2;//小根堆
int main(){
	int n=read();q1.push(read());
	cout<<q1.top()<<endl; 
	for (int i=2;i<=n;i++){
		int input=read();//等同于cin>>input
		if (input>q1.top()) q2.push(input);
			else q1.push(input);
		while (abs(q1.size()-q2.size())>1)
			if (q1.size()>q2.size()){q2.push(q1.top());q1.pop();}
				else{q1.push(q2.top());q2.pop();}
		if (i%2) cout<<(q1.size()>q2.size()?q1.top():q2.top())<<endl;
	}
	return 0;
}
