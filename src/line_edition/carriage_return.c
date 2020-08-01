#include "minishell.h"

void    carriage_return_key(t_l *l, t_h **h)
{
    append_history(l, h);
    up_down(l, h, NULL);
    restore_term(l);
}