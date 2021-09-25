#include <stdio.h>

int	main()
{
	printf("NUMBERS\n");
	printf(".5  : %.5d\n", 4);
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


	/*printf("STRINGS\n");
	printf(".10: %.10s\n", "hello");
	printf("10 : %10s\n", "hello");

	printf("DECIMALS\n");
	printf(".2: %.2f\n", 3.1415);
	printf("2 : %2f\n", 3.1415);
	printf("010 : %010f\n", 3.1415);

	printf("TEST\n");
	printf("+: %.d%c\n", 534, 'a');
	printf("+: %.1d%c\n", 534, 'a');
	printf("+: %10.d%c\n", 534, 'a');*/
}
