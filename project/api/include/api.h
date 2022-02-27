#ifndef API_H
# define API_H

# define HTTP_OK 200
# define HTTP_MOVED_PERMANENTLY 301
# define HTTP_UNAUTHORIZED 401
# define HTTP_NOT_FOUND 404

#include <curl/curl.h> //libcurl
#include "mongoose.h"
#include <stdlib.h>
#include <string.h>

//get data with request
int	get_content(void);

void	show_content(struct mg_connection *connection,
			struct mg_http_message *request);

//handle when I get a request
static void	handler_request(struct mg_connection *connection, int ev, void *ev_data, void *fn_data);

//controller
void	router(struct mg_connection *connection, struct mg_http_message *request);

//register logs in an achived
void	add_log(char *method, char *route, int status);

//char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif