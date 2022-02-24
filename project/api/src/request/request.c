#include <api.h>

extern char	*g_buffer;

size_t	got_data(char *buffer, size_t itemsize, size_t nitems, void *userdata)
{
	size_t	bytes = itemsize * nitems;
	g_buffer = strdup(buffer);
	return bytes;
}

int	get_data(void)
{
	CURL *curl;
	CURLcode result;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://http.cat");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
		result = curl_easy_perform(curl);
		if (result != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
		curl_easy_cleanup(curl);
	}
	return EXIT_SUCCESS;
}