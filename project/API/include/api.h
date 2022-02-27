#ifndef API_H
# define API_H

# define HTTP_OK 200
# define HTTP_NOT_FOUND 404

#include <curl/curl.h>
#include "mongoose.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief  
 * @note
 * @param  *connection:
 * @param  ev:
 * @param  *ev_data:
 * @param  *fn_data:
 * @retval None
 */
static void	handler_request(struct mg_connection *connection, int ev, void *ev_data, void *fn_data);

/**
 * @brief
 * @note
 * @retval None
 */
void	get_content(void);

/**
 * @brief
 * @note
 * @param  *connection:
 * @param  *request:
 * @retval None
 */
void	show_content(struct mg_connection *connection,
			struct mg_http_message *request);

/**
 * @brief
 * @note
 * @param  *connection:
 * @param  *request:
 * @retval None
 */
void	router(struct mg_connection *connection, struct mg_http_message *request);

/**
 * @brief
 * @note
 * @param  *method:
 * @param  *route:
 * @param  status:
 * @retval None
 */
void	add_log(char *method, char *route, int status);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif