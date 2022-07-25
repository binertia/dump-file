#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int g_get_result = 0;
static char **g_argv ;

int     ft_strlen_withnul(char *str)
{
        int     run_argv;

        run_argv = 0;
        while(str[run_argv] != '\0')
		run_argv++;
        return (run_argv + 1);
}

int     is_char_valid(char c, int n)
{
        if(c >= '1' && c <= n + '0')
                return (1);   //valid
        return (0);     //invalid
}

int     is_input_valid(char **argv)
{
        int     n;
        int     length_nul;
        int     run_argv;

        length_nul = ft_strlen_withnul(argv[1]);
        n = length_nul / 8;
        run_argv = 0;

        if ( length_nul >= 32 && !(length_nul % 4 == 0))
                return (0); //invalid

        while (!(run_argv >= length_nul-2))
        {
                if(!is_char_valid(argv[1][run_argv], n))
                        return (0);   //invalid
                if(!(argv[1][run_argv+1] == ' '))
                        return (0);   //invalid
                run_argv += 2;
        }
                return (n); //valid
}

void    fill_zero(int **map, int n)
{
    int i;
    int j;

    i = -1;
    while (i++ < n - 1)
	{
		j = -1;
		while (j++ < n - 1)
			map[i][j] = 0;
	}
}

int    is_placable(int **map, int n, int row, int col,int nbr)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (j < n)
    {
        if (j != col && map[row][j] == nbr)
            return (0);
        else
            j++;
    }
    while (i < n)
    {
        if (i != row && map[i][col] == nbr)
            return (0);
        else
            i++;
    }
    return (1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_map(int **map, int n)
{
    int    row;
    int    col;

    row = -1;
    
    while (row++ < n -1)
    {
        col = -1;
        while (col++ < n -1)
        {
            ft_putchar(map[row][col] + '0');
            ft_putchar(' ');
        }
        write(1, "\n", 1);
    }
}


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

int     is_skyscaper(int **map ,int n)
{
    printf("////////////////////\n");
    print_map(map,n);
    printf("////////////////////\n");
    if(col_up(map,n,0) && col_down(map,n,n*2) && row_left(map,n,n*4) && row_right(map,n,n*6))
    {
        g_get_result = 1;
        print_map(map,n);
        printf("\nEZ");
        return 1;
    }
    return 0;
}




int     recursive_fill_nbr(int **map,int n,int raw_row,int raw_col)
{
	int nbr = -1; //
	int row;
	int col;
    int i = 0;
    
    //printf("Badass\n");
	row = raw_row / n;
	col = raw_col % n;
	if(g_get_result)
	    return 1;
	if ((row == n))
	{
	    if(is_skyscaper(map,n))//is_skyscaper(map,n) {g_get_result = 1;{ if g_get_result -> print_map(map ,n);
	        return 1;
        else
            return 0;
	}
	
	while (i < n)
	{
	    nbr++;
	    i++;
	    if(is_placable(map,n,row,col,((nbr) % n) + 1))
    	{
    		map[row][col] = ((nbr) % n) + 1;
            if(recursive_fill_nbr(map, n, raw_row + 1,raw_col + 1 ))
                return 1;
    		map[row][col] = 0;
	    }
	    
	}
	return 0;
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
