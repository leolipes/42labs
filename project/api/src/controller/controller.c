/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:47:27 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/26 19:51:36 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

extern FILE	*g_content;

void	show_content(struct mg_connection *connection,
			struct mg_http_message *request)
{
	char	*buffer = "";
	char	tmp[1000];
	FILE	*content;

	get_content();
	content = fopen("./content/content.txt", "r");
	while (fgets(tmp, 1000, content))
		buffer = ft_strjoin(buffer, tmp);
	mg_http_reply(connection, HTTP_OK, NULL, buffer);
	add_log("GET", "/", HTTP_OK);
}
