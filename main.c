#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void welcomemessage();
void addbook();
void createit();
void searchbook();
int isfilexist();
void viewbook();
int valid_date(int ,int ,int );
void issued_book();
void display_information();
typedef struct user
{
   char username[15];
   char password[10];
    int d;
    int m;
    int y;
    char s_book[50];
}information;
information us_in;
typedef struct book
{
char bname[50];
char auname[50];
float price;
int quantity;
}BOOK;
BOOK a;
FILE *fp;
int main(void) {
welcomemessage();
int key,status;
char key_s;
int check,flg;
while(1){
flg=0;
printf("\n*================================================================================================*");
printf
("\n*                         #################### MENU #####################                        *");
printf("\n*================================================================================================*");
printf("\n*                         #########FACILITIES FOR LIBRARIAN ########                             *");
printf("\n*================================================================================================*");
printf
("\n* 1.To check library file exist or not                                                           *");
printf
("\n* 2.To create library                                                                            *");
printf
("\n* 3.To add new book in library                                                                   *");
printf
("\n* 4.TO dislay list of all books and total number of books in library                             *");
printf
("\n* 5.TO search book from library                                                                  *");
printf
("\n* 6.To display User's information                                                                *");
printf("\n*================================================================================================*");
printf("\n*                       ####### FACILITIES FOR STUDENTS #######                                  *");
printf("\n*================================================================================================*");
printf("\n* A.TO search book from library                                                                  *");
printf("\n* B.TO dislay list of all books and total number of books in library                             *");
printf("\n* C.Update Username And Password                                                                 *");
printf("\n*================================================================================================*");
//to check whether user is librarian or student
printf("\n\n####### If you are librarian enter 1 else eneter 0#######: ");
scanf("%d",&check);
if(check==1)
{
  printf("\n\nIF you are librarian then enter any key from facility for librarian: ");
  scanf("%d",&key);
  flg=1;
}
else
{ 
  if(check==0)
  { 
    printf("\n\nIF you are student then enter any key from facility for students: "); 
    while ((getchar()) != '\n');
    scanf("%c",&key_s);
  }
  else
  {
    printf("\nINVALID INPUT PLEASE TRY AGAIN!");
    printf("\n########################## THANK YOU!###############################");
    continue;
  } 
}
//to break the loop
if(key>6 || key_s>'C')
{
  printf("\n\nINVALID INPUT!");
  printf("\n\n########Thank YOU!########");
  break;
}
else{ 
if(flg==1)
{ 
    switch(key)
    {
        case 1:
                status=isfilexist();
                if(status==0)
                  printf("\nfile not exist");
                else
                    printf("\nfile exist");
                break;
        case 2:
                createit();
                break;
        case 3:
                addbook();
                break;
        case 4:
                viewbook();
                break;
        case 5:
                searchbook();
                break; 
        case 6:
                display_information(); 
                break; 
        default:
                printf("\nTHANK YOU");
                break; 

      }
}
else
{
    switch(key_s)
    {
        case 'A':
                  searchbook();
                  break;
        case 'B':
                  viewbook();
                  break;
        case 'C':
                  issued_book();
                  break; 
         default :
                  printf("\nTHANK YOU");
                  break; 
    }
} 
}
}
}

void welcomemessage()
{
printf("\t\t\t              #########################################################\n");
printf("\t\t\t              #                                                       #\n");
printf("\t\t\t              ################# WELCOME TO E-LIBRARY ##################\n");
printf("\t\t\t              #                                                       #\n");
printf("\t\t\t              #########################################################");
}
void createit()
{
  int n,i;
  fp=fopen("data.txt","w");
  printf("\nEnter Number of books you want in library: ");
  scanf("%d",&n);
  struct book a[n];
  for(i=0;i<n;i++)
  {
    while ((getchar()) != '\n');
    printf("\nEnter name of the book: ");
    gets(a[i].bname);
    printf("\nEnter name of the auther: ");
    gets(a[i].auname);
    printf("\nEnter price of the book: ");
    scanf("%f",&a[i].price);
    printf("\nEnter quantity of book: ");
    scanf("%d",&a[i].quantity);
    fseek(fp,0,SEEK_SET);
    fwrite(&a,sizeof(a),1,fp);
  }
  fclose(fp);
}
int isfilexist()
{
    int status=1;
    fp=fopen("data.txt","r");
    if(fp==NULL)
    {
      status=0;
    }
    return status;
}

