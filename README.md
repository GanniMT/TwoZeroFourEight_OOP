# TwoZeroFourEight - OOP

## Introduction

Object Oriented rendition of the popular sliding tile puzzle video game, 2048 in C++

<img src="/gitImages/gameplay.gif" alt="Gameplay">



## Classes
### GUI

Source files: `GUI.h`, `GUI.cpp`

This class is concerned with the general graphical user interface of the whole program.

#### Game GUI

Source files: `GameGUI.h`, `GameGUI.cpp`

This class is derived from the GUI class. It is concerned with the graphical user interface of the game of the program.

#### Main Menu

Source files: `MainMenu.h`, `MainMenu.cpp`

This class is derived from the GUI class. It is concerned with the Main Menu of the program.

### Base

Source files: `TwoZeroFourEight.h`, `TwoZeroFourEight.cpp`

This class is concerned with the base logic of the game itself.

#### Logic

Source files: `Logic.h`, `Logic.cpp`

This class is derived from the `TwoZeroFourEight` class. It is concerned with more rather advanced logic of the game itself.

### Input-Output

Source files: `GameIO.h`, `GameIO.cpp`

This class is concerned with any input output processes of the program.

#### Hall of Fame

Source files: `HoF.h`, `HoF.cpp`

This class is derived from the `GameIO` class. It is concerned the logic behind the Hall of Fame embedded in the game.

### Player

Source files: `Player.h`, `Player.cpp`

This class is exclusively used for the `HoF` class.
