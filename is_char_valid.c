int     is_char_valid(char c, int n)
{
        if(c >= '1' && c <= n + '0')
                return (1);   //valid
        return (0);     //invalid
}
