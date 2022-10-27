/*
This is the main file with name as main.c
This file includes many functions i.e. 
displayFeature, deleteBacklog,ProductOwnerRegister,
ReleaseManagerRegister, etc
*/


#include <stdio.h>
#include <stdlib.h>
#include <struct.h>
#include <main.h>

typedef struct
{
    int featureId;
    char featureName[max];
    int priority;
    char cost[cost_len];
} Features;





void main()     //This is the main Function
{
    int cho;
    printf("Press '1' to interact as Product Owner \nPress '2' to interact as Release Manager\n");
    scanf("%d", &cho);

    if (cho == 1)
    {
        int cho1;
        printf("****************PRODUCT OWNER****************\n");
        printf("Press '1' for Register \nPress '2' for Login\n");
        scanf("%d", &cho1);
        if (cho1 == 1)
        {
            
            ProductOwnerRegister();
        }
        else if (cho1 == 2)
        {
            int n;
            
            n = ProductOwnerLogin();
            
            if (n == 1)
            {  
                while (1)
                {

                    					    printf("---------------------------------------------\nSelect 1 to add the Features in the Product Backlog list\nSelect 2 to delete the Features from product Backlog List.\nSelect 3 to Display Feature Backlog List\nEnter 4 to Exit.\n----------------------------------------------\n");
                    int n = 0;
                    scanf("%d", &n);

                    switch (n)
                    {
                    case 1:
                        addProductBacklog();
                        break;
                    case 2:
                        deleteBacklog();
                        break;
                    case 3:
                        displayFeatureBacklog();
                        break;
                    case 4:
                        exit(0);
                    }
                }
            }
        }
    }

    else if (cho == 2)
    {
        printf("****************************Release Manager****************************\n");
        int cho2;
        printf("Press '1' for Register \nPress '2' for Login\n-----------------------------------------------------\n");
        scanf("%d", &cho2);
        if (cho2 == 1)
        {
            
            ReleaseManagerRegister();
        }
        else if (cho2 == 2)
        {
            int n;
            
            n = ReleaseManagerLogin();

            if (n == 1)
            {
                while (1)
                {
                    printf("---------------------------------\n\nEnter '1' to add feature\nEnter 2 To Display all the Release Features\nEnter 3 to delete a features\nEnter '4' for exit\n---------------------------------------------------------\n");
                    int choice;
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("Choose the features to be release from given list.\n-------------------------------------\n");
                        displayFeatureBacklog();
                        printf("-------------------------------------\nEnter the Feature Id to add in Release List:");
                        scanf("%d", &choice);
                        importFeatures(choice);
                        break;
                    case 2:
                        displayFeatureRelease();
                        break;
                    case 3:
                        deleteFeatures();
                        break; 
                    case 4:
                        exit(0);
                    }
                }
            }
        }
    }
}



struct login
{
    char pfname[pfname_len];
    char plname[plname_len];
    char pusername[pusername_len];
    char ppassword[ppassword_len];
    char rfname[rfname_len];
    char rlname[rlname_len];
    char rusername[rusername_len];
    char rpassword[rpassword_len];
};


/*
This Function will register the Product Owner.
It take First Name and Last name.
And For Authentication it takes username and password.

*/


int ProductOwnerRegister()
{
    FILE *log1;
    log1 = fopen("../data/POlogin.txt", "w");
    struct login l1;
    printf("Enter first name: ");
    scanf("%s", l1.pfname);
    printf("Enter last name: ");
    scanf("%s", l1.plname);
    printf("Enter Username: ");
    scanf("%s", l1.pusername);
    printf("Enter Password: ");
    scanf("%s", l1.ppassword);
    fwrite(&l1, sizeof(l1), 1, log1);

    fclose(log1);

    printf("\n\nYour Name is %s %s\n ",l1.pfname,l1.plname);
    printf("Now Login with UserID and Password\n\n");
    
    //printf("\n Press any key to continue....");
    //ProductOwnerLogin();

    main();
}





/*
This Function will register the Release Manager.
It take First Name and Last name.
And For Authentication it takes username and password.

*/

int ReleaseManagerRegister()
{
    FILE *log2;
    log2 = fopen("../data/RMlogin.txt", "w");
    struct login l2;
    printf("Enter first name: ");
    scanf("%s", l2.rfname);
    printf("Enter last name: ");
    scanf("%s", l2.rlname);
    printf("Enter Username: ");
    scanf("%s", l2.rusername);
    printf("Enter Password: ");
    scanf("%s", l2.rpassword);
    fwrite(&l2, sizeof(l2), 1, log2);

    fclose(log2);

    printf("\n\nyour Name is %s %s\n ",l2.rfname,l2.rlname);
    printf("Now Login with UserID and Password\n\n");
    

    //printf("\n Press any key to continue....");
    // ReleaseManagerLogin();

    main();
    
}




/*
This Function will login the Product Owner.
And For Authentication it takes username and password that was used during Registration.

*/

int ProductOwnerLogin()
{
    char pusername[20], ppassword[20];
    FILE *log1;
    log1 = fopen("../data/POlogin.txt", "r");
    struct login l1;
    printf("UserID: ");
    scanf("%s", &pusername);
    printf("Password: ");
    scanf("%s", &ppassword);

    while (fread(&l1, sizeof(l1), 1, log1))
    {
        if (strcmp(pusername, l1.pusername) == 0 && strcmp(ppassword, l1.ppassword) == 0)
        {
            printf("Successful login\n");
            return 1;
        }
        else
        {
            printf("Please Enter correct UserID or Password");
            return 0;
        }
    }
    fclose(log1);
    return 0;
}




/*
This Function will login the Release Manager.
And For Authentication it takes username and password that was used during Registration.

*/

