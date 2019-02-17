#include <cstdio>
void gotoxy(int x, int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
int main() { 
    gotoxy(10,10);
    printf(" IIIIIIIIII\n"); 
    gotoxy(10,11); 
    printf("IIIIIIIIIIIII\n"); return 0; 
}