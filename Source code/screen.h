#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#define reset_style "\033[0m"
#define black_color "\033[31;30m"
#define reset_screen "\x1B[H"
void clear_screen(){
    printf("\033[2J");
    printf("\033[H");
}
void space(int n){
    for(int i=0;i<n;i++) printf(" ");
}
void character(char c,int n){
    for(int i=0;i<n;i++) printf("%c",c);
}
void gotoyx(int y,int x){
    if(y>0) printf("\033[%dA",y);
    if(y<0) printf("\033[%dB",-y);
    if(x>0) printf("\033[%dC",x);
    if(x<0) printf("\033[%dD",-x);
}
void random_color(rgb_color *color){
    srand(clock());
    if(color->fg==0){
        do{
            color->fg=rand()%256;
        }while(color->fg==0||color->fg==16||color->fg==232||color->fg==15||color->fg==31||color->fg==255);
    }
    if(color->bg==0){
        do{
            color->bg=rand()%256;
        }while(color->bg==0||color->bg==16||color->bg==232||color->bg==15||color->bg==31||color->bg==255);
    }
}
bool no_control_char(char c){
    if(c<33||c==127||c==129||c==157||c==141||c==143||c==144) return false;
    return true;
}
char next_no_control_char(char c){
    c++;
    if(c>255) c=33;
    else if(c==127||c==129||c==157||c==141) c++;
    else if(c==143) c+=2;
    return c;
}
char previous_no_control_character(char c){
    c--;
    if(c<33) c=255;
    else if(c==127||c==129||c==157||c==141) c--;
    else if(c==144) c-=2;
    return c;
}
void color_to_string(char *buffer_str,short buffer_size,rgb_color color,short mod){
    random_color(&color);
    switch(mod){
    case 1:snprintf(buffer_str,buffer_size,"\033[38;5;%dm",color.fg);break;
    case 2:snprintf(buffer_str,buffer_size,"\033[48;5;%dm",color.bg);break;
    case 3:snprintf(buffer_str,buffer_size,"\033[38;5;%d;48;5;%dm",color.fg,color.bg);break;
    }
}
void set_color(rgb_color color,short mod){
    char color_str[50];
    color_to_string(color_str,50,color,mod);
    printf(color_str);
}
rgb_color invert_color(rgb_color color){
    swap_int(&color.bg,&color.fg);
    return color;
}
rgb_color increment_color(rgb_color color,short mod){
    switch(mod){
    case 1:
        color.fg++;
        if(color.fg>255) color.fg=0;
    break;
    case 2:case 3:
        color.bg++;
        if(color.bg>255) color.bg=0;
    }
    return color;
}
rgb_color decreament_color(rgb_color color,short mod){
    switch(mod){
    case 1:
        color.fg--;
        if(color.fg<0) color.fg=255;
    break;
    case 2:case 3:
        color.bg--;
        if(color.bg<0) color.bg=255;
    }
    return color;
}
void print_num_with_0_begin(int ,int);
void print_color_mod(rgb_color color,short mod,short digits_num){
    switch(mod){
    case 1:
        print_num_with_0_begin(color.fg,digits_num);
        break;
    case 2:case 3:
        print_num_with_0_begin(color.bg,digits_num);
        break;
    }
}
rgb_color select_color(rgb_color color,char colored_char,char *arrow,short mod,int touches_num, ... ){
    va_list loop_evade_buttons;
    char med;
    extern short menu_up,menu_down,menu_confirm,menu_go_back;
    print_color_mod(color,mod,3);
    gotoyx(0,1);
    set_color(color,mod);putchar(colored_char);
    printf(reset_style);
    gotoyx(0,-5);
    do{
        *arrow=getch();
        if(*arrow==-32) *arrow=getch();
        if(*arrow==menu_up) color=increment_color(color,mod);
        if(*arrow==menu_down) color=decreament_color(color,mod);
        print_color_mod(color,mod,3);
        gotoyx(0,1);
        set_color(color,mod);putchar(colored_char);
        printf(reset_style);
        gotoyx(0,-5);
        va_start(loop_evade_buttons,touches_num);
        for(int i=0;i<touches_num;i++){
            if((int)*arrow==va_arg(loop_evade_buttons, int )){
                va_end(loop_evade_buttons);
                return color;
            }
        }
    }while(true);
}
void print_button(char button){
    switch(button){
    case 75:printf("Left arrow ");break;
    case 77:printf("Right arrow");break;
    case 80:printf("Down arrow ");break;
    case 72:printf("Up arrow   ");break;
    case '\b':printf("Backslash  ");break;
    case '\r':printf("Enter      ");break;
    default : printf("%c          ",button);break;
    }
}
char select_button(char last){
    char ch=0,prev_ch=0;
    do{
        prev_ch=ch;
        ch=getch();
        if(ch!='\r') print_button(ch);
        else print_button(prev_ch);
        character('\b',11);
    }while(ch!='\r');
    return prev_ch;
}
char select_button_containing_enter(){
    char ch=0,prev_ch=0;bool first_tap=true;
    do{
        prev_ch=ch;
        ch=getch();
        if(ch!='\r'&&!first_tap) print_button(ch);
        else if(!first_tap&&ch=='\r'){
            print_button(prev_ch);
            break;
        }
        else{
            print_button(ch);
            break;
        }
        if(first_tap) !first_tap;
        character('\b',11);
    }while(true);
    character('\b',11);
    return prev_ch;
}
char select_no_control_button(){
    char ch=0,prev_ch=0;
    do{
        prev_ch=ch;
        ch=getch();
        while(!no_control_char(ch)&&ch!='\r') ch=getch();
        if(ch!='\r') print_button(ch);
        else print_button(prev_ch);
        character('\b',11);
    }while(ch!='\r');
    return prev_ch;
}
short select_number(int num,char *arrow,int lenght,int min,int max,int evade_loop_chars_num, ...){
     va_list loop_evade_buttons;
    char med;
    print_num_with_0_begin(num,lenght);
    gotoyx(0,-lenght);
    do{
        *arrow=getch();
        if(*arrow==-32) *arrow=getch();
        if(*arrow==menu_up) num++;
        if(*arrow==menu_down) num--;
        if(num>max) num=min;
        if(num<min) num=max;
        print_num_with_0_begin(num,lenght);
        gotoyx(0,-lenght);
        va_start(loop_evade_buttons,evade_loop_chars_num);
        for(int i=0;i<evade_loop_chars_num;i++){
            if(*arrow==va_arg(loop_evade_buttons, int )){
                va_end(loop_evade_buttons);
                return num;
            }
        }
    }while(true);
}
char select_character(char ch,char *arrow,int evade_loop_chars_num, ...){
     va_list loop_evade_buttons;
     va_start(loop_evade_buttons,evade_loop_chars_num);
     printf("%c\b",ch);
     do{
        *arrow=getch();
        if(*arrow==-32) *arrow=getch();
        if(*arrow==menu_up) ch=next_no_control_char(border_x);
        if(*arrow==menu_down) ch=previous_no_control_character(border_x);
        printf("%c\b",ch);
        for(int i=0;i<evade_loop_chars_num;i++){
            if(*arrow==va_arg(loop_evade_buttons, int )){
                va_end(loop_evade_buttons);
                return ch;
            }
        }
    }while(true);
}
void write_tictactoe_table(){
    extern short dim,shift_left,shift_down;
    extern short border_x, border_y;
    extern rgb_color border_color,area_color;
    gotoyx(-shift_down,0);
    for(int i=0;i<dim;i++){
        printf(" ");
        space(shift_left);
        printf(reset_style);set_color(border_color,1);
        character(border_x,4*(dim-1));
        character(border_x,3);
        printf(reset_style);
        printf("\n");
        space(shift_left);
        set_color(border_color,1);putchar(border_y);
        printf(reset_style);set_color(area_color,2);space(3);
        for(int j=0;j<dim-1;j++){
            printf(reset_style);set_color(border_color,1);putchar(border_y);
            printf(reset_style);set_color(area_color,2);space(3);
        }
        printf(reset_style);set_color(border_color,1);putchar(border_y);
        printf("\n");
        if(i == dim-1 ){
            printf(" ");
            space(shift_left);
            printf(reset_style);set_color(border_color,1);character(border_x,4*(dim-1));
            printf(reset_style);set_color(border_color,1);character(border_x,3);
            printf("\n");
        }
        printf(reset_style);
    }
}
#define Y 12
#define X 60
#include "animation.h"
void write_main_menu(){
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    gotoyx(-shift_down_main_menu,0);
    printf("\e[?25l");
    space(shift_left_main_menu);puts("         ------------");
    space(shift_left_main_menu);puts("        |  MAIN MENU |");
    space(shift_left_main_menu);puts("         -----------");
    printf("\n");
    space(shift_left_main_menu);
    printf(" ");set_color(main_menu_borders_color,3);printf("-----------\n",reset_style);
    space(shift_left_main_menu);set_color(main_menu_borders_color,3);printf("|",reset_style);
    set_color(main_menu_string_color,1);printf("Two players",reset_style);
    set_color(main_menu_string_color,3);printf("|\n",reset_style);
    space(shift_left_main_menu);printf(" ");set_color(main_menu_borders_color,3);printf("-----------\n",reset_style);
    space(shift_left_main_menu);printf(" ");puts("             ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,1);printf("Against a bot\n",reset_style);
    space(shift_left_main_menu);printf(" ");puts("             ");
    space(shift_left_main_menu);printf(" ");puts("          ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,1);printf("Parameters\n",reset_style);
    space(shift_left_main_menu);printf(" ");puts("          ");
    space(shift_left_main_menu);printf(" ");puts("    ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,1);printf("Exit\n",reset_style);
    space(shift_left_main_menu);printf(" ");puts("    ");
    printf("\n");
    space(shift_left_main_menu+1);set_color(main_menu_string_color,1);
    printf("Press enter to close \n",reset_style);
    while(getch()!='\r');
}
void write_parameters_menu(){
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    short shift_left_parameters_menu,shift_down_parameters_menu;
    printf("\e[?25l");
    space(shift_left_parameters_menu);puts("       Parameters:");
    printf("\n");
    space(shift_left_parameters_menu);printf(" ");puts("        ");
    space(shift_left_parameters_menu);printf(" ");set_color(parameters_menu_string_color,1);printf("In game\n",reset_style);
    space(shift_left_parameters_menu);printf(" ");puts("        ");
    space(shift_left_parameters_menu);printf(" ");puts("     ");
    space(shift_left_parameters_menu);printf(" ");set_color(parameters_menu_string_color,1);printf("Menus\n",reset_style);
    space(shift_left_parameters_menu);printf(" ");puts("     ");
    space(shift_left_parameters_menu);printf(" ");puts("    ");
    space(shift_left_parameters_menu);printf(" ");set_color(parameters_menu_string_color,1);printf("Bottons\n",reset_style);
    space(shift_left_parameters_menu);printf(" ");puts("    ");
    printf("\n");
    space(shift_left_parameters_menu+1);set_color(parameters_menu_string_color,1);
    printf("Press enter to close \n",reset_style);
}
void init_frame(char frame[Y][X]){
    for(int j=0;j<Y;j++) for(int i=0;i<X;i++) frame[j][i]='\0';
}
void first_frame(){
    rgb_color random_fg_color;
    random_fg_color.fg=0;
    char frame[Y][X];
    init_frame(frame);
    strcpy(frame[0],"  ----------      --      ---------- ");
    strcpy(frame[1]," |          |    |  |    |          |");
    strcpy(frame[2],"  ---    ---     |  |    |   ------- ");
    strcpy(frame[3],"     |  |        |  |    |  |        ");
    strcpy(frame[4],"     |  |        |  |    |  |        ");
    strcpy(frame[5],"     |  |        |  |    |  |        ");
    strcpy(frame[6],"     |  |        |  |    |  |        ");
    strcpy(frame[7],"     |  |        |  |    |  |        ");
    strcpy(frame[8],"     |  |        |  |    |  |        ");
    strcpy(frame[9],"     |  |        |  |    |   ------- ");
    strcpy(frame[10],"     |  |        |  |    |          |");
    strcpy(frame[11],"      --          --      ---------- ");
    lancher_animation1(frame,12,39);
}
void second_frame(){
    char frame[Y][X];
    init_frame(frame);
    strcpy(frame[0],"  ----------     -------------     ---------- ");
    strcpy(frame[1]," |          |   |             |   |          |");
    strcpy(frame[2],"  ---    ---    |   -------   |   |   ------- ");
    strcpy(frame[3],"     |  |       |  |       |  |   |  |        ");
    strcpy(frame[4],"     |  |       |  |       |  |   |  |        ");
    strcpy(frame[5],"     |  |       |   -------   |   |  |        ");
    strcpy(frame[6],"     |  |       |   -------   |   |  |        ");
    strcpy(frame[7],"     |  |       |  |       |  |   |  |        ");
    strcpy(frame[8],"     |  |       |  |       |  |   |  |        ");
    strcpy(frame[9],"     |  |       |  |       |  |   |   ------- ");
   strcpy(frame[10],"     |  |       |  |       |  |   |          |");
   strcpy(frame[11],"      --         --         --     ---------- ");
    lancher_animation2(frame,12,60);
}
void third_frame(){
    char frame[Y][X];
    init_frame(frame);
    gotoyx(1,0);printf(" ");
    gotoyx(-1,0);
    strcpy(frame[0],"  ----------     -------------     ---------- ");
    strcpy(frame[1]," |          |   |             |   |          |");
    strcpy(frame[2],"  ---    ---    |   -------   |   |   ------- ");
    strcpy(frame[3],"     |  |       |  |       |  |   |  |        ");
    strcpy(frame[4],"     |  |       |  |       |  |   |   ------- ");
    strcpy(frame[5],"     |  |       |  |       |  |   |          |");
    strcpy(frame[6],"     |  |       |  |       |  |   |          |");
    strcpy(frame[7],"     |  |       |  |       |  |   |   ------- ");
    strcpy(frame[8],"     |  |       |  |       |  |   |  |        ");
    strcpy(frame[9],"     |  |       |   -------   |   |   ------- ");
   strcpy(frame[10],"     |  |       |             |   |          |");
   strcpy(frame[11],"      --         -------------     ---------- ");
   lancher_animation3(frame,12,60);
}
void game_buttons(){
    extern short up,down,left,right,confirm,exit_game;
    extern short up_left,up_right,down_left,down_right;
    extern short menu_up,menu_down,menu_go_back,menu_next,menu_prev,menu_confirm;
    printf("\033[?25l");
    puts("         Setting bottons in game");
    printf("  Up:");print_button(up);puts("");
    printf("  Down:");print_button(down);puts("");
    printf("  Left:");print_button(left);puts("");
    printf("  right:");print_button(right);puts("");
    printf("  Confirm:");print_button(confirm);puts("");
    printf("  exit:");print_button(exit_game);puts("");
    printf("  Up left:");print_button(up_left);puts("");
    printf("  Up right:");print_button(up_right);puts("");
    printf("  Down left:");print_button(down_left);puts("");
    printf("  Down right:");print_button(down_right);puts("");
    puts("         Setting bottons in menus");
    printf("  Up:");print_button(menu_up);puts("");
    printf("  Down:");print_button(menu_down);puts("");
    printf("  Confirm:");print_button(menu_confirm);puts("");
    printf("  Go back:");print_button(menu_go_back);puts("");
    printf("  Next:");print_button(menu_next);puts("");
    printf("  Prev:");print_button(menu_prev);puts("");
    getch();
}
#endif // SCREEN_H_INCLUDED
