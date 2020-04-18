#define EJEMPLO_3
#ifdef EJEMPLO_3

#include <unistd.h>
#include <iostream>

using namespace std;


int main () {

	cout << "Proceso padre: " << getpid() << endl;
	pid_t id1 = fork ();

//getppid returns the parent procesor id.
//(it returns 1 when parent process is finished by the time the child asks for its parent's pid)
//When a process finishes, all its children are reassigned as children of the init process, which pid is 1.
	if ( id1 == 0 ) {
		cout << "Hijo: Hola, soy primer proceso hijo.  Mi process ID es " << getpid() << " (" << getppid() << ")" << endl;
	}

	pid_t id2 = fork ();

	if ( id2 == 0 ) {
		cout << "Hijo: Hola, soy segundo proceso hijo.  Mi process ID es " << getpid() << " (" << getppid() << ")" << endl;
	}

}

#endif
