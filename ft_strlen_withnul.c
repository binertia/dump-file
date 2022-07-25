

int     ft_strlen_withnul(char *str)
{
        int     run_argv;

        run_argv = 0;
        while(str[run_argv] != '\0')
		run_argv++;
        return (run_argv + 1);
}
