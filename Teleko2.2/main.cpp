
/**************************************************

file: demo_tx.c
purpose: simple demo that transmits characters to
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx

**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"

using namespace std;

int main()
{
  int i=0,
      cport_nr=1,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=9600;       /* 9600 baud */
        char wybor;
 char mode[]={'8','N','1',0},
       str[2][512];
/*

  strcpy(str[0], "The quick brown fox jumped over the lazy grey dog.\n");

  strcpy(str[1], "Happy serial programming!.\n");

*/

  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");

    return(0);
  }

  while(1)
  {
    printf("Wybierz prosze: 1. Wyslij tekst; 2. Zakoncz program\n");
    cin>>wybor;
switch(wybor){
    case('1'):
    {
        printf("\ncos sie dzieje! \n");
    }
    case('2'):
    {
        printf("\n");
        return 0;
    }
}
#ifdef _WIN32
    Sleep(1000);
#else
    usleep(1000000);  /* sleep for 1 Second */
#endif

    i++;

    i %= 2;
  }

  return(0);
}
