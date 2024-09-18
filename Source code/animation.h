#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

//********************Lancher animations*********************
void lancher_animation1(char str[Y][X],short y_len,short x_len){
    rgb_color random_color;
    random_color.fg=0;
    srand(time(NULL));
    random_color.bg=rand();
    x_len--;
    for(int j=0;j<y_len;j++){
        set_color(random_color,1);
        puts(str[j]);
        delay(animation_delay);
    }
    clear_screen();
}
void lancher_animation2(char str[Y][X],short y_len,short x_len){
    rgb_color random_fg_color;
    random_fg_color.fg=0;
    for(int j=0;j<x_len;j++){
        set_color(random_fg_color,1);
        for(int i=0;i<y_len;i++){
            putchar(str[i][j]);
            gotoyx(-1,-1);
        }
        delay(animation_delay*y_len/x_len);
        gotoyx(y_len,1);
    }
    clear_screen();
}
void lancher_animation3(char str[Y][X],short y_len,short x_len){
    rgb_color random_color;
    random_color.fg=0;
    x_len--;
    printf(reset_screen);
    gotoyx(-y_len,0);
    for(int j=y_len-1;j>=0;j--){
        set_color(random_color,1);
        puts(str[j]);
        printf("\r");gotoyx(2,0);
        delay(animation_delay);
    }
    clear_screen();
}
void animation4(char str[Y][X],short y_len,short x_len){
    rgb_color random_color;
    random_color.fg=0;
    x_len--;
    gotoyx(-y_len,0);
    for(short i=0;i<x_len;i++){
        short y=y_len;
        short x=i;
        set_color(random_color,1);
        while(y>=0&&x>=0){
            putchar(str[y][x]),gotoyx(1,-2),y--,x--;
        }
        x++;y++;
        if(x==0&&y==0) gotoyx(y-y_len,i-x+2);
        else if (y==0&&x!=0) gotoyx(y-y_len,i-x+2);
        else gotoyx(y-y_len-1,i-x+2);
        delay(animation_delay);
    }
    gotoyx(0,1);
    for(int j=y_len;j>=0;j--){
        short y=j;
        short x=x_len-1;
        set_color(random_color,1);
        while(y>=0){
            putchar(str[y][x]),gotoyx(1,-2),y--,x--;
        }
        x++;
        gotoyx(-j+1,x_len-x+1);
        delay(animation_delay);
    }
    printf(reset_style);
}

#endif // ANIMATION_H_INCLUDED
