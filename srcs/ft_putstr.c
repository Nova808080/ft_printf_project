#include "ft_printf.h"

int ft_putstr(char *s)
{
    int count;

    count = 0;
    if(!s)
        return write(1,"(null)",6);
    
    while(s[count])
    {
        write(1,&s[count],1);
        count++;
    }

    return (count);
}