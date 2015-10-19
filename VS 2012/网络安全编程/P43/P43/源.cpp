#ifdef _WIN32_WINNT
#define _WIN32_WINNT 0x400
#endif // _WIN32_WINNT

#include "stdio.h"
#include <windows.h>

//加密所需的头文件
#include <wincrypt.h>
#define MY_ENCODING_TYPE (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING )
#define KEYLENGTH 0x00800000	//密钥长度
#define ENCRYPT_ALGORITHM CALG_RC4
#define ENCRYPT_BLOCK_SIZE 8

//函数声明
HCRYPTPROV GetCryptProv();
void HandleError(char *s);
void ByteToStr(DWORD cb, void* pv, LPSTR sz);

int main(){
	CHAR szPlaint[100];
	CHAR szPassword[100];

	printf("请输入需要加密的消息");
	gets(szPlaint);
	printf("请输入加解密密码");
	gets(szPassword);

	//变量定义
	HCRYPTPROV hCryptprov;
	HCRYPTKEY hKey;
	HCRYPTHASH hHash;
	PBYTE pbBuffer;
	DWORD dwCount;

	//获取加密提供者句柄
	hCryptprov = GetCryptProv();

	//创建一个会话密钥（session key）
	//会话密钥也叫对称密钥，用于对称加密算法
	//（注：一个Session是指从调用CryptAcquireContext到调用函数CryptReleaseContext期间的阶段）


	//创建哈希句柄
	if (CryptCreateHash(hCryptprov, CALG_MD5, 0, 0, &hHash))
	{
		printf("创建哈希句柄成功。\n");
	} 
	else
	{
		HandleError("CryptCreateHash函数执行出错。\n");
	}


	//用输入口令产生一个哈希值
	if (CryptHashData(hHash, (BYTE *)szPassword, strlen(szPassword), 0))
	{
		printf("计算输入口令的哈希值成功！\n");
	}
	else
	{
		HandleError("CryptHashData函数执行出错！\n");
	}

	//通过哈希值生成会话密钥（session key）
	if (CryptDeriveKey(hCryptprov, ENCRYPT_ALGORITHM, hHash, KEYLENGTH, &hKey))
	{
		printf("从密码哈希值创建加解密密钥成功！\n");
	}
	else
	{
		HandleError("CryptDeriveKey函数执行出错！\n");
	}


	pbBuffer = (BYTE *)szPlaint;
	dwCount = strlen(szPlaint);
	printf("加密前数据为：");
	printf("%s\n", (char *)pbBuffer);

	//加密数据
	if (! CryptEncrypt(hKey,//加密密钥
						0, //如果数据同时进行哈希和加密，这里传入一个哈希对象
						true,//如果是最后一个被加密的块，输入true，否则输入false
						0,//保留 
						pbBuffer,//输入需加密的数据，输出加密后的数据
						&dwCount,//输入加密数据的实际长度，输出加密后的数据长度
						dwCount))//pbBuffer的大小

	{
		HandleError("CryptEncrypt函数执行出错. \n");
	}
	char EncryptedString[1000];

	ByteToStr(dwCount, pbBuffer, EncryptedString);
	printf("加密后数据为：");
		printf("%s\n", EncryptedString);


	//解密数据
	if (! CryptDecrypt(hKey, 0, true, 0, pbBuffer,&dwCount))
	{
		HandleError("CryptDecrypt 函数执行出错！");
	}

	printf("解密后数据为：");
		printf("%s\n", (char* )pbBuffer);

	//释放内存
	if (pbBuffer)
		pbBuffer = NULL;
	
	//销毁hash句柄 释放空间
	CryptDestroyHash(hHash);
	hHash = NULL;

	//销毁密钥
	if (hKey)
		CryptDestroyKey(hKey);

    //释放CSP句柄
	if(hCryptprov)
		CryptReleaseContext(hCryptprov, 0);

	
}  //End of main

//获取加密提供者句柄
HCRYPTPROV GetCryptProv()
{
	HCRYPTPROV hCryptProv;//加密服务提供者句柄

	//获取加密提供者句柄
	if (CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, 0))
	{
		printf("加密服务提供者句柄获取成功！ \n");
	}
	else
	{
		//重新建立一个新的密钥集
		if (! CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET))
		{
			HandleError("重新建立一个新的密钥集出错！");
		}
	}
	return hCryptProv;
}

//HandleError:错误处理函数，打印错误信息，并退出程序
void HandleError(char *s)
{
	printf("程序执行发生错误！\n");
	printf("%s\n ,s");
	printf("错误代码为：%x\n.",GetLastError());
	printf("程序终止执行！\n");
	exit(1);
}


//ByteToStr:转换BYTE类型数组为字符串
//参数：cb[in]需要转换的BYTE数组长度
//pv[in]需要转换的BYTE数组指针
//sz[out]字符串指针

void ByteToStr(DWORD cb, void* pv, LPSTR sz)
{
	BYTE* pb = (BYTE*)pv;
	DWORD i;
	int b;


	for (i=0;i<cb;i++)
	{
		//pb的前4位转换为字符
		b = (*pb & 0xf0) >> 4;
		*sz++ =(b<=9)? b + '0' : (b-10)+'A';
		//pb的后4位转换为字符
		b = *pb & 0x0F;
		*sz++ =(b<=9)? b + '0' : (b-10)+'A';
		pb++;
	}
	*sz++ =0;
}