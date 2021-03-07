#include<bits/stdc++.h>

using namespace std;

queue<string> stu;

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		char ch;
		ch = getchar();
		if(ch == 'A'){
			while((ch = getchar())!= ' ');
			string s;
			getline(cin,s);
			stu.push(s);
		}	
		if(ch == 'Q'){
			string s;
			getline(cin,s);
			if(stu.size()){
				if(s == "ueueHead"){
					string head = stu.front();
					cout << head << endl;
				}
				if(s == "ueueTail"){
					string tail = stu.back();
					cout << tail << endl;
				}
			}
			else{
				printf("Empty queue\n");
			}
		}
		if(ch == 'L'){
			string s;
			getline(cin,s);
			if(stu.size()) stu.pop();
		}
	}
}
			
