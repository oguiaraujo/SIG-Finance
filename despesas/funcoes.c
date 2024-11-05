#include <time.h>
#include <stdlib.h>
#include <string.h>

/* função para checar se é digito */
int checar_digito(int c){
	  if (c >= "0" && c <= "9") {
		    return 1;
	  } else{
		    return 0;
    }
}
