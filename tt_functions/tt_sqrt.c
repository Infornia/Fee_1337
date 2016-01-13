float	tt_sqrt(int x)
{
	int		prev;
	int		k;
	int 	kmax;
	float	s;
	
	prev = 0;
	k = -1;
	kmax = 1000;
	s = 1;
	while(++k < kmax)
	{
		prev = s;
		s = (s + x / s) / 2;
		if (prev == s)
			break;
	}
	return (s);
}