#include<bits/stdc++.h>

using namespace std;

long long int hancard[200005];
long long int check;
long long int cnt = 0;

typedef struct node{
	long long int num;
	struct node *next;
}NODE;

long long int out(NODE *p){
	long long int hand;
	while(p->next->next != NULL) p = p->next;
	hand = p->next->num;
	p->next = NULL;
	return hand;
}

void in(NODE *h, long long int pile){
	NODE *p;
	p = (NODE*)malloc(sizeof(NODE));
	p->num = pile;
	p->next = h->next;
	h->next = p;
}

void sorin(NODE *p, long long int inhand){
	NODE *q, *c;
	q = (NODE*)malloc(sizeof(NODE));
	c = (NODE*)malloc(sizeof(NODE));
	c = p;
	q->num = inhand;
	while(p->next->num < q->num && p->next != NULL){
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	while(c->next != NULL) c = c->next;
	check = c->num;
}

int compare(NODE *p){
	p = p->next;
	while(p->num >= p->next->num && p->next != NULL){
		p = p->next;
	}
	if(p->next == NULL) return 0;
	else return 1;
}

int main(){
	long long int n;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &hancard[i]);
	}
	NODE *h1,*h2;
	h1 = (NODE*)malloc(sizeof(NODE));
	h2 = (NODE*)malloc(sizeof(NODE));
	h1->next = NULL, h2->next = NULL;
	h1->num = -1, h2->num = -1;
	long long int pcard;
	for(int i = 0; i < n; i++){
		scanf("%lld", &pcard);
		in(h1,pcard);
	}
	for(int i = n-1; i >= 0; i--){
		in(h1,hancard[i]);
	}
	NODE *q;
	q = (NODE*)malloc(sizeof(NODE));
	q = h1;
	while(q->next!=NULL) q = q->next;
	check = q->num;
	int cpr = 1;
	while(cpr){
		while(check){
			long long int bot;
			bot = out(h1);
			in(h2,bot);
			long long int top;
			top = out(h2);
			sorin(h1,top);
			cnt++;
		}
		check = out(h2);
		cpr = compare(h2);
	}
	printf("%lld\n", cnt);
}
		
	



