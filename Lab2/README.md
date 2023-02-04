### Lab 2 prompt for CPSC 462

Exercise 1:  Object Based Design / Programming
Do these steps in order
Write a textual description of an abstract concept.  Pick one from Automobile, Board Game, or Video Player Device.  Include these paragraphs in your description
Sales pitch.  Convince me I need to buy this thing, and why yours is better than anything else our there.  Tell me the price, when it will be available, what environment it operates in, and what dependencies I must have to use it.  For example, do I need batteries that are not included, electricity or gasoline to power the thing, and so on.
Features.  What can I do to this thing, and (very important) what information is returned if do that?  Don’t tell me what it does, tell me what information is returned. For example, when I ask for a report, don’t tell me the report will be emailed to me, tell me I’ll see a response indicating the request has been accepted for processing.  Make a bullet list of at least five features, generating a report should be one of the five.  Give your features a name in verb form.
Define a software class capturing the above abstraction.  Place the class definition in a header file.  Allow clients (users of your class) to send messages (call functions) to class instances (objects) invoking each of the features above.  Allow clients to ask for a report (e.g., gas mileage history, move history, bandwidth consumption history) by providing public functions, say, generateReport.  Allow your client to ask for a report with no parameters (from inception to now), or with one parameter (start date to now), or two parameters (start and end dates), then provide all those features as overloaded functions.  Remember, think like an object.  Separate interface (the “what”) from implementation (the “how”).
Hint, your class definition will contain function declarations (prototypes) but no function definitions.  If your function has a curly brace you didn’t get it right.
Define and implement a software client that uses the class above and requests all the features (calls each public function).  You’ll have to create objects and manage their lifespan.  This can be done in function main().
Implement the abstraction (the class’s functions) in a separate source (.cpp) file.  Add private attributes to the class as needed, but do not change the class interface (the non-private stuff).  Be sure to include extracting from (reading) and inserting into (writing) your objects to standard input and output respectively and comparing objects to each other for equality and ordering (e.g., less than).

Exercise 2:  Object Oriented Design / Programming
Specialize your class above and update the client (main) accordingly.  That is, create at least two specific kinds of Automobile, Board Game, or Video Player Device and inherit the features from the generalized abstraction.  For example, if Automobile is my abstraction, then let’s say Truck and Car are specific kinds of Automobiles.  Add a unique feature to each specialization.  For example, in addition to everything an Automobile can do, a Truck can plow a snowy road and a Car can park in a tiny parking spot.  Update main above to create instances of your special kinds of automobiles, board games, or video player devices and send messages to invoke their unique features.
Hint, your header (.hpp) and source (.cpp) file from Exercise 1 above are reused here without modification.
Complete the Polymorphism Activity

3 What to deliver:
Exercise 1:  Object Based Design / Programming
Description.docx (or .pdf, or .txt)
Excercise1.cpp
contains your client code (function main() for example)
<your class>.hpp, and <your class>.cpp
Screenshots showing your program compiles and executes


Exercise 2:  Object Oriented Design / Programming
1)    Part 1
Excercise2.cpp
contains your updated client code (function main() for example)
<your 1st specialized class>.hpp, and <your 1st specialized class>.cpp
<your 2nd specialized class>.hpp, and <your 2nd specialized class>.cpp
Screenshots showing your program compiles and executes
2)    Part 2
Updated main - don't do this getSupper.cpp & Screenshots showing your program compile and executes
Updated main - simple getSupper.cpp & Screenshots showing your program compile and executes
Updated main - self registering getSupper.cpp & Screenshots showing your program compile and executes
