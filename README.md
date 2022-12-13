# CS225-Final-Project
This is our groups CS225 Final Project's Github Link so we can publicly share and send our code

Our final project video can be found here: https://www.youtube.com/watch?v=raphAr1lRiI. 

Members: Aashish Subramanian, Aditya Patel, Ved Eti, Soumil Gupta
NetID's: asubr2, apate508, vedeti2, soumilg2

The code is contained in the src folder. An example of how to use the Graph class is in the main.cpp file i.e. it contains a sigle specification of how the code can be run. The dataset is stored in the CSV folder under src. Cloning the git normally should ensure the dataset is in the right place, but please make sure when you have downloaded the code that Dataset.csv is under the CSV folder. If the file is too big, extract the zip folder and manually place the dataset in the correct place.

To run the code, follow a similar process as the mps by first making a build directory. Cd into that directory and call cmake .. 

Next, running the command make will make the project. To run main, call ./main. Similarly, to run the test cases, run ./test. Lastly, the main file can call two different graph making methods i.e. the smaller dataset that we created without webscraping (parsing1()) for testing purposes, and the bigger webscraped dataset (parsing2()), which uses the csv file to aquire links. However, using parsing2() will take a lot of time to run so for grading purposes we recommend using parsing1().
