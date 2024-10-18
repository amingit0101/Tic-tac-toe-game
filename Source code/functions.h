#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
void get_settings_table_arguments(char *buffer){
    extern short dim,shift_left,shift_down;
    extern short border_x,border_y;
    extern rgb_color border_color,area_color;
    char tmp_string[100]="";
    for(int i=0;i<5;i++){
        switch(i){
        case 0:itoa(dim,tmp_string,10);break;
        case 1:itoa(shift_left,tmp_string,10);break;
        case 2:itoa(shift_down,tmp_string,10);break;
        case 3:itoa(border_x,tmp_string,10);break;
        case 4:itoa(border_y,tmp_string,10);break;
        case 5:itoa(border_color.fg,tmp_string,10);break;
        case 6:itoa(area_color.bg,tmp_string,10);break;
        }
        strcat(buffer,tmp_string);
        strcat(buffer," ");
    }
}
void get_settings_main_menu_arguments(char *buffer){
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    char tmp_string[100]="";
    for(int i=0;i<5;i++){
        switch(i){
        case 0:itoa(shift_left_main_menu,tmp_string,10);break;
        case 1:itoa(shift_down_main_menu,tmp_string,10);break;
        case 2:itoa(main_menu_borders_color.fg,tmp_string,10);break;
        case 3:itoa(main_menu_string_color.fg,tmp_string,10);break;
        case 4:itoa(main_menu_string_color.bg,tmp_string,10);break;
        }
        strcat(buffer,tmp_string);
        strcat(buffer," ");
    }
}
void get_settings_parameters_menu_arguments(char *buffer){
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    extern short shift_left_parameters_menu,shift_down_parameters_menu;
    char tmp_string[100];
    for(int i=0;i<5;i++){
        switch(i){
        case 0:itoa(shift_left_parameters_menu,tmp_string,10);break;
        case 1:itoa(shift_down_parameters_menu,tmp_string,10);break;
        case 2:itoa(parameters_menu_borders_color.fg,tmp_string,10);break;
        case 3:itoa(parameters_menu_string_color.fg,tmp_string,10);break;
        case 4:itoa(parameters_menu_string_color.bg,tmp_string,10);break;
        strcat(buffer,tmp_string);
        strcat(buffer," ");
        }
    }
}
void get_game_buttons_parameters_arguments(char *buffer){
    extern short up,down,left,right,exit_game,confirm;
    char tmp_string[100]="";
    for(int i=0;i<10;i++){
        switch(i){
        case 0:itoa(up,tmp_string,10);break;
        case 1:itoa(down,tmp_string,10);break;
        case 2:itoa(left,tmp_string,10);break;
        case 3:itoa(right,tmp_string,10);break;
        case 4:itoa(exit_game,tmp_string,10);break;
        case 5:itoa(confirm,tmp_string,10);break;
        case 6:itoa(up_left,tmp_string,10);break;
        case 7:itoa(up_right,tmp_string,10);break;
        case 8:itoa(down_left,tmp_string,10);break;
        case 9:itoa(down_right,tmp_string,10);break;
        }
        strcat(buffer,tmp_string);
        strcat(buffer," ");
    }
}
void get_menu_buttons_parameters_arguments(char *buffer){
    extern short menu_up,menu_down,menu_go_back,menu_confirm;
    char tmp_string[100]="";
    for(int i=0;i<6;i++){
        switch(i){
        case 0:itoa(menu_up,tmp_string,10);break;
        case 1:itoa(menu_down,tmp_string,10);break;
        case 2:itoa(menu_go_back,tmp_string,10);break;
        case 3:itoa(menu_confirm,tmp_string,10);break;
        case 4:itoa(menu_next,tmp_string,10);break;
        case 5:itoa(menu_prev,tmp_string,10);break;
        strcat(buffer,tmp_string);
        strcat(buffer," ");
        }
    }
}
void get_table_settings_from_arguments(char *argv[]){
    extern short dim,shift_left,shift_down;
    extern short border_x,border_y;
    extern rgb_color border_color,area_color;
    dim=atoi(argv[1]);
    shift_left=atoi(argv[2]);
    shift_down=atoi(argv[3]);
    border_x=atoi(argv[4]);
    border_y=atoi(argv[5]);
    border_color.fg = atoi(argv[6]);
    area_color.bg=atoi(argv[7]);
}
void get_main_menu_parameters_from_arguments(char *argv[]){
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    shift_left_main_menu=atoi(argv[1]);
    shift_down_main_menu=atoi(argv[2]);
    main_menu_borders_color.fg=atoi(argv[3]);
    main_menu_string_color.fg=atoi(argv[4]);
    main_menu_string_color.bg=atoi(argv[5]);
}
void get_parameters_menu_parameters_from_arguments(char *argv[]){
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    extern short shift_left_parameters_menu,shift_down_parameters_menu;
    shift_left_parameters_menu=atoi(argv[1]);
    shift_down_parameters_menu=atoi(argv[2]);
    parameters_menu_borders_color.fg=atoi(argv[3]);
    parameters_menu_string_color.fg=atoi(argv[4]);
    parameters_menu_string_color.bg=atoi(argv[5]);

}
void get_game_buttons_setting_from_arguments(char *argv[]){
    extern short up,down,left,right,exit_game,confirm;
    extern short up_left,up_right,down_left,down_right;
    up=atoi(argv[1]);
    down=atoi(argv[2]);
    left=atoi(argv[3]);
    right=atoi(argv[4]);
    exit_game=atoi(argv[5]);
    confirm=atoi(argv[6]);
    up_left=atoi(argv[7]);
    up_right=atoi(argv[8]);
    down_left=atoi(argv[9]);
    down_right=atoi(argv[10]);
}
void get_menu_buttons_setting_from_arguments(char *argv[]){
    extern short menu_up,menu_down,menu_go_back,menu_confirm,menu_next,menu_prev;
    menu_up=atoi(argv[1]);
    menu_down=atoi(argv[2]);
    menu_go_back=atoi(argv[3]);
    menu_confirm=atoi(argv[4]);
    menu_next=atoi(argv[5]);
    menu_prev=atoi(argv[6]);
}

