#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

struct date{
	int year;
	int month;
	int day;
	};
	
struct car{                     //Globat structure car
	char name[20];
	char surName[20];
	int id;
	char make[20];
	char model[20];
	struct date regDate;	    //registrationDate
	struct date nSD;	       //nextServiceDate
	char phoneNumber[20];
	}carDirectory[SIZE];
	
int i=0, d=0;	             //Global counters (number of cors and number of deleted cars)

void newCar();              //Adding a new car
void displayCars();        //Displaying the cars	
void deleteCar(int);      //Deleting a car	
void search(char);       //Searching for a car
void sort();            //Sorting the cars	
void update(int);      //updating a car info



int main(void)
{
	int x,y,j,k;
	char c;
	
	system("color 30");    //sets the background color to red and the text color to white
	
	
	do{
		
		printf("\n\nWELCOME TO THE CAR SERVICE DIRECTORY\n___________________________________\n\nThe number of registered cars is %d",i);
		printf("\t\tThe number of deleted cars is %d\n\n", d);
		printf("1- Add a new car to the directory\n\n");
		printf("2- Delete a car from the directory\n\n");
		printf("3- List the avaialabe cars in the directory\n\n");
		printf("4- Search a car:\n\tA- Search according to car id\n\tB- Search according to name\n\n");
		printf("5- Update car information\n\n");
		printf("6- Sort according to car id\n\n");
		printf("7- Quit\n___________________________________\n\n");
		printf("Enter your selection here:\n");
		scanf("%d",&x);
		
		if(x==1||x==2||x==3||x==4||x==5||x==6||x==7)
		
		{
			
		if(x==1){
			
			printf("\nAdding car %d\n___________________\n",i+1);
			newCar();
		
		}
			
			
		
				
		if(x==2){
			
			printf("Please enter the id of the car that you want to delete it\n:");
			scanf("%d",&y);
			
			deleteCar(y);
			
			
		}
				
		if(x==3){
			if(i==0){
			
			printf("\nThere is no cars to be displayed!\n");
			system("pause");
		}
			else
			displayCars();
		}
		
		if(x==4){
			
			printf("Please choose A or B:\n");
			scanf(" %c", &c);
			if(c=='a' || c=='b'||c=='A'|| c=='B')
			search(c);
			else{
			
			printf("\nYou didnt choose A or B!\n");
			system("pause");
		}
			}
			
		if(x==5){
			
			printf("\nPlease enter the ID of the car that you want to update:\n");
			scanf("%d",&k);
			update(k);
		}
			
		if(x==6){
			sort();
		}	
		
		}
		
	else
	{
	printf("\n\nWrong Choice!\n\n");
	getchar();  //used to prevent the loop when entering a character instead of a number
	system("pause");
	}
	
	

	}while(x!=7 && i<SIZE);
	
	
	
	printf("\n\nYou Exited the program!\n\n");
	
	
	return 0;
	
	
	
	
}

void newCar(){
	
	printf("Enter the owner Name:\t");
	scanf("%s", carDirectory[i].name);
	printf("\nEnter the owner Surname:\t");
	scanf("%s", carDirectory[i].surName);
	printf("\nEnter the ID:\t");
	scanf("%d", &carDirectory[i].id);
	printf("\nEnter the brand of the car (e.g Honda, Mercedes, ...)\t");
	scanf("%s", carDirectory[i].make);
	printf("\nEnter the model of the car(e.g 2000, 2013, ...)\t");
	scanf("%s", carDirectory[i].model);
	printf("\nEnter the registration date:\t");
	printf("\nEnter the day:\t");
	scanf("%d", &carDirectory[i].regDate.day);
	printf("\nEnter the month:\t");
	scanf("%d", &carDirectory[i].regDate.month);
	printf("\nEnter the year:\t");
	scanf("%d", &carDirectory[i].regDate.year);
	printf("\nEnter the the next service date\t");
	printf("\nEnter the day:\t");
	scanf("%d", &carDirectory[i].nSD.day);
	printf("\nEnter the month:\t");
	scanf("%d", &carDirectory[i].nSD.month);
	printf("\nplease enter the year:\t");
	scanf("%d", &carDirectory[i].nSD.year);
	printf("\nEnter the owner phone number:\t");
	scanf("%s", carDirectory[i].phoneNumber);
	printf("\n\n");
	
	system("pause");
	
	
	i++; //adding the number of registered cars by 1
	
}

