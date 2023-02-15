#include <stdio.h>

int main()
{
	int a, b;
	char op;
	while ((scanf("%d %c %d", &a, &op, &b)) != EOF) {

		switch (op)
		{
			case '+': printf("%d\n", a+b); break;
			case '-': printf("%d\n", a-b); break;
			case '*': printf("%d\n", a*b); break;
			case '/': printf("%d\n", a/b); break;
			case '%': printf("%d\n", a%b); break;
			default: printf("Error!\n");
		}
	}
	return 0;
}