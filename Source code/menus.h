#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
short main_menu(){
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    extern short menu_up,menu_down,menu_confirm,menu_go_back;
    if(menu_up==0||menu_down==0||menu_next==0||menu_prev==0){
        FILE *f=fopen("menu-buttons.txt","r");
        char tmp[6][10];
        for(int i=0;i<6;i++){
            fscanf(f,"%s\n",tmp[i]);
        }
        remove_BOM(tmp[0]);
        menu_up=atoi(tmp[0]);
        menu_down=atoi(tmp[1]);
        menu_confirm=atoi(tmp[2]);
        menu_go_back=atoi(tmp[3]);
        menu_next=atoi(tmp[4]);
        menu_prev=atoi(tmp[5]);
        fclose(f);
    }
    gotoyx(-shift_down_main_menu,0);
    printf("\e[?25l");
    space(shift_left_main_menu);set_color(main_menu_borders_color,1);puts("         ------------");
    space(shift_left_main_menu);set_color(main_menu_string_color,1);puts("        |  MAIN MENU |");
    space(shift_left_main_menu);set_color(main_menu_borders_color,1);puts("         -----------");
    printf("\n");
    space(shift_left_main_menu);printf(" ");puts("           ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,3);printf("Two players\n");printf("%s",reset_style);
    space(shift_left_main_menu);printf(" ");puts("           ");
    space(shift_left_main_menu);printf(" ");puts("             ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,3);printf("Against a bot\n");printf("%s",reset_style);
    space(shift_left_main_menu);printf(" ");puts("             ");
    space(shift_left_main_menu);printf(" ");puts("          ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,3);printf("Parameters\n");printf("%s",reset_style);
    space(shift_left_main_menu);printf(" ");puts("          ");
    space(shift_left_main_menu);printf(" ");puts("    ");
    space(shift_left_main_menu);printf(" ");set_color(main_menu_string_color,3);printf("Exit\n");printf("%s",reset_style);
    space(shift_left_main_menu);printf(" ");puts("    ");
    printf("\n");
    char arrow;
    short choose=1;
    gotoyx(2,0);
    do{
        printf("\r");gotoyx(0,shift_left_main_menu+1);
        if(choose==4) set_color(main_menu_borders_color,1),printf("----");else printf("    ");
        gotoyx(1,0);if(choose==4) /*set_color(main_menu_borders_color,1),*/printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_main_menu);
        if(choose==4) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);if(choose==4) set_color(main_menu_borders_color,1),printf("----");else printf("    ");
        printf("\r");gotoyx(1,shift_left_main_menu+1);
        if(choose==3) set_color(main_menu_borders_color,1),printf("----------");else printf("          ");
        gotoyx(1,0);if(choose==3) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_main_menu);
        if(choose==3) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);if(choose==3) set_color(main_menu_borders_color,1),printf("----------");else printf("          ");
        printf("\r");gotoyx(1,shift_left_main_menu+1);
        if(choose==2) set_color(main_menu_borders_color,1),printf("-------------");else printf("             ");
        gotoyx(1,0);if(choose==2) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_main_menu);
        if(choose==2) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);
        if(choose==2) set_color(main_menu_borders_color,1),printf("-------------");else printf("             ");
        printf("\r");gotoyx(1,shift_left_main_menu+1);
        if(choose==1) set_color(main_menu_borders_color,1),printf("----------");else printf("          ");
        gotoyx(1,0);
        if(choose==1) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_main_menu);
        if(choose==1) set_color(main_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);
        if(choose==1) set_color(main_menu_borders_color,1),printf("----------");else printf("          ");
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
        if(arrow==menu_down) choose++;
        else if(arrow==menu_up) choose--;
        if(choose<1) choose=4;
        if(choose>4) choose=1;
        gotoyx(-11,0);
    }while(arrow!=menu_confirm);
    printf("%s",reset_style);
    return choose;
}
short parameters_menu(){
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    extern short shift_left_parameters_menu,shift_down_parameters_menu;
    extern short menu_up,menu_down,menu_confirm,menu_go_back;
    printf("\e[?25l");
    space(shift_left_parameters_menu+7);set_color(invert_color(parameters_menu_string_color),3);puts("Parameters:");printf("%s",reset_style);
    printf("\n");
    space(shift_left_parameters_menu);printf(" ");puts("        ");
    space(shift_left_parameters_menu);printf(" ");set_color(parameters_menu_string_color,3);printf("In game\n");printf("%s",reset_style);
    space(shift_left_parameters_menu);printf(" ");puts("        ");
    space(shift_left_parameters_menu);printf(" ");puts("     ");
    space(shift_left_parameters_menu);printf(" ");set_color(parameters_menu_string_color,3);printf("Menus\n");printf("%s",reset_style);
    space(shift_left_parameters_menu);printf(" ");puts("     ");
    space(shift_left_parameters_menu);printf(" ");puts("    ");
    space(shift_left_parameters_menu);printf(" ");set_color(parameters_menu_string_color,3);printf("Bottons\n");printf(reset_style);
    space(shift_left_parameters_menu);printf(" ");puts("    ");
    printf("\n");
    printf(" ",parameters_menu_string_color,"Arrows:Up-Down   Enter:Select");
    char arrow;
    short choose=1;
    gotoyx(2,0);
    do{
        printf("\r");gotoyx(0,shift_left_parameters_menu+1);
        if(choose==3) set_color(parameters_menu_borders_color,1),printf("-------");else printf("       ");
        gotoyx(1,0);
        if(choose==3) set_color(parameters_menu_borders_color,1),printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_parameters_menu);
        if(choose==3) set_color(parameters_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);
        if(choose==3) set_color(parameters_menu_borders_color,1),printf("-------");else printf("       ");
        printf("\r");gotoyx(1,shift_left_parameters_menu+1);
        if(choose==2) set_color(parameters_menu_borders_color,1),printf("-----");else printf("     ");
        gotoyx(1,0);
        if(choose==2) set_color(parameters_menu_borders_color,1),printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_parameters_menu);
         if(choose==2) set_color(parameters_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);
        if(choose==2) set_color(parameters_menu_borders_color,1),printf("-----");else printf("     ");
        printf("\r");gotoyx(1,shift_left_parameters_menu+1);
        if(choose==1) set_color(parameters_menu_borders_color,1),printf("-------");else printf("       ");
        gotoyx(1,0);
        if(choose==1) set_color(parameters_menu_borders_color,1),printf("|"); else printf(" ");
        printf("\r");gotoyx(0,shift_left_parameters_menu);
        if(choose==1) set_color(parameters_menu_borders_color,1),printf("|"); else printf(" ");
        gotoyx(1,0);
        if(choose==1) set_color(parameters_menu_borders_color,1),printf("-------");else printf("       ");
        arrow=getch();
        if(arrow==-32) arrow=getch();
        if(arrow==menu_down) choose++;
        else if(arrow==menu_up) choose--;
        if(choose<1) choose=3;
        if(choose>3) choose=1;
        gotoyx(-8,0);
    }while(arrow!=menu_confirm&&arrow!=menu_go_back);
    printf(reset_style);
    if(arrow==menu_go_back) return 4;
    else return choose;
}
#endif // MENUS_H_INCLUDED
