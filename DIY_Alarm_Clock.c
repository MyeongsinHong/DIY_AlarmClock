#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>

int main(void){
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);
    setlocale(LC_ALL,"");
    
    if(t->tm_hour == 0){
        wprintf(L"현재시각 -> %d:%d AM", t->tm_hour + 12, t->tm_min);
    }
    else if(t->tm_hour < 12){
        wprintf(L"현재시각 -> %d:%d AM", t->tm_hour, t->tm_min);
    }
    else if(t->tm_hour == 12){
        wprintf(L"현재시각 -> %d:%d PM", t->tm_hour, t->tm_min);
    }
    else{
        wprintf(L"현재시각 -> %d:%d PM", t->tm_hour-12, t->tm_min);
    }
    return 0;
}
