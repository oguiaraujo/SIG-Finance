#include <time.h>
#include <stdlib.h>
#include <string.h>

/* funçao de validação de digito*/
int checar_digito(int c){
	  if (c >= "0" && c <= "9") {
		  return 1;
	  } else{
		  return 0;
	  }
	
}
