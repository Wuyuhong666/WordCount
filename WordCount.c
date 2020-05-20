#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	char str[1000];
	FILE *fp;
	int n=0;
	int i=0; 
	if((fp=fopen(argv[2],"r"))==NULL)
	{ 
		printf("Open file error\n");
		exit(0);
	}
	fseek(fp,0L,0);
	while(!feof(fp))
	{ 
		fread(&str[i], 1, 1, fp);
		i++;
	}
	str[i]='\0';
	i=0;
	if(!strcmp(argv[1],"-c"))
	{
		while(str[n]!='\0')
		{
			n++;
		}
		n--;
		printf("字符数：%d\n",n);
	}
	else if(!strcmp(argv[1],"-w"))
	{
		while(str[i]!='\0')
		{
			if(str[i]==' '||str[i]==',')
			{
				n++;
			}
			i++;
		}
		n++;
			printf("单词数：%d\n",n);
	}
	else
	{
		printf("输入的参数有误");
		exit(0);
	}
	fclose(fp);
	system("pause");
	return 0;
}