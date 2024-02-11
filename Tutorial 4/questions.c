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

char categories[NUM_CATEGORIES][MAX_LEN] = {
    "programming", 
    "algorithms", 
    "databases"
};

question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is the acronym for central processing unit?");
    strcpy(questions[0].answer, "cpu");
    questions[0].value = 100;
    questions[0].answered = false;
    
    strcpy(questions[1].category, "algorithms");
    strcpy(questions[1].question, "What sorting algorithm has an average time complexity of O(n log n)?");
    strcpy(questions[1].answer, "merge");
    questions[1].value = 100;
    questions[1].answered = false;
    
    strcpy(questions[2].category, "databases");
    strcpy(questions[2].question, "What is the acronym for structured query language?");
    strcpy(questions[2].answer, "sql");
    questions[2].value = 100;
    questions[2].answered = false;
    
    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "Which programming language is named after a snake?");
    strcpy(questions[3].answer, "python");
    questions[3].value = 200;
    questions[3].answered = false;
    
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "What data structure follows the LIFO principle?");
    strcpy(questions[4].answer, "stack");
    questions[4].value = 200;
    questions[4].answered = false;
    
    strcpy(questions[5].category, "databases");
    strcpy(questions[5].question, "How is data stored in a database?");
    strcpy(questions[5].answer, "tables");
    questions[5].value = 200;
    questions[5].answered = false;
    
    strcpy(questions[6].category, "programming");
    strcpy(questions[6].question, "Which programming language is named after a hot drink?");
    strcpy(questions[6].answer, "java");
    questions[6].value = 300;
    questions[6].answered = false;
    
    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "What sorting algorithm is often regarded as the most efficient?");
    strcpy(questions[7].answer, "quick");
    questions[7].value = 300;
    questions[7].answered = false;
    
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "What is the acronym for structured query language?");
    strcpy(questions[8].answer, "sql");
    questions[8].value = 300;
    questions[8].answered = false;
    
    strcpy(questions[9].category, "programming");
    strcpy(questions[9].question, "Which programming language have we primarily been using in this course?");
    strcpy(questions[9].answer, "c");
    questions[9].value = 400;
    questions[9].answered = false;
    
    strcpy(questions[10].category, "algorithms");
    strcpy(questions[10].question, "What data structure follows the FIFO principle?");
    strcpy(questions[10].answer, "queue");
    questions[10].value = 400;
    questions[10].answered = false;
    
    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "How does MySQL connect to Python code?");
    strcpy(questions[11].answer, "mysqlconnector");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("Available Categories:\n");
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
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
    	    printf("Test for true");
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
