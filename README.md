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
First we need to set the camera, light and ambilight. Otherwise the scene will not be accepted.
### Ambilight
```
A	0.1                                             255,255,255
```
__A__ is the identifier.
>Capital letter identifiers can only be defined once. \
> If you try to set 2 Ambilights, it wont accept the scene.

__0.1__ is the intensety of the ambilight, which can be set in a range from 0 to 1. \
All values above 0 will keep nothing in the dark and setting it to 1 means no shadows at all. \
__255,255,255__ is the __Color__ of the ambilight in [RGB](https://en.wikipedia.org/wiki/RGB_color_model) values from 0 to 255.
### Camera
```
C	0,0,0		0,0,1		90
```
__C__ is the identifier.

__0,0,0__ is the positon of the camera as a vector of x,y,z. \
__0,0,1__ is the orientation vector of the camera. In other words, the directon you are looking at in the 3D space.
> All values for the orientation, have to be in the range of 0 to 1.

And the last number, represents the [FOV](https://en.wikipedia.org/wiki/Field_of_view) of the Camera in a range form 0 to 180.

### Light source
```
L	5,5,0		    	        0.7             255,255,255
```
__L__ is the identifier.
> This is the only Captial letter identifer, that can be declared multiple times.

__5,5,0__ gives the position of the lightsource as a vector of x,y,z. \
__0.7__ is the light intensety in a range from 0 to 1. \
__255,255,255__ is again the __Color__ of the light.

## Objects
Now a list of Objects you can add to your scene.
### Sphere
```
sp	0,0,20                          20              255,0,225
```
__sp__ is the identifier. 

First comes the position __0,0,20__, which is the centerpoint of the sphere. \
Second value __20__ is the diameter of the sphere, which can not be less then 0. \
Last is the __Color__ of the object. Same as for light and ambilight.
### Plane
```
pl	0,0,50		0,0,1				230,230,250
```
__pl__ is the identifier. 

The planes are infinite so the are descriped with a single point on the plan, here it is __0,0,50__, and the orientation from that point on __0,0,1__. \
So here its a plane standing upwards on the __z__ coordinate. \
And last again the __Color__ of the object.

### Cylinder
