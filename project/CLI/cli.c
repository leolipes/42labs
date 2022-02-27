#include "cli.h"

int	nline = 0;

int	get_nline(void)
{
	FILE	*log;
	char	line[1024];
	int		quantity_line = 0;

	log = fopen("../API/log/log.log", "r");

	if(log)
	{
		while(fgets(line, 1024, log))
			quantity_line++;
	}
	fclose(log);
	return (quantity_line);
}

void	show_table(void)
{
	FILE	*log;
	char	line[1024];
	char	**key_value;	//key: value

	log = fopen("../API/log/log.log", "r");

	if(log)
	{
		printf("");
		printf(" Method\t\t Path\t\t Time Request\t\t Status\n");
		printf(" _____________________________________________________________\n");
		while(fgets(line, 1024, log))
		{
			if(line[0] == '\n')
			{
				printf("\n");
				continue ;
			}
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = 0;
			key_value = ft_split(line, ':');
			printf("|%s\t\t", key_value[1]);
		}
	}
	fclose(log);
}

void	clear_terminal(void)
{
	write(1, "\033[2J\033[1;1H", 11);
}

void	update_table(void)
{
	int	new_nline = get_nline();

	if (new_nline > nline)
	{
		nline = new_nline;
		clear_terminal();
		show_table();
	}
}

int	main(int argc, char *argv[])
{
	while(true)
	{
		update_table();
	}
	return EXIT_SUCCESS;
}
