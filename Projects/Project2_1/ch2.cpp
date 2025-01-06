#include "..\..\Common.h"

int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[�˸�] ���� �ʱ�ȭ ����\n");

	printf("%d\n",wsa.iMaxSockets);
	printf("%d\n",wsa.iMaxUdpDg );
	printf("%p\n",wsa.lpVendorInfo );
	printf("%p\n",wsa.szDescription );
	printf("%s\n",wsa.szSystemStatus );
	printf("%d\n",wsa.wHighVersion);
	printf("%d\n",wsa.wVersion);

	// ���� ����
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");
	printf("[�˸�] ���� ���� ����\n");

	// ���� �ݱ�
	closesocket(sock);

	// ���� ����
	WSACleanup();
	return 0;
}
