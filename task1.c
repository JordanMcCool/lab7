// EECS 348 Lab 7
// Football
// Input: Score
// Output: Possible combinations to get that score
// Additional Collaborators
    // gpt for error testing, help with score recursion function
// Jordan McCool
// 3/20/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TD is 6
// FG is 3
// Safety is 2
// 2pt con is 8
// 1pt fg is 7

// for unpermutation
// Jordan ONLY
//char perm[100]; in hindsight this was why mine didnt work
//int permacount = 0;
//int unpermutation(char hold[5]){
//    for (int i = 0; i < permacount; i++){
 //       for (int s = 0; s < 5; s++){
//            if (perm[i][s] != hold[s]){
//                perm[permacount] = hold;
//                permacount++;
//                return 1;
//            }
//            else return 0;
//        }
//    }
        // had a method of "appending it" here but gave up since I knew it wasnt going to work (would have worked in Python)
//}
// above code was my attempt at fixing the permutation, but I knew while writing it that it wouldnt work in C
    // had gpt help convert that function into C


//gpt + Jordan(concept)
#define MAX_COMBOS 256 //sets a maximum size we can go to, changed it to 256 incase yall get freaky with the number of points
int perm[MAX_COMBOS][5]; //okay after reviewing gpts code mine was CLOSE, this was basically the only significant change
int permacount = 0;
int unpermutation(int hold[5]){ //explaination below in block
    for (int i = 0; i < permacount; i++){ // this checks the current score combination with pervious score combinations
        int duplicate = 1;
        for (int j = 0; j < 5; j++){
            if (perm[i][j] != hold[j]){
            duplicate = 0;
            break;
            }
        }
        if (duplicate) return 0; // Means false, so do not print

    }

    //If this block runs, then we need to add her to set of combinations (is not a duplicate)
    for (int j = 0; j < 5; j++){
        perm[permacount][j] = hold[j]; // adds our new friend (the unique combination) to the array
    }
    permacount++;
    return 1;
}

//above block
    //this version was written by gpt, but really the main difference between this version and mine was:
    //int perm[MAX_COMBOS][5];
        // basically, i did not know that arrays had to be declared like that first
        // neat
    // other changes seems to just be appearance/minor functionality adjustments
    // overall, works by maintaining a list of known combinations and checking each new combination against all knowns
    // this should prevent duplicates from appearing
//



// gpt recommends a recursive fuction
// otherwise, by Jordan
//void work(int score){
    // ended up just asking gpt for a better way of doing this - recursion
    // original idea was permutation/combination but kept getting stuck on how to do that

//}
// in hindsight, this code above would have been useless. Leaving it here as a fossil but not using it

// gpt(concept) + Jordan
// gpt's suggested implementations would have been wrong
    // wanted to combine the TD options into one, with the extra points as their own thing
    // Jordan wrote this version based on gpt's suggestion to use recursion
void rec(int score, int td2, int td1, int td, int fg, int safety){
    if (score == 0){
        int hold[5] = {td2, td1, td, fg, safety}; // creates a list to use to compare against other known combos
        int test = unpermutation(hold); //inefficient according to gpt (hindsight/error testing) - dont care
        if (test == 1){ // ensures that no duplicates are printed
        printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n", td2, td1, td, fg, safety); // SHOULD print the pattern
            // this comment is before testing it, but i am suspecting that its gonna have duplicates
                // essentially, what Ive made is a permutation instead of a combination
                // im gonna have to fix that UGH
                    // made a fix that would have worked in python, had gpt help to convert it to C
        }
        return;
    }
    // i wonder if it matters the order i do this in. May get duplicates?
        // i THINK it will matter
        // adding this pre-emptively to check for an error case
    if (score == 1) return; // should kill any runs that end up being wrong
    // Checks the score, and 
    if (score >= 8) rec(score - 8, td2 + 1, td1, td, fg, safety);
    if (score >= 7) rec(score - 7, td2, td1 + 1, td, fg, safety);
    if (score >= 6) rec(score - 6, td2, td1, td + 1, fg, safety);
    if (score >= 3) rec(score - 3, td2, td1, td, fg + 1, safety);
    if (score >= 2) rec(score - 2, td2, td1, td, fg, safety + 1);

}

//Jordan
int main(){
    int user;
    while (1 == 1){
        printf("Enter score, 0 or 1 to STOP:\n");
        scanf("%d", &user); // gets the user input

        if (user == 1 || user == 0) return 0;
        rec(user, 0, 0, 0, 0, 0); // starts the process
        permacount = 0; // gpt - prevents an error with previous runs affecting future runs
            // dont I need to clear perm then too? - yes, i do GOOD CATCH
        memset(perm, 0, sizeof(perm)); // asked gpt how to reset the array - this is its solution
    }
    return 0;
}
// memset
    // *memset(void *ptr, int value, size_t num)
        // ptr = memory block to fill
        // value = value to set to
        // num = number of bytes to set
    // can be used to reset an array
        // avoids needing a complicated for loop