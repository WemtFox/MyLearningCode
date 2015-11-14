#include "stdio.h"
#define PASSWORD "123456"

int verify_passowrd(char* password){
	int authenticated;
	authenticated = strcmp(password, PASSWORD);
	return authenticated;
}

main(){

	int valid_flag = 0;
	char password[1024];
	while (1)
	{
		printf("please input password:		");
		scanf("%s",password);
		valid_flag = verify_passowrd(password);
		if (valid_flag)
		{
			printf("incorrect password!\n\n");
		}else{
			printf("Congratulation! you have passed the verification!\n");
		}
	}

}


