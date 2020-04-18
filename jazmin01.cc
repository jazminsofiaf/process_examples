/*"A partir de un proceso padre, crear 10 procesos hijo. Cada proceso hijo
deberá dormir (sleep) una cant. aleatoria de segundos y finalizar al padre la
cantidad de segundos que durmió. El proceso padre deberá imprimir las
cantidades de segundos que fueron durmiendo los hijos."*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

unsigned int randomTime(int i);

int main () {

  int parent_id = getpid();
  cout << "[Parent] id: " << parent_id << endl;

  for(int i= 0; i < 10; i++){
    cout << "[Parent] creating " << i << " child here... " << " ("<< getpid() <<")" <<endl;
    pid_t id = fork ();
  	if ( id == 0 ) {
  		unsigned int tiempoAdormir = randomTime(i);
  		cout << "[Child" << i << "] Hi, I'm a child.  I'm gonna sleep " << tiempoAdormir << " secs" << " ("<< getpid() <<")" <<endl;
  		sleep ( tiempoAdormir );
  		cout << "[Child" << i << "] I've woken up! and I finish" << " ("<< getpid() <<")" <<endl;
  		exit ( tiempoAdormir ); // as exit here the child is not alive at the end of the loop
  	}
  }

  for(int i= 0; i < 10; i++){
      int status;
      wait(&status);
      unsigned int sleptTime = (unsigned int) WEXITSTATUS(status) ;
      cout << "[Parent] my son is awake and has finished. he slept " << sleptTime << " secs ("<< getpid() <<")" <<endl;
  }

  exit (0);
}


unsigned int randomTime(int i) {
	srand ( (unsigned int)time(NULL)*i );
	unsigned int result = (unsigned int)(rand() % 10 + 1);
	return result;
}
