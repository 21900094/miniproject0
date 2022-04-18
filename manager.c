#include <stdio.h>
#include <stdlib.h>
#include "manager.h"
#include <string.h>


int add(Product *p,int now){


    printf("이름은? ");
    scanf("%[^\n]s",p[now].name);
    getchar();
    printf("설명은? ");
    scanf("%[^\n]s",p[now].comment);
    getchar();
    printf("중량은? ");
    scanf("%[^\n]s",p[now].weight);
    getchar();
    printf("가격은? ");
    scanf("%d",&p[now].price);
    printf("배송방법은? ");
    scanf("%d",&p[now].delivery);
    now++;
    return now;
}      
int  list(Product *p,int now) {    
    printf("no Name comment weight price delivery\n");;
    int count=0;
    for(int i=0;i<now;i++){
    if(p[i].price==-1){
        continue;
    }
    else if(p[i].price!=-1){
        count++;
        printf("%d ",count);
        read1(p[i]);
    }
    }
    if(count<=0)return 0;
    return 1;
}
int update(Product *p,int now){    
    int pick;
    list(p,now);
    printf("번호는(취소: 0)? ");
    scanf("%d",&pick);
    getchar();
    if(pick!=0){
    printf("새 이름은? ");
    scanf("%[^\n]s",p[pick-1].name);
    getchar();
    printf("새 설명은? ");
    scanf("%[^\n]s",p[pick-1].comment);
    getchar();
    printf("새 중량은? ");
    scanf("%s",p[pick-1].weight);
    getchar();
    printf("새 가격은? ");
    scanf("%d",&p[pick-1].price);
    printf("새 배송방법은? ");
    scanf("%d",&p[pick-1].delivery);
    }
    return 1;
}
int deletes(Product *p,int now){    
    int pick;
    int deleteok;
    list(p,now);
    printf("번호는 (취소:0)? ");
    scanf("%d",&pick);
    if(pick!=0){
        printf("정말로 삭제하시겠습니까?(삭제:1)");
        scanf("%d",&deleteok);
        if(deleteok==1){
            p[pick-1].price=-1;
        }
    }
    if(pick==0)return 0;
    return 1;
}
void save(Product *p,int now){      
    FILE *fp;
    fp=fopen("product.txt","wt");
        for(int i=0;i<now;i++){
        if(p[i].price==-1){
            continue;
        }
        else if(p[i].price!=-1){
        fprintf(fp,"%s\t%s\t%s\t%d\t%d\n",p[i].name,p[i].comment,p[i].weight,p[i].price,p[i].delivery);
        }
    }

    
    fclose(fp);
    return ;
}
int load(Product *p){             
int i;
FILE *fp;
fp=fopen("product.txt","rt");
if(fp==NULL){
    printf("파일 없음\n");
    return 0;
 }  else{
    for(i=0;i<20;i++){

        fscanf(fp,"%[^\t]s",p[i].name);
        if(feof(fp)){
            
            break;
        }
        fscanf(fp," %[^\t]s",p[i].comment);
        fscanf(fp," %s",p[i].weight);
        fscanf(fp," %d",&p[i].price);
        fscanf(fp,"%d",&p[i].delivery);
    }
 }
    fclose(fp);
    if(i>0){
    printf("=>로딩 성공!\n");
    }
    return i;
}
int searchname(Product *p,int now){ 
int scnt=0;
char search[20];
    printf("검색할 이름은? ");
    scanf("%[^\n]s",search);
    printf("Name comment weight price delivery\n");
    printf("================================\n");
    for(int i=0;i<now;i++){
    if(p[i].price==-1)continue;
    if(strstr(p[i].name,search)){
        scnt++;
        read1(p[i]);
    }
    
    }
    if(scnt==0){
        return 0;
    }
    return 1;

}
int searchprice(Product *p,int now){ 
int scnt=0;
int search;
    printf("검색할 가격은? ");
    scanf("%d",&search);
    printf("Name comment weight price delivery\n");
    printf("================================\n");
    for(int i=0;i<now;i++){
    if(p[i].price==-1)continue;
    if(p[i].price==search){
        scnt++;
        read1(p[i]);
    }
    }
    if(scnt==0){
        return 0;
    }
    return 1;
}
int searchdelivery(Product *p,int now){  
int scnt=0;
int search;
    printf("검색할 배송방법은? ");
    scanf("%d",&search);
    printf("Name comment weight price delivery\n");
    printf("================================\n");
    for(int i=0;i<now;i++){
    if(p[i].price==-1)continue;
    if(p[i].delivery==search){
        scnt++;
        read1(p[i]);
    }
    }
    if(scnt==0){
        return 0;
    }
    return 1;
}
void read1(Product p){            
if(p.price!=-1){
    
printf("%s %s %s %d %d\n",p.name,p.comment,
p.weight,p.price,p.delivery);
}
return ;
}
