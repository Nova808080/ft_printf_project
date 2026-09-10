#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

/* Comparison tests between ft_printf and the standard printf. */
int	main(void)
{
	int			ft_ret;
	int			c_ret;
	const char	*fmt_s;
	const char	*fmt_empty;

	fmt_s = "%s\n";
	fmt_empty = "";
	ft_ret = ft_printf("un test de ft_printf: --%d-- --%s-- --%u-- --%p-- \n",
			0, "abc", 0, (void *)0x1234);
	c_ret = printf("un test de printf:    --%d-- --%s-- --%u-- --%p-- \n",
			0, "abc", 0, (void *)0x1234);
	printf("ft_printf ret = %d ||| printf ret = %d\n\n", ft_ret, c_ret);

	ft_ret = ft_printf("ttt%cttt%d\n", 'x', 7);
	c_ret = printf("ttt%cttt%d\n", 'x', 7);
	printf("ft_printf ret = %d ||| printf ret = %d\n\n", ft_ret, c_ret);

	ft_ret = ft_printf("%d\n", -45);
	c_ret = printf("%d\n", -45);
	printf("ft_printf ret = %d ||| printf ret = %d\n\n", ft_ret, c_ret);

	ft_ret = ft_printf("Test %% simple : %%\n");
	c_ret = printf("Test %% simple : %%\n");
	printf("ft_printf ret = %d ||| printf ret = %d\n\n", ft_ret, c_ret);

	/* NULL-argument and empty-format edge cases: checked against ft_printf's
	 * own documented behaviour rather than real printf, since gcc refuses
	 * to compile these deliberately unusual calls to the real printf. */
	ft_ret = ft_printf(fmt_s, (char *)NULL);
	printf("ft_printf(\"%%s\", NULL) ret = %d (wrote \"(null)\")\n\n", ft_ret);

	ft_ret = ft_printf(NULL);
	printf("ft_printf(NULL format) ret = %d (expected -1)\n\n", ft_ret);

	ft_ret = ft_printf("%x %X %u\n", 4095, 4095, -1);
	c_ret = printf("%x %X %u\n", 4095, 4095, -1);
	printf("ft_printf ret = %d ||| printf ret = %d\n\n", ft_ret, c_ret);

	ft_ret = ft_printf(fmt_empty);
	printf("ft_printf(\"\") ret = %d (expected 0)\n\n", ft_ret);

	/* Closed-stdout check comes last: writes after this point are lost. */
	fclose(stdout);
	ft_ret = ft_printf("fedyhew");
	fprintf(stderr, "ft_printf on closed stdout ret = %d (expected -1)\n",
		ft_ret);
	return (0);
}
