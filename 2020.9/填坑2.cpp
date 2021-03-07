#include<bits/stdc++.h>

using namespace std;

stack<int> hole;

int main() {
	int n;
	while (scanf("%d", &n)!= EOF) {
		int flag = 0;
		int maxn = -1;
		for (int i = 1; i <= n; i++) {
			int h;
			scanf("%d", &h);
			maxn = max(maxn, h);
			if (hole.empty()) {
				hole.push(h);
			}
			else {
				if (h < hole.top()) {
					hole.push(h);
				}
				else if (h == hole.top()) {
					hole.pop();
				}
				else if (h > hole.top()) {
					flag = 1;
				}
			}
		}
		if (flag == 0 && hole.size() == 0) printf("YES\n");
		else if (hole.size() == 1 && hole.top() == maxn && flag == 0) printf("YES\n");
		else printf("NO\n");
		while (hole.size()) hole.pop();
	}
}
