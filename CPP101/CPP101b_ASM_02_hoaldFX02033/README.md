## Driving Support Information Display Application
### Author: **Le Duc Hoa - hoaldfx02033**
### Date: 8-6-2021
#
## Funtion
### 1. Login feature:
- User must type password befor access this car system
### 2. Gear shift control
- P (Park): Used to shift gears to Park gear, park and stop the car
- R (Reverse): Used to shift gears to Reverse gear, reverse the car
- N (Neutral): Used to shift gears to Neutral gear, stop the car
- D (Drive): Used to shift gears to Drive gear, move forward
- POWER OFF to turn off the engine.
### 3. Safe distance
- When the speed is 0 km/h, the vehicle is sucessfully stopped. A vehicle can only shift gears to P / N when it is completely stopped.
- When the vehicle's speed is over 0 km/h (the vehicle has not completely stopped), notify the driver to stop before changing gear.
### 4. Display information for driver about gear shifting and speed changing.
- When user selects R or D gear:
For each time choosing the accelerative option: accelarate 5 km/ h (equivalent to inceasing speed).<br> For each time choosing the decelerative option: decelerate 5 km/ h (equivalent to slowing down speed. And for applying brake, <br>stop the car (decelarate to 0 km/ h).
- If speed is over 60 km / h in Drive gear (or over 20km/ h in Reverse gear), issue a high-speed warning to the driver.
### 5. Turn off the engine
- Stop engine
#
#### Editor: Visual Studio Code-version 1.56.2
#### Compiler: g++
#### OS: Ubuntu
#### ![Tux, the Linux mascot](tux.png)