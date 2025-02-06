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

