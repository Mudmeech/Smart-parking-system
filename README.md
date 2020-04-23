# Smart-parking-system
The Arduino ide program is used for control of all hardware systems. Coding is separated into 4 main files including Main, Post, Infar, Rfid and Servo. 

Main file: It is the main processor of the program. It contains all required libraries such as WIFI, Servo and etc. Set up and loop function also in this file. Moreover, Slot status function is in the main file. Its function is activated when a car leaves the spot. It will command the servo to close by Servo file and update status to the server by Post file.

Post file: Consist of a communication function to the application via WIFI, for example receiving clients booking slots and sending slot status. 

Infrared file: Control IR infrared sensors to check parking status. The data sends to slot status function in Main file 

Rfid file: Command RFID reader to read a tag on the module. Then, sending data to Post file to check with a server.

Servo file: Control six micro servo motor to close when Slot status function commands and open when loop function commands.

The sequence of steps is controlled by the Main file. Starting with, checking the RFID tag is available (Rfid file). Then, if it is available, checking client’s data with the database whether they are booking a parking slot or not. After that, if they are reserved, the server sends a parking slot number to the board.(Post file) Servo motor in that slot opens a gate.(Servo file) Next, IR infrared sensors checking status whether parking or leaving.(Infrared file) If the clients leave, servo motors close the gate and empty spot updates on the application. (Servo and post file) as shown in the picture below
