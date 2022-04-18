#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "product.h"

int main(void){
    Product *p=(Product *)malloc(sizeof(Product)*20);
    int menu;
    int now=0;
    now=load(p);
    int result;
    printf("commit number 1\n");
    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("종료됨!\n");
            break;
        }
        if (menu == 1){
		#ifdef DEBUG
		printf("=>DEBUGMODE\n");
		#endif
    		result=list(p,now);
            if(result==0){
                printf("데이터 없음\n");
            }
        }
        else if (menu == 2){
	#ifdef DEBUG
		printf("=>DEBUGMODE\n");
	#endif
            now=add(p,now);
            if(now!=0)printf("=>추가됨!\n");
        }
        else if (menu == 3){
	#ifdef DEBUG
		printf("=>DEBUGMODE\n");
	#endif
		result=update(p,now);
            if(result==1){
                printf("=>수정됨!\n");
            }
        }
        else if (menu == 4){
	#ifdef DEBUG
		printf("=>DEBUGMODE\n");
	#endif
            result=deletes(p,now);
            if(result==1){
            printf("삭제됨!\n");
            }
        }
        else if(menu==5){
	#ifdef DEBUG
		printf("=>DEBUGMODE\n");
	#endif
		save(p,now);
                printf("저장됨!\n");
        }
        else if(menu==6){
	#ifdef DEBUG
	printf("=>DEBUGMODE\n");
	#endif
            result=searchname(p,now);
            if(result==0){
                printf("검색된 데이터 없음!\n");
            }
        }
        else if(menu==7){
	#ifdef DEBUG
	printf("=>DEBUGMODE\n");
	#endif
	    	result=searchprice(p,now);
            if(result==0){
                printf("검색된 데이터 없음!\n");
            }
        }
        else if(menu==8){
	#ifdef DEBUG
		printf("=>DEBUGMODE\n");
	#endif
            result=searchdelivery(p,now);
            if(result==0){
                printf("검색된 데이터 없음!\n");
            }
        }
}
free(p);
return 0;
}
