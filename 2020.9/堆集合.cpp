#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

int h1_size, h2_size, h3_size, h4_size;

ll h1[500005], h2[500005], h3[500005], h4[500005];
ll x[500005], y[500005];

void swap(ll* a, ll* b) {
	ll t = *a; *a = *b; *b = t;
}

ll fabs(ll x) {
	if (x >= 0) return x;
	else return -x;
}

int read()
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

void insert_1(ll val) {//小根堆存大数 
	h1[++h1_size] = val;
	int now = h1_size, next;
	while (now > 1) {
		next = now >> 1;
		if (h1[next] <= h1[now]) break;
		swap(&h1[now], &h1[next]);
		now = next;
	}
}

void insert_3(ll val) {//小根堆存大数 
	h3[++h3_size] = val;
	int now = h3_size, next;
	while (now > 1) {
		next = now >> 1;
		if (h3[next] <= h3[now]) break;
		swap(&h3[now], &h3[next]);
		now = next;
	}
}

void insert_2(ll val) {//大根堆存小数 
	h2[++h2_size] = val;
	int now = h2_size, next;
	while (now > 1) {
		next = now >> 1;
		if (h2[next] >= h2[now]) break;
		swap(&h2[now], &h2[next]);
		now = next;
	}
}

void insert_4(ll val) {//大根堆存小数 
	h4[++h4_size] = val;
	int now = h4_size, next;
	while (now > 1) {
		next = now >> 1;
		if (h4[next] >= h4[now]) break;
		swap(&h4[now], &h4[next]);
		now = next;
	}
}

ll top_1() {
	return h1[1];
}

ll top_3() {
	return h3[1];
}

ll top_2() {
	return h2[1];
}

ll top_4() {
	return h4[1];
}

ll get_top_1() {
	ll out = h1[1];
	h1[1] = h1[h1_size--];
	int now = 1, next;
	while (now << 1 <= h1_size) {
		next = now << 1;
		if (next < h1_size && h1[next] > h1[next + 1]) next++;
		if (h1[now] <= h1[next]) return out;
		swap(&h1[now], &h1[next]);
		now = next;
	}
	return out;
}

ll get_top_3() {
	ll out = h3[1];
	h3[1] = h3[h3_size--];
	int now = 1, next;
	while (now << 1 <= h3_size) {
		next = now << 1;
		if (next < h3_size && h3[next] > h3[next + 1]) next++;
		if (h3[now] <= h3[next]) return out;
		swap(&h3[now], &h3[next]);
		now = next;
	}
	return out;
}

ll get_top_2() {
	ll out = h2[1];
	h2[1] = h2[h2_size--];
	int now = 1, next;
	while (now << 1 <= h2_size) {
		next = now << 1;
		if (next < h2_size && h2[next] < h2[next + 1]) next++;
		if (h2[now] >= h2[next]) return out;
		swap(&h2[now], &h2[next]);
		now = next;
	}
	return out;
}

ll get_top_4() {
	ll out = h4[1];
	h4[1] = h4[h4_size--];
	int now = 1, next;
	while (now << 1 <= h4_size) {
		next = now << 1;
		if (next < h4_size && h4[next] < h4[next + 1]) next++;
		if (h4[now] >= h4[next]) return out;
		swap(&h4[now], &h4[next]);
		now = next;
	}
	return out;
}

int main() {
	int T;
	T = read();
	for (int k = 1; k <= T; k++) {
		int n;
		n = read();
		scanf("%llf%llf", &x[1], &y[1]);
		ll midx, midy;
		ll sumx1 = 0, sumx2 = 0, sumy1 = 0, sumy2 = 0;
		insert_2(x[1]), insert_4(y[1]);
		sumx2 += x[1], sumy2 += y[1];
		for (int i = 2; i <= n; i++) {
			scanf("%llf%llf", &x[i], &y[i]);
			ll inputx = x[i], inputy = y[i];
			if (inputx >= top_2()) {
				insert_1(inputx);
				sumx1 += inputx;
			}
			else {
				insert_2(inputx);
				sumx2 += inputx;
			}
			while (fabs(h1_size - h2_size) > 1) {
				if (h1_size > h2_size) {
					sumx2 += top_1();
					sumx1 -= top_1();
					insert_2(get_top_1());
				}
				else {
					sumx1 += top_2();
					sumx2 -= top_2();
					insert_1(get_top_2());
				}
			}
			if (inputy >= top_4()) {
				insert_3(inputy);
				sumy1 += inputy;
			}
			else {
				insert_4(inputy);
				sumy2 += inputy;
			}
			while (fabs(h3_size - h4_size) > 1) {
				if (h3_size > h4_size) {
					sumy2 += top_3();
					sumy1 -= top_3();
					insert_4(get_top_3());
				}
				else {
					sumy1 += top_4();
					sumy2 -= top_4();
					insert_3(get_top_4());
				}
			}
			if (h1_size < h2_size) midx = top_1();
			if (h1_size == h2_size) midx = (top_1() + top_2()) / 2;
			if (h1_size > h2_size) midx = top_2();
			if (h3_size < h4_size) midy = top_3();
			if (h3_size == h4_size) midy = (top_3() + top_4()) / 2;
			if (h3_size > h4_size) midy = top_4();
			ll ans = h2_size * midx - sumx2 + sumx1 - h1_size * midx;
			ans += h4_size * midy - sumy2 + sumy1 - h3_size * midy;
			printf("%.4llf\n", ans);
		}
	}
}


