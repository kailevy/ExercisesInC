/*
Kai Levy
SoftSys Spring 2018
Exercise 1
*/

#include <stdio.h>
#include <stdlib.h>

void get_card(char * card_name);
void update_count(int val);


/* 
Runs the main while loop to receive cards until 'X' is received
*/
int main() {
	char card_name[3];
	do {
		int val = 0;

		get_card((char *)&card_name);		
		switch(card_name[0]) {
			case 'K':
			case 'Q':
			case 'J':
			val = 10;
			break;
			case 'A':
			val = 11;
			break;
			case 'X':
			continue;

			default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)) {
				puts("I don't understand that value");
				continue;
			}
		}
		update_count(val);
	}
	while (card_name[0] != 'X');
	return 0;
}


/* Receives the card from the user

card_name: buffer where result is stored
*/
void get_card(char * card_name) {
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}


/* Updates and displays the count

val: value of the last card
*/
void update_count(int val) {
	static int count = 0;
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	printf("Current count: %i\n", count);
}
