/// EECS 348 Lab 7
// Football
// Input: temperature
// Output: temperature conversions
// Additional Collaborators
    // gpt for minor clarifications
    // any lines changed by gpt are specified
        // otherwise, all lines are by Jordan
// Jordan McCool
// 3/22/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define celi 0 // not sure if I need these
#define fahr 1 // at this point they are more to keep track than actually be used
#define kelv 2 // extra hindsight, im noticing now that the example run has it as 1 2 3 and not 0 1 2
    // but at the time of this comment, ive already made the ENTIRE thing around 0 1 2 :L

int tempscale;
float temp;

// these functions just convert a given temperature to an output
    // basic, just followed the formula in the lab description
// written by Jordan
float celsius_to_fahrenheit (float celsius){
    float fahrenheit = ((9/5)*celsius + 32);
    return fahrenheit; // in hindsight, I dont actually need to make float fahrenheit
    // could have just done return (((9/5)*celsius + 32));
}

float fahrenheit_to_celsius (float fahrenheit){ //same as other functions
    float celsius = ((5/9)*fahrenheit - 32);
    return celsius;
}

float celsius_to_kelvin (float celsius){ // same as other functions
    return (celsius + 273.15); // more efficient
}

float kelvin_to_celsius (float kelvin){ // same as other functions
    return (kelvin - 273.15);
}

void categorize_temperature (float celsius){ // also from the lab description
    // need to make sure that the values are converted BEFORE giving it to this function
    // very basic if block that uses returns to make sure the actions are not duplicated
    if (celsius <= 0){
        printf("It is freezing\nWeather advisory: Stay indoors\n\n"); // I dont actually know what weather advisories are given at various temps
        // just gonna use the advisory that I would have
        return; // uses return to stop the function
    }
    if (celsius <= 10){
        printf("It is cold\nWeather advisory: Wear a jacket\n\n");
        return;
    }
    if (celsius <= 25){
        printf("It is comfortable\nWeather advisory: You should be fine");
        return;
    }
    if (celsius <= 35){
        printf("It is Hot\nWeather advisory: Stay Indoors\n\n");
        return;
    }
    if (celsius < 100){
        printf("It is HOT!\nWeather advisory: Survive, whatever it takes"); // getting tired of typing
        return;
    }
    if (celsius > 100){
        printf("gg.\nWeather advisory: (You are boiling at this point)"); // at this point just adding stuff to make it more interesting
        // very tired of typing
    }
}

// written by Jordan
int main(){
    int out; // used for the output conversion scale
    float newtemp; // also used for the output
        // also got used for error checking
    while (1 == 1){ // gets the inputs and checks that it is valid
        printf("Enter temperature value:\n");
        scanf("%f", &temp); // gpt corrected issue with %d versus %f

        printf("Enter scale (0 for celcius, 1 for fahrenheit, 2 for kelvin):\n");
        scanf("%d", &tempscale); // gets the scale
        
        // below if blocks are to check for impossible temperatures
        if (tempscale == 0){ // if given celsius
            newtemp = celsius_to_kelvin(temp);
        }
        if (tempscale == 1) { // if given fahrenheit
            newtemp = celsius_to_kelvin(fahrenheit_to_celsius(temp));
        }
        if (tempscale == 2){ // if given kelvin
            newtemp = temp;
        }
        if (newtemp < 0){
            printf("Invalid temperature (cannot be lower than absolute zero)\n");
        }
        else {break;}
        }

    while (1 == 1){ // gets the output scale
        printf("Enter scale to convert to (0 for celcius, 1 for fahrenheit, 2 for kelvin):\n");
        scanf("%d", &out);
        
        if (out == tempscale){
            printf("Cannot convert within the same temperature scale. Try a different scale.\n");
        }
        else {break;}
    }
    if ( tempscale == 0){ // given a celsius
        if (out == 1) { //to fahrenheit
            newtemp = celsius_to_fahrenheit(temp);
            printf("%f Celsius is %f Fahrenheit\n", temp, newtemp);
            categorize_temperature(temp); // temp is already in celsius, dont need to change it first
            return 0;
        }

        if (out == 2) { // to kelvin 
            newtemp = celsius_to_kelvin(temp);
            printf("%f Celsius is %f Kelvin\n", temp, newtemp);
            categorize_temperature(temp); // temp is already in celsius, dont need to change it first
            return 0;
        }
    }
    if (tempscale == 1){ // given fahrenheit
        if (out == 0){ // go to celsius
            newtemp = fahrenheit_to_celsius(temp);
            printf("%f Fahrenheit is %f Celsius\n", temp, newtemp);
            categorize_temperature(newtemp); // can use newtemp to avoid extra conversion
            return 0;
        }
        if (out == 2){ // go to kelvin
            newtemp = celsius_to_kelvin(fahrenheit_to_celsius(temp)); // gets kelvin
            printf("%f Fahrenheit is %f Kelvin\n", temp, newtemp);
            newtemp = fahrenheit_to_celsius(temp); // converts to usable number
                // in hindsight i didnt need to do that
            categorize_temperature(newtemp);
            return 0;
        }
    }
    if (tempscale == 2){ // given kelvin
        if (out == 0){ // go to celcius
            newtemp = kelvin_to_celsius(temp);
            printf("%f Kevlin is %f Celsius\n", temp, newtemp);
            categorize_temperature(newtemp); // uses newtemp to avoid extra conversion
            return 0;
        }
        if (out == 1){ // go to fahrenheit
            newtemp = celsius_to_fahrenheit(kelvin_to_celsius(temp)); // gets fahrenheit
            printf("%f Kevlin is %f Fahrenheit\n", temp, newtemp);
            categorize_temperature(fahrenheit_to_celsius(newtemp)); // converts to celsius then hands off
            return 0;
        }
    }
}
// ending comments
    // i believe it is apparenet that i wasnt struggling in this task because there are not GIANT comment blocks like previous assignments
    // seems to work AS LONG AS YOU FOLLOW THE 0 1 2 RULE
        // it does NOT understand words, will just crash
//