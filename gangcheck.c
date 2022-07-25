#include <stdio.h>
#include <stdlib.h>

static char **g_argv ;
int     ft_strlen_withnul(char *str);
int     is_input_valid(char **argv);
void    fill_zero(int **map, int n);
int     recursive_fill_nbr(int **map,int n,int raw_row,int raw_col);



int col_up(int **map ,int n,int run_argv)
{
    int run_row;
    int run_col;
    int visible_count;
    int highest_nbr;

    run_col = -1;
    while(run_col++ < n-1)
    {
        run_row = 0;
        visible_count = 1 ;
        highest_nbr = map[0][run_col];
        while(run_row++ < n-1)
        {
            if(map[run_row][run_col] > highest_nbr)
            {
                visible_count++;
                highest_nbr = map[run_row][run_col];
            }
        }
        if(visible_count + 48 != g_argv[1][run_argv])
            return 0;
        run_argv += 2;
    }
   return 1;
}

int col_down(int **map ,int n,int run_argv)
{
    int run_row;
    int run_col;
    int visible_count;
    int highest_nbr;


    run_col = -1;
    while(run_col++ < n-1)
    {
        run_row = n-1;
        visible_count = 1 ;
        highest_nbr = map[n-1][run_col];
        while(run_row-- > 0)
        {
            if(map[run_row][run_col] > highest_nbr)
            {
                visible_count++;
                highest_nbr = map[run_row][run_col];
            }
        }
        if(visible_count + 48 != g_argv[1][run_argv])
            return 0;
        run_argv += 2;
    }
    return 1;
}

int row_left(int **map ,int n,int run_argv)
{
    int run_row;
    int run_col;
    int visible_count;
    int highest_nbr;

    run_row = -1;
    while(run_row++ < n-1)
    {
        run_col = 0;
        visible_count = 1 ;
        highest_nbr = map[run_row][0];
        while(run_col++ < n-1)
        {
            if(map[run_row][run_col] > highest_nbr)
            {
                visible_count++;
                highest_nbr = map[run_row][run_col];
            }
        }
        if(visible_count + 48 != g_argv[1][run_argv])
            return 0;
        run_argv += 2;
    }
    return 1;
}

int row_right(int **map ,int n,int run_argv)
{
    int run_row;
    int run_col;
    int visible_count;
    int highest_nbr;

    run_row = -1;
    while(run_row++ < n-1)
    {
        run_col = n-1;
        visible_count = 1 ;
        highest_nbr = map[run_row][n-1];
        while(run_col-- > 0)
        {
            if(map[run_row][run_col] > highest_nbr)
            {
                visible_count++;
                highest_nbr = map[run_row][run_col];
            }
        }
        if(visible_count + 48 != g_argv[1][run_argv])
            return 0;
        run_argv += 2;
    }
    return 1;
}


int     main(int argc, char **argv)
{
    /////////////////////
	int	    **map;
	int	    i;
	int	    j;
    int     n;

    g_argv = argv;
   if(!(n = is_input_valid(argv)))
    {
        printf("errorrrrrr");
	    return 0;
    }

    map = (int **)malloc(n * sizeof(int *));
	i = -1;
	while (i++ < n - 1)
		map[i] = (int *)malloc(n * sizeof(int));

	fill_zero(map,n);

	if(!recursive_fill_nbr(map,n,0,0))
        printf("Noob\n");

	for (int i = 0; i < n; i++)
        	free(map[i]);
    free(map);


    return (0);

}
