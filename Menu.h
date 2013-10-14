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
	protected:
		int		menuCount;							//Menu elementu skaits

		char		header[50],						//Menu Header-is
				inputText[50],					//Ievades izvadoðais teksts
				errorInputText[50],				//Kïûdas paziòojums, ja izvçlçtais nav iekð vçrtîbâm
				footerActions[2][50];	//{"Exit [x]","About Menu[i]"}

		struct		MenuLine *Lines;			//Menu galvenie elementi ar struktûru (Teksts, Pointeris uz funkciju)
		void	printHeader(){
			printf("%s\n",this->header);	
		};
		
		void	printMenuLine( int p_line ){
			printf( "\n%c.%s", ((char)((int)'0') + p_line + 1), this->Lines[p_line].description );
		}

		void	printMenuLines(	){
			int	i;
			for( i = 0 ; i < menuCount ; i++ ){
				if(this->Lines[i].description != '\0')
					this->printMenuLine( i );	
				else
					break;
			};
		}
		
		void	printMenu(){
			this->printHeader();	
			this->printMenuLines();
			this->breakFooter();
		}

		void	aboutMenu(){
			printf("-=x-=x-=x-=x-=x-=x-=x-=x-=x-=x-=x-=x\n\n\n");
			printf("Menu.h created by Ronalds Breikðs\n\n\n");
			printf("-=x-=x-=x-=x-=x-=x-=x-=x-=x-=x-=x-=x\n\n\n");
			fflush(stdin);
			getchar();
		};

		void	breakFooter(){
			printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-\n\n");
			printf("%s\t%s",this->footerActions[0],this->footerActions[1]);
		};
	public:

		Menu(){
			strncpy( this->header,		"-=-=-=-=-=MOJ DEFAULT HEADER=-=-=-=-=-", sizeof( this->header ) );
			strncpy( this->inputText,	"Enter the selection", sizeof( this->inputText ) );
			strncpy( this->errorInputText,	"The selection was not valid", sizeof( this->errorInputText ) );
			strncpy( this->footerActions[0],"Exit [x]", sizeof( this->footerActions[0] ) );
			strncpy( this->footerActions[1],"About Menu[i]", sizeof ( this->footerActions[1] ) );

			this->Lines		=	NULL;
			this->menuCount		=	-1;
		};

		void	setHeader( char p_header[] ){
			strcpy( this->header, p_header );
		};

		void	setHeader( char p_header[], bool p_setDecoration){
			char v_header[50];

			if ( p_setDecoration == true ) {
				strcpy( v_header, "" );
				strcat(	v_header, "-=-=-=-=" );
				strcat( v_header, p_header );
				strcat(	v_header, "=-=-=-=-" );
			}else{
				strcpy( v_header, p_header );
			}

			this->setHeader( v_header );
		};

		void	setInputText( char p_inputText[]){
			strcpy( this->inputText, p_inputText );
		};

		void	setErrorInputText( char p_errorInputText[]){
			strcpy( this->errorInputText, p_errorInputText );
		};

		void	setFooterActionExit( char p_footerActionExit[]){
			strcpy( this->footerActions[0], p_footerActionExit );
		};

		void	setFooterActionInfo( char p_footerActionInfo[]){
			strcpy( this->footerActions[1], p_footerActionInfo );
		};		

		void	getMenu(){					//Menu izveide un handle-oðana
			int 	ch;						//Iterâcijas mainîgais
			char	v_select;					//Izvçlnes mainîgais
			while( 1==1 ){
			system("CLS");
			if(!(this->menuCount < 0)){
				this->printMenu();
				while( 1 == 1 ){
					fflush(stdin);
					printf( "\n\n\n%s: ", this->inputText);
					scanf("%c",&v_select);
					while((ch = getchar()) != '\n' && ch != EOF);
					if (((v_select - '0' > 0) && (v_select - '0' <= this->menuCount)) || (v_select == 'x') || (v_select == 'i'))
						break;
					else
						printf("%s",this->errorInputText);
				}
				if(v_select == 'x')
					return;
				if(v_select == 'i'){
					this->aboutMenu();
				}else
					this->Lines[v_select - '0' - 1].f1();
			}
			else
			{
				printf("\n\n\n!!!You didn't initialize Menu!!!\n\n\n");
			}
		}
		};

		struct MenuLine getStruct(char p_description[50], void (*p_function)( void )){	//Metode, kura atgrieþ struktûru paredzçtu Menu izveidei
			struct MenuLine v_my_struct;

			strcpy(v_my_struct.description,p_description);
			v_my_struct.f1 = p_function;

			return v_my_struct;
		}

		int setLines( struct MenuLine p_Lines[], int p_size_of_array ){
			int	i;	//Iteracijas mainigais

			this->menuCount = p_size_of_array;

			if (( this->Lines = (struct MenuLine *) malloc(p_size_of_array * sizeof(struct MenuLine))) == NULL ) {
				/* nav atminjas :( ko darit? :(((*/
				return -1;
			}
				

			for ( i = 0 ; i < p_size_of_array ; i++ ){
				this->Lines[i] = p_Lines[i];
			};
			return 0;

		};
};


