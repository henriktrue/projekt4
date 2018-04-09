
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <syslog.h>

int main(int argc, char **argv)
{
	// allocate socket
	int socketDesc = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

	// binding socket to port 1 of the first available
	struct sockaddr_rc server_addr = { 0 };
	server_addr.rc_family  = AF_BLUETOOTH;
	server_addr.rc_bdaddr  = *BDADDR_ANY;
	server_addr.rc_channel = (uint8_t) 1;
	int rc=bind(socketDesc, (struct sockaddr *)&server_addr, sizeof(server_addr));
	printf("bind = %d \n", rc);


	// put socket into listening mode
	int rcl = listen(socketDesc, 1);
	printf("listen = %d \n", rcl);

	// accept one connection
	struct sockaddr_rc client_addr = { 0 };
	printf("1");
	socklen_t opt = sizeof(client_addr);
	printf("2");
	int client = accept(socketDesc, (struct sockaddr *)&client_addr, &opt);
	printf("3");
	// print the MAC address of the connection received
	char mini_buf[256] = { 0 };
	printf("4");
	ba2str( &client_addr.rc_bdaddr, mini_buf );
	fprintf(stderr, "accepted connection from %s\n", mini_buf);
	printf("%s just connected", mini_buf);
	memset(mini_buf, 0, sizeof(mini_buf));

	// read data from the client
	char buf[1024] = {0};

	// perform a blocking read
	int bytes_read = read(client, buf, sizeof(buf));


		if( bytes_read > 0 ) {
			printf("received [%s]\n", buf);
		}
		else {
			printf("waiting");
		}

	// always remember to close the connections
	// especially when the connection is lost for some reason
	close(client);
	close(socketDesc);
	closelog();

	return 0;
}
