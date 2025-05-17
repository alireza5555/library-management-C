#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
//linklist
typedef struct data{
char name [20];
   char  writer[20];
    char field[20];
    char history[30][20];
    int count;
}data;
typedef struct Node {
     data inf;
    struct Node* next;
}Node;

typedef struct stu{
    char name[20];
    char pass[20];
    char field[20];
    char req[20][20];
    char books[20][20];
}stu;
typedef struct Nod{
    stu prof;
   struct Nod *next;

}Nod;

Nod* createb(stu st);
void insfirstb( Nod**,stu );
void insendb( Nod** , stu );
void inspositionb( Nod** , stu st, int position);
void delfirstb( Nod** );
void delendb( Nod** );
void delpositionb( Nod** , int position);
void readinglinkb(Nod **  );
void writinglinkb(Nod **);

Node* create(data st);
void insfirst( Node** head,data st);
void insend( Node** head, data st);
void insposition( Node** head, data st, int position);
void delfirst( Node** head);
void delend( Node** head);
void delposition( Node** head, int position);
void readinglink(Node ** head );
void writinglink(Node **head);
void adddel(Node ** head);
void modify(Node ** head);
void printlink(Node **head);
void histadd(char find[],char student[]);
 void histsee(Node *temp);
 Node* pointer(int x);
 void deccount(char name1[20]);
  void calc(int x);
  void printfreq();
  Nod* filefinder();
 //
int logout();
int login(int x);
void menu(int x);
void menulib(int y);
void createstu();
void createlib();



    Nod* bhead =NULL;
 Node* head = NULL;
char major[20];
char pass[20],user[20];

int main(){



    readinglink(&head);
    readinglinkb(&bhead);

    printf("Hello, welcome to the library system!\n");
    while(1){
    menu(login(logout()));
    writinglink(&head);
    writinglinkb(&bhead);
    }
    
}

int logout(){
    int x;
    printf("\n***********************\n\n");
    printf("Choose your role:\n"); 
    printf("1. Student\n"); 
    printf("2. Librarian\n"); 
    printf("0. Exit\n"); 
    printf("Enter your choice:\n"); 
    while(1){ 
       scanf("%d", &x); 
       if(x == 0){ 
        writinglink(&head);
    writinglinkb(&bhead);
            exit(0); 
        } 
        else if(x == 1 || x == 2){ 
            
            return x;
            
        } 
        else{ 
            printf("please try again!\n"); 
        } 
    }
}

int login(int x){
    printf("\n***********************\n\n");
    char   realu[20], realp[20]; 
    FILE *p = NULL; 
    if(x == 1 ){
        p = fopen("student.dat", "rb"); 
                printf("Enter your username:\n"); 
        scanf("%s", user); 
        printf("Enter your password:\n"); 
        scanf("%s", pass);
        Nod* temp=bhead;
        while(temp!=NULL){
            if(strcmp(temp->prof.name,user)==0 && strcmp(temp->prof.pass,pass)==0){
                 printf("Welcome %s\n",user); 
                fclose(p);
                return x;
            }
            temp=temp->next;
        }
         fclose(p);
         printf("Username or Password is wrong please try again!\n");
    } 
    if(x == 2){ 
        p = fopen("librarian.txt","r"); 
    
    while(1){ 
        printf("Enter your username:\n"); 
        scanf("%s", user); 
        printf("Enter your password:\n"); 
        scanf("%s", pass);
        while(!feof(p)){ 
            fscanf(p,"%s %s", realu, realp); 
            if(strcmp(user,realu) == 0 && strcmp(pass,realp) == 0){
                
                printf("Welcome %s\n",user); 
                fclose(p);
            
                return x;  
            } 
        } 
        printf("Username or Password is wrong please try again!\n");
        fseek(p, 0, 0);
    } } 

}

void menu(int x){
    printf("\n***********************\n\n");
    int y; 
    if(x == 1){ 
       
        while(1){ 
             printf("Student menu:\n"); 
        printf("1. Request book\n"); 
        printf("2. List of your books\n"); 
        printf("3. Return books\n"); 
        printf("0. Logout\n"); 
        printf("Enter your choice:\n");
            scanf("%d", &y); 
            if(y == 0){ 
                return;
            } 
            else if(y == 1){
              printf("Avalible books are:\n");
              printlink(&head);
              printf("Enter book number:\nPrevious:0\n");
              int zz;
              scanf("%d",&zz);
              if(zz==0)continue;
              Node* temp=head;
            
              for (int i = 1;i<zz ; i++)
              {
                temp=temp->next;
              }
              if(temp->inf.count==0){
                printf("Not enough book\n");
            
                    continue;
              }
             
              Nod * temp2=filefinder();
               if(strcmp(temp->inf.field,temp2->prof.field)!=0 && strcmp(temp->inf.field,"general")!=0){
                printf("Field error\n");
                continue;
              }

              int j;
              for (j = 0; temp2->prof.req[j][0]!='\0'; j++);
             strcpy(temp2->prof.req[j],temp->inf.name);
              printf("the request was sent\n");
              

            }
           else if(y == 2){
                printf("List of your books:\n");
                Nod * temp=filefinder();
                for(int i=0 ;i<20;i++ ){
                   if(temp->prof.books[i][0]!='\0'){ printf("[%02d] %s\n",i+1,temp->prof.books[i]);}}
                    printf("any key to return\n");
                    char tt[10];
                    scanf("%s",tt);
                    
            }   
            else if(y == 3){
                      Nod * temp=filefinder();
                for(int i=0 ;i<20;i++ ){
                  if(temp->prof.books[i][0]!='\0'){ printf("[%02d] %s\n",i+1,temp->prof.books[i]);}}
               printf("Enter the book number that you want return\nPrevious:0\n");
               int z;
               scanf("%d",&z);
               if(z==0)continue;
               z--;
               char tempe[20];
                strcpy(tempe, temp->prof.books[z]);
               temp->prof.books[z][0]='\0';
               Node * temp2=head;
                while(strcmp(tempe,temp2->inf.name)!=0){
                    temp2=temp2->next;
                
                }
                temp2->inf.count++;
                printf("returned\n");
                 writinglink(&head);
                 writinglinkb(&bhead);
            }
            else{ 
                printf("please try again!\n"); 
            } 
        }
    }
    if(x == 2){ 
      
        while(1){ 
              printf("Librarian menu:\n"); 
        printf("1. See requests\n"); 
        printf("2. Add user\n"); 
        printf("3. Editing books\n"); 
        printf("0. Logout\n"); 
        printf("Enter your choice:\n"); 
            scanf("%d", &y); 
            if(y == 0){ 
           return;
            } 
            else if(y == 1||y == 2||y == 3){ 
                menulib(y);
            }
            else{ 
                printf("please try again!\n"); 
            } 
        } 
    }
}

