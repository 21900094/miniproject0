#include <stdio.h>
#include <stdlib.h>
#include "product.h"
int selectMenu(){
 int menu;
 printf("\n*** 쇼핑몰 프로그램 ***\n");
 printf("1. 조회\n");
 printf("2. 추가\n");
 printf("3. 수정\n");
 printf("4. 삭제\n");
 printf("5. 파일 저장\n");
 printf("6. 이름 검색\n");
 printf("7. 가격 검색\n");
 printf("8. 배송 방법 검색\n");
 printf("0. 종료\n\n");
 printf("=> 원하는 메뉴는? ");
 scanf("%d", &menu);
 getchar();
 printf("\n");
 return menu;
}