void displayCars(){
	
	int j;
	printf("\n\nThe available cars are as follows:\n\n");
	for(j=0;j<i;j++)
	{
		
		printf("Car number %d is as follows:\n___________________________\n", j+1);
		printf("First name: %s\n\nLastname: %s\n", carDirectory[j].name, carDirectory[j].surName);
		printf("\nID: %d\n", carDirectory[j].id);
		printf("\nBrand is: %s\n", carDirectory[j].make);
		printf("\nThe model is: %s\n", carDirectory[j].model);
		printf("\nThe registration date is as follows:\n");
		printf("\nDay:%d	Month:%d	Year:%d\n", carDirectory[j].regDate.day, carDirectory[j].regDate.month, carDirectory[j].regDate.year);
		printf("\nThe next service date is as follows:\n");
		printf("\nDay:%d	Month:%d	Year:%d\n", carDirectory[j].nSD.day, carDirectory[j].nSD.month, carDirectory[j].nSD.year);
		printf("\nPhone number:%s\n\n", carDirectory[j].phoneNumber);
		
		
		
	}
	
		system("pause");
	
	
}

void deleteCar(int y){
	int j;
	int z;
	int flag=0;
	
	for(j=0;j<i;j++){
	
		
		if((carDirectory[j].id)==y){
		
		z=j;     //specifiying the location of delete element
		flag++;
	}
	}
	
	if(flag==0){
	printf("\nID in not found!\n");
	system("pause");
}
	
	else
	{
	
	for(j=z;j<i;j++){
	
			carDirectory[j]=carDirectory[j+1];
	}
	i--;  //decrementing the number of registered cars by 1
	d++; //adding the number of deleted cars by 1
	printf("\nThe car with the ID %d is deleted successfully!\n", y);
	system("pause");
}


}

void search(char c){
	
	int searchid;
	char searchname[20];
	int j,k,flag1=0,flag2=0;
	
	if(c=='a'|| c=='A'){
		
		printf("\nYou are searching according to car id\nPlease enter the ID of the car you want to search for\n");
		scanf("%d", &searchid);
		
		for(j=0;j<i;j++){
			
			if(carDirectory[j].id==searchid)
			{
				printf("\nThe car is FOUND !\n\nThe details are as shown below\n");
				printf("\nFirst name: %s\n\nLastname: %s\n", carDirectory[j].name, carDirectory[j].surName);
				printf("\nID: %d\n", carDirectory[j].id);
				printf("\nBrand is: %s\n", carDirectory[j].make);
				printf("\nThe model is: %s\n", carDirectory[j].model);
				printf("\nThe registration date is as follows:\n");
				printf("\nDay:%d	Month:%d	Year:%d\n", carDirectory[j].regDate.day, carDirectory[j].regDate.month, carDirectory[j].regDate.year);
				printf("\nThe next service date is as follows:\n");
				printf("\nDay:%d	Month:%d	Year:%d\n", carDirectory[j].nSD.day, carDirectory[j].nSD.month, carDirectory[j].nSD.year);
				printf("\nPhone number:%s\n\n", carDirectory[j].phoneNumber);
				flag1++;	
			}
		}
		
		if(flag1==0)
		printf("\nThe Car DOES NOT EXIST!\n");
		
		system("pause");
		
	}
	
	if(c=='b'||c=='B'){
		
		printf("\nYou are searching according to the owner name\nPlease enter the name of the owner you want to search for:\n");
		scanf("%s", searchname);
		for(k=0;k<20;k++){
		
			for (j=0;carDirectory[j].name[k]!='\0';j++){
			
			carDirectory[j].name[k]=toupper(carDirectory[j].name[k]);  //converted to uppercase letter to make the search non-case sensitive 
			}
		}
			
		for(j=0;searchname[j]!='\0';j++){
			
		searchname[j]=toupper(searchname[j]);     //converted to uppercase letter to make the search non-case sensitive 
		}
		
		for(j=0;j<i;j++){                                                                             //linear search
				if(strcmp(carDirectory[j].name, searchname)==0){
				printf("\nThe car is FOUND !\n\nThe details are as shown below\n");
				printf("\nFirst name: %s\n\nLastname: %s\n", carDirectory[j].name, carDirectory[j].surName);
				printf("\nID: %d\n", carDirectory[j].id);
				printf("\nBrand is: %s\n", carDirectory[j].make);
				printf("\nThe model is: %s\n", carDirectory[j].model);
				printf("\nThe registration date is as follows:\n");
				printf("\nDay:%d	Month:%d	Year:%d\n", carDirectory[j].regDate.day, carDirectory[j].regDate.month, carDirectory[j].regDate.year);
				printf("\nThe next service date is as follows:\n");
				printf("\nDay:%d	Month:%d	Year:%d\n", carDirectory[j].nSD.day, carDirectory[j].nSD.month, carDirectory[j].nSD.year);
				printf("\nPhone number:%s\n\n", carDirectory[j].phoneNumber);
				flag2++;
		
		}
		
		
	}
	if (flag2==0)
	printf("\nThe car DOES NOT EXIST!\n");
	
	system("pause");
	
	
	
}
}

