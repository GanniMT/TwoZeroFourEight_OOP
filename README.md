# **TwoZeroFourEight - OOP**



## **Description**

Object Oriented rendition of the popular sliding tile puzzle video game 2048. Features included are a Hall of Fame and the ability to load a game if you didn't finish playing. This project was made using C++ and can be used on any IDE that supports C++. Future updates that can be made include but are not limited to: updating the UI with better graphics and possibly incorporating an SFML library.



## **Table of Contents**

1. [How to Install and Run the Project](https://github.com/ckohlbeck1/TwoZeroFourEight_OOP/edit/main/README.md#how-to-install-and-run-the-project)

2. [How to Use the Project](https://github.com/ckohlbeck1/TwoZeroFourEight_OOP/edit/main/README.md#how-to-use-the-project)
    - [Gameplay](https://github.com/ckohlbeck1/TwoZeroFourEight_OOP/edit/main/README.md#gameplay)
    - [Classes](https://github.com/ckohlbeck1/TwoZeroFourEight_OOP/edit/main/README.md#classes)

3. [How to Contribute to the Project](https://github.com/ckohlbeck1/TwoZeroFourEight_OOP/edit/main/README.md#how-to-contribute-to-the-project)



## **How to Install and Run the Project**

Simply clone the repository
```
git clone https://github.com/GanniMT/TwoZeroFourEight_OOP 
```
Then open the folder in an IDE that supports C++, and run the program.



## **How to Use the Project**

### *Gameplay*

The game is played just like the classic game 2048. Use the AWSD keys to indicate whether you want all the tiles to combine upwards (w), to the left (a), downwards (s), or to the right (d). You play until you can no longer combine any tiles and the board is completely full.

In addition, there is a "Hall of Fame" where you can see all of the highscores, and features to load a previous game (L), start a new game (N), or save your current game (X). The "Hall of Fame" can be accessed by pressing the "H" key.

<img src="/gitImages/gameplay.gif" alt="Gameplay">

### *Classes*
#### GUI

Source files: `GUI.h`, `GUI.cpp`

This class is concerned with the general graphical user interface of the whole program.

##### Game GUI

Source files: `GameGUI.h`, `GameGUI.cpp`

This class is derived from the GUI class. It is concerned with the graphical user interface of the game of the program.

##### Main Menu

Source files: `MainMenu.h`, `MainMenu.cpp`

This class is derived from the GUI class. It is concerned with the Main Menu of the program.

#### Base

Source files: `TwoZeroFourEight.h`, `TwoZeroFourEight.cpp`

This class is concerned with the base logic of the game itself.

##### Logic

Source files: `Logic.h`, `Logic.cpp`

This class is derived from the `TwoZeroFourEight` class. It is concerned with more rather advanced logic of the game itself.

#### Input-Output

Source files: `GameIO.h`, `GameIO.cpp`

This class is concerned with any input output processes of the program.

##### Hall of Fame

Source files: `HoF.h`, `HoF.cpp`

This class is derived from the `GameIO` class. It is concerned the logic behind the Hall of Fame embedded in the game.

#### Player

Source files: `Player.h`, `Player.cpp`

This class is exclusively used for the `HoF` class.




## **How to Contribute to the Project**

If you notice a bug, or would like to improve upon the project features or UI, please fork the repository, make your changes and ensure they work, than create a pull request with your changes to the main branch and a project creator will go in an approve or deny the request.

