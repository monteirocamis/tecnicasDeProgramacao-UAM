
#include <stdio.h>
#include <string.h>

int main()
{
  char str0[6]="98765",str1[5]="abcd",str2[10]="efghijklm";

   printf("str0 = %s\t str1 = %s\t str2 = %s\n",str0,str1,str2);
   strcpy(str1,"123+4567");
   printf("str0 = %s\t str2 = %s\n",str0,str2);
}
