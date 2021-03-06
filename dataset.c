/*
gcc dataset.c -o dataset
./dataset 5000 1000 10 > donor.json
./dataset 10000 7000 20 > receiver.json

mongoimport -d organ -c donorinfo --jsonArray donor.json
mongoimport -d organ -c receiverinfo --jsonArray receiver.json
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * firstName[] = {"Avinash", "Neha", "Sunil", "Swapnil", "Prithvi"};
char * lastName[] = {"Sharma", "Irnak", "Sonawane", "Dahawad", "Gupta"};
char * gender[] = {"male", "female"};
char * hospital[] = {"kem@gmail.com", "sahyadri@gmail.com", "vardaan@gmail.com"};
char * domain[] = {"gmail.com", "ymail.com", "hotmail.com"};
char * doctor[] = {"pawan@gmail.com", "mukesh@gmail.com", "prithvi@gmail.com"};

int approved[] = {0, 1};
int priority[] = {0, 1, 2, 3, 4};
int blood[] = {0, 1, 2, 3, 4, 5, 6, 7};
int organ[] = {0, 1, 2};

int getRandom(int size);

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);					// no. of elements to be generated
	int start = atoi(argv[2]);				// start from this id
	int seed = atoi(argv[3]);				// seed value
//	char username[21] = "aaaaaa";
	int i, length = 6, j = 20000, approve = 0;
	char hack[100];
	
	srandom(seed);
	for(i = start; i < start + n; i++)
	{
		if(j >= 23000)
			j = 20000;

		fprintf(stdout, "{\n");
	
		fprintf(stdout, "\t\"email\" : "); fprintf(stdout, "\"%d@%s\",\n", i, domain[getRandom(sizeof(domain)/sizeof(domain[0]))]);
		fprintf(stdout, "\t\"password\" : "); fprintf(stdout, "\"%s\",\n", "1234");
		fprintf(stdout, "\t\"approved\" : "); fprintf(stdout, "\"%d\",\n", approve = getRandom(sizeof(approved)/sizeof(approved[0])));
		if(approve)
		{
			fprintf(stdout, "\t\"priority\" : ");
			fprintf(stdout, "\"%d\",\n", getRandom(sizeof(priority)/sizeof(priority[0])));
		}
		fprintf(stdout, "\t\"organ\" : "); fprintf(stdout, "\"%d\",\n", getRandom(sizeof(organ)/sizeof(organ[0])));
//		fprintf(stdout, "\t\"info\" : {\n");
		fprintf(stdout, "\t\"firstname\" : "); fprintf(stdout, "\"%s\",\n", firstName[getRandom(sizeof(firstName)/sizeof(firstName[0]))]);
		fprintf(stdout, "\t\"middlename\" : "); fprintf(stdout, "\"%s\",\n", firstName[getRandom(sizeof(firstName)/sizeof(firstName[0]))]);
		fprintf(stdout, "\t\"lastname\" : "); fprintf(stdout, "\"%s\",\n", lastName[getRandom(sizeof(lastName)/sizeof(lastName[0]))]);
		fprintf(stdout, "\t\"gender\" : "); fprintf(stdout, "\"%s\",\n", gender[getRandom(sizeof(gender)/sizeof(gender[0]))]);
		fprintf(stdout, "\t\"blood\" : "); fprintf(stdout, "\"%d\",\n", getRandom(sizeof(blood)/sizeof(blood[0])));
//		fprintf(stdout, "\t},\n");
		if(j < 21000)
			strcpy(hack, hospital[0]);
		else if(j < 22000)
			strcpy(hack, hospital[1]);
		else
			strcpy(hack, hospital[2]);

		fprintf(stdout, "\t\"hospital\" : "); fprintf(stdout, "\"%s\",\n", hack);
		fprintf(stdout, "\t\"Doc\" : "); fprintf(stdout, "\"%d@%s\"\n", j++, "gmail.com");

		fprintf(stdout, "}\n");
	}
	return 0;
}

int getRandom(int size)
{
	return random() % size;
}