void menulib(int y){
    printf("\n***********************\n\n");
    int x;
    if(y == 1){
        printfreq();
            printf("Choose request number to accept or decline req:\nPrevious:0\n");
            int z3;
            scanf("%d",&z3);
            if(z3==0)return;
            calc(z3);
            writinglink(&head);
            writinglinkb(&bhead);
    }
    else if(y == 2){
       
        while(1){
             printf("Add menu:\n");
        printf("1. Add student\n"); 
        printf("2. Add Librarian\n"); 
        printf("0. Pervious page\n"); 
        printf("Enter your choice:\n");
            scanf("%d", &x);
            if(x == 0){
             return;
            }
            else if(x == 1){
                createstu();
            }
            else if(x == 2){
                createlib();
            }
            else{
                printf("please try again!\n");
            }
        }
    }
    else if(y == 3){
      
        while(1){
              printf("Book editing menu:\n");
        printf("1. Add book & Delete book\n"); 
        printf("2. Change book information\n"); 
        printf("3. View book history\n");
        printf("0. Pervious page\n"); 
        printf("Enter your choice:\n"); 
            scanf("%d", &x); 
            if(x == 0){ 
               return;
            } 
            else if(x == 1){
                
                adddel(&head);
            }
            else if(x == 2){
                modify(&head);
            }
            else if(x == 3){
                printlink(&head);
                printf("Enter the book number which you want to view the history.\n");
                int ch;
                scanf("%d",&ch);
                Node *p =pointer(ch);
                if(p==NULL){
                printf("wrong number try again");
                continue;
                }
                histsee(p);
            }
            else{ 
                printf("please try again!\n"); 
            } 
        }
    }
}

