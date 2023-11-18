#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define FILENAME "blood_bank.txt"
#define MAX_RECORDS 1000

typedef struct {
    char name[30];
    int age;
    char gender[10];
    char blood_group[5];
    long contact_number;
    //char contact_number[15];
    char address[50];
} Donor;

void add_donor() {
    FILE *fp;
    Donor donor;
    fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }
    fflush(stdin);
    printf("Enter donor name: ");
    gets(donor.name);
    //scanf("%s",&donor.name);
    printf("Enter donor age: ");
    scanf("%d",&donor.age);
    fflush(stdin);
    printf("Enter donor gender: ");
    gets(donor.gender);
    //scanf("%s", donor.gender);
    printf("Enter donor blood group: ");
    gets(donor.blood_group);
    //scanf("%s", donor.blood_group);
    printf("Enter donor contact number: ");
    scanf("%ld",&donor.contact_number);
    fflush(stdin);
    printf("Enter donor address: ");
    gets(donor.address);
    //scanf("%s", donor.address);
    fwrite(&donor, sizeof(Donor), 1, fp);
    printf("Donor added successfully!\n");
    fclose(fp);
}

void search_donor() {
    FILE *fp;
    Donor donor;
    char blood_group[5];
    int count = 0;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }
    printf("Enter blood group to search: ");
    scanf("%s", blood_group);
    while (fread(&donor, sizeof(Donor), 1, fp) == 1) {
        if (strcmp(donor.blood_group, blood_group) == 0) {
            /*printf("Name: %s\n", donor.name);
            printf("Age: %d\n", donor.age);
            printf("Gender: %s\n", donor.gender);
            printf("Blood Group: %s\n", donor.blood_group);
            printf("Contact Number: %ld\n", donor.contact_number);
            printf("Address: %s\n", donor.address);*/
            printf("Name: "); puts(donor.name);
            printf("Age: %d\n", donor.age);
            printf("Gender: "); puts(donor.gender);
            printf("Blood Group: "); puts(donor.blood_group);
            printf("Contact Number: %ld\n", donor.contact_number);
            printf("Address: "); puts(donor.address);
            count++;
        }
    }
    if (count == 0) {
        printf("No donor found with blood group %s!\n", blood_group);
    }
    fclose(fp);
}

void list_donors() {
    FILE *fp;
    Donor donor;
    int count = 0;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }
    printf("List of donors:\n");
	while (!(feof(fp)))
	{
		if(fread(&donor, sizeof(Donor), 1, fp) != 1)
		break;

            printf("Name: "); puts(donor.name);
            printf("Age: %d\n", donor.age);
            printf("Gender: "); puts(donor.gender);
            printf("Blood Group: "); puts(donor.blood_group);
            printf("Contact Number: %ld\n", donor.contact_number);
            printf("Address: "); puts(donor.address);
        count++;
    }
    if (count == 0) {
        printf("No donors found!\n");
    }
    fclose(fp);
}
void check_blood_units()
{
	FILE *fp;
	Donor donor;
	int a_pos=0,a_neg=0,b_pos=0,b_neg=0,ab_pos=0,ab_neg=0,o_pos=0,o_neg=0;
	int c=0;
	fp=fopen(FILENAME,"r");
	if(fp==NULL)
	{
		printf("Error: Unable to open file");
		return ;
	}
	while(fread(&donor,sizeof(Donor),1,fp)==1)
	{
		if(strcmp(donor.blood_group,"O+")==0)
		o_pos++;
		if(strcmp(donor.blood_group,"O-")==0)
		o_neg++;
		if(strcmp(donor.blood_group,"A+")==0)
		a_pos++;
		if(strcmp(donor.blood_group,"A-")==0)
		a_neg++;
		if(strcmp(donor.blood_group,"B-")==0)
        b_neg++;
        if(strcmp(donor.blood_group,"B+")==0)
        b_pos++;
        if(strcmp(donor.blood_group,"AB-")==0)
        ab_neg++;
        if(strcmp(donor.blood_group,"AB+")==0)
        ab_pos++;

	}
	printf("||||||Amount of blood present|||||\n");
	printf("O+		:%d\n",o_pos);
	printf("O-		:%d\n",o_neg);
	printf("A+		:%d\n",a_pos);
	printf("A-		:%d\n",a_neg);
	printf("B+		:%d\n",b_pos);
	printf("B-		:%d\n",b_neg);
	printf("AB+		:%d\n",ab_pos);
	printf("AB-		:%d\n",ab_neg);
	fclose(fp);
	}


int main()
 {
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    int choice;
    do {

        printf("Blood Bank Management\n");
        printf("----------------------\n");
        printf("1. Add Donor\n");
        printf("2. Search Don\n");
        printf("3. List of Donors\n");
        printf("4. Blood units present\n");
        printf("5. Exit\n");
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_GREEN|BACKGROUND_BLUE);
        scanf("%d",&choice);
        switch(choice)
        {
        	case 1:
        		add_donor();
        		break;
        		case 2:
        			search_donor();
        			break;
        			case 3:
        				list_donors();
        				break;
        				case 4:
        					check_blood_units();
        					break;
        					case 5:
        						exit(0);
        }
    }while(1);
}
