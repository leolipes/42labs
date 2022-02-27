#ifndef API_H
# define API_H

# define HTTP_OK 200
# define HTTP_NOT_FOUND 404

#include <curl/curl.h>
#include "mongoose.h"
#include <stdlib.h>
#include <string.h>

//---------------------------------SERVER API---------------------------------//
//Function Directory: server
/**
 * @brief  Event handler function defines connection's behavior.
 * @param  *connection: A connection that received an event.
 * @param  ev: An event number, defined in mongoose.h.
 * @param  *ev_data: Points to the event-specific data, and it has a different
 * meaning for different events.
 * @param  *fn_data: A user-defined pointer for the connection, which is a
 * placeholder for application-specific data.
 * @retval None
 */
static void	handler_request(struct mg_connection *connection, int ev, void
*ev_data, void *fn_data);

//Function Directory: router
/**
 * @brief  Route management.
 * @param  *connection: connection descriptor.
 * @param  *request: HTTP message.
 * @retval None
 */
void	router(struct mg_connection *connection, struct mg_http_message *request);

//Function Directory: contoller
/**
 * @brief  Show the content of the route.
 */
void	show_content(struct mg_connection *connection,
			struct mg_http_message *request);

//Function Directory: log
/**
 * @brief  This function manage the log file.
 * @param  *method: Request method.
 * @param  *route: URI route.
 * @param  status: Response status codes
 * @retval None
 */
void	add_log(char *method, char *route, int status);
//----------------------------------------------------------------------------//

//---------------------------------CLIENT API---------------------------------//
//Function Directory: request
/**
 * @brief  This function starts libcurl, makes an http request and downloads the
 * response contents to a file
 * into a file.
 * @retval None
 */
void	get_content(void);
//----------------------------------------------------------------------------//


//-----------------------------------UTILS------------------------------------//
//Function Directory: utils
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
//----------------------------------------------------------------------------//

#endif