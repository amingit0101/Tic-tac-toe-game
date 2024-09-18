#ifndef SETTINGS2_H_INCLUDED
#define SETTINGS2_H_INCLUDED
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
void buttons_settings(){
    extern char up,down,left,right,confirm,exit_game;
    extern char up_left,up_right,down_left,down_right;
    extern char menu_up,menu_down,menu_go_back,menu_next,menu_prev,menu_confirm;
    printf("\033[?25h");
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
    puts("       Tap Backslash to exit");
    gotoyx(18,5);
    char arrow;
up:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&arrow!='\b');
    switch(arrow){
    case '\r':up=select_button(up);break;
    case '\b':goto save;
    }
    gotoyx(-1,2);
down:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':down=select_button(down);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,-2);goto up;
    }
    gotoyx(-1,0);
left:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':left=select_button(left);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,0);goto down;
    }
    gotoyx(-1,1);
right:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':right=select_button(right);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,-1);goto left;
    }
    gotoyx(-1,2);
confirm:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':confirm=select_button_containing_enter();break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,-2);goto right;
    }
    gotoyx(-1,-3);
exit:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':exit_game=select_button(exit_game);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,3);goto confirm;
    }
    gotoyx(-1,3);
up_left:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&arrow!='\b'&&(int)arrow!=72&&(int)arrow!=75);
    switch(arrow){
    case '\r':up_left=select_button(up_left);break;
    case 75:case 72:gotoyx(1,-3);goto exit;
    case '\b':goto save;
    }
    gotoyx(-1,1);
up_right:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&arrow!='\b'&&(int)arrow!=72&&(int)arrow!=75);
    switch(arrow){
    case '\r':up_right=select_button(up_right);break;
    case 75:case 72:gotoyx(1,-1);goto up_left;
    case '\b':goto save;
    }
    gotoyx(-1,1);
down_left:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&arrow!='\b'&&(int)arrow!=72&&(int)arrow!=75);
    switch(arrow){
    case '\r':down_left=select_button(down_left);break;
    case 75:case 72:gotoyx(1,-1);goto up_right;
    case '\b':goto save;
    }
    gotoyx(-1,1);
down_right:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&arrow!='\b'&&(int)arrow!=72&&(int)arrow!=75);
    switch(arrow){
    case '\r':down_right=select_button(down_right);break;
    case 75:case 72:gotoyx(1,-1);goto down_left;
    case '\b':goto save;
    }
    gotoyx(-2,-8);
menu_up:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&arrow!='\b'&&(int)arrow!=72&&(int)arrow!=75);
    switch(arrow){
    case '\r':menu_up=select_button(menu_up);break;
    case 72:case 75:gotoyx(2,8);goto down_right;
    case '\b':goto save;
    }
    gotoyx(-1,2);
menu_down:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':menu_down=select_button(menu_down);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,-2);goto menu_up;
    }
    gotoyx(-1,3);
menu_confirm:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&(int)arrow!=80&&(int)arrow!=77&&(int)arrow!=72&&(int)arrow!=75&&arrow!='\b');
    switch(arrow){
    case '\r':menu_confirm=select_button_containing_enter();break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,-3);goto menu_down;
    }
    gotoyx(-1,0);
menu_go_back:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&arrow!=72&&arrow!=75&&arrow!=77&&arrow!='\b');
    switch(arrow){
    case '\r':menu_go_back=select_button(menu_go_back);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,0);goto menu_confirm;
    }
    gotoyx(-1,-3);
menu_next:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&arrow!=72&&arrow!=75&&arrow!=77&&arrow!='\b');
    switch(arrow){
    case '\r':menu_next=select_button(menu_next);break;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,3);goto menu_go_back;
    }
    gotoyx(-1,0);
menu_prev:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!='\r'&&arrow!=72&&arrow!=75&&arrow!=77&&arrow!='\b');
    switch(arrow){
    case '\r':menu_prev=select_button(menu_prev);gotoyx(1,0);goto menu_next;
    case '\b':goto save;
    case 75:case 72:gotoyx(1,0);goto menu_next;
    }
save:
    save_game_bottons_to_file("game-buttons.txt");
    save_menu_bottons_to_file("menu-buttons.txt");
}
#endif // SETTINGS2_H_INCLUDED
