#include "variadic_functions.h"
#include <string.h>

/**
 */
void print_integer(va_list arg)
{
	int num;

	num = va_arg(arg, int);
	printf("%d", num);
}
/**
 */
void print_char(va_list arg)
{
	char c;
	
	c = va_arg(arg, int);
	printf("%c", c);
}
/**
 */
void print_float(va_list arg)
{
	float f;

	f = va_arg(arg, double);
	printf("%f", f);
}
/**
 */
void print_str(va_list arg)
{
	char *str;

	str = va_arg(arg, char*);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	prt form[] = {{"i", print_integer},
		{"c", print_char},
		{"f", print_float},
		{"s", print_str}
	};
	va_list arg;

	va_start(arg, format);

	while (format[i] != '\0')
	{
		unsigned int j = 0;

		while (j < 4 && *(format + i) != *(form[j].symb))
			j++;

		if (j < 4)
			form[j].print(arg);
		if (j < strlen(format) - 1)
			printf(", ");

		i++;
	}
	printf("\n");
	va_end(arg);

}
