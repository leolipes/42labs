#include <api.h>

extern FILE *g_content;
extern char	*url;

void	get_content(void)
{
	CURL *curl;
	CURLcode result;

	g_content = fopen("./content/content.txt", "wb");
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, g_content);
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
		result = curl_easy_perform(curl);
		if (result == CURLE_OK)
			printf("Site content downloaded successfully!\nTo view the content of the site go to: ./content\n");
		if (result != CURLE_OK)
			fprintf(stderr, "ERROR: %s\n :c", curl_easy_strerror(result));
		fclose(g_content);
		curl_easy_cleanup(curl);
	}
}
