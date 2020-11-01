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

//Definig Structures


struct contact
{
    /* data */
    char contact_Name[30];
    unsigned int primary_Number;
    char about_Primary_Number[100];
    unsigned int secondary_Number;
    char about_Secondary_Number[100];
}add, modify, check;




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

void View_Directory()
{
    FILE *view;
    view=fopen("data.dat","r");
    int test=0;
    while (fscanf(view, "%s %u %s %u %s \n", add.contact_Name, &add.primary_Number, add.about_Primary_Number, &add.secondary_Number, add.about_Secondary_Number)!=EOF)
    {
        printf("+---------------------+\n");
        printf("| Contact Information |\n");
        printf("+---------------------+----+----------------------------+\n");
        printf("| Contact Name             |  %s\t\t\t|\n", add.contact_Name);
        printf("| Primary Phone Number     |  %u\t\t\t|\n", add.primary_Number);
        printf("| Description              |  %s\t\t\t|\n", add.about_Primary_Number);
        printf("| Secondry Phone Number    |  %u\t\t\t|\n", add.secondary_Number);
        printf("| Description              |  %s\t\t\t|\n", add.about_Secondary_Number);
        printf("+--------------------------+----------------------------+\n\n");
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

        scanf(" %d",&main_exit);
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
    int choice;
    ptr=fopen("data.dat","r");
    printf("Do you want to Search by\n");
    printf("1.Contact Name \n2. Phone Number \nEnter your choice:");
    scanf(" %d",&choice);
    if (choice==1)
    {
        printf("Enter the Contact Name:> ");
        scanf("%s", check.contact_Name);

        while(fscanf(ptr, "%s %u %s %u %s \n", add.contact_Name, &add.primary_Number, add.about_Primary_Number, &add.secondary_Number, add.about_Secondary_Number)!=EOF)
        {
            if (strcmp(check.contact_Name, add.contact_Name) == 0)
            {   
                printf("+---------------------+\n");
                printf("| Contact Information |\n");
                printf("+-------------------------------------------------------+\n");
                printf("| Contact Name             |  %s\t\t\t|\n", add.contact_Name);
                printf("| Primary Phone Number     |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Primary_Number);
                printf("| Secondry Phone Number    |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Secondary_Number);
                printf("+-------------------------------------------------------+\n\n");
                test++;
            }
            
        }
    }
    else if (choice==2)
    {
        printf("Enter the Contact Number:> ");
        scanf("%u", &check.primary_Number);

        while(fscanf(ptr, "%s %u %s %u %s \n", add.contact_Name, &add.primary_Number, add.about_Primary_Number, &add.secondary_Number, add.about_Secondary_Number)!=EOF)
        {
            if (add.primary_Number == check.primary_Number || add.secondary_Number == check.primary_Number)
            {   
                printf("+---------------------+\n");
                printf("| Contact Information |\n");
                printf("+-------------------------------------------------------+\n");
                printf("| Contact Name             |  %s\t\t\t|\n", add.contact_Name);
                printf("| Primary Phone Number     |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Primary_Number);
                printf("| Secondry Phone Number    |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Secondary_Number);
                printf("+-------------------------------------------------------+\n\n");
                test++;
            }
            
        }

    }
    if (test == 0)
        printf("Contact Not Found\n\n");

    fclose(ptr);

    view_list:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        getchar();
        scanf(" %d",&main_exit);
        
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
            goto view_list;
        }

}

void Add_Contact()
{
    FILE *filePointer;

    filePointer = fopen("data.dat","a+");
    printf("\n\n------------------------------------------");
    printf("\n \tAdd Contact Section\n");
    printf("\tEnter Information of New Contact\n");
    printf("--------------------------------------------\n");
    printf("Enter Contact Name :>  ");
    scanf("%s", add.contact_Name);
    printf("Enter the Primary Number :> ");
    scanf(" %u", &add.primary_Number);
    printf("Enter Some Description of Phone Number \n");
    printf("This maybe something like “WhatsApp number” or “Home number” etc.\n");
    scanf("%s%*c", add.about_Primary_Number);
    printf("Enter the Secondary Number :> ");
    scanf(" %u", &add.secondary_Number);
    printf("Enter Some Description of Phone Number \n");
    printf("This maybe something like “WhatsApp number” or “Home number” etc.\n");
    scanf("%s%*c", add.about_Secondary_Number);
    printf("\n");
    fprintf(filePointer, "%s %u %s %u %s \n", add.contact_Name, add.primary_Number, add.about_Primary_Number, add.secondary_Number, add.about_Secondary_Number);
    fclose(filePointer);
    printf("\nNew Contact Information Added Successfully\n");
    printf("--------------------------------------------\n\n");
}


void Modify_Contact()
{
    FILE *old,*newrec;
    int choice;

    int test;
    
    old = fopen("data.dat","r");
    newrec = fopen("new.dat","w");

    printf("Enter The Name of Contact whom Information you want to Modify");
    scanf("%s", modify.contact_Name);
    while(fscanf(old, "%s %u %s %u %s \n", add.contact_Name,&add.primary_Number, add.about_Primary_Number,&add.secondary_Number, add.about_Secondary_Number));
    {
        if (add.contact_Name == modify.contact_Name)
        {
            int test = 1;
            printf("\n\n|----------------------------------------------------------|\n");
            printf("| Which information do you want to change?                 |\n");
            printf("| 1. Contact Name                                          |\n");
            printf("| 2. Primary Phone Number                                  |\n");
            printf("| 3. Description of Primary Phone Number                   |\n");
            printf("| 4. Primary Secondary Number                              |\n");
            printf("| 5. Description of Secondary Phone Number                 |\n");
            printf("|----------------------------------------------------------|");
            printf("\nEnter your choice (form | 1 | 2 | 3 | 4 | 5 |):");

            scanf("%u", &choice);
            if (choice == 1)
            {
                printf("Enter New Contact Name :> ");
                scanf("%s", modify.contact_Name);
                fprintf(newrec, "%s %u %s %u %s \n", modify.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter New Primary Contact Number :> ");
                scanf("%u", &modify.primary_Number);
                fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name, modify.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                printf("Changes saved!");
            }
            else if (choice == 3)
            {
                printf("Enter New Description of Primary Contact Number :> ");
                scanf("%s", modify.about_Primary_Number);
                fprintf(newrec, "%s %u %s %u %s \n", modify.contact_Name, modify.primary_Number, modify.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                printf("Changes saved!");
            }
            else if (choice == 4)
            {
                printf("Enter New Secondary Contact Number :> ");
                scanf("%u", &modify.secondary_Number);
                fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number, modify.secondary_Number, add.about_Secondary_Number);
                printf("Changes saved!");
            }
            else if (choice == 5)
            {
                printf("Enter New Description of Secondary Contact Number :> ");
                scanf("%s", modify.about_Secondary_Number);
                fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, modify.about_Secondary_Number);
                printf("Changes saved!");
            }
            else
            {
                fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
            }
            
        }
    fclose(old);
    fclose(newrec);
    remove("data.dat");
    rename("new.dat","data.dat");
    }
    int inp;
    if (test != 1)
    {
        printf("No Record Found!!!  \n");
        
        edit_invalid:
            printf("\nEnter \n0 to try again, \n1 to return to main menu \n2 to exit:");
            
            scanf("%u ", &inp);
            
            if (inp == 0)
            {
                Modify_Contact();
            }
            else if (inp == 1)
            {
                /* code */
                Display_Options();
            }
            else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
    }
    else
        {
            printf("\n\n\nEnter \n1 to go to the Main Menu and \n0 to Exit:");
            scanf("%u",&inp);
            //system("cls");
            if (inp ==1)
                Display_Options();
            else
                exit(0);
        }

}

void Delete_Contact()
{
    FILE *ptr,*newrec;
    int choice;

    int test;
    
    ptr = fopen("data.dat","r");
    newrec = fopen("new.dat","w");

    printf("How do wish to Search Contact for Deletion\n");
    printf("1.Contact Name \n2. Phone Number \nEnter your choice:");
    scanf("%u",&choice);
    if (choice==1)
    {
        printf("Enter the Contact Name:> ");
        scanf(" %s", check.contact_Name);

        while(fscanf(ptr, "%s %u %s %u %s \n", add.contact_Name, &add.primary_Number, add.about_Primary_Number, &add.secondary_Number, add.about_Secondary_Number)!=EOF)
        {
            if (strcmp(check.contact_Name, add.contact_Name) == 0)
            {   
                printf("+---------------------+\n");
                printf("| Contact Information |\n");
                printf("+--------------------------+----------------------------+\n");
                printf("| Contact Name             |  %s\t\t\t|\n", add.contact_Name);
                printf("| Primary Phone Number     |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Primary_Number);
                printf("| Secondry Phone Number    |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Secondary_Number);
                printf("+--------------------------+----------------------------+\n\n\n");

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
                    test++;
                    break;
                case 'y':
                    /* code */
                    test++;
                    break;

                case 'N':
                    /* code */
                    test=-1;
                    fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                    break;
                case 'n':
                    /* code */
                    test =-1;
                    fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                    break;
                default:
                    break;
                }
                
            }
            else 
            {
                fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
            }
            
        }
    }
    else if (choice==2)
    {
        printf("Enter the Contact Number:> ");
        scanf("%u", &check.primary_Number);

        while(fscanf(ptr, "%s %u %s %u %s \n", add.contact_Name, &add.primary_Number, add.about_Primary_Number, &add.secondary_Number, add.about_Secondary_Number)!=EOF)
        {
            if (add.primary_Number == check.primary_Number || add.secondary_Number == check.primary_Number)
            {   
                printf("+---------------------+\n");
                printf("| Contact Information |\n");
                printf("+--------------------------+----------------------------+\n");
                printf("| Contact Name             |  %s\t\t\t|\n", add.contact_Name);
                printf("| Primary Phone Number     |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Primary_Number);
                printf("| Secondry Phone Number    |  %u\t\t\t|\n", add.primary_Number);
                printf("| Description              |  %s\t\t\t|\n", add.about_Secondary_Number);
                printf("+--------------------------+----------------------------+\n\n");
                
                printf("Are you sure you want to delete this Contact\n");
                printf("(Y/N) :> ");
                char choice;
                choice = getchar();
                switch (choice)
                {
                case 'Y':
                    /* code */
                    test++;
                    break;
                case 'y':
                    /* code */
                    test++;
                    break;

                case 'N':
                    /* code */
                    test=-1;
                    fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                    break;
                case 'n':
                    /* code */
                    test = -1;
                    fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
                    break;
                default:
                    break;
                }
            }
            else 
            {
                fprintf(newrec, "%s %u %s %u %s \n", add.contact_Name,add.primary_Number, add.about_Primary_Number,add.secondary_Number, add.about_Secondary_Number);
            }
            
        }

    }
    fclose(ptr);
    fclose(newrec);
    remove("data.dat");
    rename("new.dat","data.dat");

    if (test > 0)
        printf("Contact Deleted Successfully\n\n");
    
    else if(test ==-1)
    {
        printf("Contact Not Deleted \n\n");
    }
    
    else
    {
        printf("Contact Not Found\n\n");
    }
    view_list:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        getchar();
        scanf(" %d",&main_exit);
        
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
            goto view_list;
        }

}


// main function

int main()
{
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