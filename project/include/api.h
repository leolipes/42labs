#ifndef API_H
# define API_H

#include <curl/curl.h>
#include "mongoose.h"

void		router(struct mg_connection *connection, struct mg_http_message *request);

static void	handler_request(struct mg_connection *connection, int ev, void *ev_data, void *fn_data);

void		controller_request(struct mg_connection *connection, struct mg_http_message *request);


size_t		got_data(char *buffer, size_t itemsize, size_t nun_items, void *userdata);

int			get_api_data(void);

#endif