#ifdef _WIN32
    void start_program_new_window(char *name,char *arguments){
        char commend[300];
        snprintf(commend,300,"start cmd /k \"%s.exe %s\"",name,arguments);
        system(commend);
    }
#elif defined __MACH__
    void start_program_new_window(char *name,char *arguments){
        char commend[300];
        snprintf(commend,300," osascript -e\"%s %s\"",name,arguments);
        system(commend);
    }
#else
    void start_commend_new_window_xfce(char *buffer,char *program,char *arguments){
    //get the commend that execute the program in xfce terminal
        snprintf(buffer,300,"xfce4-terminal -e \"./%s %s\"",program,arguments);
        puts(buffer);
    }
    void start_commend_new_window_kde(char *buffer,char *program,char *arguments){
    //get the commend that execute the program in konsol (kde terminal)
        snprintf(buffer,300,"konsole -e \"./%s %s\"",program,arguments);
    }
    void start_commend_new_window_xterm(char *buffer,char *program,char *arguments){
    //get the commend that execute the program in xterm terminal
        snprintf(buffer,300,"xterm -e \"./%s %s\"",program,arguments);
    }
    bool executed(char commend[]){//try to execute a commed ,if executed return true else returns false
        char get_error[3]="";
        strcat(commend," 2> tmp ");
        system(commend);
        FILE *f=fopen("tmp","r");
        fgets(get_error,2,f);
        fclose(f);
        remove("tmp");
        if(*get_error=='\0') return false;
        else return true;
    }
    void start_program_new_window(char *name,char *arguments){
        char commend[300]="";
        start_commend_new_window_xfce(commend,name,arguments);
        if(executed(commend)) return;
        start_commend_new_window_kde(commend,name,arguments);
        if(executed(commend)) return;
        start_commend_new_window_xterm(commend,name,arguments);
        system(commend);
    }
