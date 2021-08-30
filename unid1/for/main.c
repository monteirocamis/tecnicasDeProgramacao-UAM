#include <stdio.h>
#include <stdlib.h>
// exemplo 4 :
//#define MAX 5


// exemplo 5 :
#define MAX 20


int main()
{

     int i;
/*
// exemplo 1
    int i;
    for(i=0;i<5;i++)
        {
         printf("for em c \n ",i );
    }
*/

//exemplo 2 - mostrando as vezes
   /*
    for(i=0;i<5;i++)
        {
         printf("for em c %da vez! \n ",i );
    }





//exemplo 3 - mostrando as vezes

    for(i=0;i<max;i++)
        {
         printf("for em c %da vez! \n ",i );
    }



// exemplo 4 - decrementar
 // for(i=0;i<MAX;i--) // OOPS LOOP INFINITO
    for(i=MAX;i>0;i--)
            {
         printf("for em c %da vez! \n ",i );
    }
*/

// exemplo 5 - decrementar de 5 em 5
   for(i=MAX;i>0;i-=5)
            {
         printf("for em c %da vez! \n ",i );
    }
    return 0;
}
