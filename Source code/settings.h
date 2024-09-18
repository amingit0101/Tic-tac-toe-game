#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED
int count_digits(int num){
    if(num==0) return 1;
    int digit_num=0;
    while(num>=power(10,digit_num)) digit_num++;
    return digit_num;
}
void print_num_with_0_begin(int num,int total_digits){
    int digits_num=count_digits(num);
    character('0',total_digits-digits_num);
    printf("%d",num);
}
void main_menu_settings(){
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    short tmp_shift_left_main_menu=shift_left_main_menu,tmp_shift_down_main_menu=shift_down_main_menu;
    rgb_color tmp_main_menu_borders_color=main_menu_borders_color;
    rgb_color tmp_main_menu_string_color=main_menu_string_color;
    extern short menu_up,menu_down,menu_confirm,menu_go_back;
    char arguments[300]="";
    printf("\033[?25l");
    puts("          Main menu settings:\n");
    printf("   Foreground border color:");
    print_num_with_0_begin(main_menu_borders_color.fg,3);printf(" ");
    set_color(main_menu_borders_color,1);printf("C\n");printf(reset_style);
    printf("   Foreground string color:");
    print_num_with_0_begin(main_menu_string_color.fg,3);printf(" ");
    set_color(main_menu_string_color,1);printf("C\n");printf(reset_style);
    printf("   Background string color:");
    print_num_with_0_begin(main_menu_string_color.bg,3);printf(" ");
    set_color(main_menu_string_color,3);printf("C\n");printf(reset_style);
    printf("   Shift left:%d\n",shift_left_main_menu);
    printf("   Shift down:%d\n\n",shift_down_main_menu);
    char arrow;
    gotoyx(6,27);
    printf("\033[?25h");
foreground_border_color:
    main_menu_borders_color=select_color(main_menu_borders_color,'C',&arrow,1,4,menu_confirm,menu_go_back,77,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case '\0':
        get_settings_main_menu_arguments(arguments);
        start_program_new_window("main_menu_layout",arguments);
        goto foreground_border_color;
    }
    gotoyx(-1,0);
foreground_string_color:
    main_menu_string_color=select_color(main_menu_string_color,'C',&arrow,1,5,menu_confirm,menu_go_back,77,'0',75);
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,0);goto foreground_border_color;
    case '\0':
        get_settings_main_menu_arguments(arguments);
        start_program_new_window("main_menu_layout",arguments);
        goto foreground_string_color;
    }
    gotoyx(-1,0);
background_string_color:
    main_menu_string_color=select_color(main_menu_string_color,'C',&arrow,3,5,menu_confirm,menu_go_back,77,'0',75);
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,0);goto foreground_string_color;
    case '\0':
        get_settings_main_menu_arguments(arguments);
        start_program_new_window("main_menu_layout",arguments);
        goto background_string_color;
    }
    printf("\r");
    gotoyx(-1,14);
shift_left:
    shift_left_main_menu=select_number(shift_left_main_menu,&arrow,2,0,20,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:printf("\r");gotoyx(1,27);goto background_string_color;
    case '0':
        get_settings_main_menu_arguments(arguments);
        start_program_new_window("main_menu_layout",arguments);
        goto shift_left;
    }
    gotoyx(-1,0);
shift_down:
    shift_down_main_menu=select_number(shift_down_main_menu,&arrow,2,0,20,5,menu_confirm,menu_go_back,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:printf("\r");gotoyx(1,14);goto shift_left;
    case '0':
        get_settings_main_menu_arguments(arguments);
        start_program_new_window("main_menu_layout",arguments);
        goto shift_down;
    }
saving:
    clear_screen();
    save_main_menu_parameters_to_file("main-menu-parameters.txt");
    delay(250);
    return;
