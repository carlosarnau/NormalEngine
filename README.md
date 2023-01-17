<p align="center">
  <img width="480" height="140" src="https://github.com/carlosarnau/NormalEngine/blob/develop/docs/normalengine-logo.jpg"> <br />

<br>


# Normal Engine
Normal Engine is a free to use Game Engine made in c++ with the basic tools to create a game. Made by students from CITM Barcelona for the Game Engines subject. <br />
To access to the webpage of the engine, click the following link: [Webpage](https://carlosarnau.github.io/NormalEngine/)

<img src="https://github.com/carlosarnau/NormalEngine/blob/807aff33e11c39a86fd219652b100eb42b777834/docs/1.jpg"> <br />

<br>


## Usage Guide
The engine consists of a menu bar, located in the upper part of the screen, where you can save and load your scene or even import files that you may need. In the middle of the screen we can find the viewport area where you are able to deploy objects and navigate through them making use of the different modules of the engine, which are 8 in total:
- Configuration --> Manage the engine general configuration.

<img width="210" height="702" src="https://github.com/carlosarnau/NormalEngine/blob/65c44c9a1c9792ce431bf42b0b7bfed090c56f79/docs/7.jpg"> <br />



- Hierarchy --> Visualize the objects displayed into the scene and navigate through them.

<img width="210" height="702" src="https://github.com/carlosarnau/NormalEngine/blob/65c44c9a1c9792ce431bf42b0b7bfed090c56f79/docs/6.jpg"> <br />



- Action Controls --> Start, Pause and Stop the action of the engine.

<img width="840" height="58" src="https://github.com/carlosarnau/NormalEngine/blob/1dcfa6f982d0bd86dc4550c9bc8fc62f7a81083f/docs/11.jpg"> <br />



- Scene Screen --> Display, modify and manage all the 3D assets that will appear in the game.

<img width="840" height="448" src="https://github.com/carlosarnau/NormalEngine/blob/1dcfa6f982d0bd86dc4550c9bc8fc62f7a81083f/docs/3.jpg"> <br />



- Game Screen --> Previsualize how the scene would look inside the game while running.

<img width="840" height="448" src="https://github.com/carlosarnau/NormalEngine/blob/1dcfa6f982d0bd86dc4550c9bc8fc62f7a81083f/docs/4.jpg"> <br />



- Camera Controls --> Rotate and move the camera in Game mode.

<img width="232" height="144" src="https://github.com/carlosarnau/NormalEngine/blob/807aff33e11c39a86fd219652b100eb42b777834/docs/9.jpg"> <br />



- Assets --> Navigate and diplay the different asstes stored in your computer. As we had problems showing the folder and file icons we used colors to identify different archieve formats. Red for the FBX files and purple for the folders.

<img width="840" height="254" src="https://github.com/carlosarnau/NormalEngine/blob/807aff33e11c39a86fd219652b100eb42b777834/docs/2.jpg"> <br />



- Console --> Follow the executions that happen in your engine. (Not working propertly!)

<img width="840" height="254" src="https://github.com/carlosarnau/NormalEngine/blob/1dcfa6f982d0bd86dc4550c9bc8fc62f7a81083f/docs/10.jpg"> <br />



- Inspector --> Change your objects properties and else.

<img width="232" height="558" src="https://github.com/carlosarnau/NormalEngine/blob/807aff33e11c39a86fd219652b100eb42b777834/docs/10.jpg"> <br />



- UI Editor --> Create and Edit the GUI for your game. (Not working propertly!)

<img width="232" height="558" src="https://github.com/carlosarnau/NormalEngine/blob/1dcfa6f982d0bd86dc4550c9bc8fc62f7a81083f/docs/12.jpg"> <br />


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
ISSUE #2: At implementing the assets folder both folders icons visulization and drag and drop didn't work at all. <br />
ISSUE #3: AABB geometry is not displaying and working correclty. <br />
ISSUE #4: Drag and drop crashes at displaying FBX files, to aboid that we deactivate it. <br />
ISSUE #5: Save and Load with custom file format is not working correctly, and either accept fbx files. <br />
ISSUE #6: When creating a method to create GUI elements inside the engine we take into account different options but we finally ended up with printing them with OpenGL, given that we had a lot of problems beacuse we couldn't make a system to manage them, insted we printed them ath the beginning. <br />
ISSUE #7: Related with the way of printing 2D assets inside a 3D environment we dealed that while using an orthogonal camera the different GUI elements didn't show. In half the path of the assignment we realised that printing things in OpenGL was to complicated so we forked Wiwa Engine (our coleages engine) to try to implement them using assets and methods created last year.<br />
ISSUE #8: Continuing with the last issue in the new engine we realised that was to difficult given that we used methods that were none similiar with Wiwa Engine so we returned back to NormalEngine to try to make something work.<br />

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
