#include "includes/ft_printf.h"
#include <limits.h>

int main()
{

	char a;
	int i;
	int n = 0;
	int j = 0;

	a = 'a';


//	char *c = "123456789";
//	char *str = " |%*.*s| \n";
//	n = ft_printf(str,-2, 1, c);
//	j =    printf(str,-2, 1, c);


//	int c = 4;
//	char *str = "%20.14p\n";
//	n = ft_printf(str, &c);
//	j =    printf(str, &c);
//

//	unsigned long c = 0xffffffffffffffff;
//	char *str = "%#050.20llu\n";
//	n = ft_printf(str, c);
//	j =    printf(str, c);

//
//	char c = 120;
//	char *str = "%+010.5hho\n";
//	n = ft_printf(str, c);
//	j =    printf(str, c);
//
//
//	char *str = "%0.d\n";
//	n = ft_printf(str, 0);
//	j =    printf(str, 0);


//	char *str = "% 10.5u\n";
//	n = ft_printf(str, 0);
//	j =    printf(str, 0);

//
//	char *c = NULL;
//	char *str = " |%.s| \n";
//	n = ft_printf(str, c);
//	j =    printf(str, c);


//

//	char *c = "123456789";
//	char *str = " |%+*.*s| \n";
//	n = ft_printf(str,10,0, c);
//	j =    printf(str,10, 0, c);
//
//	char *c = "123456789";
//	char *str = " {Blue}|%010.*s| {eoc}asdfgh \n";
//	n = ft_printf(str, 0, c);
//	j =    printf(str, 0, c);


//
//	double c = NAN;
//	char *str = "% 5lf\n";
//	n = ft_printf(str, c);
//	j =    printf(str, c);

//	double c = NAN;
//	char *str = "%+4.lf\n";
//	n = ft_printf(str, c);
//	j =    printf(str, c);



//	int c = 4;
//	char *str = "%20.14p\n";
//	n = ft_printf(str, &c);
//	j =    printf(str, &c);
//

//	char c = 100;
//	char *str = "%s\n";//leak
//	n = ft_printf(str, c);
//	j =    printf(str, c);




//	char *c = "sdfghjkrtyuiop-76543--7654jkl;'";
//	char *str = "%ls\n";
//	n = ft_printf(str, c, 234, -987, +6789, 3234, INT_MAX, INT_MIN);
//	j =    printf(str, c, 234, -987, +6789, 3234, INT_MAX, INT_MIN);
//	n = ft_printf(str, c, "dfghjkl4567890/=9453+-*8=4123", "");
//	j =    printf(str, c, "dfghjkl4567890/=9453+-*8=4123", "");
//	n = ft_printf(str, &c, &n, &j);
//	j =    printf(str, &c, &n, &j);


//	int c = 100;
	char *s = NULL;
//	double f = 12345678.9;
	int c = 5828;
	char *str = "%Lf\n";//leak
	n = ft_printf(str, 23.00023l);
	j =    printf(str, 23.00023l);
	if ( n == j)
		printf("равны\n");
	else
		printf("не равны\n");







//
//	ft_printf("%Lf\n", 0.0l);
//	printf("%Lf\n", 0.0l);
//
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
//	printf("%llo\n", LONG_LONG_MIN);
//
//	ft_printf("%lo\n", LONG_LONG_MAX);
//	printf("%lo\n", LONG_LONG_MAX);
//
//	ft_printf("%#ho\n", LONG_MAX);
//	printf("%#ho\n", LONG_MAX);
//
//	ft_printf("%hho\n", LONG_MAX);
//	printf("%hho\n", LONG_MAX);
//
//	ft_printf("%Lf\n", LDBL_MAX);
//	printf("%Lf\n", LDBL_MAX);
//
//	ft_printf("%Lf\n", LDBL_MIN);
//	printf("%Lf\n", LDBL_MIN);

    return 0;
}