void createlib(){
    printf("\n***********************\n\n");
    char user[20], pass[20], realu[20], realp[20];
    FILE *p = fopen("librarian.txt", "a+");
    int k = 2;
    while(k == 2){
        printf("Enter librarian Username:\n");
        scanf("%s", user);
        printf("Choose a Password:\n");
        scanf("%s", pass);
        printf("Confirm?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("0. pervious page\n");
        printf("Enter your choice:\n");
        scanf("%d", &k);
        if(k == 0){
            return;
        }
    }
    fprintf(p,"\n%s %s", user, pass);
    fclose(p);
    printf("New librarian has been added\n");

}

void createstu(){
    printf("\n***********************\n\n");
    FILE *p = fopen("student.dat", "ab+");
    int k = 2;
     stu one={
        .req={{'\0'}},
        .books={{'\0'}}
        
     };
    while(k == 2){
       
        printf("Enter student Username:\n");
        scanf("%s", one.name);
        printf("Enter student Field:");
        scanf("%s", one.field);
        printf("Choose a Password:\n");
        scanf("%s", one.pass);
        printf("Confirm?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("0. pervious page\n");
        printf("Enter your choice:\n");
        scanf("%d", &k);
        if(k == 0){
        
            return;
        }
    }
    insendb(&bhead,one);
     writinglinkb(&bhead);
    printf("New student has been added\n");
    
}

 Node* create(data st) {
     Node* newnode = (Node*)malloc(sizeof(Node));
    (*newnode).inf = st;
    newnode->next = NULL;
    return newnode;
}


void insfirst( Node** head,data st) {
     Node* newnode = create(st);
    newnode->next = *head;
    *head = newnode;
}


void insend( Node** head, data st) {
     Node* newnode = create(st);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
     Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}


void insposition( Node** head, data st, int position) {
     Node* newnode = create(st);
    if (position == 0) {
        insfirst(head,st);
        return;
    }
     Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("wrong position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}


void delfirst( Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
     Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void delend( Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
     Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delposition( Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
     Node* temp = *head;
    if (position == 0) {
        delfirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("wrong position\n");
        return;
    }
     Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
//end of link list
//reading and writing link list from file
   void readinglink(Node ** head ){
    FILE *p=fopen("database.dat","rb");
     data temp;
     int i=0;
    while (fread(&temp, sizeof(data), 1, p) == 1) {
    insposition(head, temp, i);
    i++;
}
    fclose(p);
   }
    void writinglink(Node **head){
            FILE *p=fopen("database.dat","wb");
            Node *temp= *head;
            while(temp!=NULL)
            {
                fwrite(&(temp->inf),sizeof(data),1,p);
                temp=temp->next;
            }
            fclose(p);
    }
//end r and w

//deleting and adding book
void adddel(Node ** head){
    int k=3;
    
    while(k){
        printf("Adding a book: 1\nDeleting a book: 2\nPrevious menu: 0\n");
    scanf("%d",&k);
  

   if(k==1){
   
        data inf={
            .history={{'\0'}}
            
        };
            printf("Enter name of the book\n");
            scanf("%s",inf.name);
            printf("Enter name of the writer\n");
             scanf("%s",inf.writer);
             printf("Enter field of the book\n");
              scanf("%s",inf.field);
              printf("Enter the number of the book\n");
                scanf("%d",&inf.count);
                    insend(head,inf);
                     printf("added\n");
                     writinglink(head);
   }
        else if(k==2) {
            printlink(head);
            printf("\nEnter book number that you want delete\n");
            int x;
           
            scanf("%d",&x);
             x--;
                delposition(head,x);
                
                printf("Deleted\n");
                
            }
           else if(k!=0){
            printf("invalid entry\n");}
 
}
return;
}
//
void modify(Node ** head){
        printlink(head);
            printf("\nEnter the number of book that you want to change the information\npreveious:0\n");
            int x,k=5; 
            data inff;
            scanf("%d",&x);
            if(x==0)return;
            Node *temp=*head;
                for (int i = 1; i < x; i++)
                {
                    temp=temp->next;
                }
                inff=temp->inf;
                while(k){
            printf("wich one you want to change?\nname: 1\nwritername: 2\nfield: 3\ncount: 4\n exit:0\n");
            scanf("%d",&k);
            switch(k){
                case 1:
                printf("Enter name\n");
                    scanf("%s",inff.name);
                        break;
                        case 2:
                          printf("Enter writername\n");
                    scanf("%s",inff.writer);
                            break;
                            case 3:
                              printf("Enter field name\n");
                    scanf("%s",inff.field);
                    break;
                    case 4:
                      printf("Enter a number\n");
                    scanf("%d",&inff.count);
                    break;
                    case 0:
                    k=0;
                    break;
                    default:
                    printf("invalid entry\n");
                    k=5;
            }
}
temp->inf=inff;
writinglink(head);
 return;
}
//print the link list
        void printlink(Node **head){
            Node *temp=*head;
              printf("     %-20s%-20s%-20s%-20s\n","Book name","Writer name","Field","count");

                for(int i=1;temp!=NULL;i++){
                    printf("[%02d] ",i);
                    printf("%-20s%-20s%-20s%-20d\n",temp->inf.name,temp->inf.writer,temp->inf.field,temp->inf.count);
                    temp=temp->next;
                }
        }

        //sabeghe
        void histadd(char find[],char student[])
                {
                    Node *temp=head;
                    while(strcmp(temp->inf.name,find)!=0){
                       temp= temp->next;
                    }
                    for (int i = 0; i < 30; i++)
                    {
                        if(strcmp(student,temp->inf.history[i]));
                    }
                    
                    int i;

                    for (i = 0;i < 30  ; i++){
                   if(temp->inf.history[i][0]=='\0') {strcpy(temp->inf.history[i],student);break;}}
                    
                }
                void histsee(Node *temp){int x=1;
                    for (int i = 0; i < 30  ; i++)
                    {
                       if(temp->inf.history[i][0]!='\0') {printf("%s\n",temp->inf.history[i]);
                        if(x)x=0;}
                    }
                    if(x)printf("List is empty\n\n");
                }

                Node * pointer(int x){
                    Node *temp=head;
                    while (--x)
                    {
                        temp=temp->next;
                        if (temp==NULL)
                        {
                            printf("wrong number\n");
                            return temp;
                        }
                        
                    }
                    return temp;
                }

//student profile link list
Nod* createb(stu st) {
     Nod* newnode = (Nod*)malloc(sizeof(Nod));
    (*newnode).prof = st;
    newnode->next = NULL;
    return newnode;
}


void insfirstb( Nod** head,stu st) {
     Nod* newnode = createb(st);
    newnode->next = *head;
    *head = newnode;
}


void insendb( Nod** head, stu st) {
     Nod* newnode = createb(st);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
     Nod* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}


void inspositionb( Nod** head, stu st, int position) {
     Nod* newnode = createb(st);
    if (position == 0) {
        insfirstb(head,st);
        return;
    }
     Nod* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("wrong position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}


void delfirstb( Nod** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
     Nod* temp = *head;
    *head = temp->next;
    free(temp);
}

void delendb( Nod** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
     Nod* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delpositionb( Nod** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
     Nod* temp = *head;
    if (position == 0) {
        delfirstb(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("wrong position\n");
        return;
    }
     Nod* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

 void readinglinkb(Nod ** bhead ){
    FILE *p=fopen("student.dat","rb");
     stu  temp;
     int i=0;
    while (fread(&temp, sizeof(stu), 1, p) == 1) {
    inspositionb(bhead, temp, i);
    i++;
}
    fclose(p);
   }
    void writinglinkb(Nod **head){
            FILE *p=fopen("student.dat","wb");
            Nod *temp= *head;
            while(temp!=NULL)
            {
                fwrite(&(temp->prof),sizeof(stu),1,p);
                temp=temp->next;
            }
            fclose(p);
    }

    Nod* filefinder(){
        Nod * temp= bhead;
        while(temp!=NULL && strcmp(user,temp->prof.name)!=0){
            temp=temp->next;
        }
        return temp;
    }
    
    void printfreq(){
        Nod* temp=bhead; int j=1;
        printf("      Username     Book requested\n");
    
            while(temp!=NULL){
               
                for(int i=0;i<20;i++ ){
               if(temp->prof.req[i][0]!='\0') {printf("[%02d]  %-13s%s\n",j,temp->prof.name,temp->prof.req[i]);
               j++;}
                }
                temp=temp->next;
            }
    }
   void calc(int x){
    int k=0;int i,z, con=1;
        Nod* temp=bhead;
        


        while(con){
        for ( i = 0;k<x&&i<20 ;i++)
        {
            if(temp->prof.req[i][0]!='\0'){z=i,k++;}
           
        }
        i=z;

        if(x==k){
            int z44;
            
            printf("Decline: 1\nAccept: 2\n");
            scanf("%d",&z44);
            if (z44==1)
            {
                printf("%d %s",i,temp->prof.name);
                temp->prof.req[i][0]='\0';
                printf("Declined\n");
                 
                con=0;
            }
            else if (z44==2)
            {int p;
                deccount(temp->prof.req[i]);
               for(p=0; temp->prof.books[p][0]!='\0';p++);
             
                strcpy(temp->prof.books[p],temp->prof.req[i]);
               histadd(temp->prof.req[i],temp->prof.name);
                 temp->prof.req[i][0]='\0';
                
                printf("Accepted\n");
                con=0;
            }
            else{ printf("invalid entry\n");
            con=0;}
            
        }
        temp=temp->next;

        }
        }

    void deccount(char name1[20]){
        Node* temp=head;
        while (strcmp(name1,temp->inf.name)!=0)
        {
            temp=temp->next;
        
        }
        temp->inf.count--;
    }
    
/*
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

struct book{
    char name[100];
    char author[100];
    char major[100];
    char history[100000];
    int a;
};

char user[50], pass[50], major[50];

int logout();
int login(int x);
void menu(int x);
void menulib(int y);
void createlib();
void createstu();
void booklist(int x);
void requests(char t[], int y);
void addbook(int x);
void returnbook();
void requestbook();
void deletebook();
void changebook();
void change(struct book b, int y, int x, char u[]);
void delete(struct book b);
int changerequest(char ur[], char mr[], struct book b, int y);
void bookhistory();
void requestlist(int x);

int main(){
    printf("Hello, welcome to the library system!\n");
    logout();
}

int logout(){
    int x;
    printf("\n***********************\n\n");
    printf("Choose your role:\n"); 
    printf("1. Student\n"); 
    printf("2. Librarian\n"); 
    printf("0. Exit\n"); 
    printf("Enter your choice:\n"); 
    while(1){ 
       scanf("%d", &x); 
       if(x == 0){ 
            exit(1); 
       }
       if(x == 1 || x == 2){
            login(x);
       }
       else{
            printf("please try again!\n"); 
       }
    }
}

int login(int x){
    printf("\n***********************\n\n");
    char realu[50], realp[50]; 
    FILE *p = NULL; 
    if(x == 1){ 
        p = fopen("student.txt", "r"); 
    } 
    if(x == 2){ 
        p = fopen("librarian.txt", "r"); 
    }
    while(1){ 
        printf("Enter your username:\n"); 
        scanf("%s", user); 
        printf("Enter your password:\n"); 
        scanf("%s", pass);
        while(!feof(p)){ 
            if(x == 1){
                fscanf(p,"%s %s %s", realu, realp, major);
            }
            if(x == 2){
                fscanf(p,"%s %s", realu, realp);
            } 
            if(strcmp(user, realu) == 0 && strcmp(pass, realp) == 0){
                printf("Welcome %s\n", user); 
                fclose(p);
                menu(x);
                return 1;
            } 
        } 
        printf("Username or Password is wrong please try again!\n");
        fseek(p, 0, 0);
    } 
}

void menu(int x){
    printf("\n***********************\n\n");
    int y;
    if(x == 1){ 
        printf("Student menu:\n"); 
        printf("1. Request books\n"); 
        printf("2. List of books\n"); 
        printf("3. Return books\n");
        printf("4. Requests tracking\n"); 
        printf("0. Logout\n"); 
        printf("Enter your choice:\n");
        while(1){ 
            scanf("%d", &y); 
            if(y == 0){ 
                logout(); 
            } 
            if(y == 1){
                requestbook();
            }
            if(y == 2){
                booklist(2);
            }
            if(y == 3){
                returnbook();
            }
            if(y == 4){
                requestlist(1);
            }
            else{ 
                printf("please try again!\n"); 
            } 
        }
    }
    if(x == 2){ 
        printf("Librarian menu:\n"); 
        printf("1. Requests\n"); 
        printf("2. Add user\n"); 
        printf("3. Editing books\n"); 
        printf("0. Logout\n"); 
        printf("Enter your choice:\n"); 
        while(1){ 
            scanf("%d", &y); 
            if(y == 0){ 
                logout(); 
            } 
            if(y == 1){
                requests("a", 0);
            }
            else if(y == 2||y == 3){ 
                menulib(y);
            }
            else{ 
                printf("please try again!\n"); 
            } 
        } 
    }
}

void menulib(int y){
    printf("\n***********************\n\n");
    int x;
    if(y == 2){
        printf("Add menu:\n");
        printf("1. Add student\n"); 
        printf("2. Add Librarian\n"); 
        printf("0. Pervious page\n"); 
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &x);
            if(x == 0){
               menu(2);
            }
            if(x == 1){
                createstu();
            }
            if(x == 2){
                createlib();
            }
            else{
                printf("please try again!\n");
            }
        }
    }
    if(y == 3){
        printf("Book editing menu:\n");
        printf("1. List of books\n");
        printf("2. Add books\n"); 
        printf("3. Change book information\n"); 
        printf("4. Delete book\n");
        printf("5. View book history\n");
        printf("0. Pervious page\n"); 
        printf("Enter your choice:\n");
        while(1){ 
            scanf("%d", &x); 
            if(x == 0){ 
                menu(2);
            }
            if(x == 1){
                booklist(4);
            }
            if(x == 2){
                addbook(0);
            }
            if(x == 3){
                changebook();
            }
            if(x == 4){
                deletebook();
            }
            if(x == 5){
                bookhistory();
                printf("Do you want to see another book history?\n");
                int k;
                while(1){
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("Enter your choice:\n");
                    scanf("%d", &k);
                    if(k == 1){
                        bookhistory();
                        printf("Do you want to see another book history?\n");
                    }
                    else if(k == 2){
                        menulib(3);
                    }
                    else{
                        printf("please try again!\n");
                    }
                }

            }
            else{ 
                printf("please try again!\n"); 
            } 
        }
    }
}

void createlib(){
    printf("\n***********************\n\n");
    char user1[50], pass[50], u[50], pa[50];
    int f = 0;
    FILE *q = NULL;
    FILE *p = NULL;
    int k = 2, x;
    while(1){
        while(k == 2){
            q = fopen("librarian.txt", "r");
            printf("Enter librarian Username:\n");
            scanf("%s", user1);
            printf("Choose a Password:\n");
            scanf("%s", pass);
            printf("Confirm?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("0. pervious page\n");
            printf("Enter your choice:\n");
            while(1){
                scanf("%d", &k);
                if(k == 1 || k == 2 || k == 0){
                    break;
                }
                printf("please try again!\n");
            }
            if(k == 0){
                fclose(p);
                menulib(2);
            }
        }
        while(!feof(q)){
            fscanf(q, "%s %s", u, pa);
            if(strcmp(user1, u) == 0){
                printf("This name has already been used\n");
                f = 1;
                break;
            }
        }
        fclose(q);
        if(f == 0){
            p = fopen("librarian.txt", "a");
            fprintf(p,"%s %s\n", user1, pass);
            fclose(p);
            printf("New librarian has been added\n");
        }
        f = 0;
        printf("Do you want to add another librarian?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &x);
            if(x == 1){
                k = 2;
                break;
            }
            if(x == 2){
                menulib(2);
            }
            else{
                printf("please try again!\n");
            }
        }
    }
}

void createstu(){
    printf("\n***********************\n\n");
    char user1[50], pass[50], major1[50], u[50], pa[50], m[50];
    FILE *q = NULL;
    FILE *p = NULL;
    int k = 2, x, f = 0;
    while(1){
        while(k == 2){
            q = fopen("student.txt", "r");
            printf("Enter student Username:\n");
            scanf("%s", user1);
            printf("Enter student Major:\n");
            scanf("%s", major1);
            printf("Choose a Password:\n");
            scanf("%s", pass);
            printf("Confirm?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("0. pervious page\n");
            printf("Enter your choice:\n");
            while(1){
                scanf("%d", &k);
                if(k == 1 || k == 2 || k == 0){
                    break;
                }
                printf("please try again!\n");
            }
            if(k == 0){
                fclose(p);
                menulib(2);
            }
        }
        while(!feof(q)){
            fscanf(q, "%s %s %s", u, m ,pa);
            if(strcmp(user1, u) == 0){
                printf("This name has already been used\n");
                f = 1;
                break;
            }
        }
        fclose(q);
        if(f == 0){
            p = fopen("student.txt", "a");
            fprintf(p, "%s %s %s\n", user1, pass, major1);
            fclose(p);
            printf("New student has been added\n");
        }
        f = 0;
        printf("Do you want to add another student?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &x);
            if(x == 1){
                k = 2;
                break;
            }
            if(x == 2){
                fclose(p);
                menulib(2);
            }
            else{
                printf("please try again!\n");
            }
        }
    }
}

void booklist(int x){
    struct book b;
    FILE *p = fopen("booklist.txt", "r");
    printf("\n***********************\n\n");
    if(x == 3 || x == 4){
        printf("List of books:\n");
        printf("   %-15s %-15s %-15s %-15s\n", "Title:", "Author:", "BookMajor:", "Count:");
    }
    else{
        printf("List of available books for you:\n");
        printf("   %-15s %-15s %-15s\n", "Title:", "Author:", "BookMajor:");
    }
    while(!feof(p)){
        fscanf(p, "%s %s %s %d %s", b.name, b.author, b.major, &b.a, b.history);
        if(feof(p)){
            break;
        }
        if(x == 3 || x == 4){
            printf("   %-15s %-15s %-15s %-15d\n", b.name, b.author, b.major, b.a);
        }
        else if(b.a > 0 && ((strcmp(b.major, major) == 0 || strcmp(b.major, "general") == 0))){
            printf("   %-15s %-15s %-15s\n", b.name, b.author, b.major);
        }
    }
    fclose(p);
    if(x == 1 || x == 3){
        return;
    }
    printf("Press any key to continue:\n");
    char i = getchar();
    i = getchar();
    if(x == 4){
        menulib(3);
    }
    menu(1);
}

void requests(char t[], int y){
    struct book a, b, d;
    char u[50], m[50], s[50], ur[50], mr[50], u2[50];
    int x, c = 0;
    if(y == 0){
        printf("\n***********************\n\n");
    }
    FILE *p = fopen("requests.txt", "r");
    FILE *q = fopen("booklist.txt", "r");
    while(1){
        printf("Requests:\n");
        printf("   %-15s %-15s %-15s %-15s %-15s %-15s\n", "Student", "StudentMajor", "Title", "Author", "BookMajor", "Status");
        while(!feof(p)){
            fscanf(p, "%s %s %s %s %s %s", u, m, b.name, b.author, b.major, s);
            if(feof(p)){
                break;
            }
            printf("   %-15s %-15s %-15s %-15s %-15s %-15s\n", u, m, b.name, b.author, b.major, s);
        }
        fseek(p, 0, 0);
        printf("Do you want to accept or reject %s request?\n", t);
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &x);
            if(x == 1){
                break;
            }
            if(x == 2){
                menu(2);
            }
            else{
                printf("please try again!\n");
            }
        }
        while(1){
            printf("Enter student Username:\n");
            scanf("%s", u);
            printf("Enter the name of the book:\n");
            scanf("%s", b.name);
            printf("Enter the name of the book's author:\n");
            scanf("%s", b.author);
            while(!feof(q)){
                fscanf(q, "%s %s %s %d %s", d.name, d.author, d.major, &d.a, d.history);
                if(strcmp(b.name, d.name) == 0 && strcmp(b.author, d.author) == 0){
                    fclose(q);
                    break;
                }
            }
            if(d.a > 0){
                while(!feof(p)){
                    fscanf(p, "%s %s %s %s %s %s", ur, mr, a.name, a.author, a.major, s);
                    if(strcmp(u, ur) == 0 && strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0){
                        fclose(p);
                        c = 1;
                        int i = changerequest(ur, mr, b, 1);
                        if(i == 1){
                            strcat(d.history, "|");
                            strcat(d.history, u);
                            change(d, 4, 1, "hello");
                        }
                        if(i == 2){
                            printf("This request has already been accepted\n");
                        }
                        if(i == 3){
                            printf("This request has already been rejected\n");
                        }
                        if(x == 4){
                            printf("This request has already been returned\n");
                        }
                        break;
                    }
                }
            }
            else{
                fclose(p);
                int i = changerequest(u, mr, d, 2);
                if(i == 2){
                    printf("This request has already been accepted\n");
                }
                else if(i == 3){
                    printf("This request has already been rejected\n");
                }
                else if(i == 4){
                    printf("This request has already been returned\n");
                }
                else{
                    printf("This book is no longer available\n");
                }
                c = 1;
            }
            if(c == 0){
                fclose(p);
                printf("You entered incorrect information please try again!\n");
            }
            requests("another", 1);
        } 
    }
}

void addbook(int x){
    int k = 2, c = 0;
    struct book a, b;
    if(x != 1){
        printf("\n***********************\n\n");
    }
    while(k){
        printf("Enter title of book:\n");
        scanf("%s", b.name);
        printf("Enter book author:\n");
        scanf("%s", b.author);
        printf("Enter book major:\n");
        scanf("%s", b.major);
        printf("Please enter the number of books:\n");
        while(1){
            scanf("%d", &b.a);
            if(b.a < 0){
                printf("please try again!\n");
                continue;
            }
            break;
        }
        printf("Confirm?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("0. pervious page\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &k);
            if(k == 0){
                menu(2);
            }
            if(k == 1){
                break;
            }
            if(k == 2){
                addbook(1);
            }
            else{
                printf("please try again!\n");
            }
        }
        if(k == 1){
            break;
        }
    }
    FILE *p = fopen("booklist.txt", "r");
    while(!feof(p)){ 
        fscanf(p,"%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history); 
        if(strcmp(b.name ,a.name) == 0 && strcmp(b.author ,a.author) == 0){
            c = 1;
            fclose(p);
            change(a, 6, b.a, "hello");
            break;
        } 
    }
    if(c == 0){
        fclose(p);
        p = fopen("booklist.txt", "a");
        strcpy(b.history, "History:");
        fprintf(p, "%s %s %s %d %s\n", b.name, b.author, b.major, b.a, b.history);
        fclose(p);
    }
    printf("Book added successfully\n");
    printf("Do you want to add another book?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice:\n");
    while(1){
        scanf("%d", &k);
        if(k == 1){
            addbook(1);
        }
        if(k == 2){
            menulib(3);
        }
        else{
            printf("please try again!\n");
        }
    }
}

void returnbook(){
    char u[50], m[50], s[50]; 
    struct book a, b, c;
    int x = 0, k, f = 0;
    FILE *p = NULL;
    FILE *q = NULL;
    printf("\n***********************\n\n");
    while(1){ 
        p = fopen("booklist.txt", "r");
        q = fopen("requests.txt", "r");
        requestlist(2);
        printf("Please enter the name of the book you want to return:\n");
        scanf("%s", b.name);
        printf("Please enter the name of the author of the book you want to return:\n");
        scanf("%s", b.author);
        while(!feof(q)){
            fscanf(q, "%s %s %s %s %s %s", u, m, a.name, a.author, a.major, s);
            if(strcmp(user, u) == 0 && strcmp(s, "Accepted") == 0 && strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0){
                f = 1;
                break;
            }
        }
        fclose(q);
        while(!feof(p)){ 
            fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history); 
            if(strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0 && f == 1 && (strcmp(major, a.major) == 0 || strcmp("general", a.major) == 0)){
                fclose(p);
                change(a, 5, 1, "hello");
                changerequest(user, major, a, 3);
                printf("The book was successfully returned\n"); 
                x = 1;
                break;
            } 
        }
        if(x == 0){ 
            printf("You entered the wrong book or author name please try again!\n");
            fclose(p);
        }
        x = 0;
        printf("Do you want to return another book?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &k);
            if(k == 2){

                menu(1);
            }
            if(k == 1){
                break;
            }
            else{
                printf("please try again!\n");
            }
        }
    }
}

void requestbook(){
    int x = 0, k, y = 0;
    struct book a, b;
    FILE *p = fopen("booklist.txt", "r");
    FILE *q = fopen("requests.txt", "a");
    while(1){ 
        booklist(1);
        printf("Please enter the name of the book you are looking for:\n");
        scanf("%s", b.name);
        printf("Please enter the name of the author of the book you are looking for:\n");
        scanf("%s", b.author);
        while(!feof(p)){ 
            fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history); 
            if(strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0){
                if(a.a == 0){
                    printf("This book is currently unavailable\n");
                }
                if(strcmp(major, a.major) == 0 || strcmp("general", a.major) == 0){
                    fprintf(q, "%s %s %s %s %s %s\n", user, major, a.name, a.author, a.major, "Unknown");
                    printf("Your request has been registered\n"); 
                    x = 1;
                    break;
                }
                else{
                    printf("This book is not for your major please try again!\n");
                    x = 1;
                    break;
                } 
            } 
        }
        if(x == 0){ 
            printf("You entered the wrong book or author name please try again!\n");
        }
        x = 0;
        fseek(p, 0, 0);
        printf("Do you have another book request?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &k);
            if(k == 2){
                fclose(p);
                fclose(q);
                menu(1);
            }
            if(k == 1){
                break;
            }
            else{
                printf("please try again!\n");
            }
        }
    }
}

void deletebook(){
    struct book a, b;
    int x = 0, k;
    FILE *p = NULL;
    while(1){
        booklist(3);
        p = fopen("booklist.txt", "r");
        printf("Please enter the name of the book you want to delete:\n");
        scanf("%s", b.name);
        printf("Please enter the name of the author of the book you want to delete:\n");
        scanf("%s", b.author);
        while(!feof(p)){
            fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history);
            if((strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0)){
                fclose(p);
                delete(a);
                x = 1;
                break;
            }
        }
        if(x == 0){
            printf("You entered the wrong book or author name please try again!\n");
            fclose(p);
        }
        x = 0;
        printf("Do you want to delete another book?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &k);
            if(k == 2){
                menulib(3);
            }
            if(k == 1){
                break;
            }
            else{
                printf("please try again!\n");
            }
        }
    }
}

void changebook(){
    struct book a, b;
    int x = 0, k, y;
    booklist(3);
    FILE *p = NULL;
    while(1){
        booklist(3);
        p = fopen("booklist.txt", "r");
        printf("Please enter the name of the book you want to edit:\n");
        scanf("%s", b.name);
        printf("Please enter the name of the author of the book you want to edit:\n");
        scanf("%s", b.author);
        while(!feof(p)){
            fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history);
            if((strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0)){
                printf("Which part of the book do you want to edit?\n");
                printf("1. Specifications\n");
                printf("2. Number of books\n");
                printf("3. Both of them\n");
                printf("Enter your choice:\n");
                while(1){
                    scanf("%d", &y);
                    if(y == 1 || y == 2 || y == 3){
                        break;
                    }
                    else{
                        printf("please try again!\n");
                    }
                }
                fclose(p);
                change(a, y, 0, "hello");
                x = 1;
                break;
            }
        }
        if(x == 0){
            printf("You entered the wrong book or author name please try again!\n");
            fclose(p);
        }
        x = 0;
        printf("Do you want to edit another book?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &k);
            if(k == 2){
                menulib(3);
            }
            if(k == 1){
                break;
            }
            else{
                printf("please try again!\n");
            }
        }
    }
}

void change(struct book b, int y, int x, char u[]){
    struct book a, c;
    c = b;
    if(y == 1 || y == 3){
        printf("Please enter the new book title:\n");
        scanf("%s", c.name);
        printf("Please enter the name of the new book author:\n");
        scanf("%s", c.author);
        printf("Please enter the new major of the book:\n");
        scanf("%s", c.major);
    }
    if(y == 2 || y == 3){
        printf("Please enter the new number of books:\n");
        scanf("%d", &c.a);
    }
    if(y == 4){
        c.a--;
    }
    if(y == 5){
        c.a++;
    }
    if(y == 6){
        c.a += x;
    }
    FILE *p = fopen("booklist.txt", "r");
    FILE *q = fopen("temp.txt", "w");
    int d = 0;
    while(!feof(p)){
        fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history);
        if(feof(p)){
            break;
        }
        if(strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0){
            d = 1;
            fprintf(q, "%s %s %s %d %s\n", c.name, c.author, c.major, c.a, c.history);
            continue;
        }
        fprintf(q, "%s %s %s %d %s\n", a.name, a.author, a.major, a.a, a.history);
    }
    fclose(p);
    fclose(q);
    if(d){
        remove("booklist.txt");
        rename("temp.txt", "booklist.txt");
        if(y == 1 || y == 2 || y == 3){
            printf("The book was successfully edited\n");
        }
    } else {
        remove("temp.txt");
    }
    return;
}

void delete(struct book b){
    struct book a;
    FILE *p = fopen("booklist.txt", "r");
    FILE *q = fopen("temp.txt", "w");
    int c = 0;
    while(!feof(p)){
        fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history);
        if(feof(p)){
            break;
        }
        if(strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0){
            c = 1;
            continue;
        }
        fprintf(q, "%s %s %s %d %s\n", a.name, a.author, a.major, a.a, a.history);
    }
    fclose(p);
    fclose(q);
    if(c){
        remove("booklist.txt");
        rename("temp.txt", "booklist.txt");
        printf("The book was successfully deleted\n");
    } else {
        remove("temp.txt");
    }
    return;
}

int changerequest(char ur[], char mr[], struct book b, int y){
    char u[50], m[50], s[50], *sr;
    struct book a;
    int x, d = 0;
    if(y == 1){
        printf("1. Accept\n");
        printf("2. Reject\n");
        printf("Enter your choice:\n");
        while(1){
            scanf("%d", &x);
            if(x == 1){
                sr = "Accepted";
                break;
            }
            if(x == 2){
                sr = "Rejected";
                break;
            }
            else{
                printf("please try again!\n");
            }
        }
    }
    if(y == 2){
        sr = "Rejected";
    }
    if(y == 3){
        sr = "Returned";
    }
    FILE *p = fopen("requests.txt", "r");
    FILE *q = fopen("temp.txt", "w");
    while(!feof(p)){
        fscanf(p, "%s %s %s %s %s %s", u, m, a.name, a.author, a.major, s);
        if(feof(p)){
            break;
        }
        if(strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0 && strcmp(ur, u) == 0){
            d = 1;
            if(strcmp(s, "Accepted") == 0 && y != 3){
                fclose(p);
                fclose(q);
                remove("temp.txt");
                return 2;
            }
            if(strcmp(s, "Returned") == 0){
                fclose(p);
                fclose(q);
                remove("temp.txt");
                return 4;
            }
            if(strcmp(s, "Rejected") == 0 && strcmp(sr, "Rejected") == 0){
                fclose(p);
                fclose(q);
                remove("temp.txt");
                return 3;
            }
            fprintf(q, "%s %s %s %s %s %s\n", u, m, a.name, a.author, a.major, sr);
            continue;
        }
        fprintf(q, "%s %s %s %s %s %s\n", u, m, a.name, a.author, a.major, s);
    }
    fclose(p);
    fclose(q);
    if(d){
        remove("requests.txt");
        rename("temp.txt", "requests.txt");
        if(x == 1 && y == 1){
            printf("Request successfully accepted\n");
            return 1;
        }
        if(x == 2 && y == 1){
            printf("Request successfully rejected\n");
            return 0;
        }
    } 
    else {
        remove("temp.txt");
    }
    return 0;
}

void bookhistory(){
    struct book a, b;
    int c = 0;
    char *h;
    FILE *p = NULL;
    booklist(3);
    while(1){
        p = fopen("booklist.txt", "r");
        printf("Enter the name of the book:\n");
        scanf("%s", b.name);
        printf("Enter the name of the book's author:\n");
        scanf("%s", b.author);
        while(!feof(p)){
            fscanf(p, "%s %s %s %d %s", a.name, a.author, a.major, &a.a, a.history);
            if(strcmp(b.name, a.name) == 0 && strcmp(b.author, a.author) == 0){
                c = 1;
                fclose(p);
                break;
            }
        }
        if(c == 0){
            printf("You entered the wrong book or author name please try again!");
        }
        if(c == 1){
            break;
        }
    }
    printf("%s %s ", a.name, a.author);
    h = strtok(a.history, "|");
    while(h != NULL){
        printf("%s\n", h);
        h = strtok(NULL, "|");
    }
    return;
}

void requestlist(int x){
    struct book b;
    char u[50], m[50], s[50];
    if(x == 1){
        printf("\n***********************\n\n");
        printf("Your requests:\n");
        printf("   %-15s %-15s %-15s %-15s %-15s %-15s\n", "Student", "StudentMajor", "Title", "Author", "BookMajor", "Status");
    }
    FILE *p = fopen("requests.txt", "r");
    if(x == 2){
        printf("Books you currently have:\n");
        printf("   %-15s %-15s %-15s\n", "Title", "Author", "BookMajor");
    }
    while(!feof(p)){
        fscanf(p, "%s %s %s %s %s %s", u, m, b.name, b.author, b.major, s);
        if(feof(p)){
            break;
        }
        if(strcmp(user, u) == 0 && x == 1){
            printf("   %-15s %-15s %-15s %-15s %-15s %-15s\n", u, m, b.name, b.author, b.major, s);
        }
        if(strcmp(user, u) == 0 && x == 2 && strcmp(s, "Accepted") == 0){
            printf("   %-15s %-15s %-15s\n", b.name, b.author, b.major);
        }
    }
    if(x == 1){
        fclose(p);
        printf("Press any key to continue:\n");
        char i = getchar();
        i = getchar();
        menu(1);
    }
}
*/