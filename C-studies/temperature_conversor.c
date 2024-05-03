#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

float celsius_fahrenheit(float temp, char conv_unit) {
    float nov_temp;

    if (conv_unit == 'C') {
        nov_temp = (temp - 32) * (5 / (float) 9);
    }

    else {
        nov_temp = (temp * (9 / (float) 5)) + 32;
    }

    return nov_temp;
}

float celsius_kelvin(float temp, char conv_unit) {
    float nov_temp;

    if (conv_unit == 'C') {
        nov_temp = temp - 273.15;
    }

    else {
        nov_temp = temp + 273.15;
    }

    return nov_temp;
}

float celsius_rankine(float temp, char conv_unit) {
    float nov_temp;

    if (conv_unit == 'C') {
        nov_temp = (temp - 491.67) * (5 / (float) 9);
    }

    else {
        nov_temp = (temp * (9 / (float) 5)) + 491.67;
    }

    return nov_temp;
}

float fahrenheit_kelvin(float temp, char conv_unit) {
    float nov_temp;

    if (conv_unit == 'F') {
        nov_temp = ((temp - 273.15) * (9 / (float) 5)) + 32;
    }

    else {
        nov_temp = ((temp - 32) * (5 / (float) 9)) + 273.15;
    }

    return nov_temp;
}

float fahrenheit_rankine(float temp, char conv_unit) {
    float nov_temp;

    if (conv_unit == 'F') {
        nov_temp = temp - 459.67;
    }

    else {
        nov_temp = temp + 459.67;
    }

    return nov_temp;
}

float kelvin_rankine(float temp, char conv_unit) {
    float nov_temp;

    if (conv_unit == 'K') {
        nov_temp = temp * (5 / (float) 9);
    }

    else {
        nov_temp = temp * 1.8;
    }
    
    return nov_temp;
}

float convert(float temp, char prim_unit, char conv_unit, char array[]) {
    float nov_temp;

    switch (prim_unit) {

    case 'C':

        switch (conv_unit) {

        case 'F':
            nov_temp = celsius_fahrenheit(temp, conv_unit);
            strcpy(array, "Fahrenheit");
            break;
        
        case 'K':
            nov_temp = celsius_kelvin(temp, conv_unit);
            strcpy(array, "Kelvin");
            break;

        case 'R':
            nov_temp = celsius_rankine(temp, conv_unit);
            strcpy(array, "Rankine");
            break;
        }

        break;
    
    case 'F':

        switch (conv_unit) {
            
        case 'C':
            nov_temp = celsius_fahrenheit(temp, conv_unit);
            strcpy(array, "Celsius");
            break;
        
        case 'K':
            nov_temp = fahrenheit_kelvin(temp, conv_unit);
            strcpy(array, "Kelvin");
            break;

        case 'R':
            nov_temp = fahrenheit_rankine(temp, conv_unit);
            strcpy(array, "Rankine");
            break;
        }

        break;

    case 'K':

        switch (conv_unit) {

        case 'C':
            nov_temp = celsius_kelvin(temp, conv_unit);
            strcpy(array, "Celsius");
            break;
        
        case 'F':
            nov_temp = fahrenheit_kelvin(temp, conv_unit);
            strcpy(array, "Fahrenheit");
            break;

        case 'R':
            nov_temp = kelvin_rankine(temp, conv_unit);
            strcpy(array, "Rankine");
            break;
        }

        break;

    case 'R':

        switch (conv_unit) {

        case 'C':
            nov_temp = celsius_rankine(temp, conv_unit);
            strcpy(array, "Celsius");
            break;
        
        case 'F':
            nov_temp = fahrenheit_rankine(temp, conv_unit);
            strcpy(array, "Fahrenheit");
            break;

        case 'K':
            nov_temp = kelvin_rankine(temp, conv_unit);
            strcpy(array, "Kelvin");
            break;
        }

        break;
    }

    return nov_temp;
}

int main() {
    char unit;
    float temp;
    bool check = true;
    char array[10];

    printf("\nInput the unit of temperature Celsius (C), Fahrenheit (F), Kelvin (K) or Rankine (R): ");
    scanf(" %c", &unit);

    unit = toupper(unit);

    switch (unit) {

    case 'C':
        printf("The temperature is currently in Celsius.");
        strcpy(array, "Celsius");
        break;
    
    case 'F':
        printf("The temperature is currently in Fahrenheit.");
        strcpy(array, "Fahrenheit");
        break;

    case 'K':
        printf("The temperature is currently in Kelvin.");
        strcpy(array, "Kelvin");
        break;

    case 'R':
        printf("The temperature is currently in Rankine.");
        strcpy(array, "Rankine");
        break;

    default:
        printf("This isn't an unit of temperature supported on this programm.");
        check = false;
        break;
    }

    if (check) {
        printf("\nEnter the temperature in %s: ", array);
        scanf("%f", &temp);

        char new_unit;
        char array2[10];

        printf("Enter the unit that you want to convert: ");
        scanf(" %c", &new_unit);

        new_unit = toupper(new_unit);

        if (unit == new_unit) {
            printf("I think you already have this temperature...");
        }

        else {
            float conv_temp = convert(temp, unit, new_unit, array2);
            printf("%.2f in %s equals to %.2f in %s", temp, array, conv_temp, array2);
        }
    }
    
    return 0;
}