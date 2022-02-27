/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:30:51 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/27 04:19:47 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

void	add_log(char *method, char *route, int status)
{
	time_t	curtime;
	FILE	*file_log;

	file_log = fopen("./log/log.log", "a+");
	time(&curtime);
	if (file_log != NULL)
	{
		fprintf(file_log, "Method: %s\n", method);
		fprintf(file_log, "URI: %s\n", route);
		fprintf(file_log, "Time Resquest: %s", ctime(&curtime));
		fprintf(file_log, "Status: %d\n\n", status);
		fclose(file_log);
	}
}
