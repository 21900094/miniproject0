typedef struct{
    char name[30];       
    char comment[100];   
    char weight[30];     
    int price;           
    int delivery;        
}Product;
int add(Product *p,int now);        
int list(Product *p,int now);      
int update(Product *p,int now);     
int deletes(Product *p,int now);    
void save(Product *p,int now);      
int load(Product *p);             
int searchname(Product *p,int now); 
int searchprice(Product *p,int now); 
int searchdelivery(Product *p,int now);  
void read1(Product p);
