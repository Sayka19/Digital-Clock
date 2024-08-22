#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void fill_time(char[],int);
void fill_date(char[]);
int input_format();
void clear_screen();
int main()
{
    char time[50];
    char date[100];
    int format=input_format();
    while(1){
    fill_time(time,format);
    fill_date(date);
    clear_screen();
    printf("\nCurrent time: %s",time);
    printf("\nCurrent date: %s\n",date);
    sleep(1);
    }
    return 0;
}
void fill_time(char buffer[50],int format)
{
     time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time=localtime(&raw_time);
    if(format==1)
    {
       strftime(buffer,50,"%H:%M:%S",current_time);
    }
    else
    {
       strftime(buffer,50,"%I:%M:%S %p",current_time);
    }
    return buffer;
}
int input_format()
{
   int format;
    printf("Choose the time format:\n");
    printf("1.24 hour time format\n");
    printf("2.12 hour time format(default)\n");
    printf("Enter a choice:");
    scanf("%d",&format);
}
void fill_date(char buffer[100])
{
     time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time=localtime(&raw_time);
    strftime(buffer,50,"%A %B %d %Y",current_time);
    return buffer;
}
void clear_screen()
{
    #ifdef _WIN32
    system("cls");
    #endif
}
