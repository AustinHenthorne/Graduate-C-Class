Austin Henthorne and Glenn Ellis
Progress on Final Project 1: MEC510 

The code is finished and works as assigned.

The first class is Wind and the first member function is readData(). This function 
opens and reads all the .csv files (4 files) and seperates the date, time, speed, and
direction into 4 seperate arrays for each file. If their is an empty data point, 
the empty() function is called and replaces the empty cell with a 0.0. We then concate
the string arrays into one large array (deleting the header rows of each .csv file)for
the speed and direction data. The code then goes into the user inputs date, start date, 
start time, end date, end time etc. The start index is then deteremined correspondingly
to the users time and date inputs to our speed and direction arrays. The end index is
also determined. 

The next member function is created called windAverage(). This function deteremines the 
average wind speed using the start and end index (connected to user inputs) created previously 
to choose the range of data points in our self created speed array to average the speeds.
Also does the same for Direction.

The windStandardDev() calculates the root mean square from the average wind speeds using
again our self created start and end index in our speed array. Also the same for Direction.

Our Turbine class is used to calculate the Power of the turbine using the average speed
and some asked user inputs.

The main() function calls these functions respectivley to obtain the average wind speed
and directions, root mean square, and the power of the turbine form the user defined
date and times. These values are outputted for the user.  