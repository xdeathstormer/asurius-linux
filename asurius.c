// Made by xdeathstormer
// https://github.com/xdeathstormer/asurius




#include <stdio.h>
#include <stdlib.h>

// Intialise the required functions
void dgpu(); // Switch to dGPU
void igpu(); // Switch to iGPU
void hybrid(); // Switch to Hybrid GPU [iGPU renders everything and the programs but the dGPU ]
void performanceProfile(); // Switch performance profile [Requires PPD]
void leds(); // Led brightness
void refreshRate(); // Change the refresh rate [a secondary function]


// Intitialise the function required to pick the function that is to be executed

void chooseFunction();

// 
char* version="0.1";


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
}


// dGPU switching function
void dgpu(){
    system("supergfxctl -m AsusMuxDgpu");
}

// iGPU switching function

void igpu(){
    system("supergfxctl -m Igpu");
}

// Hybrid mode switching function
void hybrid(){
    system("supergfxctl -m Hybrid");
}

// Performance profile switching function
void performanceProfile(){
    system("asusctl profile set next");
}

// Switch to the next LED brightness mode
void leds(){
    system("asusctl leds next");
}

// Refresh rate switching function
void refreshRate(){
    ;
}

// Function picker

void chooseFunction(){

    char choice;
    char gpuMode[32];
    char command[100];

    printf("Choose a function: \n"
        
        "1. Change GPU mode \n"
        "2. Switch performance profile \n"
        "3. Change led brightness \n"
        "4. Change Battery limit \n "
        ">>> ");
    scanf("%c", &choice);



    if (choice == '1'){
        printf("Current gpu mode is ");
        fflush(stdout);
        system("supergfxctl -g");
        printf("\n");
        printf("Supported modes are:\n");
        system("supergfxctl -s");
        
        printf("Choose a mode: ");
        scanf("%s", &gpuMode);
        snprintf(
            command,
            sizeof(command),
            "supergfxctl -m %s",
            gpuMode
        );
        system(command);
    }

    if( choice == '2'){
        system("./profile.sh");
    }
    if (choice=='3'){
        system("asusctl leds next");
    }
    if(choice=='4'){
        printf("")
    }
}