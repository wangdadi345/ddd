#include<stdio.h>

   void main(){ int **k, *a, b=100; a=&b; k=&a; printf("%d\n", **k); }
