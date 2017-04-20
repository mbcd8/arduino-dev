#include<stdio.h>
#include<time.h>
main()
{
int portnum;   //port number.
int baudrate; //speed of port.
int bits;    //stop bits.

int x1, y1, z1, u1;
int x2, y2, z2, u2;

x1=y1=z1=u1=0;
x2=y2=z2=u2=0;
printf("|=========================================================|\n");
printf("|=========================================================|\n");
printf("|                          Test RS232                     |\n");
printf("|=========================================================|\n");
printf("|                                                         |\n");

printf("             bit1=%d, bit2=%d, bit3=%d, bit4=%d\n", x1, y2, z1, u1);
  x1 = ++z1;
  x2 = z2++;
printf("             bit1=%d, bit2=%d, bit3=%d, bit4=%d\n", x2, y2, z2, u2);

printf("|                                                         |\n");
printf("|=========================================================|\n");
printf("|                   This is UI test app in c                |\n");
printf("|=========================================================|\n");
printf("|                          Sucсessfly!                    |\n");


while (1);
printf("                              EXIT                        |\n");
return (0);
}
