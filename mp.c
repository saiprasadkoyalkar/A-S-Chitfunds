#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Register();
void Login();
void Chits();
void join();
void creat();
void Users();
void prof(char name[100]);
void Paychits();
void pay_continue();
void display();
char str1[100];
char txtfile[100]=".txt";
void Notifications();
void chit_info();

void main()
{
		int i;
        printf("\n\t\t\t**A&S CHIT FUND APP**\n\n");
        printf("\t\t1.Login\n");
        printf("\t\t2.Sign up\n");
        printf("\t\tEnter your option:");
        scanf("%d",&i);
		if(i==1)
		{
			Login();
		}
        else if(i==2)
		{
			Register();
        }
        else
        {
            printf("please enter valid input:");
        }
        

}
void Register(){
     char name[100],pass[100],pass2[100],t[100],mail[100],phn[100];
     char occ[100],add[100];
    FILE *ptr,*tptr;
	printf ("Enter your name:") ;
	scanf("%s", name);
    strcpy(str1,name);
	strcpy(t,name);
	strcat(t,txtfile);
	printf("Enter password:");
	scanf("%s",pass);
    printf("confirm the password:");
    scanf("%s",pass2);
    if(strcmp(pass,pass2)==0)
    {
        tptr=fopen(t,"w");
	    fclose(tptr);
        ptr = fopen("usernames.txt", "a");
        fprintf(ptr,"%s\n",name);
        fprintf(ptr,"%s\n",pass);
        fclose(ptr);
        printf("Enter your mail:");
        scanf("%s",mail);
        printf("Enter your mobile num:");
        scanf("%s",phn);
        printf("Enter your occupation:");
        scanf("%s",occ);
        printf("Enter your address:");
        scanf("%s",add);
        ptr=fopen("prof.txt","a");
        fprintf(ptr,"%s\n",name);
        fprintf(ptr,"%s\n",mail);
        fprintf(ptr,"%s\n",phn);
        fprintf(ptr,"%s\n",occ);
        fprintf(ptr,"%s\n",add);
        fclose(ptr);
         printf("your account created successfully\n");
        display();
    }
    else
    {
        printf("pls..enter confirm password correctly\n");
        Register();
    }
    

}

