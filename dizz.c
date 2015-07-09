/*

            "Dizz" the file_id.diz grabber
              by Snake Man, PMC 1999-2015.
                www.nekromantix.com/pmc

    reads specified dir of *.zip files and extracts the
    dizzys into the specified daydream filelist. simple.

 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

FILE *filelisting;
FILE *file_diz;
FILE *FileName;

int i = 0, nodiz = 0, diz = 0;
unsigned long FileSize = 0;
char buf[1024];
char dizline[200];
char timer[80];
char *utemp[100];
char da_path[100];

glob_t gl;
time_t currtime;

int timer_call()
{
	struct stat ft;

	stat(gl.gl_pathv[i], &ft);
	printf("hihihii: %s", ctime(&ft.st_mtime));

	strcpy(timer, ctime(&ft.st_mtime));

	return 0;
}

/* to stript the path from files (names actually) */
int splitpath(char **args, char *p)
{
	int c = 0;

	while (*p == '/')
		p++;

	args[c++] = p;
	while (*p)
	{
		if (*p == '/')
		{
			*(p++) = 0;
			args[c++] = p;
			while(*p == '/')
				p++;
		}
		else
			p++;
	}
	args[c] = 0;

	return c - 1;
}

int main(int x, char *argc[])
{
	int ui = 0;

	if (x == 2)
		strcpy(da_path, argc[1]);

	printf("\n\n\tdizz the file_id.diz grabber (c) Snake Man, PMC 1999-2015.\n\n");

	strcat(da_path, "*.zip");
	glob(da_path, 0, 0, &gl);

	filelisting = fopen("directory.diz", "at");
	if (!filelisting)
	{
		printf("error at: directory.diz!\n");
		exit(1);
	}
	printf("Opened directory.diz\n");

	for (i = 0; i < gl.gl_pathc; i++)
	{
		printf("working on: %s\n", gl.gl_pathv[i]);
		sprintf(buf, "unzip %s file_id.diz FILE_ID.DIZ >/dev/null", gl.gl_pathv[i]);
		system(buf); /* execute the unzip command */

		file_diz = fopen("file_id.diz", "rt");
		if (!file_diz)
		{
			file_diz = fopen("FILE_ID.DIZ", "rt");
			if (!file_diz)
				printf("no file_id.diz OR FILE_ID.DIZ on the %s file.\n", gl.gl_pathv[i]);
		} /* flow evaluate this: open diz, if not found open DIZ. should it work? */

		FileName = fopen(gl.gl_pathv[i], "r");
		fseek(FileName, 0, SEEK_END); /* zoom to end */
		FileSize = 0;                 /* make sure the size is zero */
		FileSize = ftell(FileName);   /* grab the position (filesize) */
		fclose(FileName);             /* close the file */

		timer_call();
		ui = splitpath(utemp, gl.gl_pathv[i]);

		sprintf(buf, "%-34s P--- %7lu %s", utemp[ui], FileSize, timer);
		fputs(buf, filelisting); /* write filename */

		if (!file_diz)
		{
			fputs("                                   no file_id.diz found in this file!\n", filelisting);
			nodiz++;
		}
		else
		{
			fgets(dizline, 200, file_diz);

			while (!feof(file_diz))
			{
				sprintf(buf, "                                   %s", dizline);
				if (strlen(buf) > 80)
				{
					buf[80] = '\n';
					buf[81] = '\0';
				}
				fputs(buf, filelisting);
				fgets(dizline, 200, file_diz); /* get diz, yes longer than 46 */
			}

			fclose(file_diz);
			unlink("file_id.diz");
			unlink("FILE_ID.DIZ");
			diz++;
		}
	}

	globfree(&gl);
	fclose(filelisting);

	printf("\n\n\tYou had %i file_id.diz files and %i with no dizzy found\n\n", diz, nodiz);

	return 0;
}
