//void		ft_putnbr(int nb);

int		ft_atoi(char *str)
{
        int     i;
        int     negativ;
        int     number;

        i = 0;
        negativ = 0;
        number = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if (str[i] ==  43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number *10;
		number = number + ((int)str[i] - 48);
		i++;
	}
	if (negativ)
	{
//		ft_putnbr(-number);
		return(-number);
	}
	else
	{
//		ft_putnbr(number);
		return(number);
	}
}




