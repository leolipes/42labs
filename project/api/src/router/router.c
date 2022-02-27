/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:16:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/26 18:55:58 by lfilipe-         ###   ########.fr       */
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
	}
	else if (mg_http_match_uri(request, "/tv") && !strncmp(request->method.ptr, "GET", 3))
	{
		url = "http://api.tvmaze.com/search/shows?q=golden%20girls";
		show_content(connection, request);
	}
	else if (mg_http_match_uri(request, "/cat") && !strncmp(request->method.ptr, "GET", 3))
	{
		url = "https://http.cat";
		show_content(connection, request);
	}
	else
	{
		mg_http_reply(connection, HTTP_NOT_FOUND, NULL, "{\"status\":\"%d\"}",
			HTTP_NOT_FOUND);
	}
}