void sort(){                                                          //Bubble sort
	struct car temp;
	int j,k;
	for(j=0;j<i-1;j++)
	{
		for(k=0;k<i-j-1;k++)
		{
			if(carDirectory[k].id>carDirectory[k+1].id)
			{
				temp=carDirectory[k];
				carDirectory[k]=carDirectory[k+1];
				carDirectory[k+1]=temp;
			}
		}
	}
	
	if(i==0)
	printf("\nThere is no items to be sorted! please add some! \n");
	else
	printf("\nThe list is sorted successfully!\n");
	system("pause");
	
	
	
}

void update(int x){
	
	int j,k,flag=0;
	
	for (j=0;j<i;j++){
		if(carDirectory[j].id==x){
		printf("\nThe car with the ID: %d is found!\n",x);
		k=j;
		flag++;
		}	
	}
	if(flag==0)
	printf("\nThe car DOES NOT EXIST!\n");
	else{
		printf("\nYou are going to update the information of the car with ID: %d!\n",x);
		printf("\nPlease enter the new owner name:\n");
		scanf("%s", carDirectory[k].name);
		printf("\nPlease enter the new owner Surname\n");
		scanf("%s", carDirectory[k].surName);
		printf("\nPlease enter the new ID:\n");
		scanf("%d", &carDirectory[k].id);
		printf("\nPlease enter the brand\n");
		scanf("%s", carDirectory[k].make);
		printf("\nPlease enter the model:\n");
		scanf("%s", carDirectory[k].model);
		printf("\nRegistration date:\n");
		printf("\nPlease enter the day\n");
		scanf("%d", &carDirectory[k].regDate.day);
		printf("\nPlease enter the month:\n");
		scanf("%d", &carDirectory[k].regDate.month);
		printf("\nPlease enter the year\n");
		scanf("%d", &carDirectory[k].regDate.year);
		printf("\nNext Service Date\n");
		printf("\nPlease enter the day\n");
		scanf("%d", &carDirectory[k].nSD.day);
		printf("\nPlease enter the month:\n");
		scanf("%d", &carDirectory[k].nSD.month);
		printf("\nPlease enter the year:\n");
		scanf("%d", &carDirectory[k].nSD.year);
		printf("\nPlease enter the phone number:\n");
		scanf("%s", carDirectory[k].phoneNumber);
		
	}
	
	system("pause");
	
	
	
	
	
	
}
	
	

