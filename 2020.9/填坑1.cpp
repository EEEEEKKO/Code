#include<bits/stdc++.h>

using namespace std;

stack<int> hole;

int main() {
	int n;
	while ((scanf("%d", &n) != EOF)) {
		for (int i = 1; i <= n; i++) {
			int h;
			scanf("%d", &h);
			if (hole.empty()) {
				hole.push(h);
			}
			else {
				if (abs(hole.top() - h) % 2 == 0) {
					hole.pop();
				}
				else {
					hole.push(h);
				}
			}
		}
		if (hole.size() <= 1) printf("YES\n");
		else printf("NO\n");
		while(hole.size()) hole.pop();
	}
}
