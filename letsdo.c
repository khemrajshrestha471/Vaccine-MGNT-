#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define no_of_vaccine 200
int password();
void menu();
void newRecord();
void vaccineDate();
void search();
void viewAvailable();
struct record
{
    char name[30], gender, profession[20], address[20], conf;
    int age, bp;
    float temperature;
    unsigned long long phone;
};

int main()
{
    int k = 3;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\tDeveloped By:- Khemraj Shrestha ");
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to continue.............  ");
    getch();
start:
    system("cls");
    printf("\n\n\t\t\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\t\tEnter User name and Password\n");
    printf("\t\t\t\t\t\t*********************************************\n");
    while (k >= 1)
    {

        int c = password();
        if (c == 1)
        {
            menu();
            break;
        }
        else
            printf("\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only %d times more", k - 1);
        k--;
        if (k < 1)
        {
            for (int i = 59; i >= 0; i--)
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!");
                printf("\n\n\n\n\n\n\t\t\t\t\tTRY AFTER %d SECONDS.....", i);
                Sleep(1000);
            }
            k = 3;
            goto start;
        }
    }
}

int password()
{
    char cname[30], pass[20];
    int ch, i = 0, cap = 0, capt = 0;
    printf("\n\n\n\n\n\t\t\t\t\tUSER NAME:  ");
    fflush(stdin);
    gets(cname);
    printf("\n\t\t\t\t\tPASSWORD:    ");
    while ((ch = getch()) != 13)
    {
        printf("*");
        pass[i] = ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap = rand();
    printf("\n\n\t\t\t\t AUTO GENERATED NUMBER:->  %d", cap);
    printf("\n\n\n\n\t\tPlease enter the valid auto_generated number :-   ");
    scanf("%d", &capt);
    if ((strcmp(cname, "a") == 0) && (strcmp(pass, "a") == 0) && cap == capt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void menu()
{
run:
    system("cls");
    int n1;
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t\t  MENU");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\t\t\t\t\t\t1: Add NEW Record\t\t\t 2: View Vaccine Data");
    printf("\n\n\n\n\t\t\t\t\t\t3: Search   \t\t\t\t 4: Exit");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tChoice:- ");
    scanf("%d", &n1);
    switch (n1)
    {
    case 1:
        newRecord();
        break;
    case 2:
    {
        vaccineDate();
        break;
    }
    case 3:
    {
        search();
        break;
    }
    case 4:
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t\tThank you for giving your valuable time for us. \n\t\t\t\t\t\t\t\t HAVE A GOOD DAY\n\n\n\n\n\n");
        exit(0);
    }
    default:
    {
        printf("\n\t\tWrong choice \n");
        char ch;
        printf("\n\t\tWanna stay in this page(y/n)?:- ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            goto run;
        }
        else
        {
            exit(0);
        }
    }
    }
}

void newRecord()
{
    system("cls");
    FILE *fp;
    fp = fopen("record.txt", "a");
    if (fp == NULL)
    {
        printf("\n\t\tError opening the file");
        exit(0);
    }
    else
    {
        system("cls");
        struct record rec;
        printf("\n\t\t\t\t\t\t\t*****************************************\n");
        printf("\t\t\t\t\t\t\t\t  RECORD INSERTING ZONE");
        printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
        fflush(stdin);
        printf("\n\t\t Enter your name :-  ");
        gets(rec.name);
        fflush(stdin);
        printf("\n\t\t Enter your gender (M|F) :-  ");
        scanf("%c", &rec.gender);
        fflush(stdin);
        printf("\n\t\t Enter your age:- ");
        scanf("%d", &rec.age);
        fflush(stdin);
        printf("\n\t\t Enter your profession :-  ");
        gets(rec.profession);
        fflush(stdin);
        printf("\n\t\t Enter your diastolic blood pressure(B.P) :-  ");
        scanf("%d", &rec.bp);
        fflush(stdin);
        printf("\n\t\t Enter your Body temperature (Fahrenheit):-  ");
        scanf("%f", &rec.temperature);
        fflush(stdin);
        printf("\n\t\t Enter your permanent address :-  ");
        gets(rec.address);
        fflush(stdin);
        printf("\n\t\t Enter your Mobile number:- ");
        scanf("%llu", &rec.phone);
        fflush(stdin);
    take1:
        fflush(stdin);
        printf("\n\n\n\n\t\t\t\t Hit dot(.) for conformation:- ");
        scanf("%c", &rec.conf);
        if (rec.conf != '.')
        {
            printf("\n\n\n\n\t\t\t\t (Please enter vallid character)\n");
            goto take1;
        }
        fflush(stdin);
        fwrite(&rec, sizeof(rec), 1, fp);
        fclose(fp);
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\tYour data is successfully recorded. That means, you are now vaccinated. \n\n\t\t\t\t\t\t\t\t STAY HOME STAY SAFE \n\n\n\n\n\n\n\n");
        printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
        getch();
        menu();
    }
}

void search()
{
    FILE *fp;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError opening file");
        exit(1);
    }
    int counter = 0;
    struct record rec;
    char pt_name[25], cht;
    int pt_age;
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t\t  SEARCH");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\t\t\t\t\t\t\tEnter name of patient:- ");
    fflush(stdin);
    gets(pt_name);
    printf("\n\n\t\t\t\t\t\t\tAge:- ");
    fflush(stdin);
    scanf("%d", &pt_age);
    while (fread(&rec, sizeof(rec), 1, fp) == 1)
    {
        if (((strcmp(pt_name, rec.name)) == 0) && (pt_age == rec.age))
        {
            counter = 1;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t\t\t\tName=>   %s\n", rec.name);
            printf("\n\t\t\t\t\t\t\tGender=>   %c\n", rec.gender);
            printf("\n\t\t\t\t\t\t\tAge=>   %d\n", rec.age);
            printf("\n\t\t\t\t\t\t\tProfession=>   %s\n", rec.profession);
            printf("\n\t\t\t\t\t\t\tBlood Pressure=>   %d\n", rec.bp);
            printf("\n\t\t\t\t\t\t\tBody Temperature=>   %.3f\n", rec.temperature);
            printf("\n\t\t\t\t\t\t\tPermanent Address=>   %s\n", rec.address);
            printf("\n\t\t\t\t\t\t\tPhone Number=>   %llu", rec.phone);
            printf("\n\n\n\n\n\n\n\n\n");
        }
    }
    if (!counter)
    {
        printf("\n\n\n\t\t\t\t\t\tThis person is not vaccoinated from this hospital.");
    }
    fclose(fp);
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
    getch();
    menu();
}

