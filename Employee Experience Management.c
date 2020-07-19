/* file named password.txt should be created containing userId and password
file named database.csv should be created containing the information of employees
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
void delay(int millis);
void screen();
void change_Password();
int strength_of_password(char password[]);
int Login_page();
void get_today();
void getdata_from_file();
void encrypt_data();
void decrypt_data();
int get_experience();
int date_validate(int x);
int flag,choice,empID=0,i,exp_year,exp_month,exp_day;
long int today,joining_date;
char now[7],filename[22],emp_Name[30],data[50];
char name[20];
FILE *db_file,*file_temp,*report_file;
int main()
{
system("color 0b");
long int date;
int name_len,ID,min_year,max_year;
char temp[50];
get_today();
Home_screen: //Home_screen
screen();
	printf("\n\n\t\t\t\tEnter a choice\n\t\t\t\t1.Login\n\t\t\t\t2.Change Password\n\t\t\t\t3.Quit\n\n\t\t\t\t\t\t\t\tChoice: ");
scanf("%d",&choice);
switch(choice) //Home_screen_switch
{
case 1:
login_page:
flag=Login_page();
if(flag==1)
			{
				printf("\n\n\n\t\t\t\t\t\t\t\t\tAccess Granted...");
				delay(1000);
				goto main_Menu;
			}
else

			{
				screen();
				printf("\n\n\n\t\t\t\t\t\t\t\t\tInvalid ID/Password");
				delay(1000);
				goto login_page;
			}
case 2:
flag=Login_page();
if(flag==1)
change_Password();
else
			{
				screen();
				printf("\n\n\n\t\t\t\t\t\t\t\t\tInvalid ID/Password");
				delay(1000);
				goto login_page;
			}
goto Home_screen;
case 3:
goto Quit;
default:
			screen();
			printf("\n\n\n\t\t\t\t\t\t\t\t\tInvalid choice");
			delay(1000);
			goto Home_screen;
}
main_Menu: //main_Menu
screen();
	printf("\n\n\t\t\t\t\t\tEnter choice:\n\n");
	printf("\n\t\t\t\t\t\t1 -> Add New Employee Detail\n\n");
	printf("\n\t\t\t\t\t\t2 -> Retrieve Employee Detail\n\n");
	printf("\n\t\t\t\t\t\t3 -> Logout\n\n");
	printf("\n\t\t\t\t\t\t4 -> Quit");
	printf("\n\n\t\t\t\t\t\t\t\tChoice:");
scanf("%d",&choice);
switch(choice) //main_Menu_switch
{
case 1:
update_database: //update_database
screen();
			printf("\n\t\t\t\t\t\t\t\tADDING NEW EMPLOYEE DETAIL");
		    printf("\n\t\t\t\t\t\t\t\t--------------------------");
		    printf("\n\n\t\t\t\t\t\tEnter Name of Employee:");
scanf("%s",name);
name_len=strlen(name);
if(name[name_len-1]=='#')
goto main_Menu;
//validate_name();
		    printf("\n\n\t\t\t\t\t\tEnter D.O.B           :");
scanf("%ld",&date);
flag=date_validate(date);
if(flag==0)
{
screen();
				printf("\n\n\n\t\t\t\t\t\t\t\t\tinvalid date\n");
delay(1000);
goto update_database;
}
db_file=fopen("database.csv","r");
while(!feof(db_file))
{
file_temp=db_file;
fgets(temp,50,file_temp);
}
i=0;
empID=0;
while(temp[i]!=',')
{
empID+=temp[i++]-48;
empID*=10;
}
empID/=10;
empID++;
fclose(db_file);
encrypt_data();
db_file=fopen("database.csv","a");
fprintf(db_file,"%d,",empID);
printf("today=%d\n",today);
fprintf(db_file,"%d,",today);
fprintf(db_file,"%s,",name);
fprintf(db_file,"%d,\n",date);
fclose(db_file);
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEmp ID - %d",empID);
end_of_update:
delay(1000); //end_of_update
screen();
			printf("\n\n\t\t\t\t\t\tEnter the choice\n\t\t\t\t\t\t1.Main menu\n\t\t\t\t\t\t2.Add one more employee\n\t\t\t\t\t\t3.Quit\n\n\t\t\t\t\t\t\t\tChoice: ");
switch(choice) //end_of_update_switch
{
case 1:
goto main_Menu;
break;
case 2:
goto update_database;
break;
case 3:
goto Quit;
default:
screen();
					printf("\n\n\n\t\t\t\t\t\t\t\t\tInvalid choice");
delay(1000);
goto end_of_update;
break;
}
case 2: //retrieve_details
retrieve_details:
get_today();
memset(filename,'\0',sizeof(filename));
for(i=0;i<8;i++)
filename[i]=(today/(int)pow(10,7-i))%10+48;
strcat(filename,"-");
strcat(filename,now);
strcat(filename,".csv");
screen();
			printf("\n\n\t\t\t\t\t\t\t\tRETRIEVING EMPLOYEE DETAIL");
			printf("\n\t\t\t\t\t\t\t\t--------------------------");
			printf("\n\n\t\t\t\t\t\tEnter your choice");
			printf("\n\t\t\t\t\t\t1 -> Details of all Employee");
			printf("\n\t\t\t\t\t\t2 -> Details of Specified Year Bound");
			printf("\n\t\t\t\t\t\t3 -> Details with specified year span");
			printf("\n\t\t\t\t\t\t4 -> detail of Particular Employee");
			printf("\n\t\t\t\t\t\t5 -> logout");
			printf("\n\t\t\t\t\t\t6 -> Quit\n\n\t\t\t\t\t\t\t\tChoice: ");
			scanf("%d",&choice);
switch(choice) //retrieve_details_switch
{
case 1:
	screen();
//system("cls"); //details of all employee
					printf("\n\n\t\t\t\t\t\t\t\tDETAILS OF ALL EMPLOYEE");
					printf("\n\t\t\t\t\t\t\t\t-----------------------\n\n");
db_file=fopen("database.csv","r");
report_file=fopen(filename,"w");
fgets(data,50,db_file);
fgets(data,50,db_file);
while(!feof(db_file))
{
getdata_from_file();
decrypt_data();
{
fprintf(report_file,"%d,",empID);
fprintf(report_file,"%s,",emp_Name);
fprintf(report_file,"%d,\n",exp_year);
printf("%d-%s-%s\n",empID,emp_Name,exp_year);
}
}
fclose(db_file);
fclose(report_file);
printf("\n\n\n\t\t\t\t\t\t\t\tfile created in the name %s\n",filename);
break;
case 2: //details of employee with minimum experience
screen();
					printf("\n\n\t\t\t\t\t\t\t\tDETAILS WITHIN SPECIFIED YEAR BOUND");
					printf("\n\t\t\t\t\t\t\t\t-----------------------------------");
					printf("\n\n\t\t\t\t\t\tEnter Number of Years:");
					scanf("%d",&min_year);
					printf("\n\n\t\t\t\t\t\tEnter the date       :");
scanf("%d",&today);
db_file=fopen("database.csv","r");
report_file=fopen(filename,"w");
fgets(data,50,db_file);
fgets(data,50,db_file);
while(!feof(db_file))
{
getdata_from_file();
if(exp_year>=min_year)
{
decrypt_data();
fprintf(report_file,"%d,",empID);
fprintf(report_file,"%s,",emp_Name);
fprintf(report_file,"%d,\n",exp_year);
printf("%d-%s-%s\n",empID,emp_Name,exp_year);
}
}
fclose(db_file);
fclose(report_file);
printf("\n\n\n\t\t\t\t\t\t\t\tfile created in the name %s\n",filename);
break;
case 3: //details of employee with span of experience
span_of_exp_years:
	screen();
//system("cls");
					printf("\n\n\t\t\t\t\t\t\t\tDETAILS WITH SPECIFIED YEAR SPAN");
					printf("\n\n\t\t\t\t\t\t\t\t--------------------------------\n\n");
					printf("\n\n\t\t\t\t\t\tEnter Minimun Number of Years:");	
					scanf("%d",&min_year);
					printf("\n\t\t\t\t\t\tEnter Maximun Number of Years:");
					scanf("%d",&max_year);
					printf("\n\t\t\t\t\t\tEnter date                    :");
scanf("%d",&today);
if(min_year>max_year)
{
						printf("\n\n\n\n\n\n\n\n\n\nRe-enter years\n");
goto span_of_exp_years;
}
db_file=fopen("database.csv","r");
report_file=fopen(filename,"w");
fgets(data,50,db_file);
fgets(data,50,db_file);
while(!feof(db_file))
{
getdata_from_file();
if(exp_year>=min_year&&exp_year<=max_year)
{
decrypt_data();
fprintf(report_file,"%d,",empID);
fprintf(report_file,"%s,",emp_Name);
fprintf(report_file,"%d,\n",exp_year);
printf("%d-%s-%s\n",empID,emp_Name,exp_year);
}
}
fclose(db_file);
fclose(report_file);
printf("\n\n\n\t\t\t\t\t\t\t\tfile created in the name %s\n",filename);
delay(1000);
break;
case 4:
//					system("cls");									//particular employee
					screen();
					printf("\n\n\t\t\t\t\t\t\t\tDETAILS OF PARTICULAR EMPLOYEE");
					printf("\n\n\t\t\t\t\t\t\t\t------------------------------");
					printf("\n\n\t\t\t\t\t\tEnter ID:");
					scanf("%d",&ID);
					printf("\n\t\t\t\t\t\tEnter date                    :");
scanf("%d",&today);
db_file=fopen("database.csv","r");
report_file=fopen(filename,"w");
fgets(data,50,db_file);
fgets(data,50,db_file);
while(!feof(db_file))
{
getdata_from_file();
if(ID==empID)
{
decrypt_data();
fprintf(report_file,"%d,",empID);
fprintf(report_file,"%s,",emp_Name);
fprintf(report_file,"%d,\n",exp_year);
printf("%d-%s-%s\n",empID,emp_Name,exp_year);
}
}
fclose(db_file);
fclose(report_file);
printf("\n\n\n\t\t\t\t\t\t\t\tfile created in the name %s\n",filename);
break;
case 5:
goto Home_screen;
case 6:
goto Quit;
}
end_of_retrieve: //end_of_update
screen();
			printf("\n\n\t\t\t\t\t\tEnter the choice\n\t\t\t\t\t\t1.Main menu\n\t\t\t\t\t\t");
			printf("2.Retrieve one more detail\n\t\t\t\t\t\t3.Quit\n\n\t\t\t\t\t\t\t\tChoice: ");
			scanf("%d",&choice);
switch(choice) //end_of_update_switch
{
case 1:
goto main_Menu;
case 2:
goto retrieve_details;
case 3:
goto Quit;
default:
screen();
					printf("\n\n\n\t\t\t\t\t\t\t\t\tInvalid choice\n");
delay(1000);
goto end_of_retrieve;
}
case 3:
goto Home_screen;
case 4:
goto Quit;
default:
screen();
			printf("\n\n\n\t\t\t\t\t\t\t\t\tInvalid choice\n");
delay(1000);
goto main_Menu;
}
Quit: //quit
screen();
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\tThank You");
		delay(1000);
return 0;
}
void delay(int millis) //delay function
{
clock_t start_clock = clock();
millis+=start_clock;
while(clock()<millis);
}
void screen() //default screen content
{
system("cls");
	printf("\n\n\n\t\t\t\t\t\t\t\tDatabase of Employee's years of Experience\n");
}
void change_Password() //password change block
{
FILE *frptr,*fwptr;
char new_password[16],user_name[15],ch,i=0;
frptr=fopen("password.txt","r");
ch=fgetc(frptr);
while(ch!=' ')
{
user_name[i]=ch;
i++;
ch=fgetc(frptr);
}
user_name[i]='\0';
fclose(frptr);
// printf("%s",user_name);
enter_password:
	printf("\n\n\t\t\t\t\t\tEnter new password:");
scanf("%s",new_password);
flag=strength_of_password(new_password);
if(flag==0)
{
screen();
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\tChange password");
delay(1000);
goto enter_password;
}
else
{
fwptr=fopen("password.txt","wb");
fprintf(fwptr,"%s",user_name);
fprintf(fwptr," ");
fprintf(fwptr,"%s",new_password);
		printf("\n\n\n\t\t\t\t\t\t\t\tPassword created successfully\n");
fclose(fwptr);
delay(1000);
}
}
int strength_of_password(char password[]) //checking strength of password while changing
{
int uc=0,lc=0,sc=0,n=0,password_len,i;
password_len=strlen(password);
if(password_len<8||password_len>15)
return 0;
else
{
for(i=0;i<password_len;i++)
if(password[i]>64 && password[i]<91)
uc=1;
else if(password[i]>96 && password[i]<123)
lc=1;
else if(password[i]>47 && password[i]<58)
n=1;
else
sc=1;
if(uc==1&&lc==1&&sc==1&&n==1)
return 1;
else
return 0;
}
}
int Login_page() //login validation
{
char User_ID[16],password[16],ch,a[30];
int i,flag=0,len,count=0;
FILE *fptr;
login_page:
	screen();						//validating username and password
	printf("\t\t\t\t\t\t\t\t\t\tLOGIN PAGE\n");
	printf("\t\t\t\t\t\t\t\t\t\t----------\n");
	printf("\t\t\t\t\t\tUSER ID:");
scanf("%s",User_ID);
len=strlen(User_ID);
count=0;
if((8>len||len>15))
/* {
printf(" Invalid entry...");
delay(1000);
system("cls");
goto login_page;
}
*/ return 0;
for(i=0;i<len;i++)
{
if((User_ID[i]>47&&User_ID[i]<58)||(User_ID[i]>64&&User_ID[i]<91)||(User_ID[i]>96&&User_ID[i]<123))
count++;
}
i=0;
if(count==len)
{
fptr=fopen("password.txt","r");
ch=fgetc(fptr);
while(ch!=EOF)
{
if(ch!=' ')
{
a[i]=ch;
i++;
}
ch=fgetc(fptr);
}
}
else
/* {
printf(" Invalid entry...");
delay(1000);
system("cls");
goto login_page;
}
*/ return 0;
fclose(fptr);
	printf("\n\t\t\t\t\t\tPASSWORD:");
