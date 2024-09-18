#include "environement.h"
void main(int argc,char *argv[]){
    printf("\e[?25l");
    if(argc<8){
        puts(" Enter from game lancher!");
        while(getch()!='\r');
        exit(0);
    }
    get_table_settings_from_arguments(argv);
    write_tictactoe_table();
}
