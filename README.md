# Koenigsegg's Ultimate Power On Demand (UPOD) System
Koenigsegg's custom Light Speed Transmission is uniquely impressive, allowing the driver to make lightning fast shifts between any gears, not just adjacent ones. To allow this, it employs a technology called UPOD or Ultimate Power On Demand that acts as "the brain that instantly selects and engages optimum gearing for maximum acceleration" ([Koenigsegg](https://www.koenigsegg.com/lst)). I have recreated the UPOD system here.

## My Solution
### Planning
When going into this project I knew speed was going to be the most important aspect. Koenigsegg says that the LST "gearbox can jump between any two ratios in just two milliseconds" ([Car and Driver](https://www.caranddriver.com/features/a28927301/koenigsegg-new-transmission-promises-ultraquick-shifts/)), so my recreation of the UPOD technology needed to be a small fraction of that.
After that prioritization, I found the dyno chart and gearing of the Koenigsegg Jesko Absolut, which would be my example car ([Source](https://www.motormatchup.com/catalog/Koenigsegg/Jesko/2021/Absolut)). With that information I derived the following relevant items:
- Power Band: I determined the power band to be from 4500 to 8500 RPM. At 4500 RPM the Jesko produces the maximum amount of torque. As RPMs increase the torque stays high as the horsepower rises until 7800 where maximum horsepower is reached and sustained until redline at 8500 RPM.
- Optimal Engine Speed: If the power band is 4500 to 8500 RPM, the UPOD system would select a value in that range for the optimal power. I shot for the low end to allow the driver to experience a fuller range of the power band before needing to shift again.
- Speed/RPM Functions: For each gear I mapped the speed at a given RPM value onto a graph and then found a best fit function for each. This would be used to determine the RPMs of each gear at a given speed.
### Implementation
I tried multiple approaches but ultimately landed on using if-else statements since ranges are not accepted in switch statements in C++ and looping through the functions would be much slower. Additionally, I passed variables by reference whenever possible to avoid copying.
The if-else statements allow me to implement the logic that I build before implementing the code. This logic dictates that the speed for the selected optimal gear will be between the speed when that gear is at 4500 rpm to the speed where the next gear up is at 4500 rpm (barring edge cases). For example, gear 5 would be at 4500 RPM when the car is going 63 mph and gear 6 would be at 4500 RPM when the car is going 79 mph. Therefore, the UPOD system will put the car in 5th gear when the car is going between 63 mph and 78 mph to make the engine run in the low end of the power band somewhere between 4500 RPM and a bit more than 5500 RPM (depending on the speed) to give the driver the optimal gear for maximum acceleration.
Using the if-else statements to dictate these speed ranges, the program sets the optimal gear and the engine RPM (dictated by the best fit function that was found for each gear).
### GUI
Having set up the logic (the main bit of the problem) I then created a simple ASCII visual to run in the command line to allow the user to interact with the UPOD system and represent relevant information. I also added  error checking for user inputs.
### Results
After tweaking for program efficiency several times, the program now determines the optimal gear and RPM in an average of 492 nanoseconds (sample size of 10 tests) on an Apple M3 Pro chip. I have not seen it go above 1 microsecond on the latest version. 
> This means that on average, my recreation of the UPOD system computes the optimal gear in 1/4000th of the overall shift time.
## How to Use
I used auto classifiers for the timing functions, so you need to be using C++11 to compile this program. To run the program on your system, download the `upod_logic.cpp` file, head over to your terminal, navigate to the correct directory and run `g++ upod_logic.cpp -o upod.exe` then `./upod.exe`. Finally, enjoy!
