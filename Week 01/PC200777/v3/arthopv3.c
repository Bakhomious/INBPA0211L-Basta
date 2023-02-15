#include <stdio.h>

int main()
{
	int a, b;
	char op;
	while (scanf("%d %c %d", &a, &op, &b)) {

		if (a == 0 || b == 0) {
			break;
		}
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