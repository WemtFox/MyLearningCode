#ifdef _WIN32_WINNT
#define _WIN32_WINNT 0x400
#endif // _WIN32_WINNT

#include "stdio.h"
#include <windows.h>

//���������ͷ�ļ�
#include <wincrypt.h>
#define MY_ENCODING_TYPE (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING )
#define KEYLENGTH 0x00800000	//��Կ����
#define ENCRYPT_ALGORITHM CALG_RC4
#define ENCRYPT_BLOCK_SIZE 8

//��������
HCRYPTPROV GetCryptProv();
void HandleError(char *s);
void ByteToStr(DWORD cb, void* pv, LPSTR sz);

int main(){
	CHAR szPlaint[100];
	CHAR szPassword[100];

	printf("��������Ҫ���ܵ���Ϣ");
	gets(szPlaint);
	printf("������ӽ�������");
	gets(szPassword);

	//��������
	HCRYPTPROV hCryptprov;
	HCRYPTKEY hKey;
	HCRYPTHASH hHash;
	PBYTE pbBuffer;
	DWORD dwCount;

	//��ȡ�����ṩ�߾��
	hCryptprov = GetCryptProv();

	//����һ���Ự��Կ��session key��
	//�Ự��ԿҲ�жԳ���Կ�����ڶԳƼ����㷨
	//��ע��һ��Session��ָ�ӵ���CryptAcquireContext�����ú���CryptReleaseContext�ڼ�Ľ׶Σ�


	//������ϣ���
	if (CryptCreateHash(hCryptprov, CALG_MD5, 0, 0, &hHash))
	{
		printf("������ϣ����ɹ���\n");
	} 
	else
	{
		HandleError("CryptCreateHash����ִ�г���\n");
	}


	//������������һ����ϣֵ
	if (CryptHashData(hHash, (BYTE *)szPassword, strlen(szPassword), 0))
	{
		printf("�����������Ĺ�ϣֵ�ɹ���\n");
	}
	else
	{
		HandleError("CryptHashData����ִ�г���\n");
	}

	//ͨ����ϣֵ���ɻỰ��Կ��session key��
	if (CryptDeriveKey(hCryptprov, ENCRYPT_ALGORITHM, hHash, KEYLENGTH, &hKey))
	{
		printf("�������ϣֵ�����ӽ�����Կ�ɹ���\n");
	}
	else
	{
		HandleError("CryptDeriveKey����ִ�г���\n");
	}


	pbBuffer = (BYTE *)szPlaint;
	dwCount = strlen(szPlaint);
	printf("����ǰ����Ϊ��");
	printf("%s\n", (char *)pbBuffer);

	//��������
	if (! CryptEncrypt(hKey,//������Կ
						0, //�������ͬʱ���й�ϣ�ͼ��ܣ����ﴫ��һ����ϣ����
						true,//��������һ�������ܵĿ飬����true����������false
						0,//���� 
						pbBuffer,//��������ܵ����ݣ�������ܺ������
						&dwCount,//����������ݵ�ʵ�ʳ��ȣ�������ܺ�����ݳ���
						dwCount))//pbBuffer�Ĵ�С

	{
		HandleError("CryptEncrypt����ִ�г���. \n");
	}
	char EncryptedString[1000];

	ByteToStr(dwCount, pbBuffer, EncryptedString);
	printf("���ܺ�����Ϊ��");
		printf("%s\n", EncryptedString);


	//��������
	if (! CryptDecrypt(hKey, 0, true, 0, pbBuffer,&dwCount))
	{
		HandleError("CryptDecrypt ����ִ�г���");
	}

	printf("���ܺ�����Ϊ��");
		printf("%s\n", (char* )pbBuffer);

	//�ͷ��ڴ�
	if (pbBuffer)
		pbBuffer = NULL;
	
	//����hash��� �ͷſռ�
	CryptDestroyHash(hHash);
	hHash = NULL;

	//������Կ
	if (hKey)
		CryptDestroyKey(hKey);

    //�ͷ�CSP���
	if(hCryptprov)
		CryptReleaseContext(hCryptprov, 0);

	
}  //End of main

//��ȡ�����ṩ�߾��
HCRYPTPROV GetCryptProv()
{
	HCRYPTPROV hCryptProv;//���ܷ����ṩ�߾��

	//��ȡ�����ṩ�߾��
	if (CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, 0))
	{
		printf("���ܷ����ṩ�߾����ȡ�ɹ��� \n");
	}
	else
	{
		//���½���һ���µ���Կ��
		if (! CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET))
		{
			HandleError("���½���һ���µ���Կ������");
		}
	}
	return hCryptProv;
}

//HandleError:������������ӡ������Ϣ�����˳�����
void HandleError(char *s)
{
	printf("����ִ�з�������\n");
	printf("%s\n ,s");
	printf("�������Ϊ��%x\n.",GetLastError());
	printf("������ִֹ�У�\n");
	exit(1);
}


//ByteToStr:ת��BYTE��������Ϊ�ַ���
//������cb[in]��Ҫת����BYTE���鳤��
//pv[in]��Ҫת����BYTE����ָ��
//sz[out]�ַ���ָ��

void ByteToStr(DWORD cb, void* pv, LPSTR sz)
{
	BYTE* pb = (BYTE*)pv;
	DWORD i;
	int b;


	for (i=0;i<cb;i++)
	{
		//pb��ǰ4λת��Ϊ�ַ�
		b = (*pb & 0xf0) >> 4;
		*sz++ =(b<=9)? b + '0' : (b-10)+'A';
		//pb�ĺ�4λת��Ϊ�ַ�
		b = *pb & 0x0F;
		*sz++ =(b<=9)? b + '0' : (b-10)+'A';
		pb++;
	}
	*sz++ =0;
}