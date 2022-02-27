/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:47:27 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/27 14:39:20 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

extern FILE	*g_content;

void	show_content(struct mg_connection *connection,
			struct mg_http_message *request)
{
	char	*buffer = strdup("");
	char	tmp[1000];
	char	*aux;
	FILE	*content;

	get_content();
	content = fopen("./content/content.txt", "r");
	while (fgets(tmp, 1000, content))
	{
		aux = buffer;
		buffer = ft_strjoin(buffer, tmp);
		free(aux);//free the old malloc from ft_strjoin
	}
	fclose(content);
	mg_http_reply(connection, HTTP_OK, NULL, buffer);
	free(buffer);
}
