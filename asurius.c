// Made by xdeathstormer
// https://github.com/xdeathstormer/asurius

#include <stdio.h>
#include <stdlib.h>

// Intialise the required functions
void optimusController(); //Function for controlling Nvidia optimus
void performanceProfile(); // Switch performance profile [Requires PPD]
void leds(); // Led brightness
void refreshRate(); // Change the refresh rate [a secondary function]
void mainBoard(); // Find the mainboard (using dmidecode)
void serialNumber(); // Find the serial number of the laptop

// Intitialise the function required to pick the function that is to be executed

void chooseFunction();
 
const char* version="0.1.1";

// Main function

int main(){
    printf(
    "\033[37mWelcome to Asurius, a "
    "\033[31mLinux"
    "\033[37m alternative to "
    "\033[94mMyASUS"
    "\033[37m and "
    "\033[90mArmoury Crate"
    "\033[0m\n"
);
    printf("Version: %s\n", version);
    chooseFunction();
    return 0;
}


// Deprecated functions
//dGPU switching function
//void dgpu(){
//    system("supergfxctl -m AsusMuxDgpu");
//}

// iGPU switching function

//void igpu(){
  //  system("supergfxctl -m Igpu");
//}

// Hybrid mode switching function
//void hybrid(){
//    system("supergfxctl -m Hybrid");
//}

// [Deprecated]Performance profile switching function
// void performanceProfile(){
    // system("asusctl profile set next"); Deprecated, use ./profile.sh [uses powerprofilesctl to do the same thing but faster]
// }

// Switch to the next LED brightness mode
void leds(){
    system("asusctl leds next");
}

// Refresh rate switching function
void refreshRate(){
    ;
}

// Find the mainboard

void mainBoard(){
    system("sudo dmidecode -s system-product-name | sed 's/.*_//'");
}

// Function picker


void optimusController(){
    
    char gpuMode[32];
    char command[100];

    printf("Current GPU mode is: ");
    fflush(stdout);
    system("supergfxctl -g");

    printf("\nSupported modes:\n");
    system("supergfxctl -s");

    printf("Choose a mode: ");
    scanf("%31s", gpuMode);

    snprintf(
        command,
        sizeof(command),
        "supergfxctl -m %s",
        gpuMode
    );

    system(command);
}

void serialNumber(){
    system("sudo cat /sys/devices/virtual/dmi/id/product_serial");
}


void performanceProfile(){
    system("./profile.sh");
}

// Function chooser
void chooseFunction(){

    int choice;
    //Deprecated variables: gpuMode[32];
    // Deprecated variables:  char command[100];

    printf("Choose a function: \n"
        
        "1. Change GPU mode \n"
        "2. Switch performance profile \n"
        "3. Change led brightness\n"
        "4. Change Battery limit\n"
        "5. Find laptop model\n"
        "6. Find laptop serial number\n"
        ">>> ");
    scanf("%d", &choice);




    switch (choice) {
        case 1:
            optimusController();
            break;

        case 2:
            performanceProfile();
            break;

        case 3:
            leds();
            break;

        case 4:
            printf("Battery limit switching is not implemented yet.\n");
            break;

        case 5:
            mainBoard();
            break;
        
        case 6:
            serialNumber();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}
