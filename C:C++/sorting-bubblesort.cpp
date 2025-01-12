#include <stdio.h>
struct pluto
{
    int a=0;
    int t=0;
}array[11];
void swap(struct pluto *a,struct pluto *b);
int main()
{
    array[1-1].a=1;
    array[2-1].a=3;
    array[3-1].a=9;
    array[4-1].a=5;
    array[5-1].a=10;
    array[6-1].a=0;
    array[7-1].a=3;
    array[8-1].a=1;
    array[9-1].a=4;
    array[10-1].a=4;
	int    i, j,k;
	for (i = 0; i < 10; i++)
	{
		for (j = 9; j > i; j--)
		{
			if (array[j].a < array[j-1].a)
			{
                    swap(&array[j], &array[j-1]);
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", array[i].t);
	}
	return    0;
}
void swap(struct pluto *a, struct pluto *b)
{
	struct pluto *temp;
	temp = *a;
	  *a = *b;
      *b = temp;
      a.t++;
      b.t++;
}