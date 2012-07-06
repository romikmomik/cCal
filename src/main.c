#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <langinfo.h>

typedef struct _callendar_t callendar_t;
struct _callendar_t
{
	unsigned int m;
	unsigned int y;
};

int parse(const char* par, callendar_t * call)
{
	int error = 0;
	if((!call)&&(!par)){
		printf("Invalid parameters\n");
		return -1;
	}
	if(strlen(par)!=7){
	 	printf("Invalid parameters\n");
                return -1;
	}

	error = sscanf(par,"%02d.%04d",&call->m,&call->y);
	if( (1>call->m)||
	    (12<call->m)||
	    (call->y<1900)|| error < 2 )
	{
		printf("Invalid parameters\n");
		return -2;
	}
	return 0;
}
int format_printf(const callendar_t call)
{
	time_t date;
	char *locale;
	struct tm* tm_date;

	locale = setlocale(LC_ALL,"");
	time (&date);
	tm_date = localtime( &date );
	tm_date->tm_year = call.y - 1900;
	tm_date->tm_mon = call.m - 1;
	mktime (tm_date);
	printf("locale = %s \n",locale);
	printf("TIME = %s \n",asctime(tm_date)); 
	{
		int i = 0;
	{
		int first_weekday 	= 0;
		long week_1stday_l 	= 0;
		first_weekday =* nl_langinfo (_NL_TIME_FIRST_WEEKDAY);
		week_1stday_l = (long) nl_langinfo (_NL_TIME_WEEK_1STDAY);
		printf("%d %d\n",first_weekday,week_1stday_l);
        }
		for(;i<7;i++)
		{
			 printf("%s ",nl_langinfo(ABDAY_1+i));
		}
		printf("\n");
	}
	return 0;
}
int main(int argc,char** argv)
{
	callendar_t call;
	char* parametr = NULL;
	if(argc < 2){
		printf("Invalid Parameters\n");
		return -1;
	}
	parametr =  argv[1];
	printf("Input: %s\n",parametr);
	if(!parse(parametr,&call)){
		printf("Parsed: %02d : %04d \n",call.m,call.y);
		format_printf(call);
	}
	return 0;
}
