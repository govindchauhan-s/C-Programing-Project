#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

void clear_screen();
void fill_time(char*, int);
void fill_date(char*);
int input_format();

int main(){
    char time[50], date[100];
    int format = input_format();

    while(1){
    fill_time(time, format);
    fill_date(date);
    clear_screen();
    printf("Current Time: %s\n", time);
    printf("Date: %s\n", date);
    sleep(1);
    }
    return 0;
}

void clear_screen(){
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
}

int input_format(){
    int format;
    printf("\nChoose the timr format: ");
    printf("\n1. 24 Hour format");
    printf("\n2. 12 Hour format (default)");
    printf("\nMake a choise(1/2): ");
    scanf("%d", &format);
    return format;
}

void fill_date(char* buffer){
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 100, "%A %B %d %Y", current_time);


}

void fill_time(char* buffer, int format){
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    if (format == 1){
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }else {
    strftime(buffer, 50, "%I:%M:%S", current_time);
    }
}