#ifndef ENVIRONEMENT_H_INCLUDED
#define ENVIRONEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#ifdef _WIN32_
    #include <conio.h>
    #include <windows.h>
    #define delay(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define delay(ms) usleep(ms*1000)
    void linux_arrows(char *c){//turn arrows in linux ,like windows
        if(*c!='\033') return;
        scanf("%c",c);
        if(*c!='[') return;
        scanf("%c",c);
        switch(*c){
        case 'A':*c=72;break;
        case 'B':*c=80;break;
        case 'C':*c=77;break;
        case 'D':*c=75;break;
        }
    }
    int getch(){
        char c;
        system("stty raw -echo");
        scanf("%c",&c);
        if((int)c==127) c=8;//Fix backslash
        linux_arrows(&c);
        system("stty -raw echo");
        return c;
    }
    void itoa(short num,char *buffer,int radix){
        strcpy(buffer,"");
        int i=0;
        if(num==0){
            buffer[i]='0',buffer[i+1]='\0';
            return ;
        }
        while(num>0){
            if(radix>10&& num%radix>9) buffer[i]='A'+num%radix-10;
            else buffer[i]='0'+num%radix;
            num/=radix;
            i++;
        }
        buffer[i]='\0';
        for(int j=0;j<=(i-1)/2;j++) buffer[j]=buffer[i-1-j];
    }
#endif
typedef struct rgb_color{
    short fg;
    short bg;
}rgb_color;
typedef struct player{
    char c;
    rgb_color c_color;
    short winns;
}player;

typedef struct coord{
    bool used;
    player player;
}coord;
short dim=3,shift_left=6,shift_down=0;
char border_x='-',border_y='|';
rgb_color border_color,area_color;

rgb_color main_menu_borders_color,main_menu_string_color;
rgb_color parameters_menu_borders_color,parameters_menu_string_color;
short shift_left_main_menu=0,shift_down_main_menu=0;
short shift_left_parameters_menu=0,shift_down_parameters_menu=0;

char up='8',down='2',left='6',right='4',exit_game='\b',confirm='\r';
char up_left='9',up_right='7';
char down_left='3',down_right='1';

char menu_up=72,menu_down=80,menu_next=77,menu_prev=75;
char menu_go_back='\b',menu_confirm='\r';

int power(int n,int m){
    int result=1;
    for(int i=0;i<m;i++) result*=n;
    return result;
}
typedef struct position{
    short x;
    short y;
}position;
#define animation_delay 50
#include "functions.h"
#include "screen.h"
#include "menus.h"
#include "settings.h"
#include "game.h"
#endif // ENVIRONEMENT_H_INCLUDED
