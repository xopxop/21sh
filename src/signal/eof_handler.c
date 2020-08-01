#include "minishell.h"

int iseof_in_line(char *line)
{
    while (*line)
    {
        if (*line == '\x04')
            return (1);
        ++line;
    }
    return (0);
}

void eof_handler(t_l *l)
{
    char *tmp;
    t_term old;

    if (l->type == LINE_TYPE_SINGLE)
    {
        restore_term(l);
        ft_exit(EXIT_SUCCESS);
    }
    else if (l->type == LINE_TYPE_DQUOTE)
    {
        error_monitor("\n21sh: unexpected EOF while looking",
                      " for matchin `\"\'", NULL, NULL, 0, 0);
        tmp = ft_strjoin(l->line, "\"");
        ft_strdel(&l->line);
        l->line = tmp;
    }
    old = get_set_default_term(NULL);
    tcsetattr(0, TCSANOW, &old);
}