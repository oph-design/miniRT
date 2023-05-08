# miniRT
This project is about implementing a basic Raytracer for ecole 42 by students [luntiet-](https://github.com/LaurinUB) and [oheinzel](https://github.com/oph-design)
## How to use
1. You will have to download and install the [glfw](https://github.com/glfw/glfw) libary.
2. clone the repo and build miniRT
```bash
git clone https://github.com/oph-design/miniRT.git
cd miniRT
make
```
3. run the program with the given scenes for example:
```bash
./miniRT  scenes/default.rt
```
> You can also create your own .rt files.
## How to create your own scene
We will explain it on an example file from our scenes.
```
A	0.1                                             255,255,255
C	0,0,0		0,0,1		90
L	5,5,0		    	        0.7             255,255,255

sp	1,1,6			        2               255,0,0
sp	0,0,20                          20              255,0,225
pl	30,0,10		1,0,0.1				230,230,250
pl	-30,0,10	-1,0,0.1			230,230,250
pl	0,0,50		0,0,1				230,230,250
pl	0,-15,0		0,1,0				230,230,250
pl	0,20,0		0,1,0				230,230,250
```
First we need to set the Camera, Light and Ambilight. Otherwise the scene will not be accepted.
### Ambilight
```
A	0.1                                             255,255,255
```
__A__ is the identifier. Capital letter identifiers can only be defined once. 
> If you try to set 2 Ambilights, it wont accept the scene.

The __0.1__ is the intensety of the Ambilight, which can be set in a range from 0 to 1. \
And at the end is the __Color__ of the Ambilight in RGB values from 0 to 255.
### Camera
```
C	0,0,0		0,0,1		90
```
__C__ is the identifier.

The __0,0,0__ is the positon of the Camera as a Vector with x,y,z. \
The next __0,0,1__ is the orientation Vector of the Camera. In other words, the directon you are looking at in the 3D space.
> All values for the orientation, have to be in the range of 0 to 1.

And the last number, represents the [FOV](https://en.wikipedia.org/wiki/Field_of_view) of the Camera in a range form 0 to 180.

### Light source
```
L	5,5,0		    	        0.7             255,255,255
```
