/*	
	Title			: Phone Directory Management System
	Language		: C
	Author			: Ravi Prakash Singh
	Date Created	: 25-10-2020
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main_exit;

struct Numbers
{
    //data
    char MobileNumber[15];
    char aboutNumber[30];

};



struct Contact
{
    /* data */
    char contact_Name[30];
    int num_Of_Num;
    struct Numbers *numbers;
}display;


//function declaraions

void Display_Options(); //To display Options
void Select_Option();  //To let user Select from available option
void View_Directory(); //To view all available contacts in one go 
void Search_Contact(); //To search Contact in Directory
void Add_Contact();    //For adding contact to directory
void Modify_Contact(); //Mofify any contact information
void Delete_Contact(); //Delete a contact from directory



void Display_Options()
{
    printf("+---------------------------------------------+\n");
    printf("| Enter a command :                           |\n");
    printf("| V - View Directory                          |\n");
    printf("| A - Add Contact                             |\n");
    printf("| S - For Search                              |\n");
    printf("| M - Modify Contact                          |\n");
    printf("| D - Delete Contact                          |\n");
    printf("| L - Log Out                                 |\n");
    printf("+---------------------------------------------+\n\n");
    printf("Enter One of the Options from Above to continue : ");
}

void Select_Option()
{
    while(1)
    {
        char option;
        Display_Options();
        option = getchar();
        printf("\n");
        printf("You Entered the Option :> %c \n", option);
        switch(option)
        {
            case 'V': View_Directory();
                    break;
            case 'v': View_Directory();
                    break;
            
            case 'A': Add_Contact();
                    break;
            case 'a': Add_Contact();
                    break;
            
            case 'M': Modify_Contact();
                    break;
            case 'm': Modify_Contact();
                    break;

            case 'S': Search_Contact();
                    break;
            case 's': Search_Contact();
                    break;
            
            case 'D': Delete_Contact();
                    break;
            case 'd': Delete_Contact();
                    break;

            case 'L': system("clear");
                    exit(0);
            case 'l': system("clear");
                    exit(0);
            default : Select_Option();
                    break;
        }
    }

}

void Add_Contact()
{
    FILE *filePointer;

    filePointer = fopen("data.txt","a+");

    struct Contact add;

    printf("\n\n------------------------------------------");
    printf("\n \tAdd Contact Section\n");
    printf("\tEnter Information of New Contact\n");
    printf("--------------------------------------------\n");
    
    printf("Enter Contact Name :>  ");
    scanf(" %[^\n]%*c", add.contact_Name);
    
    printf("Enter Number of Phone Nunbers for Contact %s :> ", add.contact_Name);
    scanf("%d", &add.num_Of_Num);

    int n = add.num_Of_Num;

    fprintf(filePointer, "%s\n%d\n", add.contact_Name, n);

    add.numbers = (struct Numbers*) malloc(n*sizeof(struct Numbers));

    for(int i=0; i<n; i++)
    {
        printf("\nNumber %d : ", i+1);
        scanf("%s", add.numbers[i].MobileNumber);
        printf("Enter Some Description of Phone Number \n");
        printf("This maybe something like “WhatsApp Number” or “Home Number” etc.\n");
        getchar();
        printf("Enter :>");
        scanf(" %[^\n]%*c", add.numbers[i].aboutNumber);
        fprintf(filePointer, "%s %s\n", add.numbers[i].MobileNumber, add.numbers[i].aboutNumber);
    }
    // fwrite(&add, sizeof(add), 1, filePointer);
    printf("\n");
    fclose(filePointer);
    printf("\nNew Contact Information Added Successfully\n");
    printf("--------------------------------------------\n\n");
}


