
#include <iostream>
#include <unistd.h> // Needed for the sleep() function to freeze time loops
#include "SFML/Audio.hpp"



// Standard function to handle flashing the desktop alert
void sendDesktopAlert(std::string title, std::string message) {
    // Construct the terminal execution command string
    std::string command = "notify-send '" + title + "' '" + message + "'";

    // system() executes the string command natively on your Linux layout
    system(command.c_str());
}

int main() {
    int minutes = 0;
    bool isRunning = true;

    std::cout << "========================================\n";
    std::cout << "     🛡️ CYBERSECURITY FOCUS GUARD 🛡️   \n";
    std::cout << "========================================\n";
    std::cout << "Enter focus session duration (in minutes): ";
    std::cin >> minutes;

    // Send an immediate notification that the timer has initialized
    sendDesktopAlert("Focus Guard Active", "Your session has started. Lock in, Sean!");
    // Me fucking around with DesktopAlert and system command code
    // Maybe add a sound effect or two
    // Also see about adding a basic graphical user interface or something with graphics

    // Play the audio boss blow from ROTT soundtrack when starting or timer ends


    // load the .wav file for boss blow
   std::cout << "--- BOSS DEFEATED ---" << std::endl;
    std::cout << "Triggering explosion sound effect..." << std::endl;

    // Plays boss_blow.wav in the background using the local directory path
    // Plays boss_blow.wav in the background with proper quotes for spaces
std::system("paplay \"/home/sean/Documents/focus guard/30 - Boss Blow.wav\" &");


    std::cout << "The sound is playing! Text can still print out concurrently." << std::endl;

    // Pause the program for 4 seconds so the console doesn't close mid-sound
    sleep(4);

    std::cout << "Program finished." << std::endl;


    sendDesktopAlert("Eat Lead!!!", "Here, Catch!!!");

    std::cout << "\nTimer started for " << minutes << " minutes. Keep crushing it!\n";

    // Loop until our timer countdown hits zero
    while (minutes > 0) {
        std::cout << "Time remaining: " << minutes << " minutes...\n";

        // sleep(60) freezes the execution path for exactly 60 seconds (1 minute)
        sleep(60);

        minutes = minutes - 1; // Subtract one minute from our tracker variable
    }

    // The countdown has finished! Flip our tracking boolean state
    isRunning = false;

    if (!isRunning) {
        std::cout << "\nTime is UP! Step away from the screens.\n";

        // Trigger a native graphical alert box and ring the terminal bell sound channel

        sendDesktopAlert("🛡️ SESSION COMPLETE", "Step away from the screen, grab some water, and blink!");
        // Play How'd I do from rott when timer is done
        std::system("paplay \"/home/sean/Documents/focus guard/How.wav\" &");

        std::cout << "\a";
    }

    return 0;
}
// Credit for Boss Blow and How'd I do go to Apogee, Lee Jackson and Rise of The Triad
