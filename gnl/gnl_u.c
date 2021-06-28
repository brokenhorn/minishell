#include "get_next_line.h"

void	free_strbuffer(char *str, char *buffer, char **line)
{
	ft_strchngz_zero(str);
	*line = ft_strjoin(NULL, str);
	free(str);
	free(buffer);
}
