#define EJEMPLO_4
#ifdef EJEMPLO_4

#include <unistd.h>
#include <iostream>

using namespace std;


int main () {

	cout << "Proceso padre: " << getpid() << endl;
	pid_t id1 = fork ();

	if ( id1 == 0 ) { //if it is the child
		cout << "Hijo: Hola, soy el primer proceso hijo.  Mi process ID es " << getpid() << " (" << getppid() << ")" << endl;
	} else {
		//otherwise, it is the parent thread
		pid_t id2 = fork ();//this new thread is created only in the parent.
		if ( id2 == 0 ) {
			cout << "Hijo: Hola, soy el segundo proceso hijo.  Mi process ID es " << getpid() << " (" << getppid() << ")" << endl;
		}
	}

}

#endif
