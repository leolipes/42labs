/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <lfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:21:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/24 00:40:34 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <api.h>
//callback function
/*size_t it's going to return the number of bytes that the function processed*/
size_t got_data(char *buffer, size_t itemsize, size_t nun_items, void *userdata)
{
	printf("%s\n", buffer);
	return (size_t)buffer;
}

void controller_request(struct mg_connection *connection, struct mg_http_message *request)
{
	mg_http_reply(connection, 200, "", "%d", got_data);
}

int	get_api_data(void)
{
	CURL	*curl = curl_easy_init();
	CURLcode result;

	if (!curl)
	{
		fprintf(stderr, "init failed\n");
		return EXIT_FAILURE;
	}

	curl_easy_setopt(curl, CURLOPT_URL, "https://http.cat");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
	result = curl_easy_perform(curl);
	if (result != CURLE_OK)
		fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
	curl_easy_cleanup(curl);
	return EXIT_SUCCESS;
}
