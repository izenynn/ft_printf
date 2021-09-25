#include "src/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int n1, n2;
	void *p;
	p = malloc(1);

	n1 = printf("Ptr: %.9d\n", -2147483647 - 1);
	n2 = ft_printf("Ptr: %.9d\n", -2147483647 - 1);

	printf("n1: %d\nn2: %d\n", n1, n2);

	/*printf("PRINTF\n");
	printf("+: %.s%c\n", "hello", 'a');
	printf("+: %.03s%c\n", "hello", 'a');
	printf("+: %10.03s%c\n", "hello", 'a');

	ft_printf("FT_PRINTF\n");
	ft_printf("+: %.s%c\n", "hello", 'a');
	ft_printf("+: %.03s%c\n", "hello", 'a');
	ft_printf("+: %10.03s%c\n", "hello", 'a');*/

	/*printf("PRINTF\n");
	printf("NUMBERS\n");
	printf(".5  : %.1d\n", 0);
	printf("0.05: %0.05d\n", 4);
	printf("09.5 : %09.5d\n", 4);
	printf("5   : %5d\n", 4);
	printf("05  : %05d\n", 4);
	printf("05  : %05d\n", 4432555);
	printf("NEG NUMBERS\n");
	printf(".5  : %.5d\n", -4);
	printf("0.05: %0.5d\n", -4);
	printf("09.5 : %09.5d\n", -4);
	printf("5   : %5d\n", -4);
	printf("05  : %05d\n", -4);
	printf("05  : %05d\n", 4432555);

	printf("\nFT_PRINTF\n");
	printf("NUMBERS\n");
	ft_printf(".5  : %.1d\n", 0);
	ft_printf("0.05: %0.05d\n", 4);
	ft_printf("09.5 : %09.5d\n", 4);
	ft_printf("5   : %5d\n", 4);
	ft_printf("05  : %05d\n", 4);
	ft_printf("05  : %05d\n", 4432555);
	printf("NEG NUMBERS\n");
	ft_printf(".5  : %.5d\n", -4);
	ft_printf("0.05: %0.5d\n", -4);
	ft_printf("09.5 : %09.5d\n", -4);
	ft_printf("5   : %5d\n", -4);
	ft_printf("05  : %05d\n", -4);
	ft_printf("05  : %05d\n", 4432555);*/
}
