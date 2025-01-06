#include "..\..\Common.h"
#include <iostream>

#define TESTNAME "www.tu.ac.kr"

// ������ �̸� -> IPv4 �ּ�
bool GetIPAddr(const char* name, struct in_addr* addr)
{
	struct hostent* ptr = gethostbyname(name);
	if (ptr == NULL) {
		err_display("gethostbyname()");
		return false;
	}
	if (ptr->h_addrtype != AF_INET)
		return false;
	memcpy(addr, ptr->h_addr, ptr->h_length);
	return true;
}

// IPv4 �ּ� -> ������ �̸�
bool GetDomainName(struct in_addr addr, char* name, int namelen)
{
	struct hostent* ptr = gethostbyaddr((const char*)&addr,
		sizeof(addr), AF_INET);
	if (ptr == NULL) {
		err_display("gethostbyaddr()");
		return false;
	}
	if (ptr->h_addrtype != AF_INET)
		return false;
	strncpy(name, ptr->h_name, namelen);
	return true;
}

int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	printf("������ �̸�(��ȯ ��) = %s\n", TESTNAME);

	// ������ �̸� -> IP �ּ�
	struct in_addr addr;
	if (GetIPAddr(TESTNAME, &addr)) {
		// �����̸� ��� ���
		char str[INET_ADDRSTRLEN];
		char* tmp = inet_ntoa(addr);
		printf("IP �ּ�(��ȯ ��) = %s\n", tmp);

		// IP �ּ� -> ������ �̸�
		char name[32];
		if (GetDomainName(addr, name, sizeof(name))) {
			// �����̸� ��� ���
			printf("������ �̸�(�ٽ� ��ȯ ��) = %s\n", name);
		}
	}

	// ���� ����
	WSACleanup();
	return 0;
}
