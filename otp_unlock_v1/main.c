#include "LCD.h"
#include "Keypad.h"
#include "eeprom.h"
#include "types.h"


char password[5] = {"12345"};
char password_str[5] = {0};
char *eeprom_password_read;

int initialisation();

enum states
{
	initialisation_state,
	password_state,
	change_password,
	validate_pass,
	perform_action,
	
	
	
}state;

int main()
{
	int i;
	char val;
	
	initialisation();
	
	while(1)
	{
		switch (state)
		{
			case password_state:
				
				Write_cmd_LCD(0x80);
				Write_str_LCD("Enter Password");
				Write_cmd_LCD(0xc0);
			
				val = key_val();
			
				for(i = 0; i < sizeof(password_str); i++)
				{
					if(val == '*') //char to move to next menu option
					{
						state = change_password;
						break;
					}
					
					if(val == '=') //char as enter to validate
					{
							state = validate_pass;
							break;
					}
					
					if(val == '0') //char for backspace
					{
						i--;
						//lCD clear a bit
						//Kartik look into it for clearing LCD last char
					}
					
					password_str[i] = val;
					
					
				}
				
				break;
				
			case change_password:
				break;
			
			case validate_pass:
				
				eeprom_password_read = page_byte_read(0xa0, 0x00, 5);
			
				for(i = 0; i < 5; i++)
				{
					if(eeprom_password_read[i] != password_str[i])
					{
						Write_cmd_LCD(0x80);
						Write_str_LCD("WRONG PASSWORD");
					
						state = password_state;
						
						break;
						
					}
				}
					//perform Action
				state = perform_action;
				break;
	
					
			case perform_action:
				Write_cmd_LCD(0x80);
				Write_str_LCD("Welcome");
				break;
		
			
			default :
				break;

			
		}
	}
}

int initialisation()
{
	LCD_Init();
	page_byte_write(0xa0,0x00,password,5);
	
}