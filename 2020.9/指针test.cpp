#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	char choice;
	struct node * link;
}NODE;

int main(){
	NODE *h1,*p;
	h1 = (NODE*)malloc(sizeof(NODE));
	p = (NODE*)malloc(sizeof(NODE));
	h1->link = NULL;
	h1->choice = '1';
	char ch;
	while((ch = getchar()) != '\n'){
		p = (NODE*)malloc(sizeof(NODE));
		p->choice = ch;
		p->link = h1->link;
		h1->link = p;
	}
	NODE *q = h1->link;
	while(q != NULL){
		printf("%c",q->choice);
		q = q->link;
	} 
}