void View_Directory()
{
    FILE *view;
    view=fopen("data.txt","r");
    if (view == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        Select_Option();
    }

    int test=0;
    
    struct Contact display;
    
    char mobile[15];
    char about[30];
    
    while (fscanf(view, "%[^\n]\n%d\n", display.contact_Name, &display.num_Of_Num)!=EOF)
    {
        int n = display.num_Of_Num;
        printf("+---------------------+\n");
        printf("| Contact Information |\n");
        printf("+---------------------+-----------------------------\n");
        printf("| Contact Name        |  %s\t\t\t\n", display.contact_Name);
        printf("+---------------------+-----------------------------\n");
        for (int i = 0; i < n; i++)
        {
            fscanf(view, "%s %[^\n]\n", mobile, about);
            printf("| Phone Number        |  %s\t\t\t\n", mobile);
            printf("+---------------------+------------------------------\n");
            printf("| Description         |  %s\t\t\t\n", about);
            printf("+---------------------+------------------------------\n");
        }
        printf("\n\n");
        test++;
    }

    fclose(view);

    if (test==0)
        {   
            system("clear");
            printf("\nNO RECORDS FOUND!!\n");
        }

    view_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");

        scanf("%d",&main_exit);
        //system("clear");
        
        if (main_exit==1)
        {
            printf("\n\n");
            Select_Option();
        }
        
        else if(main_exit==0)
        {
            exit(0);
        }
        
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
     
}

void Search_Contact()
{
    FILE *ptr;
    int test=0;

    ptr = fopen("data.txt","r");
    
    char mobile[15];
    char about[30];
    struct Contact search;
    char Name[30];

    printf("\n\n------------------------------------------");
    printf("\n \tSearch Contact Section\n");
    printf("\tSearch  Contact  Information  Here\n");
    printf("--------------------------------------------\n");

    printf("Enter the name of Contact You Want to Search \n");
    printf("Enter the Contact Name:> ");
    scanf(" %[^\n]%*c", Name);
    while (fscanf(ptr, "%[^\n]\n%d\n", search.contact_Name, &search.num_Of_Num)!=EOF)
    {
        if (strcmp(search.contact_Name, Name) == 0)
        {
            int n = search.num_Of_Num;
            printf("+---------------------+\n");
            printf("| Contact Information |\n");
            printf("+---------------------+-----------------------------\n");
            printf("| Contact Name        |  %s\t\t\t\n", search.contact_Name);
            printf("+---------------------+-----------------------------\n");
            for (int i = 0; i < n; i++)
            {
                fscanf(ptr, "%s %[^\n]\n", mobile, about);
                printf("| Phone Number        |  %s\t\t\t\n", mobile);
                printf("+---------------------+------------------------------\n");
                printf("| Description         |  %s\t\t\t\n", about);
                printf("+---------------------+------------------------------\n");
            }
            test++;
            printf("\n\n");

        }
    }
    if (test == 0)
        printf("Contact Not Found\n\n");

    fclose(ptr);

    int option;
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf(" %d",&option);
    
    if (option==1)
    {
        printf("\n\n");
        Select_Option();
    }
    
    else if(option==0)
    {
        exit(0);
    }
    
    else
    {
        printf("\nInvalid!\a");
        Select_Option();
    }

}


