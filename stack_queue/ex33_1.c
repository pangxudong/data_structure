#include "stack.h"

int BracketsCheck(char *str) {
	int i=0;
	char x;
	Stack s;
	s = InitStack(s);

	while(str[i]!='\0') {
		switch(str[i]) {
			case '(': Push(s, '('); printf("push (\n"); break;
			case '[': Push(s, '['); printf("push [\n"); break;
			case '{': Push(s, '{'); printf("push {\n"); break;
			case ')': x = Pop(s); printf("pop (\n"); if(x != '(') { printf("err %c)\n",x);return 0;} break;
			case ']': x = Pop(s); printf("pop [\n");if(x != '[') { printf("err %c]\n",x);return 0;} break;
			case '}': x = Pop(s); printf("pop {\n");if(x != '{') { printf("err %c}\n",x);return 0;} break;
			default: break;
		}
		i++;
	}
	if(!StackEmpty(s)) {
		printf("不匹配\n");
		return 0;
	}else {
		printf("匹配！\n");
		return 1;
	}
}

int main() {
	char *str = "{[]()[()]}";
	if(!BracketsCheck(str)) {
		printf("please check!\n");
	}
}
