#include<bits/stdc++.h>//可做加减乘除取模和幂运算，可检查表达式是否正确
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OF -1
#define OK 1
#define ERROR 0
#define N 0xffffff
using namespace std;
typedef double Status;
typedef double SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}CMyStack_i;

Status InitStack_i(CMyStack_i *S) //构造一个空栈
{
	S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base) exit(OF);
		S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push_i(CMyStack_i *S,SElemType e) //插入元素e为新的栈顶元素
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) exit(OF);
			S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;
}

Status Pop_i(CMyStack_i *S) //用e返回栈顶元素并删除栈顶元素
{
	double ret;
	if(S->top==S->base)
		return ERROR;
	ret=*--S->top;
	return OK;
}

Status GetTop_i(CMyStack_i S) //返回栈顶元素
{	
	double ret;
	if(S.top==S.base)
		return ERROR;
	ret=*(--S.top);
	return ret;
}

Status StackEmpty_i(CMyStack_i S) //若栈为空，返回OK，否则返回ERROR
{
	if(S.top==S.base)
		return OK;
	else
		return ERROR;
}

Status StackFull_i(CMyStack_i S)  //判断栈满
{
	
	if(STACK_INIT_SIZE == (S.top-S.base))
		return OK;
	else
		return ERROR;
}

int StackLength_i(CMyStack_i S) //返回栈的长度
{
	return (S.top-S.base);
}

Status PrintElem_i(SElemType e) //visit指针函数的调用
{
	printf("%d\t",e);
	return OK;
}

Status StackTraverse_i(CMyStack_i S,Status(*visit)(SElemType)) //栈的遍历
{
	SElemType *p;
	p=S.base;
	while(p!=S.top)
	{
		if(!visit(*p))
			return ERROR;
		p++;
	}
	return OK;
}

Status ClearStack_i(CMyStack_i *S) //置为空栈
{
	S->top=S->base;
	return OK;
}

Status DestroyStack_i(CMyStack_i *S) //销毁栈
{
	free(S->base);
	S->base=NULL;
	S->top=NULL;
	S->stacksize=0;
	return OK;
}
///////////////---------------///////////////////
typedef struct{
	char *base;
	char *top;
	int stacksize;
}CMyStack_c;

char InitStack_c(CMyStack_c *S) //构造一个空栈
{
	S->base=(char *)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!S->base) exit(OF);
		S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

char Push_c(CMyStack_c *S,char e) //插入元素e为新的栈顶元素
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(char*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(char));
		if(!S->base) exit(OF);
			S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;
}

char Pop_c(CMyStack_c *S) //用e返回栈顶元素并删除栈顶元素
{	
	char ret;
	if(S->top==S->base)
		return ERROR;
	ret=*--S->top;
	return OK;
}

char GetTop_c(CMyStack_c S) //返回栈顶元素
{
	char ret;
	if(S.top==S.base)
		return ERROR;
	ret=*(--S.top);
	return ret;
}

char StackEmpty_c(CMyStack_c S) //若栈为空，返回OK，否则返回ERROR
{
	if(S.top==S.base)
		return OK;
	else
		return ERROR;
}

char StackFull_c(CMyStack_c S)  //判断栈满
{
	
	if(STACK_INIT_SIZE == (S.top-S.base))
		return OK;
	else
		return ERROR;
}

int StackLength_c(CMyStack_c S) //返回栈的长度
{
	return (S.top-S.base);
}

char PrintElem_c(char e) //visit指针函数的调用
{
	printf("%c\t",e);
	return OK;
}

char StackTraverse_c(CMyStack_c S,char(*visit)(char)) //栈的遍历
{
	char *p;
	p=S.base;
	while(p!=S.top)
	{
		if(!visit(*p))
			return ERROR;
		p++;
	}
	return OK;
}

char ClearStack_c(CMyStack_c *S) //置为空栈
{
	S->top=S->base;
	return OK;
}

char DestroyStack_c(CMyStack_c *S) //销毁栈
{
	free(S->base);
	S->base=NULL;
	S->top=NULL;
	S->stacksize=0;
	return OK;
}