void Login()
{
        char name[100],pass[100],temp[100];
        int flag=0;
         FILE *ptr;
        printf("Enter username:");
        scanf("%s",name);
        strcpy(str1,name);
        strcat(name,"\n");
        printf("Enter Password:");
        scanf("%s",pass);
        strcat(pass,"\n");
	 ptr = fopen("usernames.txt", "r");
	 while(fgets(temp,sizeof(temp),ptr)){
        if(strcmp(temp,name)==0){
            fgets(temp,sizeof(temp),ptr);
             if(strcmp(temp,pass)==0){
                flag=1;
                 display();
                 break;
             }
        }
	 }
	 if(flag==0){
        printf("pls enter your credentials correctly \n");
        Login();
	 }

}
void display()
{
	 int choose;
                printf("**********\n");
                printf("1.Chits\n");
                printf("2.Users\n");
                printf("3.paychits\n");
                printf("4:exit\n");
                printf("Enter your option in main menu:");
                scanf(" %d",&choose);
                if(choose==1)
				{
					Chits();
				}
                else if(choose==2)
				{
					Users();
                }
                else if(choose==3)
				{
					Paychits();
                }
                else
				{
						printf("Bye...!");
                        exit(0);
				}
}
void Chits()
{
        char c,s[100],temp[100];
        int count=0;
        FILE *ptr1,*ptr2;
        strcpy(s,str1);
        strcat(s,txtfile);
        ptr1=fopen(s,"r");
        printf("These are your chits joined till now:\n");
        printf("<--------START--------->\n");
        while(fgets(temp,sizeof(temp),ptr1)){
            count++;
            if(count%2!=0)
            {
                printf("%s  ",temp);
            }
            else
            {
            }
            
        }
       fclose(ptr1);
       printf("\n<---------STOP-------->\n");
        printf("A.join\nB.create\nC.chit_info\nZ.Else go to Main menu\n");
        printf("Enter your option:");
	    scanf(" %c",&c);

		if(c=='A')
		{
			join();
		}
        if(c=='B')
		{
			creat();
		}
        if(c=='C')
		{
			chit_info();
		}
		if(c=='Z')
		{
			display();
		}

}
void join()
{
        char str2[100],temp[100],t[100],s[100],m[100],p[100];
        int count=0,total,amt,new=0,option;
        char d;
        FILE *ptr1,*ptr2,*ptr3,*ptr4;
        printf("<--------START--------->\n");
        printf("\nThese are total chits in the market:\n");
		ptr1 = fopen("allchits.txt", "r");
        while(fgets(temp,sizeof(temp),ptr1))
        {
            printf("%s",temp);
        }
        fclose(ptr1);
        printf("<-------STOP---------->\n");
		printf("\nSelect\n1.Cotinue..joining process\n2.Main Menu:");
        scanf("%d",&option);
        if(option==1)
        {

        printf("Enter the name of chit you want to join:");    
        scanf("%s",str2);//chit
        strcpy(s,str2);
        strcpy(p,str1);
        strcat(p,"\n");
        strcat(str2,txtfile);
         ptr2= fopen(str2, "r");//str2
         fgets(temp,sizeof(temp),ptr2);
         total=atoi(temp);
         fgets(temp,sizeof(temp),ptr2);
         amt=atoi(temp);
        while(fgets(temp,sizeof(temp),ptr2))//str2
        {
                count++;
                if(strcmp(temp,p)==0)
                {
                    new=1;
                }
        }
        fclose(ptr2);
        printf("<-------START---------->\n");
        if(count<total && new==0)
        {
            ptr3 = fopen(str2, "a");
            fprintf(ptr3,"%s\n",str1);
            strcpy(m,str1);
            strcat(m,txtfile);
            ptr4 = fopen(m, "a");
            fprintf(ptr4,"%s\n",s);
            fprintf(ptr4,"UNPAID\n");
            fclose(ptr4);
            fclose(ptr3);
            printf("successfully joined %s\n",s);
            printf("<-------STOP---------->\n");
            printf("Enter Z to go to main menu:");
            scanf(" %c",&d);
            if(d=='Z')
            {
                display();
            }
        }
        else
        {
            if(new==1)
            {
                printf("You have already joined in this chit..!\n");
            }
            else if(new==0)
            {
                 printf("sorry!You have selected the chit which is full\n");
            }
            else
            {
                printf("SEE BELOW\n");
            }
            
            
            printf("<-------STOP---------->\n");
            printf("1.select another chit to join\n2.Main menu:");
            scanf("%d",&d);
            if(d==1)
            {
                join();
            }
            else
            {
                display();
            }
        }

        }
        else
        {
            display();
        }
        


}
void creat()
{
        char str3[100],Ch,s[100],ksp[100];
        int n,m,i;
        FILE *ptr,*cptr,*ptr2;
        printf("Enter the name of Chit:");
        scanf("%s",str3);
        strcpy(s,str1);
        strcat(s,txtfile);
         ptr2= fopen(s, "a");
        fprintf(ptr2,"%s\n",str3);
        fprintf(ptr2,"UNPAID\n");
        fclose(ptr2);
        cptr=fopen("allchits.txt","a");
        fprintf(cptr,"%s\n",str3);
        strcat(str3,txtfile);
        ptr=fopen(str3,"a");
        printf("Enter the no.of chit members:");
        scanf("%d",&n);
        fprintf(ptr,"%d\n",n);
        printf("Enter the Chit amount:");
        scanf("%d",&m);
        fprintf(ptr,"%d\n",m);
        fprintf(ptr,"%s\n",str1);
        printf("\nSuccesfully the chit is created\n");
        fclose(ptr);
        fclose(cptr);
		display();
		
}
void Users()
{
      char s[100],str[100],tempstr[100],ts[100],f_name[100],dis[100];
        int n,m,i,count=0,p,ent;
        FILE *ptr,*ptr2;
        strcpy(s,str1);
        strcat(s,txtfile);
         ptr=fopen(s, "r");
         printf("<----------START-------->\n\n");
         printf("The chits you have joined are:\n");
          while(fgets(tempstr,sizeof(tempstr),ptr)){
               count++;
            if(count%2!=0)
            {
                printf("%s  ",tempstr);
            }
            else
            {
                printf("");
            }
        }
        printf("\n<----------STOP-------->\n");
        printf("Select\n1.Continue Users process\n2.Main Menu:");
        scanf("%d",&ent);
        if(ent==1)
        {
            printf("\nEnter the chit name to see your chit friends:\n");
        scanf("%s",str);
        strcpy(dis,str);
        strcat(str,txtfile);
        ptr2=fopen(str,"r");
        fgets(tempstr,sizeof(tempstr),ptr2);//10
        fgets(tempstr,sizeof(tempstr),ptr2);//1500
        //printf("The chit amount:%s",tempstr);
        strcpy(ts,str1);
        strcat(ts,"\n");
         printf("<--------START--------->\n");
         printf("->Heyy.. %s These are your friends in chit [ %s ] :\n",str1,dis);
          while(fgets(tempstr,sizeof(tempstr),ptr2)){
                if(strcmp(ts,tempstr)==0){
                    printf(" ");
                }
                else{
                    printf("%s",tempstr);
                }
            }
            fclose(ptr2);
            fclose(ptr);
            printf("\n<--------STOP--------->\n");
            printf("\nselect\n1.Friends_profile\n2.Main_menu:");
            scanf("%d",&p);
            if(p==1)
            {
                printf("Enter the name of your friend:");
                scanf("%s",f_name);

                prof(f_name);
            }
            else
            {
                 display();
            }
            
        }
        else
        {
            display();
        }
        
        

}
void prof(char name[100])
{
    FILE *ptr1;
    char temp[100];
    int k=4,i;
    strcat(name,"\n");
    ptr1=fopen("prof.txt","r");
    printf("<--------START--------->\n");
    while(fgets(temp,sizeof(temp),ptr1))
        {
                if(strcmp(temp,name)==0)
                {
                    while(k)
                    {
                        fgets(temp,sizeof(temp),ptr1);
                        if(k==4)
                        {
                            printf("Mail      :%s",temp);
                        }
                        if(k==3)
                        {
                            printf("phn number:%s",temp);
                        }
                        if(k==2)
                        {
                            printf("Occupation:%s",temp);
                        }
                        if(k==1)
                        {
                            printf("Address   :%s",temp);
                        }
                        k--;
                    }
                }
        }
        printf("\n<---------STOP-------->\n");
        printf("\n");
        display();  
    
}
void Paychits()
{
    char str4[100],s[100],Ch,temp[100],temp2[100];
    int count=0,n,l;
    FILE *ptr1,*ptr2;
    strcpy(s,str1);
    strcat(s,txtfile);
    ptr1=fopen(s,"r");
    while(fgets(temp,sizeof(temp),ptr1)){
            count++;
            if(count%2!=0)
            {
                printf("%s  ",temp);
            }
            else
            {
                printf("STATUS:%s",temp);
            }
            
        }
    fclose(ptr1);
    printf("\nSelect your option\n1)If you want to continue to pay\n2)Main menu:\n");
    scanf("%d",&l);
    if(l==1)
    {
        pay_continue();
    }
    if(l==2)
    {
        display();
    }
    
}
void pay_continue()
{
    char str4[100],s[100],Ch,temp[100],temp2[100],ad[100],temp3[100];
    int n,l;
    FILE *ptr2,*ptr3;
    strcpy(s,str1);
    strcat(s,txtfile);
    printf("Enter the chit name to be pay:");
    scanf("%s",str4);
    strcpy(ad,str4);
    strcat(ad,txtfile);
    strcat(str4,"\n");
    printf("<----------START-------->");
    printf("\nThis is our phonepay number....6303838918\n");
    ptr3=fopen(ad,"r");
    fgets(temp3,sizeof(temp3),ptr3);
    fgets(temp3,sizeof(temp3),ptr3);
    printf("\nThis is the amount to be pay:%s",temp3);
    fclose(ptr3);
    printf("<----------STOP-------->\n");
    printf("Enter \n1.Paid\n2.Not_paid:");
    scanf("%d",&n);
    if(n==1)
    {
       
         FILE *dup;
         dup=fopen("duplicate.txt","w");
         ptr2 = fopen(s,"r");
	     while(fgets(temp2,sizeof(temp2),ptr2))
        {
            fprintf(dup,"%s",temp2);
            
            if(strcmp(temp2,str4)==0)
            {
                fprintf(dup,"PAID\n");
                fgets(temp2,sizeof(temp2),ptr2);
            }
        }
        printf("Succesfully your transction is cmplted\n");
     fclose(ptr2);
     fclose(dup);

     remove(s);
     rename("duplicate.txt",s);
     display();
    }
    else
    {
        printf("pls pay as soon as possible \n");
        display();
    }
}
void Notifications()
{
        printf("Notifications\n");
        printf("Here we will show the notifications of payements");
        Paychits();
}
void chit_info()
{
    char name[100],temp[100],dis[100];
    FILE *ptr;
    int count=1,i=1;
    printf("Enter the name of chit:");
    scanf("%s",name);
    strcpy(dis,name);
    printf("<--------START--------->\n\n");
    strcat(name,txtfile);
    ptr=fopen(name,"r");
    if(ptr==NULL)
    {
        printf("Sorry man ...This chit is not exist:");
    }
    else
    {
            printf("|| * * * * *%s CHIT* * * * * ||\n\n",dis);
            while(fgets(temp,sizeof(temp),ptr))
            {
        
                    if(count==1)
                    {
                        printf("Chit max Capacity(Members):%s",temp);
                    }
                    else if(count==2)
                    {
                         printf("Chit Capacity(Amount per month):%s",temp);
                    }
                    else
                    {
                         printf("%d) %s",i,temp);
                         i++;
                    }
                    count++;
            }
    }
     printf("\n<--------STOP--------->\n");
     display();       
}