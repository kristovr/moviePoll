#include "main.h"

int main() {
	
	menu();
	return 0;
}

void menu(){
	
	int choice, selectedPoll, selectedMovie;
	system("cls");
	printf("-----------Welcome to Tony's Cinema------------\n");
	printf("---------------Select an action----------------\n");
	printf("1. Create a Poll\n2. Vote\n3. View Results\n>>");
	scanf("%d", &choice);
	
	switch(choice){
		case(1):
			system("cls");
			createNewPoll();
			break;
		case(2):
			selectedPoll = printPoll();
			selectedMovie = viewMoviesForPoll(selectedPoll);
			castVote(selectedPoll, selectedMovie);
			break;
		case(3):
			viewResult();
			break;
		default:
			printf("Enter a value betweem 1-3\n");
			menu();
	}
}

void createNewPoll(){ //creates a new poll with respective movies
	//allocate memory for new node
	struct Poll *newPoll = (struct Poll*) malloc(sizeof(struct Poll));
	int i;
	
	//data input for poll
	
	printf("---------------Creating a New Poll----------------\n");
	printf("Enter an ID: \n>>");
	scanf("%d", &newPoll->id);
	printf("Enter a name: \n>>");
	scanf("%s", newPoll->name);
	printf("Enter a description: \n>>");
	scanf("%s", newPoll->description);
	printf("Enter a start date: \n>>");
	scanf("%d", &newPoll->startDate);
	printf("Enter a end date: \n>>");
	scanf("%d", &newPoll->endDate);
	
	//data input for movies
	for(i = 0; i < 3; i++){
		printf("Enter a Movie ID: \n>>");
		scanf("%d", &newPoll->MovieList[i].id);
		printf("Enter a Movie name: \n>>");
		scanf("%s", newPoll->MovieList[i].name);
		
		newPoll->MovieList[i].score = 0;		
	}
	
	newPoll->next = NULL;
	
	//linked list creation 
	
	if(head == NULL){
		head = newPoll;
		current = newPoll;
	}
	else{
		current->next = newPoll;
	}
	
	printf("New Poll Created! Press enter to continue\n");
	getch();
	menu();
}

int printPoll(){ //prints all created polls returns poll the user wishes to vote on
	
	int pollSelection;
	struct Poll *link = head;
	while(link != NULL){
		printf("---------Current List of Polls-------------\n");
		printf("Poll ID: %d \n",link->id);
		printf("Poll Name: %s \n",link->name);
		link = link->next;
	}
	
	//all the ID and names of poll are returned
	printf("\nSelect an ID to enter Poll:\n>>"); 
	scanf("%d", &pollSelection);
	return pollSelection;	
}

int viewMoviesForPoll(int poll){ // the selected poll is explored to see the movies
	int i, selectedMovie;
	struct Poll *link = head;
	
	while(link != NULL){
		if(link->id == poll){
			printf("ID: %d\n", link->id);
			printf("Name: %s\n", link->name);
			printf("Description: %s\n", link->description);
			printf("Start Date: %d\n", link->startDate);
			printf("End Date: %d\n", link->endDate);
			
			for(i = 0; i < 3; i++){ //movies are printed
				printf("	Movie ID: %d\n", link->MovieList[i].id);
				printf("	Movie Name: %s\n", link->MovieList[i].name);
				printf("\n");
			}	
		}
		
		link = link->next;	
	}
	
	//user selects the movie to cast a vote on
	
	printf("\nEnter the ID for the movie you would like to vote for\n>>");
	scanf("%d", &selectedMovie);	
	return selectedMovie;
}

void castVote(int selectedPoll, int selectedMovie){ //the actual vote is recorded
	int i;
	struct Poll *link = head;
	
	while(link != NULL){
		if(link->id == selectedPoll){ //match the selected with the poll id
			for(i = 0; i < 3; i++){
				if(link->MovieList[i].id == selectedMovie){ //match the selected with the movie id
					link->MovieList[i].score += 1;
					//the movie's score gets a plus one 
				}	
			}	
		}
		
		link = link->next;
	}
	
	printf("Vote recorded! Press enter to continue\n");
	getch();
	menu();
}

void viewResult(){ //print all the poll information showing the votes received
	int i;
	struct Poll *link = head;
	while(link != NULL){
	
		printf("ID: %d\n", link->id);
		printf("Name: %s\n", link->name);
		printf("Description: %s\n", link->description);
		printf("Start Date: %d\n", link->startDate);
		printf("End Date: %d\n", link->endDate);
			
		for(i = 0; i < 3; i++){
			printf("	Movie ID: %d\n", link->MovieList[i].id);
			printf("	Movie Name: %s\n", link->MovieList[i].name);
			printf("	Votes: %d\n", link->MovieList[i].score);
			printf("\n");
		}	
		
		link = link->next;	
	}
	printf("Results of Poll. Press enter to continue\n");
	getch();
	menu();
}


