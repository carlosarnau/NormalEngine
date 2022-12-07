<p align="center">
  <img width="480" height="140" src="https://github.com/carlosarnau/NormalEngine/blob/develop/docs/normalengine-logo.jpg"> <br />

<br>


# Normal Engine
Normal Engine is a free to use Game Engine made in c++ with the basic tools to create a game. Made by students from CITM Barcelona for the Game Engines subject. <br />
To access to the webpage of the engine, click the following link: [Webpage](https://fakefarreraspol.github.io/NormalEngine/)

<br>


## Usage Guide
The engine consists of a menu bar, located in the upper part of the screen, where you can save and load your scene or even import files that you may need. In the middle of the screen we can find the viewport area where you are able to deploy objects and navigate through them making use of the different modules of the engine, which are 8 in total:
- Configuration --> Manage the engine general configuration.
- Hierarchy --> Visualize the objects displayed into the scene and navigate thorugh them.
- Action Controls --> Start, Pause and Stop the action of the engine.
- Assets --> Navigate and siplay the different asstes stored in your computer.
- Console --> Follow the executions that happen in your engine.
- Inspector --> Change your objects properties and else.

<br>

Also in the menu bar, to improve the communication in case of bugs and crashes we implemented a menu item called help with the possiblity of:
- About --> A window will pop up with all the important information about the engine.
- Go to GitHub --> The GitHub page of the engine will open in your browser.
- Donwload latest --> In case you don't have the latest version of the engine, it will bring you to the releases page of the engine.
- Documentation --> The GitHub page of the egnine will open in your browser in case you need deeper information about the engine.
- Report a Bug --> In case you find a bug the GitHub issue page of the engine will open in your browser so you can label it. 

<br>


## Controls
~~~~~~~~~~~~~~~

Menu Actions:
- SAVE --> Ctrl + S
- SAVE FILE --> Ctrl + S
- OPEN FILE --> Ctrl + Shift + S
- IMPORT --> Ctrl + I
- SHOW/HIDE WINDOWS --> Ctrl + H
- DELETE SCENE --> Ctrl + D
- EXIT --> Esc

Mouse Controls:
- LEFT CLICK --> Selection
- RIGHT CLICK --> Rotate camera

Camera Controls:
- MOVEMENT --> Right Click + WASD and Right Click + R/V (Up/Down)
- MOVEMENT SPEED x2 --> Shift
- ZOOM --> Mouse Wheel
- FOCUS ON OBJECT --> Right Click + F

~~~~~~~~~~~~~~~

<br>


## Developers
- Carlos Javier Arnau Montoriol [carlosarnau](https://github.com/carlosarnau) <br />
- Pol Farreras Olivera [fakefarreraspol](https://github.com/fakefarreraspol) <br />

<br>

## Additional Functionalities
No additional funcionalities yet.

<br>


## Additional Comments
### Issues solved: <br>
ISSUE #1: When working with objects in the viewport the engine crashed every time at exit, fortunatelly the error was in an overflow over an array, so we were able to fix it.

### Issues not solved: <br>
ISSUE #2: At implementing the assets folder both folders icons visulization and drag and drop didn't work at all.
ISSUE #3: AABB geometry is not displaying and working correclty.
ISSUE #4: Drag and drop crashes at displaying FBX files, to aboid that we deactivate it.
ISSUE #5: Save and Load with custom file format is not working correctly, and either accept fbx files.

<br>


## License
MIT License <br /> <br />

Copyright (c) 2022 Pol  <br /> <br />

Permission is hereby granted, free of charge, to any person obtaining a copy <br />
of this software and associated documentation files (the "Software"), to deal <br />
in the Software without restriction, including without limitation the rights <br />
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell <br />
copies of the Software, and to permit persons to whom the Software is <br />
furnished to do so, subject to the following conditions: <br /> <br />

The above copyright notice and this permission notice shall be included in all <br />
copies or substantial portions of the Software. <br /> <br /> 

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR <br />
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, <br />
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE <br />
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER <br />
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, <br />
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE <br />
SOFTWARE. <br />
