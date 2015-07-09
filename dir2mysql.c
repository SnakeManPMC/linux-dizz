#include <stdio.h>
#include <string.h>

FILE *in;

char temp[1024], oldline[1024];
char *p;
char c1[80], c2[80], c3[80], c4[80], c5[80], c6[80], c7[80], c8[80];
int diz = 0;

int main()
{
	in = fopen("directory.009", "rt");

	fgets(temp, 1024, in);

	while (!feof(in))
	{
//    if (strlen(temp) >80) {temp[80]='\n'; temp[81]='\0';}

		if (strncmp(temp, "             ", 13) != 0)
		{
			if (diz)
			{
				diz = 0;
				strcpy(temp, oldline);
			}

			p = strtok(temp, " ");
			strcpy(c1, p);
			printf("c1: %s\n", c1);

			p = strtok(NULL, " ");
			strcpy(c2, p);
			printf("c2: %s\n", c2);

			p = strtok(NULL, " ");
			strcpy(c3, p);
			printf("c3: %s\n", c3);

			p = strtok(NULL, " ");
			strcpy(c4, p);
			printf("c4: %s\n", c4);

			p = strtok(NULL, " ");
			strcpy(c5, p);
			printf("c5: %s\n", c5);

			p = strtok(NULL, " ");
			strcpy(c6, p);
			printf("c6: %s\n", c6);

			p = strtok(NULL, " ");
			strcpy(c7, p);
			printf("c7: %s\n", c7);

			p = strtok(NULL, " ");
			strcpy(c8, p);
			printf("c8: %s\n", c8);
		}
		else
		{
			printf("at else, and the fucker is:\n%s", temp);
			while (strncmp(temp, "             ", 13) == 0)
			{
				diz = 1;
				fgets(temp, 1024, in);
				printf("=>%s", temp);
				strcpy(oldline, temp);
			}
		}

		fgets(temp, 1024, in);
	}

	fclose(in);
	return 0;
}
