#include "includes/ft_printf.h"

int main()
{
	int i = ft_printf("%.5s%7s", "yo", "boi");
	printf("\ni = %d\n", i);
	int a = printf("%5");
    printf("\na = %d", a);

    return 0;
}