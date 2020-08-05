#include "includes/ft_printf.h"
#include <limits.h>

int main()
{

	char a;
	int i;

	a = 'a';


	char *c = "123456789";
	char *str = " |%*.*s| \n";
	int n = ft_printf(str,-2, 1, c);
	int j =    printf(str,-2, 1, c);


	if ( n == j)
		printf("равны\n");
	else
		printf("не равны\n");

//	char *c = "123456789";ok
//	char *str = " |%+*.*s| \n";
//	int n = ft_printf(str,10,0, c);
//	int j =    printf(str,10, 0, c);

//	char *c = "123456789";ok
//	char *str = " |%0*.*s| \n";
//	int n = ft_printf(str,10,0, c);
//	int j =    printf(str,10, 0, c);

//	char *c = NULL;
//	char *str = " |%.s| \n";
//	int n = ft_printf(str, c);
//	int j =    printf(str, c);

//	double c = NAN;ok
//	char *str = "% 5lf\n";
//	int n = ft_printf(str, c);
//	int j =    printf(str, c);

//	double c = NAN;ok
//	char *str = "%+4.lf\n";
//	int n = ft_printf(str, c);
//	int j =    printf(str, c);

//	float c = 0.125;
//	char *str = "%20.2f\n";//leak
//	int n = ft_printf(str, c);
//	int j =    printf(str, c);

//	int c = 4;
//	char *str = "%20.14p\n";
//	int n = ft_printf(str, &c);
//	int j =    printf(str, &c);

//	unsigned long c = 0xffffffffffffffff;
//	char *str = "%#050.20llu\n";
//	int n = ft_printf(str, c);
//	int j =    printf(str, c);

//	char c = 120;
//	char *str = "%+010.5hho\n";
//	int n = ft_printf(str, c);
//	int j =    printf(str, c);

//	char *str = "%#.o\n";
//	int n = ft_printf(str, 0);
//	int j =    printf(str, 0);

//	char *str = "% 10.5u\n";
//	int n = ft_printf(str, 0);
//	int j =    printf(str, 0);

//	char *str = "%0.d\n";
//	int n = ft_printf(str, 0);
//	int j =    printf(str, 0);






//	ft_printf("%Lf\n", 0.0);
//	printf("%Lf\n", 0.0);

//	ft_printf("%c\n", 'g');
//	printf("%c\n", 'g');
//
//	ft_printf("%%%s%s%s\n", "LDBL_MAX", "jhgfjhgf", "fgtyui");
//	printf("%%%s%s%s\n", "LDBL_MAX", "jhgfjhgf", "fgtyui");
//
//	ft_printf("%.0f\n", 230.0042);
//	printf("%.0f\n", 230.0042);
//
//	ft_printf("%%llu\n", LONG_LONG_MAX);
//	printf("%%llu\n", LONG_LONG_MAX);
//
//	ft_printf("%lu\n", LONG_MIN);
//	printf("%lu\n", LONG_MIN);
//
//	ft_printf("%hu\n", LONG_MIN);
//	printf("%hu\n", LONG_MIN);
//
//	ft_printf("%hhu\n", INT_MAX);
//	printf("%hhu\n", INT_MAX);
//
//	ft_printf("%lld\n", LONG_LONG_MIN);
//	printf("%lld\n", LONG_LONG_MIN);
//
//	ft_printf("%ld\n", LONG_MIN);
//	printf("%ld\n", LONG_MIN);
//
//	ft_printf("%hd\n", LONG_MAX);
//	printf("%hd\n", LONG_MAX);
//
//	ft_printf("%hhd\n", INT_MIN);
//	printf("%hhd\n", INT_MIN);
//
//	ft_printf("%llx\n", LONG_LONG_MAX);
//	printf("%llx\n", LONG_LONG_MAX);
//
//	ft_printf("%#lx\n", LONG_MAX);
//	printf("%#lx\n", LONG_MAX);
//
//	ft_printf("%hx\n", INT_MIN);
//	printf("%hx\n", INT_MIN);
//
//	ft_printf("%hhx\n", INT_MIN);
//	printf("%hhx\n", INT_MIN);
//
//	ft_printf("%llo\n", LONG_LONG_MIN);
//	printf("%llox\n", LONG_LONG_MIN);
//
//	ft_printf("%lo\n", LONG_LONG_MAX);
//	printf("%lox\n", LONG_LONG_MAX);
//
//	ft_printf("%#ho\n", LONG_MAX);
//	printf("%#hox\n", LONG_MAX);
//
//	ft_printf("%hho\n", LONG_MAX);
//	printf("%hhox\n", LONG_MAX);
//
//	ft_printf("%Lf\n", LDBL_MAX);
//	printf("%Lf\n", LDBL_MAX);
//
//	ft_printf("%Lf\n", LDBL_MIN);
//	printf("%Lf\n", LDBL_MIN);

    return 0;
}