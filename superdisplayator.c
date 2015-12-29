#include "fillit.h"

static void		display_line(t_fillit *f, size_t p)
{
	size_t			e;
	char			buffer[21];
	unsigned char	x;
	unsigned short	b;

	e = 0;
	ft_memset(buffer, (int)'.', 21);
	ft_memset(buffer + f->grid_size, (int)'\0', 21 - f->grid_size);
	//ft_putnbr((int)(f->grid_size));
	//ft_putchar('\n');
	while(e < f->elements_count)
	{
		x = f->elems[e].pos >> 8;
		//ft_putnbr((int)x);
		//ft_putchar('\n');
		if (x <= p && (x + 4) > p)
		{
			b = (f->elems[e].bin << (p - x) * 4) & 61440;
			x = (unsigned char)(f->elems[e].pos & 255);
			//ft_putnbr((int)x);
			//ft_putchar('\n');
			buffer[x] = (b & 32768) ? f->elems[e].letter : buffer[x];
			buffer[x + 1] = (b & 16384) ? f->elems[e].letter : buffer[x + 1];
			buffer[x + 2] = (b & 8192) ? f->elems[e].letter : buffer[x + 2];
			buffer[x + 3] = (b & 4096) ? f->elems[e].letter : buffer[x + 3];
		}
		++e;
	}
	ft_putstr(buffer);
}

void			super_display_of_doom(t_fillit *f)
{
	size_t			p;

	p = 0;
	while (p < f->grid_size)
	{
		display_line (f, p);
		ft_putchar('\n');
		++p;
	}
}
