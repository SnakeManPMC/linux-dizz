#include <stdio.h>
#include <string.h>

FILE *in;
FILE *out;

char line[300];
char temp[300];

int main()
{
	in = fopen("directory.mis", "rt");
	out = fopen("new.dir", "wt");

	fgets(temp, 300, in);

	while (!feof(in))
	{
		if (strlen(temp) > 80)
		{
			temp[80] = '\n';
			temp[81] = '\0';
		}
		strcpy(line, temp);

		if (strstr(temp, ""))
			fputs(line, out);
		fgets(temp, 300, in);
	}

	fclose(in);
	fclose(out);
	return 0;
}