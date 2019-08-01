Simulation
==========

The Simulation abstract class is essential part of Leconte's GUI. It enables a cleaner, more effective codebase that does not repeat the same thing over multiple files. Right now, it consists of six functions and one variable. 

## Grabbing Windows

Seguing to the children of Simulation, there is something that each of them do that is essential but also is their weakest property. 

Each of the simulations (Fluid, Smoke, and NeuralPaint) are external binaries, each with the ability to run individually. This is because each of them is unique in their own way. Fluid and Smoke are both heavily modified demos from NVIDIA, written in GLEW and OpenGL. NeuralPaint is a web application that interacts with a Python Flask server. (The neural net model it uses was designed specifically for that only.) 

Leconte runs each of the binaries, using the `system()` command, and captures their Window ID, which it then uses to embed the window into the simulation widget. 

Unfortunately, this is the only way to use all of these applications and still have a pleasant user experience with the UI. 

## Future

I would like to expand the Simulation class to include even more common elements that its children share, like the graphs and the different widgets they all have.

I would also like to remove the window capture from the app entirely, instead having Leconte hook directly into their source and run them in Qt. 