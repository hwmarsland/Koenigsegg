/*
 * Koenigsegg's Ultimate Power On Demand (UPOD) System - C++ Implementation
 *
 * This program simulates Koenigsegg's UPOD system, the "brain" behind their custom Light Speed Transmission 
 * that enables lightning-fast shifts between any gears, not just adjacent ones. It optimally selects the 
 * gear for maximum acceleration by mapping speed to engine RPMs within the Jesko Absolut's power band (4500 to 8500 RPM).
 *
 * Key Features:
 * - Calculates optimal gear and engine RPM in ~492 nanoseconds on average (Apple M3 Pro chip).
 * - Uses dyno data and speed-to-RPM functions for each gear to determine optimal performance.
 * - Implements efficient if-else logic for speed-based gear selection.
 * - Includes an ASCII command-line interface with error checking for user inputs.
 *
 * Requirements:
 * - C++11 or later for compilation.
 * - To run: Execute via terminal: 
 *   `g++ upod_logic.cpp -o upod.exe` and `./upod.exe`
 *
 * Author: Harris Marsland
 */

# include <iostream>
#include <iomanip>
#include <thread>

using namespace std;
using namespace chrono;

struct GearFunctions {
    double m; // Slope
    double b; // Y-Intercept
};

const GearFunctions gears[] = {
    {0.00509412, 0.0529412}, // Gear 1
    {0.00658235, 0.233824}, // Gear 2
    {0.00838235, 0.0588235}, // Gear 3
    {0.0107088, 0.0705882},
    {0.0138147, 0.442647},
    {0.0176382, 0.0941176},
    {0.0223824, 0.0588235},
    {0.0290118, 0.194118},
    {0.0367676, 0.0411765} // Gear 9
};

int getOsName()
{
    #ifdef _WIN32
    return 0;
    #elif _WIN64
    return 0;
    #elif __APPLE__ || __MACH__
    return 1;
    #endif
}


int upod(double &speed, double &rpm, int &computedGear, double &ms){

    auto start = high_resolution_clock::now(); // Timing activations

    if (speed < 6) {
        rpm = 1000;
        computedGear = 1;
    } else if (speed < 30){
        rpm = floor((speed - gears[0].b) / gears[0].m);
        computedGear = 1;
    } else if (speed < 38){
        rpm = floor((speed - gears[1].b) / gears[1].m);
        computedGear = 2;
    } else if (speed < 48){
        rpm = floor((speed - gears[2].b) / gears[2].m);
        computedGear = 3;
    } else if (speed < 63){
        rpm = floor((speed - gears[3].b) / gears[3].m);
        computedGear = 4;
    } else if (speed < 79){
        rpm = floor((speed - gears[4].b) / gears[4].m);
        computedGear = 5;
    } else if (speed < 101){
        rpm = floor((speed - gears[5].b) / gears[5].m);
        computedGear = 6;
    } else if (speed < 131){
        rpm = floor((speed - gears[6].b) / gears[6].m);
        computedGear = 7;
    } else if (speed < 165){
        rpm = floor((speed - gears[7].b) / gears[7].m);
        computedGear = 8;
    } else if (speed >= 165){
        rpm = floor((speed - gears[8].b) / gears[8].m);
        computedGear = 9;
    } else {
        cout << "Error, no gear found" << endl;
    }

    auto end = high_resolution_clock::now();
    ms = duration<double, nano>(end-start).count();

    return 0;
}


void displayMeters(double &speed, double &rpm, int &computedGear, double &ms) {
    // Clear the screen
    if (getOsName() == 1){
        system("clear");  // For Linux/macOS
    } else {
        system("cls");  // For Windows
    }

    cout << "Koenigsegg Jesko Absolut\n" << endl;
    cout << "Previous shift to gear " << computedGear << " computed in " << ms << " nanoseconds.\n" << endl;
    cout << "Speedometer: " << setw(3) << speed << " mph / 310 mph" << endl;
    
    // Simple ASCII representation
    cout << "[";
    for (int i = 0; i < 50; i++) {
        if (i < speed / 6) cout << "=";
        else cout << " ";
    }
    cout << "]\n";

    cout << "Tachometer: " << setw(4) << rpm << " rev/min / 8500 rev/min" << endl;

    cout << "[";
    for (int i = 0; i < 50; i++) {
        if (i < rpm / 170) cout << "=";
        else cout << " ";
    }
    cout << "]" << endl;

    cout << "\nMenu:" << endl;
    cout << "Set Speed - S" << endl;
    cout << "Set RPMs - R" << endl;
    cout << "Find Optimal Gear (UPOD) - G" << endl;
    cout << "Close Program - Q\n" << endl;

}


int main (){
    double speed = 0, rpm = 0;
    char menuInput;
    int temp;
    int speedInput;
    int computedGear = 1;
    double ms = 0;

    while (true) {
        displayMeters(speed, rpm, computedGear, ms);

        cout << "Enter menu command: ";
        cin >> menuInput;

        if (menuInput == 'q' || menuInput == 'Q') break;

        switch (menuInput) {
            case 'S': case 's':
                cout << "Enter speed (mph): ";
                while (!(cin >> speedInput)) {
                    cin.clear();  // Clear error flag
                    cin.ignore(1000, '\n');  // Discard invalid input
                    cout << "Invalid input. Please enter an integer: ";
                }
                if (speedInput < 0 || speedInput > 310){
                    cout << "Invalid input!\n\n";
                    this_thread::sleep_for(milliseconds(200));
                    break;
                } else {
                    speed = speedInput;
                    break;
                }
            case 'R': case 'r':
                cout << "Enter engine RPMs: ";
                while (!(cin >> speedInput)) {
                    cin.clear();  // Clear error flag
                    cin.ignore(1000, '\n');  // Discard invalid input
                    cout << "Invalid input. Please enter an integer: ";
                }
                if (speedInput < 0 || speedInput > 8500){
                    cout << "Invalid input!\n\n";
                    this_thread::sleep_for(milliseconds(200));
                    break;
                } else {
                    rpm = speedInput;
                    break;
                }
            case 'g': case 'G':
                upod(speed, rpm, computedGear, ms);
                break;
            default:
                cout << "Invalid input!\n\n" << endl;
                this_thread::sleep_for(milliseconds(200));
                break;
        }
    }
}
