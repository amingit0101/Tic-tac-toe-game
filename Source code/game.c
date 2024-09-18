#include "environement.h"
void main(){
    extern short dim,shift_left,shift_down;
    extern short up,down,left,right,exit_game,confirm;
    extern rgb_color area_color;
    get_last_game_bottons_from_file("game-bottons.txt");
    get_last_menu_bottons_from_file("menu-buttons.txt");
    get_last_table_parameters_from_file("table.txt");
    if(confirm==0) confirm='\r';
    coord table[dim][dim];
    position position,prev_position;
    player players[2];
    short part=1;
    clear_screen();
    select_players_chars(players,0);
    clear_screen();
    players[0].winns=0;
    players[1].winns=0;
    players[1].c_color.bg=50;
    players[0].c_color.bg=50;
play_again:
    clear_screen();
    short shift_left_infs;
    if(shift_left-3>0) shift_left_infs=shift_left-3;
    else shift_left_infs=shift_left;
    gotoyx(0,shift_left_infs+2*(dim));
    printf("Part %d:\n\n",part);
    gotoyx(0,shift_left_infs);
    set_color(invert_color(players[1].c_color),3);printf("Player1");printf(reset_style);
    gotoyx(0,4*(dim-1));
    set_color(invert_color(players[0].c_color),3);printf("Player2\n");printf(reset_style);
    gotoyx(0,shift_left_infs+1);
    set_color(players[0].c_color,1);printf("----");
    gotoyx(0,4*(dim-1)+3);
    set_color(players[1].c_color,1);printf("----\n");
    gotoyx(0,shift_left_infs);
    set_color(invert_color(players[0].c_color),1);printf("|");
    set_color(area_color,3);print_num_with_0_begin(players[0].winns,4);printf(reset_style);
    set_color(invert_color(players[1].c_color),1);printf("|");
    gotoyx(0,4*(dim-1)+1);
    set_color(invert_color(players[1].c_color),1);printf("|");
    set_color(invert_color(area_color),3);print_num_with_0_begin(players[1].winns,4);printf(reset_style);
    set_color(invert_color(players[0].c_color),1);printf("|\n");
    gotoyx(0,shift_left_infs+1);
    set_color(players[1].c_color,1);printf("----");
    gotoyx(0,4*(dim-1)+3);
    set_color(players[0].c_color,1);printf("----\n");
    game_initialization(table,&position);
    write_tictactoe_table();
    printf("\r");
    gotoyx(dim*2,shift_left+1);
    char arrow;
    bool player=false;
    position.x=0;position.y=0;
    do{
        prev_position=position;
        position=next_player_position(table);
        if(position.x==-1){
            printf("\r");gotoyx((prev_position.y-dim*2)-2,shift_left);
            printf("Drawn part\n",(int)player+1);
            delay(500);
            part++;
            clear_screen();
            goto play_again;
        }
        gotoyx((prev_position.y-position.y)*2,(position.x-prev_position.x)*4);
        do{
            arrow=getch();
            if((int)arrow==-32) arrow=getch();
            if(arrow==exit_game){
                clear_screen();
                return;
            }
            prev_position=position;
            position=next_position(position,table,arrow);
            gotoyx((prev_position.y-position.y)*2,(position.x-prev_position.x)*4);
        }while(arrow!=confirm);
        table[position.x][position.y].used=true;
        table[position.x][position.y].player=players[(int)player];
        set_color(players[(int)player].c_color,3);printf("%c\b",players[(int)player].c);
        printf(reset_style);
        if(winned(table,players[0])||winned(table,players[1])){
            printf("\r");gotoyx((position.y-dim)*2-2,shift_left);
            printf("Player %d winned\n",(int)player+1);
            delay(500);
            players[(int)player].winns++;
            clear_screen();
            part++;
            goto play_again;
        }
        player=!player;
    }while(true);
}