void Delete_Contact()
{
    FILE *ptr,*newrec;
    int choice;

    int test = 0;
    
    ptr = fopen("data.txt","r");
    newrec = fopen("new.txt","w");

    char mobile[15];
    char about[30];
    int n;
    struct Contact check; 
    struct Contact verify;

    printf("Enter the name of Contact You Want to Delete \n");
    printf("Enter the Contact Name:> ");
    scanf(" %[^\n]%*c", verify.contact_Name);
    while (fscanf(ptr, "%[^\n]\n%d\n", check.contact_Name, &check.num_Of_Num)!=EOF)
    {
        if (strcmp(verify.contact_Name, check.contact_Name) == 0)
        {
            n = check.num_Of_Num;
            printf("+---------------------+\n");
            printf("| Contact Information |\n");
            printf("+---------------------+-----------------------------\n");
            printf("| Contact Name        |  %s\t\t\t\n", check.contact_Name);
            printf("+---------------------+-----------------------------\n");
            for (int i = 0; i < n; i++)
            {
                fscanf(ptr, "%s %[^\n]\n", mobile, about);
                printf("| Phone Number        |  %s\t\t\t\n", mobile);
                printf("+---------------------+------------------------------\n");
                printf("| Description         |  %s\t\t\t\n", about);
                printf("+---------------------+------------------------------\n");
            }
            printf("\n\n");            
            printf("Are you sure you want to delete this Contact\n");
            printf("(Y/N) :> ");
            char choice;
            printf("\n");
            getchar();
            choice = getchar();
            printf("\n");
            switch (choice)
            {
            case 'Y':
                /* code */
                printf("Contact Deleted Successfully!!!\n");
                break;
            case 'y':
                /* code */
                printf("Contact Deleted Successfully!!!\n");
                test++;
                break;

            case 'N':
                /* code */
                printf("Contact Not Deleted \n\n");
                test=-1;
                fprintf(newrec, "%s\n%d\n", check.contact_Name, check.num_Of_Num);
                n = check.num_Of_Num;
                for (int i = 0; i < n; i++)
                {
                    fscanf(ptr, "%s %[^\n]\n", mobile, about);
                    fprintf(newrec, "%s %s\n", mobile, about);
                }
                break;
            case 'n':
                /* code */
                printf("Contact Not Deleted \n\n");
                test =-1;
                fprintf(newrec, "%s\n%d\n", check.contact_Name, check.num_Of_Num);
                int n = check.num_Of_Num;
                for (int i = 0; i < n; i++)
                {
                    fscanf(ptr, "%s %[^\n]\n", mobile, about);
                    fprintf(newrec, "%s %s\n", mobile, about);
                }
                break;
            
            default:
                break;
            }
                
        }

        else
        {
            /* code */
            fprintf(newrec, "%s\n%d\n", check.contact_Name, check.num_Of_Num);
            n = check.num_Of_Num;
            for (int i = 0; i < n; i++)
            {
                fscanf(ptr, "%s%[^\n]\n", mobile, about);
                fprintf(newrec, "%s %s\n", mobile, about);
            }

        }
           
            
    
    }
    
    fclose(ptr);
    fclose(newrec);
    remove("data.txt");
    rename("new.txt","data.txt");

    int option;
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf(" %d",&option);
    
    if (option==1)
    {
        printf("\n\n");
        Select_Option();
    }
    
    else if(option==0)
    {
        exit(0);
    }
    
    else
    {
        printf("\nInvalid!\a");
        Select_Option();
    }
    
}



