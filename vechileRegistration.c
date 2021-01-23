//vechile regisrtation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getownerinfo(char *[], char [], char []);
void getcarinfo(int *, char *, char [], char []);
void calculateFee(float [], char , int *, float *);
void displayRegistration(char [], char [], int ,char [], char [], char [], float  );

int main(){
	char *states[8]={"Michigan", "Ohio", "Illinious", "Indiana", "Wisconsin", "Minnesota", "Iowa", "Missouri"};
	float fee[4]={69.50, 78.00, 93.00, 82.50}, totalFee;
	int vehicleYear, registrationStatus, newPlateNumber;
	char name[50], vehicleModel[15], vehicleVin[20], stateResidence[10], plateNumber[7];
	char vehicleCategory;
	
	getownerinfo(states, name, stateResidence);
	getcarinfo(&vehicleYear, &vehicleCategory, vehicleModel, vehicleVin);
	calculateFee( fee,  vehicleCategory, &registrationStatus, &totalFee);
	
	if(registrationStatus==1){
		srand(time(0));
		newPlateNumber= (rand() % 9000) + 1000;
	}else if (registrationStatus==2){
		
		gets(plateNumber);
		printf("Enter your plate number: ");
		gets(plateNumber);
	}
	displayRegistration( name, stateResidence, vehicleYear, vehicleModel,  vehicleVin,  plateNumber,  totalFee );
	
}
void getownerinfo(char *states[], char name[], char stateResidence[]){
	int x, found;
	
	for(x=0; x<8; x++){
		printf("%s \n", states[x]);
	}
	do{
		printf("\nPlease choose your state of residence: ");
		gets (stateResidence);
		
		for(x=0; x<8; x++){
			if (strcmp( stateResidence, states[x])==0){
			found=1;
			break;
			}else{
				found=0;
			}
		}
		if (found==0)
			printf("\n[Error] The State must be one of the States listed above");
			
	}while(found==0);
	
	printf("\nEnter your full name: ");
	gets(name);
	
}
void getcarinfo(int *vehicleYearPtr, char *vehicleCategoryPtr, char vehicleModel[], char vehicleVin[]){
	int vehicleYear=0;
	char vehicleCategory;
	
	do{
		printf("\nEnter the vehicle year: ");
		scanf("%d", &vehicleYear);
		
		if(vehicleYear < 1900 || vehicleYear > 2020)
			printf("\nThe vehicle must be from Year 1900 to 2020");
			
	}while(vehicleYear < 1900 || vehicleYear > 2020);
	
	printf("\nChoose your vehicle category");
	printf("\n	P: Passenger vehicle");
	printf("\n	S: Sports vehicle");
	printf("\n	T: Truck");
	printf("\n	V: Van");
	printf("\nCategory: ");
	scanf(" %c", &vehicleCategory);
	
	while(vehicleCategory != 'P' && vehicleCategory != 'p' 
		&& vehicleCategory != 'S' && vehicleCategory != 's'
		&& vehicleCategory != 'T' && vehicleCategory != 't'
		&& vehicleCategory != 'V' && vehicleCategory != 'v'){
			
		printf("[Error] Vehicle category not listed above");
		printf("\nChoose your vehicle category: ");
		scanf(" %c", &vehicleCategory);
	}
	
	
	gets(vehicleModel);
	printf("Enter the model of your vehicle: ");
	gets(vehicleModel);
	
	printf("Enter your vehicle identification number (VIN): ");
	gets(vehicleVin);
	
	*vehicleCategoryPtr= vehicleCategory;
	*vehicleYearPtr=vehicleYear;
}
void calculateFee(float fee[], char vehicleCategory, int *registrationStatusPtr, float *totalFeePtr){
	float totalFee;
	int registrationStatus;
	
	switch (vehicleCategory)
	{
		case 'P': case 'p':
			totalFee= fee[0];
			break;
		case 'S': case 's':
			totalFee= fee[1];
			break;
		case 'T': case 't':
			totalFee= fee[2];
			break;
		case 'V': case 'v':
			totalFee= fee[3];
			break;
		
	}
	
	printf("(1)New registration \n(2) Returning registration: ");
	scanf("%d", &registrationStatus);
	
	if(registrationStatus==1)
		totalFee+=100;
	
	*registrationStatusPtr= registrationStatus;
	*totalFeePtr= totalFee;
}

void displayRegistration(char name[], char stateResidence[], int vehicleYear,char vehicleModel[], char vehicleVin[], char plateNumber[], float totalFee ){
	printf("\nOwner:		%s", name);
	printf("\nState:		%s", stateResidence);
	printf("\nYear:		%d", vehicleYear);
	printf("\nModel:		%s", vehicleModel);
	printf("\nVin:		%s", vehicleVin);
	printf("\nPlate:		%s", plateNumber);
	printf("\nTotal:		%.2f", totalFee);
}
