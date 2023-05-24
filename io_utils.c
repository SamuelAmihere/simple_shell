#include "main.h"

/**
 * _puts - writes string to stdout
 *
 * @str: string to be written
 *
 * Return: number of characters written
 */

int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (0);
}

/**
 * _putchar - write a charcter to standard out
 *
 * @c: the character to write
 *
 * Return: 1 on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;
		if (*(s + count) == '-')
			pn *= -1;
		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}
	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

/**
 * _itos - convert int to string
 * @n: integer
 * Return: string
 */
char *_itos(int n)
{
	int ln = _count_digits(n);
	unsigned int n1;
	char *str;

	str = malloc(sizeof(char) * (ln + 1));
	{
		if (!str)
			return (NULL);
		*(str + ln) = '\0';
		if (n < 0)
		{
			n1 = n * -1;
			str[0] = '-';
		} else
			n1 = n;
		while (n1 > 0)
		{
			ln -= 1;
			str[ln] = (n1 % 10) + '0';
			n1 /= 10;
		}
		return (str);
	}
}

/**
 * _count_digits - count digits
 * @n: integer
 * Return: count
 */
int _count_digits(int n)
{
	int cnt = 0;

	if (n <= 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}
