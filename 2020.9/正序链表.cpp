#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	char words;
	struct node *next;
}NODE;

string s;
long long int flag[400010];

void add(NODE *p, char ch){
	while(p->next != NULL){
		p = p->next;
	}
	p->next =(NODE*)malloc(sizeof(NODE));
	p->next->words = ch;
	p->next->next = NULL;
	return;
}

void move(NODE *p){
	NODE *q;
	q = (NODE*)malloc(sizeof(NODE));
	q = p;
	while(q->next != NULL){
		q = q->next;
	}
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp = p->next;
	p->next = p->next->next;
	temp->next = q->next;
	q->next = temp;
}

void print(NODE *p){
	while(p != NULL){
		printf("%c", p->words);
		p = p->next;
	}
	printf("\n");
}
	

int main(){
	NODE *head;
	head = (NODE*)malloc(sizeof(NODE)); 
	head->words = '1';
	head->next = NULL;
	getline(cin,s);
	char ch;
	while((ch = getchar()) != '\n'){
		add(head,ch);
	}
	NODE *q = head->next;
	int t = 0;
	while(q != NULL){
		t++;
		q = q->next;
	}
	NODE *check;
	check = (NODE*)malloc(sizeof(NODE));
	s = s + s;
	long long int len = s.length();
	long long int k = 0;
	long long int pos = 0;
	while(pos < len/2){
		check = head->next;
		memset(flag,0,sizeof(flag));
		for(long long int j = pos; j < pos + len/2; j++){
			if(s[j] == head->next->words){
				pos = j + 1;
				break;
			}
		}
		for(long long int j = pos - 1; j < pos - 1 + len/2; j++){
			if(check == NULL) break;
			if(s[j] == check->words){
				flag[k++] = j;
				check = check->next;
			}
		}
		if(k == t) break;
		else k = 0;
	} 
	for(int i = 0; i < t; i++){
		if(flag[i] + 1 > len/2){
			flag[i] = flag[i] + 1 - len/2;
		}
		else{
			flag[i] = flag[i] + 1;
		}
	}
	sort(flag,flag+t);
	for(int i = 0; i < t-1; i++){
		printf("%lld ", flag[i]);
	}
	printf("%lld\n", flag[t-1]);
}
	
