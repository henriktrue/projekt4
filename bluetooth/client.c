

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
	// A total of 32 Bluetooth channels at the time of writing [1..32]
	//  2 clients cannot connect on the same channel if a
	//  connection is still open on the server
	static const short BLUETOOTH_CHANNEL = 13;
	struct sockaddr_rc addr = { 0 };
	// HARD CODED MAC ADDRESS OF THE SERVER
	char dest[18] = "5C:F3:70:89:5C:93";
	// allocate a socket
	int socketDesc = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	// set the connection parameters (who to connect to)
	addr.rc_family  = AF_BLUETOOTH;
	addr.rc_channel = BLUETOOTH_CHANNEL;
	str2ba( dest, &addr.rc_bdaddr );
	// connect to server
	int status = connect(socketDesc, (struct sockaddr *)&addr, sizeof(addr));
	// send a message
	if( status == 0 ) {
		char message[] = "Mesa Back! Grlgrlgr!";
		// non­blocking write to socket
		status = write(socketDesc, message, sizeof(message));
	}
		if( status < 0 ) {
		printf("I cannot connect");
	}
	// ALWAYS close the connection, even if the connection was declined
	close(socketDesc);
}

