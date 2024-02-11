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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What does CPU stand for?");
    strcpy(questions[0].answer, "Central Processing Unit");
    questions[0].value = 100;
    questions[0].answered = false;
    
    // TODO: Add more questions...
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("Available Categories:\n");
    for (int i = 0; i < NUM_CATEGORIES; ++i) {
    	if (!already_answered(questions[i].category, questions[i].value)) {
    	    printf("%d. %s ($%d)\n", i + 1, questions[i].category, questions[i].value);
    	}
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
    	if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
    	    printf("Question: %s\n", questions[i].question);
    	    break;
    	}
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
    	if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
    	    return (strcmp(questions[i].answer, answer) == 0);
    	}
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
    	if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
    	    return questions[i].answered;
    	}
    }
    return false;
}
