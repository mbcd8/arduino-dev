#include<stdio.h>
#include<time.h>
main()
{
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


x1=y1=z1=u1=0;
x2=y2=z2=u2=0;
x3=y3=z3=u3=0;
x4=y4=z4=u4=0;
x5=y5=z5=u5=0;
x6=y6=z6=u6=0;
x7=y7=z7=u7=0;
x8=y8=z8=u8=0;

printf("|=========================================================|\n");
printf("|              ======== >Test RS232 < ========            |\n");
printf("|=========================================================|\n");
printf("|                                                         |\n");

printf("|              bit1=%d,  bit2=%d, bit3=%d, bit4=%d            |\n", x1, y2, z1, u1);
printf("|              bit5=%d,  bit6=%d, bit7=%d, bit8=%d            |\n", x2, y2, z2, u2);
printf("|              bit9=%d,  bit10=%d, bit11=%d, bit12=%d         |\n", x3, y3, z3, u3);
printf("|             bit13=%d, bit14=%d, bit15=%d, bit16=%d          |\n", x4, y4, z4, u4);
printf("|             bit17=%d, bit18=%d, bit19=%d, bit20=%d          |\n", x5, y5, z5, u5);
printf("|             bit21=%d, bit22=%d, bit23=%d, bit24=%d          |\n", x6, y6, z6, u6);
printf("|             bit25=%d, bit26=%d, bit27=%d, bit28=%d          |\n", x7, y7, z7, u7);
printf("|             bit29=%d, bit30=%d, bit31=%d, bit32=%d          |\n", x8, y8, z8, u8);
printf("|                                                         |\n");
printf("|=========================================================|\n");
printf("|                   This is UI test app in c              |\n");
printf("|=========================================================|\n");
printf("|                        Sucсessfly!                      |\n");
printf("|=========================================================|\n");

while (1);
{}
printf("                              EXIT                        |\n");
return (0);
}
