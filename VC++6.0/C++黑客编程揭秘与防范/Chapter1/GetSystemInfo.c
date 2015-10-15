#include<windows.h>

void GetSysInfo();

int main(){

	GetSysInfo();
	return 0;
}

void GetSysInfo(){

	char szComputerName[MAXBYTE] = {0};
	char szUserName[MAXBYTE] = {0};

	unsigned long nSize = MAXBYTE;
	OSVERSIONINFO OsVer;

	OsVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&OsVer);

	if(OsVer.dwPlatformId == VER_PLATFORM_WIN32_NT){
		if(OsVer.dwMajorVersion == 5 && OsVer.dwMinorVersion == 1){
			printf("WIndows XP %s \r\n", OsVer.szCSDVersion);
		}else if(OsVer.dwMajorVersion == 5 && OsVer.dwMinorVersion == 0){
			printf("Windows 2K \r\n");
		}else if(OsVer.dwMajorVersion == 6){
			printf("Windows 7 \r\n");
		}else{
			printf("Windows 7以上系统");
		}
		
	}else{
		printf("Other System \r\n");
	}



	GetComputerName(szComputerName, &nSize);
	printf("Computer Name is %s \r\n", szComputerName);

	nSize = MAXBYTE;
	GetUserName(szUserName, &nSize);
	printf("User Name is %s \r\n", szUserName);
} 