recover:
    shift_left_main_menu=tmp_shift_left_main_menu;
    shift_down_main_menu=tmp_shift_down_main_menu;
    main_menu_borders_color=tmp_main_menu_borders_color;
    main_menu_string_color=tmp_main_menu_string_color;
}
void parameters_menu_settings(){
    extern short shift_left_parameters_menu,shift_down_parameters_menu;
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    extern short menu_up,menu_down,menu_confirm,menu_go_back;
    short tmp_shift_left_parameters_menu=shift_left_parameters_menu;
    short tmp_shift_down_parameters_menu=shift_down_parameters_menu;
    rgb_color tmp_parameters_menu_borders_color=parameters_menu_borders_color;
    rgb_color tmp_parameters_menu_string_color=parameters_menu_string_color;
    char arguments[300]="";
    printf("\033[?25l");
    puts("          Parameters menu settings:\n");
    printf("   Foreground border color:");
    print_num_with_0_begin(parameters_menu_borders_color.fg,3);printf(" ");
    set_color(parameters_menu_borders_color,1);printf("C\n");printf(reset_style);
    printf("   Foreground string color:");
    print_num_with_0_begin(parameters_menu_string_color.fg,3);printf(" ");
    set_color(main_menu_string_color,1);printf("C\n");printf(reset_style);
    printf("   Background String color:");
    print_num_with_0_begin(parameters_menu_string_color.bg,3);printf(" ");
    set_color(parameters_menu_string_color,3);printf("C\n");printf(reset_style);
    printf("   Shift left:%d\n",shift_left_parameters_menu);
    printf("   Shift down:%d\n\n",shift_down_parameters_menu);
    char arrow;
    gotoyx(6,27);
    printf("\033[?25h");
foreground_border_color:
    select_color(parameters_menu_borders_color,'C',&arrow,1,4,menu_confirm,menu_go_back,77,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case '\0':
        get_settings_parameters_menu_arguments(arguments);
        start_program_new_window("parameters_menu_layout",arguments);
        goto foreground_border_color;
    }
    printf("\r");gotoyx(-1,27);
foreground_string_color:
    parameters_menu_string_color=select_color(parameters_menu_string_color,'C',&arrow,1,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,0);goto foreground_border_color;
    case '\0':
        get_settings_parameters_menu_arguments(arguments);
        start_program_new_window("parameters_menu_layout",arguments);
        goto foreground_string_color;
    }
    gotoyx(-1,0);
background_string_color:
    parameters_menu_string_color=select_color(parameters_menu_string_color,'C',&arrow,2,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,0);goto foreground_string_color;
    case '0':
        get_settings_parameters_menu_arguments(arguments);
        start_program_new_window("parameters_menu_layout",arguments);
        goto background_string_color;
    }
    printf("\r");gotoyx(-1,14);
shift_left:
    shift_left_parameters_menu=select_number(shift_left_parameters_menu,&arrow,2,0,20,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:printf("\r");gotoyx(1,27);goto background_string_color;
    case '0':
        get_settings_parameters_menu_arguments(arguments);
        start_program_new_window("parameters_menu_layout",arguments);
        goto shift_left;
    }
    gotoyx(-1,0);
shift_down:
    shift_down_parameters_menu=select_number(shift_down_parameters_menu,&arrow,2,0,10,4,menu_confirm,menu_go_back,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,0);goto shift_left;
    case '0':
        get_settings_parameters_menu_arguments(arguments);
        start_program_new_window("parameters_menu_layout",arguments);
        goto shift_down;
    }
    goto saving;
saving:
    clear_screen();
    save_parameters_menu_parameters_to_file("parameters-menu.txt");
    delay(250);
    return;
