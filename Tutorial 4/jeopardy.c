/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2024, Tahmid Chowdhury, Armaghan Nasir, Harsh Tamakuwala
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    (void)argc; // Suppress unused parameter warning
    (void)argv; // Suppress unused parameter warning

    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Enter player names (up to %d players):\n", NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; ++i) {
    	printf("Player %d: ", i + 1);
    	fgets(players[i].name, MAX_LEN, stdin);
    	
    	// Remove the newline character if present
    	players[i].name[strcspn(players[i].name, "\n")] = '\0';
    	
    	// Initialize score
    	players[i].score = 0;
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {    	
        // Call functions from the questions and players source files
        // Display available categories and question values
    	display_categories();
    	
    	// Get user input (category and value)
    	printf("Enter category and value (e.g., 'programming 100'): ");
    	fgets(buffer, BUFFER_LEN, stdin);
    	char category[MAX_LEN] = { 0 };
    	int value = 0;
    	sscanf(buffer, "%s %d", category, &value);
    	
    	// Display the question for the chosen category and value
    	display_question(category, value);
    	
    	// Get user's answer
    	printf("Your answer: ");
    	fgets(buffer, BUFFER_LEN, stdin);
    	char answer[MAX_LEN] = { 0 };
    	sscanf(buffer, "%s", answer);
    	
    	// Validate answer and update player scores
    	if (valid_answer(category, value, answer)) {
    	    printf("Correct!\n");
    	    update_score(players, NUM_PLAYERS, players[0].name, value);
    	} else {
    	    printf("Incorrect!\n");
    	}
    	
    	// Mark the question as answered
    	for (int i = 0; i < NUM_QUESTIONS; ++i) {
    	    if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
    	    	questions[i].answered = true;
    	    }
    	}

        // Execute the game until all questions are answered
        // Check if all questions are answered (end game condition)
        bool all_answered = true;
        for (int i = 0; i < NUM_QUESTIONS; ++i) {
            if (!questions[i].answered) {
            	all_answered = false;
            	break;
            }
        }
        if (all_answered) {
            break; // Exit the game loop
        }
    }
    
    // Display the final results and exit
    show_results(players, NUM_PLAYERS);
    
    return EXIT_SUCCESS;
}
