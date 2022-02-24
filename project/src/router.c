/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:16:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/24 01:43:22 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>

void	router(struct mg_connection *connection, struct mg_http_message *request)
{
	if (mg_http_match_uri(request, "/200") && strncmp(request->head.ptr, "GET", 3) == 0)
		controller_request(connection, request);
}
