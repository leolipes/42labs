/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:53:04 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/24 01:39:50 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

static void	handler_request(struct mg_connection *connection, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_message *request;

	request = (struct mg_http_message *)ev_data;

	if (ev == MG_EV_HTTP_MSG)
	{
		router(connection, request);
	}
}

int	main(int argc, char *argv[])
{
	struct mg_mgr	mgr;
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, "http://localhost:8000", handler_request, &mgr);
	while (true)
		mg_mgr_poll(&mgr, 1000);
	mg_mgr_free(&mgr);
	return EXIT_SUCCESS;
}
