#include "environement.h"
void main(int argc,char *argv[]){
    printf("\e[?25l");
    if(argc<12){
        puts(" Enter from game lancher!");
        getch();
        exit(0);
    }
    get_main_menu_parameters_from_arguments(argv);
    write_main_menu();
}
