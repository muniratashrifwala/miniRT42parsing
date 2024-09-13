#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// Function to skip leading whitespace
char *skip_whitespace(char *str) 
{
    while (*str && isspace((unsigned char)*str)) {
        str++;
    }
    return str;
}

// Function to parse the sign of the number
int parse_sign(char **str)
{
    int sign = 1;
    if (**str == '-') {
        sign = -1;
        (*str)++;
    } else if (**str == '+') {
        (*str)++;
    }
    return sign;
}

// Function to parse the integer part of the number
double parse_integer_part(char **str)
{
    double integer_part = 0.0;
    while (**str >= '0' && **str <= '9') {
        integer_part = integer_part * 10.0 + (**str - '0');
        (*str)++;
    }
    return integer_part;
}

// Function to parse the fractional part of the number
double parse_fractional_part(char **str)
{
    double fractional_part = 0.0;
    double divisor = 10.0;
    if (**str == '.') {
        (*str)++;
        while (**str >= '0' && **str <= '9') {
            fractional_part += (**str - '0') / divisor;
            divisor *= 10.0;
            (*str)++;
        }
    }
    return fractional_part;
}

// Function to parse the exponential part of the number (optional)
double parse_exponential_part(char **str)
{
    double exponential_part = 1.0;
    if (**str == 'e' || **str == 'E') {
        (*str)++;
        int exp_sign = parse_sign(str);
        int exponent = parse_integer_part(str);
        while (exponent-- > 0) {
            exponential_part *= (exp_sign == 1) ? 10.0 : 0.1;
        }
    }
    return exponential_part;
}

// Custom atof function
double ft_atof(const char *str)
{
    char *s = (char *)str;
    double result;
    int sign;

    s = skip_whitespace(s);
    sign = parse_sign(&s);
    result = parse_integer_part(&s);
    result += parse_fractional_part(&s);
    result *= parse_exponential_part(&s);
    return result * sign;
}
