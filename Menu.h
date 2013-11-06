/*
	Menu.h
	Apraksts:
		Menu headeris, kurâ ietilpst Menu klase âtras izvçlnes izveidç "kosnoles" reþîmam.

	Piemçrs:
		int main(){
			Menu *MyMenu;
			void (*f2)(void);
			struct MenuLine MenuLines[] = {
				{"HelloWorld Program",&HelloWorld},
				{"Shitso",&HelloWorld},
				{"HelloWorld for test", &power}
			};
			MyMenu = new Menu;
			MyMenu->setHeader("Jaunais headeris", true);
			MyMenu->setLines(MenuLines, sizeof(MenuLines) / sizeof(struct MenuLine));
			MyMenu->printMenu();
			return EXIT_SUCCESS;
}
*/

#define bool int
#define true 1
#define false 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuLine{								//Menu elementu struktûra
	char	description[50];
	void	(*f1)( void );
};

class Menu{
        private:
		int		menuCount;							//Menu elementu skaits

		char		header[50],						//Menu Header-is
				inputText[50],					//Ievades izvadoðais teksts
				errorInputText[50],				//Kïûdas paziòojums, ja izvçlçtais nav iekð vçrtîbâm
				footerActions[2][50];	//{"Exit [x]","About Menu[i]"}

	 	struct		MenuLine *Lines;			//Menu galvenie elementi ar struktûru (Teksts, Pointeris uz funkciju)

	protected:
	 	void	printHeader();

		void	printMenuLine( int p_line );

		void	printMenuLines();

		void	printMenu();

		void	aboutMenu();

		void	breakFooter();
	public:
                Menu();

		void	setHeader( char p_header[] );

		//void	setHeader( const char p_header[], bool p_setDecoration);

		void	setHeader( char p_header[], bool p_setDecoration);

		void	setInputText( char p_inputText[] );

		void	setErrorInputText( char p_errorInputText[] );

		void	setFooterActionExit( char p_footerActionExit[] );

		void	setFooterActionInfo( char p_footerActionInfo[] );

		void	getMenu();

		struct MenuLine getStruct(char p_description[50], void ( *p_function )( void ) );

		int setLines( struct MenuLine p_Lines[], int p_size_of_array );
};
