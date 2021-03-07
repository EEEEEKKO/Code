#include<bits/stdc++.h>

using namespace std;

const int mxn = 1e6 + 5;

stack<int> color;
stack<int> height;

struct house {
	int c;
	int h;
}flat[mxn];

int ans,col[mxn];

inline int read()
{
	int x = 0, f = 1;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')	f = -1;
		ch = getchar();
	}
	do {
		x = x * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	return x * f;
}

void print(int n, int i, int a){
	if(i < n){
		printf("%d ", a);
	}
	else printf("%d\n", a);
}

int main() {
	int T;
	T = read();
	for (int k = 0; k < T; k++) {
		int n;
		n = read();
		memset(col, 0, sizeof(col));
		ans = 0;
		memset(flat, 0, sizeof(flat));
		for (int i = 1; i <= n; i++) {
			flat[i].c = read();
		}
		for (int i = 1; i <= n; i++) {
			flat[i].h = read(); 
		}
		for (int i = 1; i <= n; i++) {
			if (color.empty()) {
				color.push(flat[i].c);
				col[flat[i].c]++;
				height.push(flat[i].h);
				ans = 1;
				print(n,i,ans);
			}
			else {
				if (flat[i].h < height.top()) {
					color.push(flat[i].c);
					height.push(flat[i].h);
					if (col[flat[i].c] >= 1) col[flat[i].c]++;
					else {
						col[flat[i].c]++;
						ans++;
					}
					
					print(n,i,ans);
				}
				else {
					while(height.size() && flat[i].h >= height.top()) {
						if (col[color.top()] > 1) col[color.top()]--;
						else{
							col[color.top()]--;
							ans--;
						}
					    height.pop();
						color.pop();
					}
					color.push(flat[i].c);
					height.push(flat[i].h);
					
					if (col[flat[i].c] >= 1) col[flat[i].c]++;
					else {
						col[flat[i].c]++;
						ans++;
					}
						
					print(n,i,ans);
				}
			}
		}
		while (color.size()) color.pop();
		while (height.size()) height.pop();
	}
}
						

