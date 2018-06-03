// fruit_bot.c
// Assignment 3, COMP1511 18s1: Fruit Bot
//
// This program by YOUR-NAME-HERE (z5555555) on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: minor bug in main fixed

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "fruit_bot.h"
#include <stdlib.h>

void print_player_name(void);
void print_move(struct bot *b);
void run_unit_tests(void);

// ADD YOUR STRUCT DEFS HERE
struct fruit_potential {                  
    char type [MAX_NAME_CHARS];
    int they_sell ;  
    int they_buy ;   
    int distance_to_buy ;          
    int potential_profit ; 
    struct node *nexta;  
};
// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
//struct fruit_potential *new_fruit_potential(struct bot *b, int distance); // makes a new node

//void free_node(struct fruit_potential *node);

//void run_through_list(struct fruit_potential *topa, struct bot *b, int distance);

// YOU SHOULD NOT NEED TO CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {

    if (argc > 1) {
        // supply any command-line argument to run unit tests
        run_unit_tests();
        return 0;
    }

    struct bot *me = fruit_bot_input(stdin);
    if (me == NULL) {
        print_player_name();
    } else {
        print_move(me);
    }

    return 0;
}

void print_player_name(void) {
    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME
    printf("VROOVROOM");

}

// print_move - should print a single line indicating
//              the move your bot wishes to make
//
// This line should contain only the word Move, Sell or Buy
// followed by a single integer

void print_move(struct bot *b) {
    
    struct location *l = b->location;
    
    if (
        l->price < 0 &&
        l->quantity > 0 &&
        strcmp(l->fruit, "Electricity") == 0 &&
        b->battery_level < b->battery_capacity
        ) {
        printf("Buy %d\n", b->battery_capacity - b->battery_level);
    } else  if (
        l->price < 0 &&
        l->quantity > 0 &&
        strcmp(l->fruit, "Apples") == 0 &&
        b->fruit_kg == 0 &&
        l->price < b->cash 
        ) {
        printf("Buy %d\n", b->maximum_fruit_kg);
    } else  if (
        l->price > 0 &&
        l->quantity > 0 &&
        strcmp(l->fruit, "Apples") == 0 &&
        b->fruit_kg > 0 &&
        strcmp(b->fruit, "Apples") == 0
        ) {
        printf("Sell %d\n", b->fruit_kg);
    } else {

        printf("Move 1");
    }
}

// ADD A COMMENT HERE EXPLAINING YOUR OVERALL TESTING STRATEGY
/* the main idea was to create a function that would scan through the world and create a struct for each different piece of fruit it could find, in this struct it would hold the highest sell price if the fruit it could find and the lowest buy price (for the player). after it looked around the world it would calculate the the max potential profit of the fruit and return the distance in moves to get to the best seller of that fruit. to test this i would make a little world with different fruits and prices and see if it choose the right one. after that a fuction would be made that if cargo is on board, looks for the most profitable buyer and drives to them, making sure battery is in range. same testing strategy as before. sadly i couldnt get the function to work and put all my eggs in one basket ;/.   

*/



void run_unit_tests(void) {
    // PUT YOUR UNIT TESTS HERE
    // This is a difficult assignment to write unit tests for,
    // but make sure you describe your testing strategy above.
}
// ADD YOUR FUNCTIONS HERE
/*
int best_buy_move(struct bot *b){
    
    struct location *start = b->location;
    struct location *eastwards = b->location;
    int distance = 0;
    int move = 0;
    
    struct fruit_potential *topa = new_fruit_potential(b, distance);
    while (distance == 0 || eastwards != start) {       // gona walk me around the map
                
        run_through_list(topa, b, distance);
        
        
        //wana look at locations fruit - > throw it into a char
        //wana make a struct for it // thinking first run through gona have to make a dud one at the start so it doesnt go idk where to look
        // wana edit a struct if has it
        // find best location and go there
        
        //then make a function to drive to best buyer making sure energy is ok
        eastwards = eastwards->east;
        distance = distance + 1;
        
    }
    return move ;
}


/////////////////////////////////////////////
/////////////////////////////////////////////
struct fruit_potential *new_fruit_potential(struct bot *b, int distance){ //just makes a fruit potential struct and returns adress not for the edit part of best
    
    struct fruit_potential *new = malloc(sizeof(struct fruit_potential));
    strcpy(new->type , b->location->name) ;
    if(b->location->price > 0){    
         new->they_buy = b->location->price;
    }
    if(b->location->price < 0){
        new->they_sell = b->location->price;
    }    
    new->distance_to_buy = distance;
    new->potential_profit = 0 ;
    new->nexta = NULL;
    return new;           //will make a node and give you its adress pointer
}
void free_node(struct fruit_potential *node){ //give it a pointer, frees it
    free(node);
}  


void run_through_list(struct fruit_potential *topa, struct bot *b, int distance){ // u need to give it the head of list
    struct fruit_potential *curr = topa;
    while (curr != NULL){
    
        if(strcmp(curr->type, b->location->name) == 0){    // i wana check for edit
            if (b->location->price < 0){
                    if(b->location->price > curr->they_sell){
                        curr->they_sell = b->location->price ;
                        curr->distance_to_buy = distance ;
                        curr->potential_profit = curr->they_buy + curr->they_sell ;  // only need to calc prof when have both variables
                        }
            }
            if (b->location->price > curr->they_buy){
                    curr->they_buy = b->location->price ;                   
            }           
        }
        curr = curr->nexta;
     } 
     //since its reached end of list and hasnt found a match, wana make a struct and link onto bottom
     curr = new_fruit_potential(b, distance);
}                                           

*/


