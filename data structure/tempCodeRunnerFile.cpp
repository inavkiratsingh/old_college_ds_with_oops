#include <stdio.h>
int main()
{
float* ptr = (int*)malloc(sizeof(float));
ptr = NULL;
free(ptr);
}