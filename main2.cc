#define EJEMPLO_2
#ifdef EJEMPLO_2

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

unsigned int calcularRandom ();


int main () {

	pid_t id = fork ();

	if ( id == 0 ) {

		unsigned int tiempoAdormir = calcularRandom ();
		cout << "Hijo: Hola, soy el proceso hijo.  Voy a dormir " << tiempoAdormir << " segundos" << endl;
		sleep ( tiempoAdormir );
		cout << "Hijo: ya me desperte y termino" << endl;

		exit ( 0 );

	} else {

		cout << "Padre: Hola, soy el proceso padre.  Espero a que mi hijo se despierte" << endl;
		int estado;
		//system call suspends execution of the calling thread until one of its children terminates.
		//If wstatus is not NULL, wait store status information  in the int to which it points
		//returns the process ID of the terminated child; on error, -1 is returned
		wait ( &estado );
		cout << "Padre: mi hijo se desperto y termino. status " << estado << endl;

		exit ( 0 );
	}
}


unsigned int calcularRandom () {
	srand ( (unsigned int)time(NULL) );
	unsigned int resultado = (unsigned int)(rand() % 10 + 1);
	return resultado;
}

#endif
