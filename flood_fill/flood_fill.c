
typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void	floodfill2(char **tab, char a, t_point size, t_point pos)
{
	t_point		point[4];

	point[0].x = pos.x;
	point[0].y = pos.y + 1;
	point[1].x = pos.x;
	point[1].y = pos.y - 1;
	point[2].x = pos.x + 1;
	point[2].y = pos.y;
	point[3].x = pos.x - 1;
	point[3].y = pos.y;

	if (pos.x >= 0 && pos.x < size.x && pos.y >= 0 && pos.y < size.y)
	{
		if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] != a)
			return ;
		tab[pos.y][pos.x] = 'F';
		floodfill2(tab, a, size, point[0]);
		floodfill2(tab, a, size, point[1]);
		floodfill2(tab, a, size, point[2]);
		floodfill2(tab, a, size, point[3]);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	a;

	a = tab[begin.y][begin.x];
	floodfill2(tab, a, size, begin);
}