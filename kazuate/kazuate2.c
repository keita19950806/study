#include <stdio.h>

int main(void)
{
        int no;
        int ans = 7;

        printf("0〜9の整数を当ててください。\n\n");

	do{
       		printf("いくつかな？:");
	        scanf("%d",&no);

        	if ( no > ans )
	                printf("\aもっと小さいよ！\n");
	        else if ( no < ans )
	                printf("\aもっと大きいよ！\n");
	} while ( no != ans );
	
	printf("正解！\n");
	
        return 0;
}