void vaccineDate()
{
run:
    system("cls");
    int n2;
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t  VACCINE STATISTICS");
    printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
    printf("\n\n\n\t\t\t\t\t\t1: View Available ");
    printf("\n\n\n\n\t\t\t\t\t\t2: Back");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tChoice:- ");
    scanf("%d", &n2);
    switch (n2)
    {
    case 1:
    {
        viewAvailable();
        break;
    }
    case 2:
    {
        menu();
        break;
    }
    default:
    {
        printf("\n\t\tWrong choice \n");
        char ch;
        printf("\n\t\tWanna stay in this page(y/n)?:- ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
            goto run;
        else
            exit(0);
    }
    }
}

void viewAvailable()
{
    FILE *fp;
    char ch;
    int add_no_of_vaccine = 0, rem_vaccine = 0, no_of_patients = 0;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError opening the file");
        exit(0);
    }
    ch = fgetc(fp);
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '.')
        {
            no_of_patients++;
        }
    }
    rem_vaccine = no_of_vaccine - no_of_patients;
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t   REMAINING VACCINE");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\n\t\t\t\t\t\tNumber of people vaccinated from this hospital:- %d", no_of_patients);
    printf("\n\n\t\t\t\t\t\tAvailable number of vaccine are:- %d \n", rem_vaccine);
    fclose(fp);
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
    getch();
    menu();
}