#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

char DizzyBuf[80];
int DizzyDate = 0, DizzyMonth = 0, cur_date = 0, newuser = 0;
int day, month, year, hour, min, c_day, c_month, c_year, c_hour, c_min;

/*
 ***************************************************************************
 ********[ DizzyCompute ]****************************************************
 ***************************************************************************
*/
int DizzyCompute()
{
	struct tm *tm; /* file time */
/* struct tm *t; */
	time_t t;
	struct stat ft;

	stat(DizzyBuf, &ft); /* grab the file time */
	tm = localtime(&ft.st_mtime);

	day = tm->tm_mday;
	month = tm->tm_mon + 1;
	year = tm->tm_year;
	hour = tm->tm_hour;
	min = tm->tm_min;

/*
   (void *) t=time(0);
   tm=localtime(&t);


   struct tm *tm;
 */
	t = time(0);
	tm = localtime(&t);

	c_day = tm->tm_mday;
	c_month = tm->tm_mon + 1;
	c_year = tm->tm_year;
	c_hour = tm->tm_hour;
	c_min = tm->tm_min;

	printf("year: %i -- current year: %i\n", year, c_year);
	if (year < c_year)
	{
		DizzyDate = 6;
		printf("Not the same year EXITING!\n");
	}

	if ((month - c_month) == 0)
	{
		DizzyDate = (c_day - day);
	}
	else
	{
		if (month == 1) /* if month is 1 */
		{
			DizzyDate = (c_day - day + 31);
		}
		if (month == 2) /* if month is 2 */
		{
			DizzyDate = (c_day - day + 29);
		}
		if (month == 3) /* if month is 3 */
		{
			DizzyDate = (c_day - day + 30);
		}
		if (month == 4) /* if month is 4 */
		{
			DizzyDate = (c_day - day + 30);
		}
		if (month == 5) /* if month is 5 */
		{
			DizzyDate = (c_day - day + 31);
		}
		if (month == 6) /* if month is 6 */
		{
			DizzyDate = (c_day - day + 30);
		}
		if (month == 7) /* if month is 7 */
		{
			DizzyDate = (c_day - day + 31);
		}
		if (month == 8) /* if month is 8 */
		{
			DizzyDate = (c_day - day + 31);
		}
		if (month == 9) /* if month is 9 */
		{
			DizzyDate = (c_day - day + 30);
		}
		if (month == 10) /* if month is 10 */
		{
			DizzyDate = (c_day - day + 31);
		}
		if (month == 11) /* if month is 11 */
		{
			DizzyDate = (c_day - day + 30);
		}
		if (month == 12) /* if month is 12 */
		{
			DizzyDate = (c_day - day + 31);
		}
	}

/* remove this to FASTEST !!!!!! */
	printf("date: %s", ctime(&ft.st_mtime));
	printf("day   : %i\n", tm->tm_mday);
	printf("month : %i\n", tm->tm_mon);
	printf("yeah  : %i\n", tm->tm_year);
	printf("hour  : %i\n", tm->tm_hour);
	printf("min   : %i\n", tm->tm_min);

	printf("\n*** FILE DATE ***\nday   : %i\n", day);
	printf("month : %i\n", month);
	printf("yeah  : %i\n", year);
	printf("hour  : %i\n", hour);
	printf("min   : %i\n", min);

	printf("\n** CURRENT TIME ***\nc_day   : %i\n", c_day);
	printf("c_month : %i\n", c_month);
	printf("c_yeah  : %i\n", c_year);
	printf("c_hour  : %i\n", c_hour);
	printf("c_min   : %i\n", c_min);

	printf("\nmonth == %i\nDizzyDate == %i\n", month, DizzyDate);
/* remove this to FASTEST !!!!!! */

	return 0;
}

/*
   void DizzyCompute()
   {

   struct tm *tm;
   struct stat ft;

   stat(fish,&ft);

   tm=localtime(&ft.st_mtime);

    printf("date: %s",ctime(&ft.st_mtime));
    printf("day   : %i\n",tm->tm_mday);
    printf("month : %i\n",tm->tm_mon);
    printf("yeah  : %i\n",tm->tm_year);
    printf("hour  : %i\n",tm->tm_hour);
    printf("min   : %i\n",tm->tm_min);
   }
 */

int main()
{
	strcpy(DizzyBuf, "test.txt");

	DizzyCompute();

	return 0;
}
