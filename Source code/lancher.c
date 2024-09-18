#include "environement.h"
void main(){
    extern char menu_up,menu_down,menu_confirm,menu_down;
    printf("\e[?25l");
    puts("");
    first_frame();
    delay(300);
    clear_screen();
    puts("");
    second_frame();
    delay(300);
    clear_screen();
    third_frame();
    delay(300);
    clear_screen();
    gotoyx(-3,10);
    puts("Created by Amine HB");
    delay(750);
    get_last_main_menu_parameters_from_file("main-menu-parameters.txt");
    get_last_parameters_menu_parameters_from_file("parameters-menu.txt");
    get_last_menu_bottons_from_file("menu-buttons.txt");
    get_last_table_parameters_from_file("table.txt");
    get_last_game_bottons_from_file("game-buttons.txt");
    printf("%d %d %d \n",menu_up,menu_down,menu_confirm);
    short choose;
    bool exit=false;
main_menu:
    clear_screen();
    choose=main_menu();
    clear_screen();
    printf(reset_screen);
    switch(choose){
    case 1:
        start_program_new_window("game","");
        goto main_menu;
    case 2:
        break;
    case 3:
parameters_menu:
        clear_screen();
        choose=parameters_menu();
        clear_screen();
        switch(choose){
        case 1:
            game_settings();
            goto parameters_menu;
        case 2:
            menu_settings();
            goto parameters_menu;
        case 3:
            buttons_settings();
            goto parameters_menu;
        case 4: goto main_menu;
        }
    break;
    }
}