#endif
void swap_int(short *a,short *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void remove_BOM(char *str){
    char BOM[]={-17,-69,-65};
    if(strncmp(str,BOM,3)==0)
     memmove(str,str+3,strlen(str));
}
void save_table_parameters_to_file(char *f_name){
    FILE *f=fopen(f_name,"w");
    extern short dim,shift_left,shift_down;
    extern short border_x,border_y;
    extern rgb_color border_color,area_color;
    fprintf(f,"%d\n",dim);
    fprintf(f,"%d\n",shift_left);
    fprintf(f,"%d\n",shift_down);
    fprintf(f,"%c\n",border_x);
    fprintf(f,"%c\n",border_y);
    fprintf(f,"%d\n",border_color.fg);
    fprintf(f,"%d",border_color.bg);
    fclose(f);
}
void save_main_menu_parameters_to_file(char *f_name){
    FILE *f=fopen(f_name,"w");
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    fprintf(f,"%d\n",shift_left_main_menu);
    fprintf(f,"%d\n",shift_down_main_menu);
    fprintf(f,"%d\n",main_menu_borders_color.fg);
    fprintf(f,"%d\n",main_menu_string_color.fg);
    fprintf(f,"%d",main_menu_string_color.bg);
    fclose(f);
}
void save_parameters_menu_parameters_to_file(char *f_name){
    FILE *f=fopen(f_name,"w");
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    extern short shift_left_parameters_menu,shift_down_parameters_menu;
    fprintf(f,"%d\n",shift_left_parameters_menu);
    fprintf(f,"%d\n",shift_down_parameters_menu);
    fprintf(f,"%d\n",parameters_menu_borders_color.fg);
    fprintf(f,"%d\n",parameters_menu_string_color.fg);
    fprintf(f,"%d",parameters_menu_string_color.bg);
    fclose(f);
}
void save_game_bottons_to_file(char *f_name){
    FILE *f=fopen(f_name,"w");
    extern short up,down,left,right,exit_game,confirm;
    extern short up_left,up_right;
    extern short down_left,down_right;
    fprintf(f,"%d\n",up);
    fprintf(f,"%d\n",down);
    fprintf(f,"%d\n",left);
    fprintf(f,"%d\n",right);
    fprintf(f,"%d\n",confirm);
    fprintf(f,"%d\n",exit_game);
    fprintf(f,"%d\n",up_left);
    fprintf(f,"%d\n",up_right);
    fprintf(f,"%d\n",down_left);
    fprintf(f,"%d",down_right);
    fclose(f);
}
void save_menu_bottons_to_file(char *f_name){
    FILE *f=fopen(f_name,"w");
    extern short menu_up,menu_down,menu_go_back,menu_confirm;
    fprintf(f,"%d\n",menu_up);
    fprintf(f,"%d\n",menu_down);
    fprintf(f,"%d\n",menu_confirm);
    fprintf(f,"%d\n",menu_go_back);
    fprintf(f,"%d\n",menu_next);
    fprintf(f,"%d",menu_prev);
    fclose(f);
}
void get_last_table_parameters_from_file(char *f_name){
    FILE *f=fopen(f_name,"r");
    if(f==NULL){
        save_table_parameters_to_file(f_name);
        return;
    }
    extern short dim,shift_left,shift_down;
    extern short border_x,border_y;
    extern rgb_color border_color,area_color;
    char tmp[7][10];
    for(int i=0;i<7;i++){
        fscanf(f,"%s",tmp[i]);
    }
    remove_BOM(tmp[0]);
    dim=atoi(tmp[0]);
    shift_left=atoi(tmp[1]);
    shift_down=atoi(tmp[2]);
    border_x=tmp[3][0];
    border_y=tmp[4][0];
    border_color.fg=atoi(tmp[5]);
    border_color.bg=atoi(tmp[6]);
    fclose(f);
}
void get_last_main_menu_parameters_from_file(char *f_name){
    FILE *f=fopen(f_name,"r");
    if(f==NULL){
        save_main_menu_parameters_to_file(f_name);
        return;
    }
    extern rgb_color main_menu_borders_color,main_menu_string_color;
    extern short shift_left_main_menu,shift_down_main_menu;
    char tmp[5];
    fscanf(f,"%s\n",tmp);
    remove_BOM(tmp);
    shift_left_main_menu=atoi(tmp);
    fscanf(f,"%d\n",&shift_down_main_menu);
    fscanf(f,"%d\n",&main_menu_borders_color.fg);
    fscanf(f,"%d\n",&main_menu_string_color.fg);
    fscanf(f,"%d",&main_menu_string_color.bg);
    fclose(f);
}
void get_last_parameters_menu_parameters_from_file(char *f_name){
    FILE *f=fopen(f_name,"r");
    if(f==NULL){
        save_parameters_menu_parameters_to_file(f_name);
        return;
    }
    extern rgb_color parameters_menu_borders_color,parameters_menu_string_color;
    extern short shift_left_parameters_menu,shift_down_parameters_menu;
     char tmp[5];
    fscanf(f,"%s\n",tmp);
    remove_BOM(tmp);
    shift_left_parameters_menu=atoi(tmp);
    fscanf(f,"%d\n",&shift_down_parameters_menu);
    fscanf(f,"%d\n",&parameters_menu_borders_color.fg);
    fscanf(f,"%d\n",&parameters_menu_string_color.fg);
    fscanf(f,"%d",&parameters_menu_string_color.bg);
    fclose(f);
}
void get_last_game_bottons_from_file(char *f_name){
    FILE *f=fopen(f_name,"r");
    if(f==NULL){
        save_game_bottons_to_file(f_name);
        return;
    }
    extern short up,down,left,right,exit_game,confirm;
    extern short up_left,up_right;
    extern short down_left,down_right;
    char first_line[10];
    char tmp[10];
    fscanf(f,"%s\n",first_line);
    remove_BOM(first_line);
    up=atoi(first_line);
    fscanf(f,"%d\n",&down);
    fscanf(f,"%d\n",&left);
    fscanf(f,"%d\n",&right);
    fscanf(f,"%d\n",&confirm);
    if(confirm==0) confirm='\r';
    fscanf(f,"%d\n",&exit_game);
    if(exit_game==0) exit_game='\r';
    fscanf(f,"%d\n",&up_left);
    fscanf(f,"%d\n",&up_right);
    fscanf(f,"%d\n",&down_left);
    fscanf(f,"%d",&down_right);
    fclose(f);
}
void get_last_menu_bottons_from_file(char *f_name){
    extern short menu_up, menu_down,menu_go_back,menu_confirm;
    FILE *f=fopen(f_name,"r");
    if(f==NULL){
        save_menu_bottons_to_file(f_name);
        return;
    }
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
#endif // FUNCTIONS_H_INCLUDED
