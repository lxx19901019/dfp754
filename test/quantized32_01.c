#if defined HAVE_CONFIG_H
# include "config.h"
#endif	/* HAVE_CONFIG_H */
#include <stdlib.h>
#include <stdio.h>
#include "dfp754_d32.h"

#if !defined countof
# define countof(x)	(sizeof(x) / sizeof(*x))
#endif	/* !countof */

int
main(void)
{
	_Decimal32 x[] = {
		0.df, 1.df, 1.23df, 0.23df, 1.234df, 12.34df,
		12.df, 100.df, 123.df,
	};

	for (size_t i = 0U; i < countof(x); i++) {
		char buf[32U];
		int l = d32tostr(buf, sizeof(buf), quantized32(x[i], 0.1df));
		buf[l] = '\0';
		puts(buf);
	}

	for (size_t i = 0U; i < countof(x); i++) {
		char buf[32U];
		int l = d32tostr(buf, sizeof(buf), quantized32(x[i], 0.01df));
		buf[l] = '\0';
		puts(buf);
	}
	return 0;
}
