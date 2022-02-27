#include <cli.h>

int	nline = 0;
FILE	*log_file;

int	get_nline(void)
{
	char	line[1024];
	int		quantity_line = 0;

	log_file = fopen("../API/log/log.log", "r");
	if(log_file)
	{
		while(fgets(line, 1024, log_file))
			quantity_line++;
	}
	fclose(log_file);
	log_file = 0;
	return (quantity_line);
}

void	free_buffer(char **key_value)
{
	size_t	index = 0;

	while (key_value[index])
	{
		free(key_value[index]);
		index++;
	}
	free(key_value);
}

void	show_table(void)
{
	FILE	*log;
	char	line[1024];
	char	**key_value;

	log = fopen("../API/log/log.log", "r");

	if(log)
	{
		printf("_______________________________________________________________\n\n");
		printf("|    Method\t|     Path\t|      Time Request\t|Status|\n");
		printf("_______________________________________________________________\n\n");
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
			free_buffer(key_value);
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

void	logout(int signal)
{
	if (log_file)
		fclose(log_file);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	signal(SIGINT, logout);
	while(true)
	{
		update_table();
	}
	return EXIT_SUCCESS;
}
