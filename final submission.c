#include<stdio.h>  // standard input/output
#include<windows.h> // windows.h is for windows related functions
#include<conio.h> /* conio.h header used in c programming contains functions
for console input/output.*/
#include<string.h>  // string operations
#include<stdlib.h> /*stdlib.h is the header of the general purpose standard library of C programming
language which includes functions involving memory allocation, process control, conversions and others. */
#include <time.h> /*The time.h header defines four variable types,
two macro and various functions for manipulating date and time. */
#include<ctype.h> /* The ctype.h header file of the C Standard Library provides
declares several functions useful for testing and mapping characters. */
#include<dos.h> /* dos.h header file of c language contains functions for
handling interrupts, producing sound, date and time functions etc. */


void mainmenu(void);
void adoption();
void Password(int);
void timerecord();
void timerecord1();
void addnewemployee();
void searchemployees();
void deleteemployee();
int getdata();
void returnfunc();
void editemployee();
int  checkid(int);
void searchalltmr();
void searchalltmremployee();
void particularemployeesearch();
void particularemployeesearchforemployee();
void recordlogintime();
void recordlogouttime();
void t_number();
COORD coord = {0,0}; /*Defines the coordinates of a character cell in a console screen buffer.
The origin of the coordinate system (0,0) is at the top, left cell of the buffer. */

