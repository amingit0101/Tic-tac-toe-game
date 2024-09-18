#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
void game_initialization(coord table[dim][dim],position *position){
    for(int i=0;i<dim;i++) for(int j=0;j<dim;j++) table[i][j].used =false;
    position->x=1;
    position->y=1;
}
void select_players_chars(player players[2],short player_num){
    char arrow;
    extern char menu_confirm;
    if(player_num==2) return;
    if(player_num==0) players[0].c='X';
    else players[1].c='O';
    players[player_num].c_color.fg=1;
    printf("   Enter player %d character:%c\n",player_num+1,players[player_num].c);
    printf("   Color:");
    print_num_with_0_begin(players[player_num].c_color.fg,3);putchar(' ');
    set_color(players[player_num].c_color,1);printf("%c\n",players[player_num].c);
    printf(reset_style);
    printf("   Background color:");
    print_num_with_0_begin(players[player_num].c_color.bg,3);putchar(' ');
    set_color(players[player_num].c_color,3);printf("%c\n",players[player_num].c);
    printf(reset_style);
    printf("\r");gotoyx(3,28);
player1char:
    do{
        arrow=getch();
        if((int)arrow==-32) arrow=getch();
    }while(arrow!=menu_confirm&&(int)arrow!=77);
    if(arrow==menu_confirm)  players[player_num].c=select_no_control_button(players[player_num].c);
    printf("\r");
    gotoyx(-1,9);
player_color_fg:
    players[player_num].c_color=select_color(players[player_num].c_color,players[player_num].c,&arrow,1,3,75,menu_confirm,77);
    if (arrow==menu_confirm) goto end_customization;
    switch(arrow){
    case 75:printf("\r");gotoyx(1,28);goto player1char;
    }
    gotoyx(-1,11);
player_color_bg:
    players[player_num].c_color=select_color(players[player_num].c_color,players[player_num].c,&arrow,3,2,menu_confirm,75);
    switch(arrow){
    case 75:printf("\r");gotoyx(1,9);goto player_color_fg;
    }
end_customization:
    clear_screen();
    select_players_chars(players,player_num+1);
}
position next_left_position(position current_position,coord table[dim][dim]){
    extern short dim;
    do{
        current_position.x++;
        if(current_position.x==dim) current_position.x=0;
    }while(table[current_position.x][current_position.y].used);
    return current_position;
}
position next_right_position(position current_position,coord table[dim][dim]){
    extern short dim;
    do{
        current_position.x--;
        if(current_position.x<0) current_position.x=dim-1;
    }while(table[current_position.x][current_position.y].used);
    return current_position;
}
position next_up_position(position current_position,coord table[dim][dim]){
    extern short dim;
    do{
        current_position.y--;
        if(current_position.y<0) current_position.y=dim-1;
    }while(table[current_position.x][current_position.y].used);
    return current_position;
}
position next_down_position(position current_position,coord table[dim][dim]){
    extern short dim;
    do{
        current_position.y++;
        if(current_position.y==dim) current_position.y=0;
    }while(table[current_position.x][current_position.y].used);
    return current_position;
}
position next_up_left_position(position current_position,coord table[dim][dim]){
    position pos=current_position;
    short m=current_position.y;
    extern short dim;
    current_position.x++;
    do{
        current_position.y=m;
        while(current_position.y>0&&table[current_position.x][current_position.y-1].used) current_position.y--;
        if(current_position.y>0&&!table[current_position.x][current_position.y-1].used) current_position.y--;
        current_position.x++;
    }while(current_position.x<=dim&&table[current_position.x-1][current_position.y].used);
    if(current_position.x==dim+1) return pos;
    else{
        current_position.x--;return current_position;
    }
}
position next_up_right_position(position current_position,coord table[dim][dim]){
    position pos=current_position;
    short m=current_position.y;
    extern short dim;
    current_position.x--;
    do{
        current_position.y=m;
        while(current_position.y>0&&table[current_position.x][current_position.y-1].used) current_position.y--;
        if(current_position.y>0&&!table[current_position.x][current_position.y-1].used) current_position.y--;
        current_position.x--;
    }while(current_position.x>=-1&&table[current_position.x+1][current_position.y].used);
    if(current_position.x==-2) return pos;
    else{
        current_position.x++;
        return current_position;
    }
}
position next_down_left_position(position current_position,coord table[dim][dim]){
    position pos=current_position;
    short m=current_position.y;
    extern short dim;
    current_position.x++;
    do{
        current_position.y=m;
        while(current_position.y<dim-1&&table[current_position.x][current_position.y+1].used) current_position.y++;
        if(current_position.y<dim-1&&!table[current_position.x][current_position.y+1].used) current_position.y++;
        current_position.x++;
    }while(current_position.x<=dim&&table[current_position.x-1][current_position.y].used);
    if(current_position.x==dim+1) return pos;
    else{
        current_position.x--;
        return current_position;
    }
}
position next_down_right_position(position current_position,coord table[dim][dim]){
    position pos=current_position;
    short m=current_position.y;
    extern short dim;
    current_position.x--;
    do{
        current_position.y=m;
        while(current_position.y<dim-1&&table[current_position.x][current_position.y+1].used) current_position.y++;
        if(current_position.y<dim-1&&!table[current_position.x][current_position.y+1].used) current_position.y++;
        current_position.x--;
    }while(current_position.x>=-1&&table[current_position.x+1][current_position.y].used);
    if(current_position.x==-2) return pos;
    else{
        current_position.x++;
        return current_position;
    }
}
position next_player_position(coord table[dim][dim]){
    position pos;
    pos.x=0;
    pos.y=0;
    extern short dim;
    while(table[pos.x][pos.y].used&& pos.y < dim){
        while(pos.x<dim&&table[pos.x][pos.y].used) pos.x++;
        if(pos.x==dim) pos.x=0,pos.y++;
    }
    if(pos.y==dim) pos.y=-1,pos.x=-1;
    return pos;
}
bool equ_2_positions(position p1,position p2){
     return (p1.x==p2.x&&p1.y==p2.y);
}
position next_position(position currant_position,coord table[dim][dim],char arrow){
    extern char up,down,left,right;
    position m;
    if(arrow==up) return next_up_position(currant_position,table);
    else if(arrow==down) return next_down_position(currant_position,table);
    else if(arrow==left) return next_left_position(currant_position,table);
    else if(arrow==right) return next_right_position(currant_position,table);
    else if(arrow==up_left) return next_up_left_position(currant_position,table);
    else if(arrow==up_right) return next_up_right_position(currant_position,table);
    else if(arrow==down_left) return next_down_left_position(currant_position,table);
    else if(arrow==down_right) return next_down_right_position(currant_position,table);
    else return currant_position;
}
bool is_equ_players(player playere1,player playere2){
    if(playere1.c!=playere2.c) return false;
    if(playere1.c_color.fg!=playere2.c_color.fg) return false;
    if(playere1.c_color.bg!=playere2.c_color.bg) return false;
    return true;
}
bool winned(coord table[dim][dim],player playere){
    int i,j=0;
    short extern dim;
    while(j<dim){
        i=0;
        while(i<dim&&table[i][j].used&&is_equ_players(table[i][j].player,playere)) i++;
        if(i==dim) return true;
        else j++;
    }

    i=0;
    while(i<dim){
        j=0;
        while(j<dim&&table[i][j].used&&is_equ_players(table[i][j].player,playere)) j++;
        if(j==dim) return true;
        else i++;
    }
    i=0;j=0;
    while(i<dim&&table[i][j].used&&is_equ_players(table[i][j].player,playere)) i++,j++;
    if(i==dim) return true;

    i=0;j=dim-1;
    while(i<dim&&table[i][j].used&&is_equ_players(table[i][j].player,playere)) i++,j--;
    if(i==dim) return true;

    return false;
}
#endif // GAME_H_INCLUDED