class CExpression{
private:

CMyStack_c oper;
CMyStack_i num;
char operation[9] = {'+','-','*','/','(',')','#','^','%'};
int check[9][9] = {
	{ 1, 1,-1,-1,-1, 1, 1,-1,-1},    
    { 1, 1,-1,-1,-1, 1, 1,-1,-1},    
    { 1, 1, 1, 1,-1, 1, 1,-1, 1},    
    { 1, 1, 1, 1,-1, 1, 1,-1, 1},    
    {-1,-1,-1,-1,-1, 0,-2,-1,-1},    
    { 1, 1, 1, 1,-2, 1, 1, 1, 1},    
    {-1,-1,-1,-1,-1,-2, 0,-1,-1},    
    { 1, 1, 1, 1,-1, 1, 1,-1, 1},    
    { 1, 1, 1, 1,-1, 1, 1,-1, 1}
};
public:

void init(){
	InitStack_c(&oper);
	InitStack_i(&num);
}

double operate(char ch, double a, double b){
	switch(ch){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':if(b) return a/b;
				 else{
				 	printf("Divide 0.\n");
				 	return N;
				 }
		case '%':return (int)a%(int)b;
		case '^':if(b>=0)return pow(a,b);
				 else{
				 	printf("error.\n");
				 	return N;
				 }
		default: printf("error.\n");
				 return N;
	}
}

int cmp(char a, char b){
	int x,y;
	for(int i = 0; i < 9; i++){
		if(operation[i] == a) {x = i;break;}
	}
	for(int i = 0; i < 9; i++){
		if(operation[i] == b){y = i; break;}
	}
	return check[x][y];
}

bool Isnum(char ch){
	if(ch >= '0' && ch <= '9') return true;
	else return false;
}

bool opif(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') return true;
	else return false;
}

int Tonum(char ch){
	int p = ch - '0';
	return p;
}

double GetValue(string s, int len){
	while(!StackEmpty_c(oper)) Pop_c(&oper);
	while(!StackEmpty_i(num)) Pop_i(&num);
	Push_c(&oper,'#'),s[len] = '#';
	int type = 2;
	if(s[0] == '-' && Isnum(s[1])) s[0] = '0';
	for(int i = 1; i < len; i++)
		if(!Isnum(s[i-1]) && (s[i] =='-')) s[i] = '0';
	for(int i = 0; i < len || GetTop_c(oper) != '#';){
		if(Isnum(s[i])){
			if(type == 0){
				double temp = GetTop_i(num);
				Pop_i(&num);
				if(temp <= 0) Push_i(&num,temp*10 + Tonum(s[i++])*(-1));
				else Push_i(&num,temp*10 + Tonum(s[i++]));
				type = 0;
			}
			else Push_i(&num,Tonum(s[i++])),type = 0;
		}

		else{
			if(type == 1){
				if(opif(s[i])){
					printf("error.\n");
					return ERROR;
				}
			}
			if(s[i] == '(') type = 1;
			else type = 2;
			if(StackEmpty_c(oper)){
				printf("error.\n");
				return ERROR;
			}
			else{
				char ch = GetTop_c(oper);
				Pop_c(&oper);
				int pr = cmp(ch,s[i]);
				if(pr == -2){
					printf("error.\n");
					return ERROR;
				}
				else if(pr == -1){
					Push_c(&oper,ch);
					Push_c(&oper,s[i++]);
					continue;
				}
				else if(pr == 0){i++; continue;}
				else{
					double b = GetTop_i(num);
					Pop_i(&num);
					double a = GetTop_i(num);
					Pop_i(&num);
					double k = operate(ch,a,b);
					if(k  == N) return ERROR;
					else Push_i(&num,k);
					continue;
				}
				i++;
			}
		}
	}
	if(StackLength_i(num) == 1 && StackLength_c(oper) == 1) return GetTop_i(num);
	else{
		while(!StackEmpty_c(oper)){
			Pop_c(&oper);
		}
		printf("error.\n");
		return ERROR;
	}
}

};

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		string s;
		cin >> s;
		CExpression ex;
		ex.init();
		int len = s.length();
		cout << ex.GetValue(s,len) << endl;
	}
}