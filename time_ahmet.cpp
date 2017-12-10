#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

extern "C" char *now(){
char buffer[30];
char *bp;
int millisec;
struct tm* tm_info;
struct timeval tv;
gettimeofday(&tv, NULL);
millisec = lrint(tv.tv_usec/1000.0);// Round to nearest millisec
if (millisec>=1000){// Allow for rounding up to nearest second millisec -=1000;
tv.tv_sec++;}
tm_info=localtime(&tv.tv_sec);
strftime(buffer, 50, "%Y:%m:%d %H:%M:%S", tm_info);
bp=(char*)malloc(40);
sprintf(bp,"%s.%03d \n",buffer,millisec);
//printf("%s",bp);
return bp;
};

int _main() {
printf("%s",now());
printf("%s",now());
printf("%s",now());
return 0;};
