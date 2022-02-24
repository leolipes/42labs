/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:16:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/24 16:27:13 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

extern char	*g_buffer;

void	router(struct mg_connection *connection, struct mg_http_message *request)
{
	if (mg_http_match_uri(request, "/") && !strncmp(request->method.ptr, "GET", 3))// ! it's the same thing as doing like this: == 0
	{
		get_data();
		mg_http_reply(connection, HTTP_OK, NULL, "{\"title\":\"My website\", \"content\":\"%s\"}", g_buffer);
	}
	if (mg_http_match_uri(request, "/200") && !strncmp(request->method.ptr, "GET", 3))
	{
		get_data();
		mg_http_reply(connection, HTTP_OK, NULL, "{\"title\":\"My website\", \"content\":\"%s\"}", g_buffer);
	}
	else
		mg_http_reply(connection, HTTP_NOT_FOUND, NULL, "{\"status\":\"%d\"}", HTTP_NOT_FOUND);
}
