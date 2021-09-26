#include "src/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int n1, n2;
	void *p;
	p = malloc(1);

	printf("pr:%#4x\n", 9);
	printf("pr:%4x\n", 9);
	printf("pr:%#.4x\n", 9);
	printf("pr:%.4x\n", 9);
	printf("pr:%#04x\n", 9);
	printf("pr:%04x\n", 9);
	printf("pr:%#-4x\n", 9);
	printf("pr:%-4x\n\n", 9);

	ft_printf("ft:%#4x\n", 9);
	ft_printf("ft:%4x\n", 9);
	ft_printf("ft:%#.4x\n", 9);
	ft_printf("ft:%.4x\n", 9);
	ft_printf("ft:%#04x\n", 9);
	ft_printf("ft:%04x\n", 9);
	ft_printf("ft:%#-4x\n", 9);
	ft_printf("ft:%-4x\n", 9);

	/*printf("05p  : %05p_\n", 54);
	printf("01p  : %01p_\n", 54);
	printf(".5p  : %.5p_\n", 54);
	printf(".1p  : %.1p_\n", 54);
	printf("5p   : %5p_\n",  54);
	printf("1p   : %1p_\n",  54);
	printf("10.5p: %10.5p_\n", 54);
	printf("-5p  : %-5p_\n", 54);
	printf("ptf  :_%-11p_%-12p_\n", -2147483647 - 1, 2147483647);
	printf("ptf  :%-2p_\n", 1);
	ft_printf("---------------------------------\n");
	ft_printf("05p  : %05p_\n", 54);
	ft_printf("01p  : %01p_\n", 54);
	ft_printf(".5p  : %.5p_\n", 54);
	ft_printf(".1p  : %.1p_\n", 54);
	ft_printf("5p   : %5p_\n",  54);
	ft_printf("1p   : %1p_\n",  54);
	ft_printf("10.5p: %10.5p_\n", 54);
	ft_printf("-5p  : %-5p_\n", 54);
	ft_printf("ft_  :_%-11p_%-12p_\n", -2147483647 - 1, 2147483647);
	ft_printf("ptf  :%-2p_\n", 1);*/

	/*n1 = printf("printf: %.40p", p);
	printf("\n");
	n2 = ft_printf("ft_ptf: %.40p", p);
	printf("\n");

	printf("n1: %d\nn2: %d\n", n1, n2);*/

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
