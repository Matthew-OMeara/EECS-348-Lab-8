// Include the standard input/output header
#include <stdio.h>

// Create a prototype function for convert_temp
float convert_temp(float original_temp, char original_scale, char desired_scale);

// Create a main fuction that is run when temp_converter.c is run
int main() {
    // Create a variable that will hold the original temperature the user enters
    float original_temp;
    // Create a variable that will hold the original scale the user enters
    char original_scale;
    // Create a variable that will hold the desired scale the user enters
    char desired_scale;
    // Prompt the user to enter the temperature
    printf("\nEnter the temperature value: ");
    // Use scanf to get the temperature the user entered and assign it to original_temp
    scanf("%f", &original_temp);
    // Prompt the user to enter the original scale
    printf("Enter the original scale (C, F, or K): ");
    // Use scanf to get the character the user entered and assign it to original_scale
    scanf(" %c", &original_scale);
    // Run scanf to reset the buffer
    getchar();
    // Prompt the user to enter the desired scale
    printf("Enter the scale to convert to (C, F, or K): ");
    // Use scanf to get the character the user entered and assign it to desired_scale
    scanf(" %c", &desired_scale);
    // Perform a check to see if the value of original_scale is not a valid value (Not 'C', 'F', or 'K')
    if (original_scale != 'C' && original_scale != 'F' && original_scale != 'K') {
        // Tell the user that an invalid character was entered for original scale
        printf("The character \'%c\' entered for the original scale is not 'C', 'F', or 'K'. Please make sure that your entry is a capital of the letters listed. Ending program.\n\n", original_scale);
        // Return 0 to exit main and end the program
        return 0;
    }
    // Perform a check to see if the value of desired_scale is not a valid value (Not 'C', 'F', or 'K')
    if (desired_scale != 'C' && desired_scale != 'F' && desired_scale != 'K') {
        // Tell the user than an invalid character was entered for desired scale
        printf("The character \'%c\' entered for the scale to convert to is not 'C', 'F', or 'K'. Please make sure that your entry is a capital of the letters listed. Ending program.\n\n", desired_scale);
        // Return 0 to exit main and end the program
        return 0;
    }
    // Print the temperature after the conversion
    printf("Converted temperature: %.2f %c\n", convert_temp(original_temp, original_scale, desired_scale), desired_scale);
    // Create a variable to hold the temperature entered in celcius to do the temperature category
    float cels_temp = convert_temp(original_temp, original_scale, 'C');
    // Print the temperature category label
    printf("Temperature category: ");
    // Check to see if cels_temp is below O C
    if (cels_temp < 0) {
        // Print the temperature category
        printf("Freezing\n");
        // Print a weather advisory
        printf("Weather advisory: Wear a heavy coat when going outside.\n\n");
    }
    // Else, check to see if cels_temp is between 0 and 10 C
    else if (cels_temp < 10) {
        // Print the temperature category
        printf("Cold\n");
        // Print a weather advisory
        printf("Weather advisory: Wear a jacket.\n\n");
    }
    // Else, check to see if the cels_temp is between 10 and 25 C
    else if (cels_temp < 25) {
        // Print the temperature category
        printf("Comfortable\n");
        // Print a weather advisory
        printf("Weather advisory: Make sure to wear sunscrean.\n\n");
    }
    // Else, check to see if the cels_temp is between 25 and 35 C
    else if (cels_temp < 35) {
        // Print the temperature category
        printf("Hot\n");
        // Print a weather advisory
        printf("Weather advisory: Drink plenty of water!\n\n");
    }
    // Else, the category is extreme heat
    else {
        // Print the temperature category
        printf("Extreme Heat\n");
        // Print a weather advisory
        printf("Weather advisory: Stay indoors and keep your AC on.\n\n");
    }
    // Exit main with a return of 0
    return 0;
}

// Create a function that takes a temperature, the temperatures scale, and the conversion target and converts the given temperature to the desired scale
float convert_temp(float original_temp, char original_scale, char desired_scale) {
    // Check to see if the original_scale and the desired_scale are the same
    if (original_scale == desired_scale) {
        // If they are the same, then no conversion needs to happen, and we can just return original_temp
        return original_temp;
    }
    // Check to see if the desired scale is Celsius
    else if (desired_scale == 'C') {
        // Check to see if the original scale is Fahrenheit
        if (original_scale == 'F' ) {
            // Return the result of converting Fahrenheit to Celsius using C = (F - 32) * 5/9.0
            return (original_temp - 32) * 5.0/9.0;
        }
        // Else, the original scale is Kelvin
        else {
            // Return the result of converting Kelvin to Celsius using C = K - 273.15
            return original_temp - 273.15;
        }
    }
    // Check to see if the desired scale is Kelvin
    else if (desired_scale == 'K') {
        // Check to see if the original scale is Celsius
        if (original_scale == 'C') {
            // Return the result of converting Celsius to Kelvin using K = C + 273.15
            return original_temp + 273.15;
        }
        // Else, the original scale is Fahrenheit
        else {
            // Return the result of converting Fahrenheit to Kelving using K = ((F - 32) * 5/9.0) + 273.15
            return ((original_temp - 32) * 5.0/9.0) + 273.15;
        }
    }
    // Else, the desired scale is Fahrenheit
    else {
        // Check to see if the original scale is Celsius
        if (original_scale == 'C') {
            // Return the result of converting Celsius to Fahrenheit using F = (C * 1.8) + 32
            return (original_temp * 1.8) + 32;
        }
        // Else the original scale is Kelvin
        else {
            // Return the result of converting Kelvin to Fahrenheit using F = ((K - 273.15) * 1.8) + 32
            return ((original_temp - 273.15) * 1.8) + 32; 
        }
    }
}