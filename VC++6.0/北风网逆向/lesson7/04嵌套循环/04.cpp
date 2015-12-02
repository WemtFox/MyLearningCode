#include "stdio.h"

int main(){
	int array[2][2] = {1,2,3,4};
	for (int i =0;i<2;i++)
	{
		for (int j =0;j<2;j++)
		{
			if (j == 1)
			{
				// break;
				// continue;
				goto lable;
			}
			printf("%d\n",array[i][j]);
		}	
	}
lable:	
	return 0;
}