char password[10]={"project"};
char findemployee;
char erank[][100]={"Administrator","Accountant","Electrician","Software Operator"," Clark","Architecture"};
struct employees
{
    int  id;
    char name[50];
    char designation[50];
    int  wex;
    char gender[20];
    char *department;
    char loginhour;
    char loginmin;
    char loginsec;
    char logouthour;
    char logoutmin;
    char logoutsec;
    int  t_numberempl;
};
    //Keyword struct is used for creating a structure.
    struct employees employee;
    struct td
    {
        int yr;
        char day;
        char mon;
    };
    struct td timeday;
    FILE *fp,*ft,*fs;
    int s;
    int searchid;
    int posx,posy;
    void gotoxy(int x,int y)
{
    coord.X= x;coord.Y = y;
//X=The horizontal coordinate or column value. The units depend on the function call.
//Y=The vertical coordinate or row value. The units depend on the function call.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//STD_OUTPUT_HANDLE: The standard output device.Initially,this is the active console screen buffer.
}
int main()
{
    mainmenu();
    return 0;
}
void mainmenu()
{
    InputOptions:
        system("cls"); /* system() is used to run the DOS commands from the C.
        cls is the clear screen command(DOS cmd). */
        system("COLOR C");
        gotoxy(20,3); //places cursor at a desired location on screen.
        printf("****************************************");
        gotoxy(20,4);
        printf("            >>MAIN MENU<< ");
        gotoxy(20,5);
        printf("****************************************");
        gotoxy(20,7);
        printf("*");
        gotoxy(59,4);
        printf("*");
        gotoxy(20,6);
        printf("*");
        gotoxy(20,4);
        printf("*");
        gotoxy(20,5);
        printf("*");
        gotoxy(20,8);
        printf("*");
        gotoxy(20,9);
        printf("*");
        gotoxy(20,10);
        printf("*");
        gotoxy(28,6);
        printf("1.Data Entry.   ");
        gotoxy(59,6);
        printf("*");
        gotoxy(28,7);
        printf("2.Daily Time Record.");
        gotoxy(59,7);
        printf("*");
        gotoxy(28,8);
        printf("3.Exit System.");
        gotoxy(59,8);
        printf("*");
        gotoxy(59,9);
        printf("*");
        gotoxy(59,10);
        printf("*");
        gotoxy(20,11);
        printf("****************************************");
        gotoxy(20,15);
        printf("Enter your choice:");
        char c = getchar();
	switch(c)
	{
		case '1':
        Password(1);
        break;
	case '2':
	    recordlogintime();
	    timerecord1(1);
		break;
    case '3':
		  finish();
    default:
        {
        system("cls");
		gotoxy(20,7);
		printf("\aWrong Entry!!Please re-enter correct option");
		getch();
		goto InputOptions;
		}
    }
}
void Password(int isFirstTime)
{

   system("cls");
   system("COLOR 1B");
   if(isFirstTime == 0)
   {

       gotoxy(15,16);
	   printf("Incorrect Password. Input the password again!!");
   }

   char d[25]=">>Password Protected<<";
   char ch,pass[10];
   int i=0,j;
   gotoxy(10,4);
   for(j=0;j<18;j++)
    {
        printf("*");
    }
    for(j=0;j<25;j++)
    {
        printf("%c",d[j]);
    }
   for(j=0;j<15;j++)
   {
        printf("*");
   }
   gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
    {
	ch=getch(); //getch() are used to read a character from screen.

	if(ch!=13 && ch!=8)
    {
	putch('*'); //putch() are used to write a character to screen.
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if((strcmp(pass,password)==0))
      {
    gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to go to for  update employee  data.");
	if(getch())
    {
    adoption();
    }
   }
   else
   {
	 Password(0);
   }
}
void timerecord()
{

    system("cls");
    system("COLOR 1B ");
    gotoxy(23,2);
    printf(">>>You select previous record of Employee<<<.");
    gotoxy(23,5);
    printf("*****************************************");
    gotoxy(23,6);
    printf("    Employee time record system");
    gotoxy(23,7);
    printf("*****************************************");
    gotoxy(22,5);
    printf("*");
    gotoxy(22,6);
    printf("*");
    gotoxy(22,7);
    printf("*");
    gotoxy(22,8);
    printf("*");
    gotoxy(22,9);
    printf("*");
    gotoxy(22,10);
    printf("*");
    gotoxy(22,11);
    printf("*");
    gotoxy(22,12);
    printf("*");
    gotoxy(22,13);
    printf("*");
    gotoxy(22,14);
    printf("*");
    gotoxy(22,15);
    printf("*");
    gotoxy(23,8);
    printf(" 1.Time Record of Particular Employee. ");
    gotoxy(63,6);
    printf("*");
    gotoxy(23,10);
    printf(" 2.Time Record of All Employee");
    gotoxy(63,7);
    printf("*");
    gotoxy(23,12);
    printf(" 3.Back to Admin menu");
    gotoxy(63,8);
    printf("*");
    gotoxy(63,9);
    printf("*");
    gotoxy(63,10);
    printf("*");
    gotoxy(63,11);
    printf("*");
    gotoxy(63,12);
    printf("*");
    gotoxy(63,13);
    printf("*");
    gotoxy(63,14);
    printf("*");
    gotoxy(63,15);
    printf("*");
    gotoxy(23,15);
    printf("*****************************************");
    gotoxy(23,18);
    InputOptions:
	gotoxy(23,20);
	printf("Enter your choice: ");
	char c = getchar();
	switch(c)
	{
	    case '1':
            particularemployeesearch();
            break;
        case '2':
            searchalltmr();
            break;
        case'3':
            adoption();
        default:
            {
              gotoxy(23,22);
              goto InputOptions;
            }
    }
}
void timerecord1()
{
    system("cls");
    system("COLOR 1B");
    gotoxy(23,2);
    printf(">>>You select previous record of Employee<<<<.");
    gotoxy(20,5);
    printf("****************************************");
    gotoxy(21,6);
    printf("  Employee time record system");
    gotoxy(20,6);
    printf("*");
    gotoxy(20,7);
    printf("*");
    gotoxy(20,8);
    printf("*");
    gotoxy(20,9);
    printf("*");
    gotoxy(20,10);
    printf("*");
    gotoxy(20,11);
    printf("*");
    gotoxy(20,12);
    printf("*");
    gotoxy(20,13);
    printf("*");
    gotoxy(20,14);
    printf("*");
    gotoxy(20,15);
    printf("*");
    gotoxy(21,7);
    printf("***************************************");
    gotoxy(21,8);
    printf(" 1.Time Record of Particular Employee. ");
    gotoxy(59,6);
    printf("*");
    gotoxy(21,10);
    printf(" 2.Time Record of All Employee");
    gotoxy(59,7);
    printf("*");
    gotoxy(59,8);
    printf("*");
    gotoxy(21,12);
    printf(" 3.Log Out ");
    gotoxy(59,9);
    printf("*");
    gotoxy(59,10);
    printf("*");
    gotoxy(59,11);
    printf("*");
    gotoxy(21,15);
    printf("***************************************");
    gotoxy(59,12);
    printf("*");
    gotoxy(59,13);
    printf("*");
    gotoxy(59,14);
    printf("*");
    gotoxy(59,15);
    printf("*");
    gotoxy(23,18);
    InputOptions:
	gotoxy(23,20);
	printf("Enter your choice:");
	char c = getchar();
	switch(c)
	{
	    case '1':
            particularemployeesearchforemployee();
            break;
        case '2':
            searchalltmremployee();
            break;
        case'3':
           recordlogouttime();
           mainmenu();
           break;
        default:
            {
              gotoxy(23,22);
              goto InputOptions;
            }
    }
}
void adoption()
{
    system("cls");
    system("COLOR 2");
    gotoxy(22,3);
    printf("**************************************");
    gotoxy(22,4);
    printf("              >>>ADMIN OPTION<<<                 ");
    gotoxy(22,5);
    printf("**************************************");
    gotoxy(22,7);
    printf("*");
    gotoxy(22,4);
    printf("*");
    gotoxy(22,5);
    printf("*");
    gotoxy(22,6);
    printf("*");
    gotoxy(24,7);
    printf(" 1.Add New Employee.");
    gotoxy(22,8);
    printf("*");
    gotoxy(23,9);
    printf("  2.Show Daily Entries.");
    gotoxy(22,9);
    printf("*");
    gotoxy(23,11);
    printf("  3.Search Employee Record.");
    gotoxy(22,10);
    printf("*");
    gotoxy(23,13);
    printf("  4.Remove Employee.");
    gotoxy(22,11);
    printf("*");
    gotoxy(23,15);
    printf("  5.Edit Employee Record.");
    gotoxy(22,12);
    printf("*");
    gotoxy(23,17);
    printf("  6.Back to main menu");
    gotoxy(22,13);
    printf("*");
    int i;
    for(i=3;i<=17;i++)
    {
        gotoxy(59,i);
        printf("*");
    }
    gotoxy(22,14);
    printf("*");
    gotoxy(22,15);
    printf("*");
    gotoxy(22,16);
    printf("*");
    gotoxy(22,17);
    printf("*");
    gotoxy(22,18);
    printf("*");
    gotoxy(23,18);
    printf("*************************************");
    InputOptions:
	gotoxy(22,20);
	printf("Enter your choice:");
	char c = getchar();
	switch(c)
	{
        case '1':
             addnewemployee();
            break;
        case '2':
            timerecord();
            break;
        case'3':
            searchemployees();
            break;
        case'4':
            deleteemployee();
            break;
        case'5':
            editemployee();
            break;
        case'6':
            mainmenu();
            break;
        default:
            {

                gotoxy(23,22);
                goto InputOptions;
            }
            }
            getch();
}
void addnewemployee()
{
    system("cls");
    system("COLOR 1B");
	int i;

	for(i=17;i<=62;i++)
    {
       gotoxy(i,4);
       printf("*");
    }
    for(i=17;i<=62;i++)
    {
        gotoxy(i,6);
        printf("*");
    }
    for(i=17;i<=62;i++)
    {
       gotoxy(i,21);
       printf("*");
    }
    for(i=4;i<=21;i++)
    {
        gotoxy(63,i);
        printf("*");
    }
    for(i=4;i<=21;i++)
    {
      gotoxy(17,i);
      printf("*");
    }
	gotoxy(25,5);
	printf(">>>SELECT CATEGORIES OF EMPLOYEE<<<");
	gotoxy(25,7);
	printf("1.Administrator");
	gotoxy(25,9);
	printf("2. Accountant");
	gotoxy(25,11);
	printf("3. Electrician");
	gotoxy(25,13);
	printf("4. Computer Operator ");
	gotoxy(25,15);
	printf("5. Software Operator");
	gotoxy(25,17);
	printf("6. Clark");
	gotoxy(25,19);
	printf("7. Back to main menu");
	gotoxy(20,21);
    gotoxy(20,23);
	printf("Enter your choice:");
	scanf("%d",&s);
	if(s==7)
	adoption();
	fp=fopen("debian.dat","ab+"); // ab+ append or create a binary for read and write.
	if(getdata()==1)
    {
	    employee.department=erank[s-1];
        fseek(fp,0,SEEK_END); /* Sets the file position indicator for the file stream to
        the value pointed to by offset (fseek(FILE *stream, long int offset, int whence)) */
        fwrite(&employee,sizeof(employee),1,fp);
        /* size_t fwrite( const void* buf,size_t size,size_t num,FILE* fp );
        buf=A pointer to a buffer that contains the elements that you want to write.
        size=The size of each element to write.
        num=The number of elements to write.
        fp=The stream to which to write the elements. */
        fclose(fp);
        gotoxy(23,22);
        printf("The record is successfully saved");
        gotoxy(24,23);
        printf("Save any more?(Y / N):");
	if(getch()=='n')
	{
        fflush(stdin);//to clear input buffer
	    adoption();
    }
	else
	{
	    fflush(stdin);
	    addnewemployee();
    }
	}
}
int getdata()
{
    system("cls");
    system("COLOR 1E");
	int t,i;
	gotoxy(20,3);
	printf("Enter the Information Below:\n");
	gotoxy(15,4);
	for(i=15;i<=50;i++)
    {
        printf("*");
    }
	gotoxy(15,22);
	for(i=15;i<=50;i++)
    {
        printf("*");
    }
	gotoxy(28,6);
	printf("Category: ");
	gotoxy(38,6);
	printf("%s",erank[s-1]);
	gotoxy(21,8);
	printf("New EmployeeID:\t");
	InputData:
	gotoxy(36,8);
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		gotoxy(15,16);
		printf("\aThe employee id already exists. Input again.");
		goto InputData;
		return 0;
	}
	else
    {

        employee.id=t; //t= store new employee id
        gotoxy(21,10);
        printf("          Name:");
        gotoxy(36,10);
        scanf("%s",employee.name);
        gotoxy(21,12);
        printf("   Designation:");
        gotoxy(36,12);
        scanf("%s",employee.designation);
        gotoxy(20,14);
        printf("Work Experience:");
        gotoxy(36,14);
        scanf("%d",&employee.wex);
        gotoxy(20,16);
        printf("Enter Employee gender:");
        gotoxy(36,18);
        scanf("%s",&employee.gender);
        gotoxy(36,20);
        return 1;//return 1; means the program was not executed successfully for occurring error.
	}
}
int checkid(int t)
{
	rewind(fp);/*rewind function sets the file position to the beginning of the file for the stream pointed to by stream.
	It also clears the error and end-of-file indicators for stream. */
	while(fread(&employee,sizeof(employee),1,fp)==1) //read all records from file
        /* sizeof is used to calculate the size of any data type, measured in the number of
        bytes required to represent the type. */
        /* size_t fread( const void* buf,size_t size,size_t num,FILE* fp );
        buf=A pointer to a buffer that contains the elements that you want to read.
        size=The size of each element to read.
        num=The number of elements to read.
        fp=The stream to which to read the elements. */
	if(employee.id==t)
	return 0; // return 0; means the program executed successfully.
      return 1; //return 1; means the program was not executed successfully for occurring error.
}
void searchemployees()
{
    int i;
    system("cls");
    system("COLOR 1F");
    char findemployee = 0;
    gotoxy(20,5);
    int employeeId;
    printf("       >>>Search Employee<<<");
    gotoxy(20,4);
    printf("************************************");
    gotoxy(20,5);
    printf("*");
    gotoxy(20,6);
    printf("*");
    gotoxy(20,7);
    printf("*");
    gotoxy(20,8);
    printf("*");
    gotoxy(20,9);
    printf("*");
    gotoxy(20,10);
    printf("*");
    gotoxy(20,11);
    printf("*");
    gotoxy(20,12);
    printf("*");
    gotoxy(20,13);
    printf("*");
    gotoxy(20,14);
    printf("*");
    gotoxy(20,15);
    printf("*");
    gotoxy(20,16);
    printf("*");
    gotoxy(20,6);
    for(i=20;i<=55;i++)
    {
        printf("*");
    }
	gotoxy(20,17);
	for(i=20;i<=55;i++)
    {
        printf("*");
    }
    gotoxy(25,8);
    printf("1. Search By ID");
    gotoxy(55,5);
    printf("*");
    gotoxy(55,6);
    printf("*");
    gotoxy(55,9);
    printf("*");
    gotoxy(55,10);
    printf("*");
    gotoxy(25,10);
    printf("2. Search By Name");
    gotoxy(55,7);
    printf("*");
    gotoxy(55,8);
    printf("*");
    gotoxy(55,11);
    printf("*");
    gotoxy(55,12);
    printf("*");
    gotoxy(55,13);
    printf("*");
    gotoxy(25,12);
    printf("3. Back to admin menu.");
    gotoxy(55,14);
    printf("*");
    gotoxy(55,15);
    printf("*");
    gotoxy(55,16);
    printf("*");
    gotoxy(55,17);
    printf("*");
    gotoxy(20,20);
    printf("Enter Your Choice");
    fp=fopen("debian.dat","rb"); //open a binary file for reading.
    rewind(fp);/*rewind function sets the file position to the beginning of the file for the stream pointed to by stream.
	It also clears the error and end-of-file indicators for stream. */
    switch(getch())
    {
	    case '1':
	       {
               Sleep(2); //Sleep for 2 seconds.sleep() function stops the execution of the program.
               system("cls");
               system("COLOR 1B");
               gotoxy(15,3);
               printf("*************>>Search Employee By Id<<*************");
               gotoxy(20,5);
               printf("Enter the Employee id:");
               scanf("%d",&employeeId);
               while(fread(&employee,sizeof(employee),1,fp)==1)
               /* size_t fread( const void* buf,size_t size,size_t num,FILE* fp );
               buf=A pointer to a buffer that contains the elements that you want to read.
               size=The size of each element to read.
               num=The number of elements to read.
               fp=The stream to which to read the elements. */
            {

		      if(employee.id==employeeId)
              {

                  gotoxy(20,7);
                  printf("The information of your searched employee.");
		          gotoxy(15,8);

             for(i=15;i<=64;i++)
             {
                 printf("*");
             }
             gotoxy(15,8);
             for(i=9;i<=15;i++)
             {
                 gotoxy(15,i);
                 printf("*");
             }
		     gotoxy(24,9);
		     printf("ID:%d",employee.id);
		     gotoxy(24,10);
		     printf("Name:%s",employee.name);
		     gotoxy(24,11);
		     printf("Designation:%s ",employee.designation);
		     gotoxy(24,12);
		     printf("Work experience:%d ",employee.wex);
		     gotoxy(24,13);
             printf("Gender:%s",employee.gender);
             gotoxy(15,16);

             for(i=15;i<=64;i++)
             {
                 printf("*");
             }
             gotoxy(31,8);
             for(i=9;i<=15;i++)
             {
                 gotoxy(64,i);
                 printf("*");
             }
		    findemployee='t'; //t= store employee id
		    }
	     }

	     if(findemployee!='t')
	     {

             gotoxy(22,9);
             printf("\aNo Record Found");
	     }

	     gotoxy(20,17);
	     printf("Try another search?(Y/N)");
	     if(getch()=='y')
	     {
             fflush(stdin); //to clear input buffer
	         searchemployees(); //search employees id
         }
	    else
	    {

	        adoption();
	        break;
	    }
	}
	case '2':
	    {
            char employeeNameFromUser[50];
            system("cls");
            system("COLOR 1B");
            gotoxy(15,3);
            printf("*************>Search Employee By Name<************");
            gotoxy(20,5);
            printf("Enter Employee  Name:");
            scanf("%s",&employeeNameFromUser);
            int d=0;
            while(fread(&employee,sizeof(employee),1,fp)==1)
            {

		        if(strcmp(employee.name, employeeNameFromUser)==0)
                {
                    gotoxy(20,7);
                    printf("The information of your searched employee .");
                    gotoxy(15,8);
		            for(i=15;i<=64;i++)
                    {
                        printf("*");
                    }
            gotoxy(15,8);
            for(i=9;i<=15;i++)
            {
                 gotoxy(15,i);
                 printf("*");
            }
            gotoxy(20,9);
		    printf("ID:%d",employee.id);
		    gotoxy(20,10);
		    printf("Name:%s",employee.name);
		    gotoxy(20,11);
		    printf("Designation:%s ",employee.designation);
		    gotoxy(20,12);
		    printf("Experience:%d ",employee.wex);
		    gotoxy(20,13);
            printf("Gender:%s",employee.gender);
            gotoxy(15,16);
		    for(i=15;i<=64;i++)
            {
                 printf("*");
            }
             gotoxy(31,8);
             for(i=9;i<=15;i++)
            {
                gotoxy(64,i);
                printf("*");
            }
		    d++; //employee record found
		    }
	    }
	    if(d==0)
        {
	        gotoxy(22,9);
	        printf("\aNo Record Found");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchemployees();
	    else
	        adoption();
	        break;
	}
	case'3':
        adoption();
        break;
        default:
        getch();
        searchemployees();
    }
    fclose(fp);
}
void deleteemployee()
{
    system("cls");
    system("COLOR 1B");
    int d;
    char another='y';
    while(another=='y')
    {
        system("cls");
        system("COLOR 1F");
        gotoxy(10,5);
        printf("Enter the Employee ID to  delete:");
        scanf("%d",&d);
        fp=fopen("debian.dat","rb+");
        rewind(fp);
    while(fread(&employee,sizeof(employee),1,fp)==1)
    {
    if(employee.id==d)
    {
        gotoxy(10,7);
        printf("The information of your searched employee.");
        gotoxy(10,8);
        printf("Employee name is %s",employee.name);
        gotoxy(10,9);
        printf("Designation is %s",employee.designation);
        findemployee='t';
    }
    }
    if(findemployee!='t')
    {

        gotoxy(10,10);
        printf("No record is found modify the search");
        if(getch())
        adoption();
    }
    if(findemployee=='t' )
    {

        gotoxy(10,9);
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
            ft=fopen("ubuntu.dat","wb+"); //create a binary file for read and write
            rewind(fp);
       while(fread(&employee,sizeof(employee),1,fp)==1)
       {
       if(employee.id!=d)
       {
           fseek(ft,0,SEEK_CUR); //SEEK_CUR = Current position of the file pointer
           fwrite(&employee,sizeof(employee),1,ft); //stream:-This is the pointer to a FILE object that identifies the stream.
       }
    }
    fclose(ft);
    fclose(fp);
    remove("debian.dat");
    rename("ubuntu.dat","debian.dat"); //if the file rename successful then zero is returned. On error, -1 is returned
    fp=fopen("debian.dat","rb+"); //rb read a binary file
    if(findemployee=='t')
    {
        gotoxy(10,10);
        printf("The record is successfully deleted");
        gotoxy(10,11);
        printf("Delete another employee record?(Y/N)");
    }
    }
    else
    {
       adoption();
       fflush(stdin);
       another=getch();
    }
    }
    }
    gotoxy(10,15);
    adoption();
}
void editemployee()
{
    system("cls");
    system("COLOR 1B");
    int c=0;
    int d,e;
    gotoxy(20,4);
    char another='y';
    while(another=='y')
        {

            system("cls");
            gotoxy(15,6);
            printf("Enter Employee Id to be edited:");
            scanf("%d",&d); //storing employee id
            fp=fopen("debian.dat","rb+");
    while(fread(&employee,sizeof(employee),1,fp)==1)
       {

           if(checkid(d)==0)
           {

               gotoxy(15,8);
               printf("The Employee ID:%d",employee.id);
               gotoxy(20,9);
               printf(" Name:\n");
               gotoxy(26,9);
               scanf("%s",&employee.name);
               gotoxy(21,10);
               printf("Designation:");
               gotoxy(34,10);
               scanf("%s",&employee.designation);
               gotoxy(21,11);
               printf("Work Experience :");
               scanf("%s",&employee.wex);
               gotoxy(21,12);
               printf("Enter Employee gender:");
               gotoxy(43,12);
               scanf("%s",&employee.gender);
               gotoxy(21,13);
               printf("The record is modified");
               fseek(fp,ftell(fp)-sizeof(employee),0); //ftell() - It tells the byte location of current position in file pointer.
               fwrite(&employee,sizeof(employee),1,fp);
               fclose(fp);
               c=1;
       }
       if(c==0)
      {
         gotoxy(15,9);
         printf("No record found");
      }
    }
    gotoxy(15,16);
    printf("Modify another Record?(Y/N)");
    fflush(stdin);
    another=getch() ;
    }
    returnfunc();
}
void returnfunc()
{
    {
        printf(" Press ENTER to return to admin menu");
    }
    employee:
    if(getch()==13)
    adoption();
    else
    goto employee;
}
int ti()
{
    time_t tm; /* The time_t data type is a data type in the ISO C library defined for storing system time values.
    The current calendar time as a time_t object.It express calendar time */
    time(&tm);
    printf("%s",ctime(&tm)); //weekday,month,day of the month,hh:mm:ss,year.
}
void searchalltmr()
{

    system("cls");
    system("COLOR 1A");
    gotoxy(21,2);
    printf("VIEW EMPLOYEE INFORMATION");
    gotoxy(1,5);
    printf("Employee ID  Employee Name     Time Logged In     Time Logged Out ");
    rewind(fp);
    posx=3;
    posy=7;
    while(fread(&employee,sizeof(employee),1,fp)==1)
    {
        employee.name[0]=toupper(employee.name[0]); //C library function toupper() converts lowercase letter to uppercase.
        gotoxy(posx,posy);
        printf("%d",employee.id);
        gotoxy(posx+10,posy);
        printf("| %s, ",employee.name); /* | symbol is 'bitwise inclusive OR'.The bitwise inclusive OR operator (|) compares
        each bit of its first operand to the corresponding bit of its second operand. */
        gotoxy(posx+30,posy);

    if (employee.loginhour=='t')
    {
        printf("| Not Logged In");
    }
    else
        printf("| %d",employee.loginhour);
        gotoxy(posx+49,posy);
    if (employee.logouthour=='t')
    {
         printf("| Not Logged Out");
    }
    else
    printf("| %d",employee.logouthour);
    posy=posy+1;
    }
    getch();
    printf("\n");
    timerecord();
}
void searchalltmremployee()
{

    system("cls");
    system("COLOR 1B");
    gotoxy(21,2);
    printf("VIEW EMPLOYEE INFORMATION");
    gotoxy(1,5);
    printf("Employee ID  Employee Name     Time Logged In     Time Logged Out  ");
    rewind(fp);
    posx=3;
    posy=7;
   while(fread(&employee,sizeof(employee),1,fp)==1)
    {

        employee.name[0]=toupper(employee.name[0]);
        gotoxy(posx,posy);
        printf("%d",employee.id);
        gotoxy(posx+10,posy);
        printf("| %s, ",employee.name);
        gotoxy(posx+30,posy);

        if (employee.loginhour=='t')
          {
               printf("| Not Logged In");
          }
        else
            printf("| %d", employee.loginhour);
            gotoxy(posx+49,posy);
        if (employee.logouthour=='t')
        {
            printf("| Not Logged Out");
        }
        else
            printf("| %d",employee.logouthour);
            posy=posy+1;
        }
        getch();
        printf("\n");
        timerecord1();
  }
void particularemployeesearch()
  {

      system("cls");
      system("COLOR 1B");
      gotoxy(27,5);
      printf("SEARCH EMPLOYEE INFORMATION");
      gotoxy(25,9);
      printf("Enter Employee Id to Search: ");
      scanf("%d", &searchid);
      findemployee='f';
      rewind(fp);
      while(fread(&employee,sizeof(employee),1,fp)==1)
   {
       if (employee.id==searchid)
       {
           gotoxy(33,11);
           printf("Employee Information is Available.");
           gotoxy(25,13);
           printf("Employee name is:  %s",employee.name);
      if(employee.loginhour=='t')
     {
           gotoxy(25,14);
           printf("Log In Time: Not Logged In");
     }
    else
    {
        gotoxy(25,14);
        printf("Log In Time is: %d",employee.loginhour);
    }
    if(employee.logouthour=='t')
    {
        gotoxy(25,15);
        printf("Log Out Time: Not Logged Out");
    }
    else
    {
        gotoxy(25,15);
        printf("Log Out Time is: %d",employee.logouthour);
    }
    findemployee='t';
    getch();
    timerecord();
    }
    }
   if (findemployee!='t')
    {
        gotoxy(05,11);
        printf("Employee Information not available. Please modify the search.");
        getch();
        timerecord();
        getch();
   }
  }
void particularemployeesearchforemployee()
  {
      system("cls");
      system("COLOR 1B");
      gotoxy(27,5);
      printf("SEARCH EMPLOYEE INFORMATION");
      gotoxy(25,9);
      printf("Enter Employee Id to Search: ");
      scanf("%d", &searchid);
      findemployee='f';
      rewind(fp);
      while(fread(&employee,sizeof(employee),1,fp)==1)
       {
       if (employee.id==searchid)
       {
           gotoxy(33,11);
           printf("Employee Information is Available.");
           gotoxy(25,13);
           printf("Employee name is:  %s",employee.name);

      if(employee.loginhour=='t')
      {
          gotoxy(25,14);
          printf("Log In Time: Not Logged In");
      }
     else
     {
          gotoxy(25,14);
          printf("Log In Time is: %d",employee.loginhour);
     }
     if(employee.logouthour=='t')
     {
          gotoxy(25,15);
          printf("Log Out Time: Not Logged Out");
     }
     else
     {
         gotoxy(25,15);
         printf("Log Out Time is: %d",employee.logouthour);
     }
     findemployee='f';
     getch();
     timerecord1();
     }
     }

     if (findemployee!='f')
    {
        gotoxy(12,11);
        printf("Employee Information not available. Please modify the search.");
        getch();
        timerecord1();
    }
  }
 int finish()
  {
      system("cls");
      gotoxy(1,1);
      Sleep(500);
      exit(0);
  }
void recordlogintime()
  {
       system("cls");
       system("COLOR 1B");
       int searchid;
       gotoxy(20,4);
       printf("DAILY EMPLOYEE TIME RECORDING SYSTEM");
       gotoxy(20,23);
       printf("Warning: Please Enter Numeric Values Only.");
       gotoxy(23,7);
       printf("Enter Your Id to Login: ");
       scanf("%d", &searchid);
       gotoxy(20,23);
       printf("                                            ");
       findemployee='t';
       fp=fopen("debian.dat","rb");
       rewind(fp);

       while(fread(&employee,sizeof(employee),1,fp)==1)
       {
           if(employee.id == searchid )
           {

               gotoxy(23,11);
               printf("You have successfully Logged In the System.");
               gotoxy(23,13);
               printf("Employee name: %s",employee.name);
               gotoxy(23,14);
               printf("Your LogIn Time: %d");
               ti();
               gotoxy(23,15);
               fseek(fp,sizeof(employee),SEEK_CUR);
               employee.loginhour=ti();
               fwrite(&employee,sizeof(employee),1,fp);
               fclose(fp);
               findemployee='t';
               fflush(stdin);
               getch();
          }
        }
       if (findemployee=='t')
       {
            gotoxy(30,11);
            timerecord1();
            getch();
       }
       else
       {
            printf("Employee Information is not available.");
            getch();
            mainmenu();

       }
       mainmenu();
       }
   void recordlogouttime()
   {
       system("cls");
       system("COLOR 1B");
       gotoxy(20,4);
       printf("DAILY EMPLOYEE TIME RECORDING SYSTEM");
       gotoxy(20,23);
       printf("Warning: Please Enter Numeric Values Only.");
       gotoxy(23,7);
       printf("Enter Your Id to Logout: ");
       scanf("%d",&searchid);
       gotoxy(20,23);
       printf("                                            ");
       findemployee='t';
       rewind(fp);
       while(fread(&employee,sizeof(employee),1,fp)==1)
       {
           if(checkid(searchid) == 0)
           {

               gotoxy(23,11);
               printf("You have successfully Logged Out of the System.");
               gotoxy(23,13);
               printf("Employee name is: %s",employee.name);
               int time= ti();
               gotoxy(23,14);
               printf("Your Log Out Time:%d",time);
               fseek(fp,-sizeof(employee),SEEK_CUR);
               employee.logouthour=time;
               fwrite(&employee,sizeof(employee),1,fp);
               findemployee='t';
               getch();
               mainmenu();

           }
       }
       if (findemployee!='t')
       {
           gotoxy(23,11);
           printf("Employee Information is not available.");
           getch();
           mainmenu();
            }
       }
       void t_number()
      {
           int i=1,j;
           system("cls");
           gotoxy(1,1);
           printf("                             Total Emplyoee");
           gotoxy(1,2);
           printf(" SI  CATEGORY     EMPLOYEE ID   EMPLOYEE NAME         RANK        GENDER ");
           j=4;
           fp=fopen("debian.dat","rb");
           while(fread(&employee,sizeof(employee),1,fp)==1)
     {
            gotoxy(4,j);
            printf("|%s",employee.department);
		    gotoxy(21,j);
            printf("|%d",employee.id);
		    gotoxy(32,j);
            printf("|%s",employee.name);
            gotoxy(55,j);
		    printf("|%s ",employee.designation);
		    gotoxy(67,j);
            printf("|%s",employee.gender);
            gotoxy(0,j);
            printf("|%d",i);
	        j++;
	        i=i+1;
      }
      gotoxy(3,25);
      printf("Total number of employee =%d",i-1);
      fclose(fp);
      gotoxy(35,25);
      getch();
      adoption();
    }
