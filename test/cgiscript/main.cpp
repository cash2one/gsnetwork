#include <iostream> 
#include <fcgi_stdio.h> 
#include <stdlib.h> 

char *path_name;
const char* query_string;
const char* uri;
int main() 
{
	int count = 0;
	while(FCGI_Accept() >= 0){
		printf("Content-type: text/html\r\n\r\n");
		path_name = getenv("SCRIPT_NAME"); 
		query_string = getenv("QUERY_STRING"); 
		uri = getenv("REQUEST_URI"); 
		printf("path_name:%s|||||||||||||query_string:%s||||||||||||||uri:%s",path_name,query_string,uri);
	}
	return 0;
}
