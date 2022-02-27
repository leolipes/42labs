#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

//------------------------------------CLI-------------------------------------//
//All these functions are in cli
/**
 * @brief  This function read the file where it contains log information.
 * @retval Number of lines.
 */
int		get_nline(void);

/**
 * @brief To free the buffer.
 * @param  **key_value: Buffer.
 * @retval None
 */
void	free_buffer(char **key_value);

/**
 * @brief  Show the contents of the log file in the terminal in table format.
 * @retval None
 */
void	show_table(void);

/**
 * @brief  To keep updating the table in the terminal every time the log file is
 * updated.
 * @retval None
 */
void	update_table(void);

/**
 * @brief  To clear the terminal being useful as a helper of the update_table
 * function.
 * @retval None
 */
void	clear_terminal(void);

/**
 * @brief  Terminates the program with the SIGINT signal without unexpected
 * interrupt errors.
 * @param  signal: receives SIGINT signal.
 * @retval None
 */
void	logout(int signal);
//-----------------------------------UTILS------------------------------------//
//Function Directory: utils
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
//----------------------------------------------------------------------------//

#endif