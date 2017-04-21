#include<stdio.h>
#include<string.h>
#include<time.h>

main()
{
printf ("\033[0d\033[2J");//Очищение экрана терминала.

int portnum;   //port number.
int baudrate; //speed of port.
int bits;    //stop bits.
int x1, y1, z1, u1;
int x2, y2, z2, u2;
int x3, y3, z3, u3;
int x4, y4, z4, u4;
int x5, y5, z5, u5;
int x6, y6, z6, u6;
int x7, y7, z7, u7;
int x8, y8, z8, u8;

int x9, y9, z9, u9;
int x10, y10, z10, u10;
int x11, y11, z11, u11;
int x12, y12, z12, u12;
int x13, y13, z13, u13;
int x14, y14, z14, u14;
int x15, y15, z15, u15;
int x16, y16, z16, u16;


x1=y1=z1=u1=0;
x2=y2=z2=u2=0;
x3=y3=z3=u3=0;
x4=y4=z4=u4=0;
x5=y5=z5=u5=0;
x6=y6=z6=u6=0;
x7=y7=z7=u7=0;
x8=y8=z8=u8=0;

x9=y9=z9=u9=0;
x10=y10=z10=u10=0;
x11=y11=z11=u11=0;
x12=y12=z12=u12=0;
x13=y13=z13=u13=0;
x14=y14=z14=u14=0;
x15=y15=z15=u15=0;
x16=y16=z16=u16=0;


printf("|=========================================================|\n");
printf("|              ======== >Test RS232 < ========            |\n");
printf("|=========================================================|\n");
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x1, y1, z1, u1, x9,  y9,  z9,  u9);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x2, y2, z2, u2, x10, y10, z10, u10);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x3, y3, z3, u3, x11, y11, z11, u11);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x4, y4, z4, u4, x12, y12, z12, u12);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x5, y5, z5, u5, x13, y13, z13, u13);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x6, y6, z6, u6, x14, y14, z14, u14);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x7, y7, z7, u7, x15, y15, z15, u15);
printf("|                                                         |\n");
printf("|             %d   %d   %d   %d   %d   %d   %d   %d               |\n", x8, y8, z8, u8, x16, y16, z16, u16);
printf("|                                                         |\n");
printf("|=========================================================|\n");
printf("|                   This is UI test app in C              |\n");
printf("|=========================================================|\n");
printf("|                        Sucсessfly!                      |\n");
printf("|=========================================================|\n");

while (1);
{
printf("                              EXIT                        |\n");
return (0);
}
}