void Modify_Contact()
{
    FILE *ptr,*newrec;
    int test=0;

    ptr = fopen("data.txt","r");
    newrec = fopen("new.txt","w");
    
    char mobile[15];
    char about[30];
    struct Contact search;
    struct Contact modify;
    char Name[30];
    int n;

    printf("\n\n------------------------------------------");
    printf("\n \tModify Contact Section\n");
    printf("\tSearch  Contact  Information  Here\n");
    printf("--------------------------------------------\n");

    printf("Enter the name of Contact You Want to Modify \n");
    printf("Enter the Contact Name:> ");
    scanf(" %[^\n]%*c", Name);
    while (fscanf(ptr, "%[^\n]\n%d\n", search.contact_Name, &search.num_Of_Num)!=EOF)
    {
        if (strcmp(search.contact_Name, Name) == 0)
        {
            int n = search.num_Of_Num;
            printf("+---------------------+\n");
            printf("| Contact Information |\n");
            printf("+---------------------+-----------------------------\n");
            printf("| Contact Name        |  %s\t\t\t\n", search.contact_Name);
            printf("+---------------------+-----------------------------\n");
            for (int i = 0; i < n; i++)
            {
                fscanf(ptr, "%s %[^\n]\n", mobile, about);
                printf("| Phone Number        |  %s\t\t\t\n", mobile);
                printf("+---------------------+------------------------------\n");
                printf("| Description         |  %s\t\t\t\n", about);
                printf("+---------------------+------------------------------\n");
            }
            test++;
            printf("\n\n");
            printf("\n\n");            
            
            printf("Are you sure you want to Modify this Contact\n");
            printf("(Y/N) :> ");
            char choice;
            printf("\n");
            choice = getchar();
            printf("\n");
            
            switch (choice)
            {
            case 'N':
                /* code */
                printf("Contact Not Modified!!!\n");
                fprintf(newrec, "%s\n%d\n", search.contact_Name, search.num_Of_Num);
                n = search.num_Of_Num;
                for (int i = 0; i < n; i++)
                {
                    fscanf(ptr, "%s %[^\n]\n", mobile, about);
                    fprintf(newrec, "%s %s\n", mobile, about);
                }
                break;
            case 'n':
                /* code */
                printf("Contact Not Modified!!!\n");
                fprintf(newrec, "%s\n%d\n", search.contact_Name, search.num_Of_Num);
                n = search.num_Of_Num;
                for (int i = 0; i < n; i++)
                {
                    fscanf(ptr, "%s %[^\n]\n", mobile, about);
                    fprintf(newrec, "%s %s\n", mobile, about);
                }
                test++;
                break;

            
            
            case 'Y':
                /* code */
                printf("Enter New Contact Information\n\n");
                printf("Enter Contact Name :>  ");
                scanf(" %[^\n]%*c", modify.contact_Name);
                
                printf("Enter Number of Phone Nunbers for Contact %s :> ", modify.contact_Name);
                scanf("%d", &modify.num_Of_Num);

                n = modify.num_Of_Num;

                fprintf(newrec, "%s\n%d\n", modify.contact_Name, n);

                modify.numbers = (struct Numbers*) malloc(n*sizeof(struct Numbers));

                for(int i=0; i<n; i++)
                {
                    printf("\nNumber %d : ", i+1);
                    scanf("%s", modify.numbers[i].MobileNumber);
                    printf("Enter Some Description of Phone Number \n");
                    printf("This maybe something like “WhatsApp Number” or “Home Number” etc.\n");
                    getchar();
                    printf("Enter :>");
                    scanf(" %[^\n]%*c", modify.numbers[i].aboutNumber);
                    fprintf(newrec, "%s %s\n", modify.numbers[i].MobileNumber, modify.numbers[i].aboutNumber);
                }
                
                break;


            case 'y':
                /* code */
                printf("Enter New Contact Information\n\n");
                printf("Enter Contact Name :>  ");
                scanf(" %[^\n]%*c", modify.contact_Name);
                
                printf("Enter Number of Phone Nunbers for Contact %s :> ", modify.contact_Name);
                scanf("%d", &modify.num_Of_Num);

                n = modify.num_Of_Num;

                fprintf(newrec, "%s\n%d\n", modify.contact_Name, n);

                modify.numbers = (struct Numbers*) malloc(n*sizeof(struct Numbers));

                for(int i=0; i<n; i++)
                {
                    printf("\nNumber %d : ", i+1);
                    scanf("%s", modify.numbers[i].MobileNumber);
                    printf("Enter Some Description of Phone Number \n");
                    printf("This maybe something like “WhatsApp Number” or “Home Number” etc.\n");
                    getchar();
                    printf("Enter :>");
                    scanf(" %[^\n]%*c", modify.numbers[i].aboutNumber);
                    fprintf(newrec, "%s %s\n", modify.numbers[i].MobileNumber, modify.numbers[i].aboutNumber);
                }
                break;
            
            default:
                break;
            }
                
        }

        else
        {
            /* code */
            fprintf(newrec, "%s\n%d\n", search.contact_Name, search.num_Of_Num);
            n = search.num_Of_Num;
            for (int i = 0; i < n; i++)
            {
                fscanf(ptr, "%s%[^\n]\n", mobile, about);
                fprintf(newrec, "%s %s\n", mobile, about);
            }

        }
    }

    fclose(ptr);
    fclose(newrec);
    remove("data.txt");
    rename("new.txt","data.txt");

    int option;
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf(" %d",&option);
    
    if (option==1)
    {
        printf("\n\n");
        Select_Option();
    }
    
    else if(option==0)
    {
        exit(0);
    }
    
    else
    {
        printf("\nInvalid!\a");
        Select_Option();
    }
}



// main function

int main()
{
    system("color 9");
    printf("+=======================================================================+\n");
    printf("|                 Welcome to Ravi's Phone Directory!                    |\n");
    printf("+=======================================================================+\n\n");


    printf("\t\t\tAvailable features \n");
    printf("\t+=============================================+\n");
    printf("\t| 1. Search Phone Directory                   |\n");
    printf("\t| 2. Add New Contact To Phone Directory       |\n");
    printf("\t| 3. Modify Phone Directory                   |\n");
    printf("\t| 4. Quit/Log out                             |\n");
    printf("\t| 5. Clear the screen and display available   |\n");
    printf("\t+=============================================+\n\n\n\n");
    
    Select_Option();
    
    return 0;
}