/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:16:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/27 17:17:48 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

extern char	*url;


void	router(struct mg_connection *connection,
		struct mg_http_message *request)
{
	if (mg_http_match_uri(request, "/") && !strncmp(request->method.ptr, "GET",
			3))
	{
		url = "https://www.boredapi.com/api/activity";
		show_content(connection, request);
		add_log("GET", "/", HTTP_OK);
	}
	else if (mg_http_match_uri(request, "/joke") && !strncmp(request->method.ptr, "GET", 3))
	{
		url = "https://v2.jokeapi.dev/joke/Any?safe-mode";
		show_content(connection, request);
		add_log("GET", "/joke", HTTP_OK);
	}
	else
	{
		char	**matrix;
		size_t		index = 0;
		matrix = ft_split(request->method.ptr, ' ');

		mg_http_reply(connection, HTTP_NOT_FOUND, NULL, "{\"status\":\"%d\"}",
			HTTP_NOT_FOUND);
		add_log(matrix[0], matrix[1], 404);
		while (matrix[index])
		{
			free (matrix[index]);
			index++;
		}
		free(matrix);
	}
}
