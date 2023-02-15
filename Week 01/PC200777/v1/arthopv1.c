#include <stdio.h>

int main()
{
	int n, a, b;
	char op;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &a, &op, &b);
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