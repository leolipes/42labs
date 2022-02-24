#ifndef API_H
# define API_H

# define HTTP_OK 200
# define HTTP_MOVED_PERMANENTLY 301
# define HTTP_UNAUTHORIZED 401
# define HTTP_NOT_FOUND 404

#include <curl/curl.h>
#include "mongoose.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//when i got data from get data
size_t	got_data(char *buffer, size_t itemsize, size_t nitems, void *userdata);

//get data with request
int	get_data(void);

//handle when I get a request
static void	handler_request(struct mg_connection *connection, int ev, void *ev_data, void *fn_data);

//controller
void	router(struct mg_connection *connection, struct mg_http_message *request);

#endif