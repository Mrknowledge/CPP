#include <stdio.h>

int main(int argv,char **argc)
{
	gzFile file;
	
	file = gzopen(source,"rb");
	if(file == NULL)
	{
		prinf("gzopen error!\n");
		exit(1);
	}

	while(!gzeof(file))
	{
		if(gzread(file,uncompr,(unsigned)uncomprLen) != len)
		{
			printf("gzread error!");
			exit(1);
		}

		if(strcmp((char*)uncompr,hello))
		{
			printf("bad gzread!");
			exit(1);
		}
		else
		{
			printf("gzread():%s\n", (char*)uncompr);
		}
	}

	gzclose(file);

	printf("gzread file finished!");
}