scanf("%s",&password);
strcat(User_ID,password);
if(strcmp(a,User_ID))
/* {
printf("\n\n Invalid entry....");
delay(1000);
system("cls");
goto login_page;
}
*/ return 0;
else
/* {
printf(" Access Granted..\n");
delay(1000);
//goto main_menu;
}
*/
return 1;
}
void get_today() //get present date and time
{
time_t t=time(NULL);
struct tm *tm = localtime(&t);
char s[64];
strftime(s, sizeof(s),"%c",tm);
today=s[3]-48;
today*=10;
today+=s[4]-48;
today*=10;
today+=s[0]-48;
today*=10;
today+=s[1]-48;
today*=10;
today+=2;
today*=10;
today+=0;
today*=10;
today+=s[6]-48;
today*=10;
today+=s[7]-48;
now[0]=s[9];
now[1]=s[10];
now[2]=s[12];
now[3]=s[13];
now[4]=s[15];
now[5]=s[16];
now[6]='\0';
}
void getdata_from_file() //extract data from database file
{
int j;
i=0;
empID=0;
//printf("data=%s=",data);
while(data[i]!=',')
{
empID+=data[i++]-48;
empID*=10;
}
empID/=10;
//printf("empID=%d=",empID);
i++;
j=0;
joining_date=0;
while(data[i]!=',')
{
joining_date*=10;
//printf("-%c",data[i]);
joining_date+=data[i++]-48;
}
//printf("jd=%ld=",joining_date);
get_experience();
//printf("flag=%d=",flag);
i++;
j=0;
while(data[i]!=',')
{
emp_Name[j++]=data[i++];
}
emp_Name[j]='\0';
//printf("name=%s\n",emp_Name);
fgets(data,50,db_file);
}
int get_experience() //checking experience
{
	/*
expr=(today/1000000)%100-(joining_date/1000000)%100;
expr*=100;
expr+=(today/10000)%100-(joining_date/10000)%100;
expr*=10000;
expr+=exp_year=today%10000-joining_date%10000;
//printf("exp=%d=",exp);
if(today%10000-joining_date%10000>0)
return 1;
else if(today%10000-joining_date%10000==0)
{
if((today/10000)%100-(joining_date/10000)%100>0)
return 1;
else if((today/10000)%100-(joining_date/10000)%100==0)
{
if((today/1000000)%100-(joining_date/1000000)%100>=0)
return 1;
else
return 0;
}
else
return 0;
}
else
return 0;
*/
exp_year=today%10000-joining_date%10000;
exp_month=(today/10000)%100-(joining_date/10000)%100;
exp_day=(today/1000000)%100-(joining_date/1000000)%100;
//printf("%d-%d-%d\n",exp_day,exp_month,exp_year);
//delay(1000);
//if(exp_year>0)
//flag=1;
//else if(exp_year<0)
/*flag=0;
else
{
	if(exp_month>0)
		flag=1;
	else if (exp_month<0)
		flag=0;
	else
	{
		if(exp_day>=0)
			flag=1;
		else
			flag=0;
	}
}*/
}
int date_validate(int date) //validate date
{
int flag=0,years,m,dae,i;
if(date/100000000>0)
goto label;
years=date%10000;
m=(date/10000)%100;
// printf("month=%d",m);
if((m<1)||(m>12))
goto label;
if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
flag=1;
else if((m==4)||(m==6)||(m==9)||(m==11))
flag=0;
else
flag=2;
if(flag==2)
if(years%400==0||(years%100!=0&&years%4==0))
flag=3;
dae=date/1000000;
// printf("dae=%d",dae);
if(dae>31||dae<1)
goto label;
else if((dae==31)&&(flag==0))
goto label;
else if(dae>28&&flag==2)
goto label;
else if(dae>29&&flag==3)
goto label;
else
return 1;
label:
// printf("invalid");
return 0;
}

void encrypt_data()
{
	int l;
    l=strlen(name);
    for(i=0;i<l;i++)
    {
    	if(name[i]%2==0)
    		name[i]=name[i]+14;
    	else 
    		name[i]=name[i]+16;
    }
/*    l=strlen(date);
    for(i=0;i<l;i++)
    {
			if(date[i]%2==0)
				date[i]=date[i]+14;
			else 
				date[i]=date[i]+16;
    }  
    */
}
void decrypt_data()
   {
   	int l;
   	l=strlen(emp_Name);
   	for(i=0;i<l;i++)
   	{
   			if(emp_Name[i]%2==0)
				emp_Name[i]=emp_Name[i]-14;
			else
				emp_Name[i]=emp_Name[i]-16;	
	}
	/*
	l=strlen(date);
	for(i=0;i<l;i++)
	{
		if(date[i]%2==0)
			    date[i]=date[i]-14;
		else 
				date[i]=date[i]-16;
	}
	*/
   } 