void viewbook(void) {
int found=0;
int i = 0, j=0;

fp = fopen("data.txt", "rb");
if(fp == NULL)
{
  printf("File is not opened\n");
  exit(1);
}
printf("\n       ############################## Book List ####################################        \n");
printf("\n*================================================================================================*");
printf("\n*Book Name\t\t\t                       *Auther Name\t\t     *Book Price\t   *Book Quantity*"); 
printf("\n*================================================================================================*");
while (fread(&a, sizeof(a), 1, fp)) {

printf("\n%-40s\t%-20s\t %-3.2f\t        %3d",a.bname,a.auname,a.price,a.quantity);

found=1;
j++;
i = i + a.quantity;
}
if(!found)
{
    printf("\n\t\t\tNo Record");
}
printf("\n\n                        **********Total Books =%d**********                         ", j);
fclose(fp);

}
void searchbook(void){

char bname[50];
int flag=0;
char add[20];
FILE *fp=NULL;
fp = fopen("data.txt","rb");
gets(add);
printf("\nEnter the Title of book that want to search:");
gets(bname);
if(fp==NULL){
  printf("File cannot be open\n");
}

while (fread (&a, sizeof(a), 1, fp))
{
  if(!strcmp(a.bname,bname))
  {
    flag = 1;
    break;
  }
}
if(flag==1){
  printf("\n*================================================================================================*");
  printf("\n*Book name\t\t\t                       *Auther name\t\t     *Book Price\t     *Book Quantity");
  printf("\n*================================================================================================*");  
  
      printf("\n%-40s\t%-20s\t %-3.2f\t    %3d",a.bname,a.auname,a.price,a.quantity);
    
}


if(flag==0){
  printf("Book is not available");
}

fclose(fp);
} 
void addbook() {
printf("\n============= PLEASE ADD NEW BOOK DETAILS ================");
char add[20];
int quantity;
FILE *fp;

printf("\n\nNumber of book to insert:");
scanf("%d", &quantity);

struct book a[quantity];
int i;

fp = fopen("data.txt", "a+");

for (i = 0; i < quantity; i++) 
{
  gets(add);
  printf("Title:");
  gets(a[i].bname);

  printf("Author:");
  gets(a[i].auname);

  printf("Price:");
  scanf("%f", &a[i].price);

  printf("Quantity:");
  scanf("%d", &a[i].quantity);

  printf("\n");
}
fwrite(a, sizeof(a) , 1, fp);
fclose(fp);
printf("\n\n---NEW BOOK DETAILS WAS SUCCESFULLY ADDED---\n\n");
}
void issued_book()
{
   FILE *fp=NULL;
   FILE *fr;
   FILE *f;
   f=fopen("user_information.txt","a");
   int flag=0,flg1=0;
   
   int check;
   fp = fopen("data.txt","rb");
   printf("enter your new username :-");
    scanf("%s",us_in.username);
    printf("\nenter yopur new password ;-");
    scanf("%s",us_in.password);
    while(1){
    printf("\nENTER THE DATE TO RETURN BOOK(first enter date next month then year):");
     scanf("%d%d%d",&us_in.d,&us_in.m,&us_in.y);
    check=valid_date(us_in.d ,us_in.m ,us_in.y);
    if(check==1)
    {
      flg1=1;
      
     
      break;
    }
    else
    {
      printf("\nDate is invalid Please enter valid date");
       
    }}
    
    printf("\n************* Data saved succesfully*************");
  
   while ((getchar()) != '\n');
   printf("\nEnter name of the book you want: ");
   gets(us_in.s_book);
    if(fp==NULL){

    printf("File cannot be open\n");
   }


   while (fread (&a, sizeof(a), 1, fp))
    {
        if(strcmp(a.bname,us_in.s_book)==0)
        {
            if(a.quantity==0)
            {
              printf("\n#####Book is not available now");
             
            }
            else
            {
              a.quantity=a.quantity-1;
              flag = 1;
                                      
            }
            break;
        }
    }
 
     
  
  if(flg1==1&&flag==1)
  {
     fseek(f,0,SEEK_SET) ;
    
     fwrite(&us_in,sizeof(us_in),1,f);
     printf("\n######BOOk ISSUED SUCCESFULLY######");  
  }
  else
    printf("\n********** Boook is Not found**********");
  fclose(fp);
  fclose(f);
}
void display_information()
{
    int i=1;
    FILE *fr;
    fr=fopen("user_information.txt","r");
    printf("\n\n                     #############User Information#########                              ");
    printf("\n*================================================================================================*");
    printf("\n*sr.no\t\t    *username\t\t  *password\t\t   *return date\t\t *book name                  *");
    printf("\n*================================================================================================*");
  while(fread(&us_in, sizeof(us_in), 1, fr))
  {
    printf("\n\n%d\t        %-10s\t    %-10s\t    \t%d/%d/%d\t",i,us_in.username,us_in.password,us_in.d,us_in.m,us_in.y);
    printf("\t\t%-40s",us_in.s_book);
    i++;
  }
  fclose(fr);
  
}
int valid_date(int d,int m,int y)
{

if(y>0 && y<9999)
{
if(m>=1 && m<=12)
{
if((d>=1 && d<=31) && (m==1 || m==3|| m==5 || m==7||m==8 || m==10||m==12 ))
  return (1);
else if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11))
return 1;
else if((d>=1 && d<=29) && (m==2) &&((y%400==0|| y%4==0) &&(y%100!=0)))
return 1;
else if((d>=1 && d<=28) && (m==2) &&(y%4==0) && (y%100==0))
return 1;
else if((d>=1 && d<=28) && (m==2) && (y%4!=0))
return 1;
else{
return 0;}
}
else 
{
return 0;
} 

} 
else
{
return 0;
}
}
