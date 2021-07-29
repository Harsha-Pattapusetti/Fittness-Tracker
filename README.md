# Fittness-Tracker
Used the data collected from a single accelerometer (on your microcontroller board) to record body movements to identify exercises.

## Interface
 The board begins measurement once it is powered on. The button allows the user to reset the board's LEDs as well as the count of each exercise.
 
An LED of the corresponding exercise (4 LEDs) will gradually change from red to green upon detection of each repetition. Before any repetitions have begun for a particular exercise, the LEDs will remain off. Only upon detection of the first repetition will the LED first turn red. Once 15 repetitions have been completed, each LED will be solidly green.

## Tracking
The user has freedom in the order with which they complete each exercise. This means that if the user would like, the user would be able to do one jumping jack, one sit-up, one push-up, and one squat such that the LEDs will indicate progress together. To track these movements, the accelerometer on the Circuit Playground is used.
