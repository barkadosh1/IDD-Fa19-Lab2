# Digital Timer

Pre-Lab Ideas
Pre-Lab Ideas
1.	Circuit Workout: A device that takes in two time parameters – length of each set of the circuit and rest time between circuits. The device will then light up or make appropriate sounds to notify the user if they should start working out or stop and take a rest.
2.	Metronome: A device that takes in two time-related parameters: tempo (can be converted to time in between beats) and what type of time (3/4, 4/4, etc.) The device will then beat appropriately with the tempo and will add a special noise to the first beat of the time style (so as to make clear if it is 3/4, 4/4, etc.).
3.	Work Day: A personalized device for each employee. When arriving at work, you push the button and the timer will start. When you leave you, you push it again and the timer will stop. This will allow for proper reporting of time worked. 
4.	Marathon Runner: A device that takes in a number of miles and a specified value of time that the runner wants to be able to run the distance in. When the runner starts running, he or she pushes a button. The device will light up or make a sound every time the runner should have completed a quarter mile lap if he or she wants to stay on pace.
5.	Keep-Me-Awake: A device intended to keep you awake. A button is pushed and if it is not pushed every 30 minutes, it will make loud noises to wake you up. By pushing every 30 minutes, you are communicating to the device that you are still awake and do not need to be woken up.
6.	Heart Rate Monitor: Click a button. Start counting how many times your heart beats/your pulse. After 60 seconds, an alarm will sound or a light will flash and you will have measured your heart rate.
7.	Get Up and Stretch: When using a computer for a prolonged period of time, use this device. After initially hitting a button, the device will notify you through light or sound every hour so that you get up and stretch and look away from the screen.
8.	Eating Contest: With this device, an alarm will sound after a specified time. Within that time, each contestant clicks one of the buttons after each hot dog they eat (to keep score). This will determine who can eat the most hot dogs in a certain timeframe.
9.	Mental Clock: This device allows for a game. After initially hitting a button, you mentally try to count to 30 and hit the button to try to make the timer stop right at 30 seconds. The device will output how much time actually elapsed between the two presses and whoever gets closest wins the game. 
10.	 Dog in backyard: Keeps track of how long you let your dog out in the backyard to play. After a specified time, the device will flash or make sound. This not only makes sure your dog gets enough exercise but also makes sure that you don’t forget/leave your doggie friend outside too long. 



 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**

**b. What voltage level do you need to power the display backlight?**
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**
  lcd.print("hello, world!");
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

The code for my Lowly Multimeter and a video of it performing are below.
[Lowly Multimeter Code](https://github.com/barkadosh1/IDD-Fa19-Lab2/blob/master/Multimeter.ino)


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
- divide note duration by 2
- Talk about how tested both this (figured out this reduces the rest/silence note as well)
- Used a timer to confirm it actually cut in half from 2276 to 1134
Serial.begin (9600);
Serial.print(millis());
 
**b. What song is playing?**
Star Wars Opening Credits Theme Song!


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
