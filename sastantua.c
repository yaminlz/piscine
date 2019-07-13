void	etage(int largeur, int hauteur, int size);
void    base(int hauteur, int largeur, int taille_porte, int size);
int	largeur_etage_i(int i);
int	taille_porte(int size);
void	ft_putchar(char c);

int		g_i;

void		sastantua(int size)
{
	int	hauteur;
	int	largeur;
	int	decalage;

	g_i = 0;
	while(g_i<size)
	{
		hauteur = 3 + g_i ;
		largeur = largeur_etage_i(g_i) ;
		decalage = (largeur_etage_i(size-1) - largeur_etage_i(g_i))/2;
		if(g_i < size - 1)
			etage(hauteur, largeur, size);
		else
			base(hauteur, largeur, taille_porte(size), size);
		g_i++;
	}
}

void		etage(int hauteur, int largeur, int size)
{
	int	i;
	int	j;
	int	decalage;

	i = 0;
	decalage = (largeur_etage_i(size-1) - largeur_etage_i(g_i))/2;
	while(i<hauteur)
	{
		j = -decalage;
		while(j < 2*(hauteur - (1 + i)) + 2)
		{
			if (j < hauteur - (1+i))
				ft_putchar(' ');
			j++;
		}
		ft_putchar('/');
		while(j < largeur)
		{
			ft_putchar('*');
			j++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void            base(int hauteur, int largeur, int taille_porte, int size)
{
        int     i;
        int     j;
	int	decalage;
	int	decalage_porte;

	decalage_porte = taille_porte + 2 - (size%2);
	decalage = (largeur_etage_i(size-1) - largeur_etage_i(g_i))/2;
        i = 0;
        while(i<hauteur)
        {
                j = -decalage;
                while(j < 2*(hauteur - (1+i)) + 2)
                {
                        if (j < hauteur - (1+i))
                                ft_putchar(' ');
                        j++;
                }
                ft_putchar('/');
		if(i < (hauteur - taille_porte))
		{
                	while(j < largeur)
                	{
                        	ft_putchar('*');
                        	j++;
                	}
		}
		if(i >= (hauteur - taille_porte))
		{
			 while(j <= (largeur - taille_porte)/2 + decalage_porte)
                         {
                                ft_putchar('*');
                                j++;
                         }
			 while(j <= ((largeur - taille_porte)/2) + taille_porte + decalage_porte)
			 {
				if((i == hauteur - taille_porte/2 - 1)&&(j == (largeur + taille_porte)/2 + decalage_porte - 1)&&(size >= 5))
				        ft_putchar('$');
				else
					ft_putchar('|');
                                j++;
			 }
			 while(j < largeur)
                         {
                                ft_putchar('*');
                                j++;
                         }
		}
                ft_putchar('\\');
                ft_putchar('\n');
		decalage_porte--;
                i++;
        }
}

int		largeur_etage_i(int i)
{
	if(i == 0)
		return(7);
	return(largeur_etage_i(i-1) + 2*((3+i)+ 1 + (i%2) + (i/2)));
}

int		taille_porte(int size)
{
	if(size == 1)
		return(1);
	if(size == 2)
		return(1);
	else
		return(taille_porte(size-1) + 2*(size%2));
}
