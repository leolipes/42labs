/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:53:04 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/26 17:48:52 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

FILE	*g_content;
char	*url;

static void	handler_request(struct mg_connection *connection, int ev, void *ev_data, void *fn_data)
{
	/*struct mg_connection *connection - A connection that received an event*/

	/*int event - An event number, defined in mongoose.h. For example, when data arrives on an inbound connection, ev would be MG_EV_READ*/

	/*void *ev_data - Points to the event-specific data, and it has a different meaning for different events. The exact meaning of ev_data is described for each event. Protocol-specific events usually have ev_data pointing to structures that hold protocol-specific information*/

	/*void *fn_data - A user-defined pointer for the connection, which is a placeholder for application-specific data. This fn_data pointer is set during the *_listen() or *_connect() call, and it is stored in the c->fn_data.*/
	if (ev == MG_EV_HTTP_MSG)//HTTP request/response || struct mg_http_message *
		router(connection, (struct mg_http_message *) ev_data);
}

int	main(int argc, char *argv[])
{
	struct mg_mgr	mgr;

	//url = argv[1];
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, "http://localhost:8000", handler_request, &mgr);
	/*Em redes de computadores, Localhost se refere ao computador que está executando um programa. O computador funciona como se fosse um servidor virtual.*/
	while (true)
		mg_mgr_poll(&mgr, 1000);
	mg_mgr_free(&mgr);
	return EXIT_SUCCESS;
}
