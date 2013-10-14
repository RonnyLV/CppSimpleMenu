#pragma hdrstop
#pragma argsused


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "MenuExtended.h"

void HelloWorld(){
	printf("\n\n%s\n\n\n\n","This is exile");
	getchar();
}
void power(){
	printf("4 kvadrâtâ = %d\n\n",4*4);
	getchar();
}
int main(){
	MenuExtended *MyMenu;
	struct MenuLine MenuLines[] = {
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"HelloWorld Program",&HelloWorld},
		{"Shitso",&HelloWorld},
		{"HelloWorld for test", &power}
	};
	MyMenu = new MenuExtended;
	MyMenu->setHeader("Jaunais headeris", false);
	if(MyMenu->setLines(MenuLines, sizeof(MenuLines) / sizeof(struct MenuLine)) == 0){
		MyMenu->getMenu();
		return EXIT_SUCCESS;
	}
		return EXIT_FAILURE;
}