int ReleaseManagerLogin()
{
    char rusername[20], rpassword[20];
    FILE *log2;
    log2 = fopen("../data/RMlogin.txt", "r");
    struct login l2;
    printf("UserID: ");
    scanf("%s", &rusername);
    printf("Password: ");
    scanf("%s", &rpassword);

    while (fread(&l2, sizeof(l2), 1, log2))
    {
        if (strcmp(rusername, l2.rusername) == 0 && strcmp(rpassword, l2.rpassword) == 0)
        {
            printf("Successfully login\n");
            return 1;
        }
        else
        {
            printf("Please Enter correct UserID or Password");
            return 0;
        }
    }
    fclose(log2);
    return 0;
}






/*
This Function will display all the Feature backlog added by Product Owner.

*/

int displayFeatureBacklog()
{
    FILE *file;
    file = fopen("../data/featuresBacklog.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    Features features[max];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file, "%d,%49[^,],%d,%s\n", &features[records].featureId, features[records].featureName, &features[records].priority, features[records].cost);

        if (read == 4)
            records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error Reading file\n");
            return 1;
        }
    } while (!feof(file));
    fclose(file);
    printf("There are total %d features\n--------------------------------------\n", records);
    for (int i = 0; i < records; i++)
    {
        printf("%d %s %d %s\n", features[i].featureId, features[i].featureName, features[i].priority, features[i].cost);
    }
    return 0;
}




/*
This Function will display all the Release Feature selected by Release Manager.

*/

int displayFeatureRelease()
{
    FILE *file;
    file = fopen("../data/releaseFeatures.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    Features features[max];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file, "%d,%49[^,],%d,%s\n", &features[records].featureId, features[records].featureName, &features[records].priority, features[records].cost);

        if (read == 4)
            records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error Reading file\n");
            return 1;
        }
    } while (!feof(file));
    fclose(file);
    printf("Records read is %d\n", records);
    for (int i = 0; i < records; i++)
    {
        printf("%d %s %d %s\n", features[i].featureId, features[i].featureName, features[i].priority, features[i].cost);
    }
    return 0;
}






/*
This Function will select the features one by one from Backlog list to release list.

*/

int importFeatures(int choice)
{
    FILE *file, *file2;
    file = fopen("../data/featuresBacklog.csv", "r");
    file2 = fopen("../data/releaseFeatures.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    Features features[max];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file, "%d,%49[^,],%d,%s\n", &features[records].featureId, features[records].featureName, &features[records].priority, features[records].cost);

        if (read == 4)
            records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error Reading file\n");
            return 1;
        }
    } while (!feof(file));
    fclose(file);
    // printf("Records read is %d\n", records);
    for (int i = 0; i < records; i++)
    {
        // printf("%d %s %d %d\n", features[i].featureId, features[i].featureName, features[i].priority, features[i].cost);
        if (features[i].featureId == choice)
        {
            fprintf(file2, "%d,%s,%d,%s\n", features[i].featureId, features[i].featureName, features[i].priority, features[i].cost);
            printf("Feature is Succesfully added to the Release List.\n");
        }
    }
    fclose(file2);
}




/*
This method is to add a particular feature which
Product Owner wanted to add
*/

int addProductBacklog()
{
    FILE *fp = fopen("../data/featuresBacklog.csv", "a+");
    int featureId;
    char featureName[max];
    int priority;
    char cost[10];
    printf("\nEnter Feature ID\n");
    scanf("%d", &featureId);
    printf("\nEnter Feature Name\n");
    scanf("%s", &featureName);
    printf("\nEnter Priority\n");
    scanf("%d", &priority);
    printf("\nEnter Feature Shirt Size\n");
    scanf("%s", &cost);

    fprintf(fp, "%d,%s,%d,%s\n", featureId,
            featureName, priority, cost);
    printf("Features are Added Successfully\n");
    fclose(fp);
    return 0;
}


/*
This method is to delete a particular Backlog feature which
Product Owner wanted to delete
*/

int deleteBacklog()
{
    FILE *fp1;
    FILE *fp2;

    char ch;

    int line = 0;
    int temp = 1;

    fp1 = fopen("../data/featuresBacklog.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
    }
    rewind(fp1);

    printf("\nEnter line number to delete the features: ");
    scanf("%d", &line);

    fp2 = fopen("temp.csv", "w");

    while (!feof(fp1))
    {
        ch = getc(fp1);

        if (ch == '\n')
            temp++;

        if (temp != line)
            putc(ch, fp2);
    }

    fclose(fp1);

    fclose(fp2);

    remove("../data/featuresBacklog.csv");
    rename("temp.csv", "../data/featuresBacklog.csv");

    printf("\nFeature is deleted Successfully:\n");

    fp1 = fopen("../data/featuresBacklog.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
       // printf("%c", ch);
    }

    fclose(fp1);

    printf("\n");

    return 0;
}



/*
This Function will delete the Release Features one by one if Release Manager want to remove/delete. 

*/

int deleteFeatures()
{
    FILE *fp1;
    FILE *fp2;

    char ch;

    int line = 0;
    int temp = 1;

    fp1 = fopen("../data/releaseFeatures.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
    }
    rewind(fp1);

    printf("\nEnter line number to delete the features: ");
    scanf("%d", &line);

    fp2 = fopen("temp.csv", "w");

    while (!feof(fp1))
    {
        ch = getc(fp1);

        if (ch == '\n')
            temp++;

        if (temp != line)
            putc(ch, fp2);
    }

    fclose(fp1);

    fclose(fp2);

    remove("../data/releaseFeatures.csv");
    rename("temp.csv", "../data/releaseFeatures.csv");

    printf("\nModified features are:\n");

    fp1 = fopen("../data/releaseFeatures.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
        
    }

    fclose(fp1);

    printf("\n");

    return 0;
}



