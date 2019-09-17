# Digital Timer

Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**

<img src="https://github.com/barkadosh1/IDD-Fa19-Lab2/blob/master/IMG_9454.jpeg">

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**

The typical Voltage needed to power the display is +5V. We can confirm this in two ways. The easisest and surest way to confirm this is with the provided data sheet, which suggests that the supply voltage (VDD) is +5V. As the data sheet suggests, the ground pin (0 V) is VSS.

The other way to confirm this is by looking at our assembly. Since pin 2 (VDD) is the pin we are using to power our display, we can easily trace it back to the +5V connection on the Arduino board, confirming that this is the voltage being used to power the display.

**b. What voltage level do you need to power the display backlight?**

The voltage level used to power the display backlight is approximately +3.3V. Similarly, we can also confirm this in two ways. Through the provided data sheet, we see that the operating voltage of the display backlight is +3.2V +/- 0.15V. The data sheet also suggests that pin 15 is where the power for the display backlight is connected and that pin 16 is the ground for the backlight.

The other way to confirm this is again by looking at our assembly. Since pin 15 is the pin we are using to power our display backlight, we can easily trace it back to the +3.3V connection on the Arduino board, confirming that this is the voltage being used to power the display backlight.
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

The first mistake I made when wiring up my display was with understanding whether the vertical rails were connected or not. I also initially connected both the +5V and +3.3V power sources to the same power rail. However, when re-inspecting my board before plugging it into the computer, I realized that these two power sources needed to be connected to separate points. I also realized that there were 4 separate vertical rails – therefore, I changed my board and connected the +5V to one vertical rail and the +3.3V to another vertical rail. 

Additionally, when I first plugged my board in and uploaded the “Display” program, I did not notice any change. It took me a couple of minutes to realize that my potentiometer was turned all the way up. Once I turned it down and allowed more current to reach the display, the output of the program became visible. 

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

Within the code, there is a line of code lcd.print("hello, world!") which determines what string value is being flashed on the LCD. Therefore in order to change what is flashing, you simply need to change the string inside of the paranthesees -- I changed it to lcd.print("hello, Bar!").
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

The code for my Lowly Multimeter and a video of it performing are below.

[Lowly Multimeter Code](https://github.com/barkadosh1/IDD-Fa19-Lab2/blob/master/Multimeter.ino)

[Lowly Multimeter Video](https://youtu.be/rp6lIAjKkRA)


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**

A video of my rotary encoder is below. As can be seen in the video, the output is meant to track the count of how many times you turn the knob. After experimenting with turning the knob in both directions, I realized the following: if you turn it one way, it will start counting up away from 0. However, if the knob is turned the other direction, it will jump from 0 to a value of 16383 and continue counting down until the direction of rotation is reversed again.

[Rotary Encoder](https://youtu.be/tADYrZDOaCU)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

To achieve this, I tried two different methods. The first involved altering the following line of code: int noteDuration = 1000 / noteDurations[thisNote];. The second involved altering the following line of code instead: int pauseBetweenNotes = noteDuration * 1.30;. In each case, the way I altered the code was by dividing the noteDuration or the pauseBetweenNotes values by an additional factor of 2 (the rest of the answer will clarify which one of these alterations was actually correct).

My first test regarding these changes was to numerically measure if they produced the desired result. I added the line "Serial.begin(9600)" before the for loop and added the line "Serial.print(millis())" at the end of the for loop and ran the code for the above two scenarios and for one scenario where neither of the variables/durations were altered. For the unaltered scenario, the time output was 2276 milliseconds, while the altered scenarios had time outputs of 1134 and 1136 milliseconds. This confirmed for me that both methods technically sped the song up to be twice as fast.

However, after further examining the code, I realized that the melody[] array was accounting for rests/silence as well with values of 0. This meant that when dividing the noteDuration by 2, the notes AND rests were being divided by 2, which was the desired result. When actually playing the song, it sounded correct as well, so this was the correct way to make it play twice as fast. 

Dividing pauseBetweenNotes by 2, however, seems to just alter the space in between notes and not the actual value of the notes. Therefore, it squishes everything together. Although it cuts the time of the whole song in half, it does not sound correct when the program is run. This is why this alteration was not the correct choice.
 
**b. What song is playing?**

Star Wars Opening Credits Theme Song!!! Video below.

[Star Wars Theme Song!](https://youtu.be/hE0YQCECQww)


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

I like to think of my timer as a fun dance machine that would be used for study breaks in order to reduce stress and get moving. Once the program is run, a 10-second countdown will begin, accompanied by the words “Dance Party In.” Once it hits zero, two things will simultaneously occur: “Take On Me” will play on the speakers and 16 dancing stick figures will appear on the LCD screen. Once the song ends, the LCD screen will prompt the user to “Push the Button To Dance Again” – once pressed, the countdown and song will repeat. 

For my timer, I tried to make use of several different tools – sound, visual (through the LCD), and a button. For the board, I made use of the same board I had set up during part D and incorporated a button by connecting it to digital pin 0 and ground. 

For my code, I first defined the notes/pitches and used the melodies and note durations arrays for the song “Take On Me,” which I found on a public library online.  Within the loop(), a counter starts at 10 and goes down to 0. However, I initially noticed that the counter decremented in the following way: “10—90—80—70—60…0.” I realized that the 0 was being leftover from when I printed 10 and to account for this, I printed an empty string to the cursor where 0 was whenever the countdown was less than 10 in order to hide the zero.

Once the timer hits 0, a for loop begins playing each note of the “Take On Me” song. However, I wanted to add a visual component to this as well. Each time through the loop, I printed 16 stick figures with their hands down to the LCD. However, every 3rd time through the loop, I printed the stick figures with their arms up, which created the illusion of 16 stick figures dancing along with the music.

Once the for loop finishes, I coded the LCD to print “Push the Button to Dance Again :)” and then created a while loop that continues running until the button is pushed (see code for specifics of how I coded this part). Once it gets pushed, the LCD screen clears and the entire loop() process repeats. 

As a final note, I made use of the millis() method for my countdown. I subtracted millis() from 10 so that the display started at 10 seconds and counted down to 0. However, for any future loops, the millis() function was much farther past 10 seconds and my display was printing negative numbers and never actually reached 0. To fix this, at the end of the loop(), I saved the current millis() value and added it to the time value at the beginning of the next loop().

[Dance Timer Code](https://github.com/barkadosh1/IDD-Fa19-Lab2/blob/master/OwnTimer.ino)

[Dance Timer Video](https://youtu.be/TT4t3e0F5Uo)

**b. Post a link to the completed lab report your class hub GitHub repo.**

Completed.