recover:
    shift_left_parameters_menu=tmp_shift_left_parameters_menu;
    shift_down_parameters_menu=tmp_shift_down_parameters_menu;
    parameters_menu_borders_color=tmp_parameters_menu_borders_color;
    parameters_menu_string_color=tmp_parameters_menu_string_color;
}
short select_menu(){
    printf("\033[?25l");
    puts("            Select a menu:\n");
    puts("                                     ");
    puts("      Main menu      Parameters menu ");
    puts("                                     ");
    char arrow;
    short choose=1;
    gotoyx(1,6);
    do{
        if(choose==1) character('-',9);else character(' ',9);
        gotoyx(0,6);
        if(choose==0) character('-',15); else character(' ',15);
        gotoyx(1,0);
        if(choose==0) putchar('|'); else putchar(' ');
        printf("\r");gotoyx(0,5);
        if(choose==1) putchar('|'); else putchar(' ');
        gotoyx(0,9);
        if(choose==1) putchar('|'); else putchar(' ');
        gotoyx(0,4);
        if(choose==0) putchar('|'); else putchar(' ');
        printf("\r");gotoyx(1,6);
        if(choose==1) character('-',9); else character(' ',9);
        gotoyx(0,6);
        if(choose==0) character('-',15); else character(' ',15);
        printf("\r");gotoyx(-2,6);
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
        if((int)arrow==75&&choose==0) choose=1;
        else if((int)arrow==77&&choose==1) choose=0;
    }while(arrow!='\r'&&arrow!='\b');
    if(arrow=='\b') return 2;
    else return choose;
}
void menu_settings(){
select_menu:
    short menu=select_menu();
    clear_screen();
    switch(menu){
    case 1:
        main_menu_settings();
        break;
    case 0:
        parameters_menu_settings();
        break;
    case 2:goto select_menu;
    }
}
void game_settings(){
    extern short dim,shift_left,shift_down;
    extern short border_x,border_y;
    extern rgb_color border_color,area_color;
    extern short menu_up,menu_down,menu_confirm,menu_go_back;
    short tmp_dim=dim;
    short tmp_shift_left=shift_left,tmp_shift_down=shift_down;
    rgb_color tmp_border_color=border_color,tmp_area_color=area_color;
    short tmp_border_x=border_x,tmp_border_y=border_y;
    char arguments[300];
    printf("           GAME SETTINGS:\n");
    printf("   Game dimension:");
    print_num_with_0_begin(dim,2);putchar('\n');
    printf("   Borders fg color(RGB):");
    print_num_with_0_begin(border_color.fg,3);gotoyx(0,1);
    set_color(border_color,1);printf("C\n");printf(reset_style);
    printf("   Area color:");
    print_num_with_0_begin(area_color.bg,3);putchar(' ');
    set_color(area_color,1);printf("C\n");printf(reset_style);
    printf("   Vertical Border character:");printf("%c\n",border_x);
    printf("   Horisontal Border character:");printf("%c\n",border_y);
    printf("   Shift table left (pixels):");printf("%d\n",shift_left);
    printf("   Shift table down :");printf("%d\n\n",shift_down);
    gotoyx(8,18);
    char arrow;
    printf("\033[?25h");
game_dim:
    dim=select_number(dim,&arrow,2,3,11,4,menu_confirm,menu_go_back,77,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case '0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto game_dim;
    }
    gotoyx(-1,7);
border_fg_color:
    border_color=select_color(border_color,'C',&arrow,1,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,-7);goto game_dim;
    case '0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto border_fg_color;
    }
    printf("\r");
    gotoyx(-1,14);
area_color:
    area_color=select_color(area_color,'C',&arrow,2,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:printf("\r");gotoyx(1,25);goto border_fg_color;
    case '0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto area_color;
    }
    printf("\r");gotoyx(-1,29);
vertical_border_character:
    border_x=select_character(border_x,&arrow,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:printf("\r");gotoyx(1,14);goto area_color;
    case '0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto vertical_border_character;
    }
    gotoyx(-1,2);
horisontal_border_charcter:
    border_y=select_character(border_y,&arrow,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,-2);goto vertical_border_character;
    case '0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto horisontal_border_charcter;
    }
    gotoyx(-1,-2);
shift_left:
    shift_left=select_number(shift_left,&arrow,2,0,20,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75:gotoyx(1,2);goto horisontal_border_charcter;
    case '0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto shift_left;
    }
    gotoyx(-1,-8);
shift_down:
    shift_down=select_number(shift_down,&arrow,2,0,20,5,menu_confirm,menu_go_back,77,75,'0');
    if(menu_confirm==arrow) goto saving;
    else if(menu_go_back==arrow) goto recover;
    switch(arrow){
    case 75: gotoyx(1,8);goto shift_left;
    case '\0':
        get_settings_table_arguments(arguments);
        start_program_new_window("write_table_layout",arguments);
        goto shift_down;
    }
saving :
    clear_screen();
    save_table_parameters_to_file("table.txt");
    puts("  Status saved!");
    delay(250);
    return;
recover:
    shift_left=tmp_shift_left;
    shift_down=tmp_shift_down;
    border_x=tmp_border_x;
    border_y=tmp_border_y;
    border_color=tmp_border_color;
    area_color=tmp_area_color;
}
#include "settings2.h"
#endif // SETTINGS_H_INCLUDED
