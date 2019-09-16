//application Form
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LENGTH 40
#define FILE_NAME "ApplicationDetails.dat"
void ReadData();
void Update();
void ShowData();
struct Student
{
int ApplicationNumber;
char Name[LENGTH];
int Marks;
};
FILE *fp;
struct Student s;
void main()
{
int choice;
printf("\nEnter any number from 1, 2 and 3 ");
printf("\n1- Fill the application form ");
printf("\n2- See the filled application form ");
printf("\n3- Update the details ");
printf("\n4- Exit ");
scanf("%d", &choice);
switch(choice)
{
case 1:	
ReadData();
break;
case 2: 
ShowData();
break;
case 3: 
Update();
break;
case 4: 
exit(0);
break;	
default:
printf("Enter the correct choice: ");
break;	
}
}
void ReadData()
{
fp=fopen(FILE_NAME, "a");
printf("           -------------------------APPLICATION FORM-------------------------");
printf("\n");
printf("\nApplicationNumber: ");
scanf("%d", &s.ApplicationNumber);
printf("\nName: ");
scanf("%s", s.Name);
printf("\nMarks: ");
scanf("%d", &s.Marks);
fwrite(&s, sizeof(struct Student), 1, fp);
fclose(fp);
}
void ShowData()
{
int value;
fp=fopen(FILE_NAME, "r");
printf("Enter the ApplicationNumber: ");
scanf("%d", &value);
while(fread(&s, sizeof(struct Student), 1, fp)==1)
{
if(value==s.ApplicationNumber)
{
printf("                 ---------------APPLICATION FORM---------------");
printf("\nName: %s", s.Name);
printf("\nMarks: %d", s.Marks);
break;
}
}
fclose(fp);
}
void Update()
{
int number, count;
printf("Enter the Application Number: ");
scanf("%d", &number);
fp=fopen(FILE_NAME, "r+");
while(fread(&s, sizeof(struct Student), 1, fp)==1)
{
if(number==s.ApplicationNumber)
{
printf("Enter a number to update the data: ");
printf("\n1- Update Name");
printf("\n2- Update Marks");
scanf("%d", &count);
switch(count)
{
case 1: 
printf("Enter Name: ");
scanf("%s", s.Name);
break;
case 2: 
printf("Enter Marks: ");
scanf("%d", &s.Marks);
break;
default:
printf("\nEnter valid data!!\nTry again. ");
       break;
}
break;	
}	
}
fseek(fp, -sizeof(struct Student), SEEK_CUR);
fwrite(&s, sizeof(struct Student), 1, fp);
fclose(fp); 
}


