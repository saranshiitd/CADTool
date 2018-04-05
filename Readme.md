# CAD Module

This application can be used to
1. Generate Projections and Orthographic Views of 3D objects.
![Projections](/doc/projections.jpg?raw=true "Projections")
2. Reconstruct 3D objects from orthographic projections.
![3D_Object](/doc/3d.jpg?raw=true "3D Object")

### Installing

	The app folder contains an AppImage which can run on Linux systems. 
	Make the app executable by running 

	chmod a+x CAD.AppImage 

	in the app folder.

#### Build from sources ####
```
qmake CAD.pro
make
```



## Format of Input

1. To Get 3D object provide a *.txt* file containing the informaion about orthographic projections.
	#### Format of *.txt* file ####
		f 0 0      # a vertex (0, 0) in front projection
		f 0 1      # a vertex (0, 1) in front projection
		f ...
		...

		fe 1 2    # an edge in front projection between vertices (0, 0) and (0, 1)
		fe ...
		...

		t 0 1      # a vertex (0, 1) in top projection
		t 0 2      # a vertex (0, 2) in top projection
		t 1 2	   # a vertex (1, 2) in top projection
		...

		te 1 3    # an edge in side projection between vertices (0, 1) and (1, 2)
		te 2 3	  # an edge in side projection between vertices (0, 2) and (1, 2)
		...

		s 1 0      # a vertex (1, 0) in side projection
		s 1 1      # a vertex (1, 1) in side projection
		s ...
		...

		se 1 2    # an edge in side projection between vertices (1, 0) and (1, 1)
		se ...
		...

	The application takes such a *.txt* file and generates a *.obj* file.

2. To Generate Projections and Orthographic Views provide a *.obj* file of the 3D object.

	#### Format of *.obj* file ####
		v 1 2 3    # a vertex 'v' followed by (x, y, z) coordinates of the point
		v ...
		...

		f 1 3 4    # a face 'f' followed by indices of vertices lying on that plane
		f ...
		...

	The application takes such a *.obj* file and generates a *.txt* file.


## Authors

* **[Saransh Verma](http://github.com/saranshiitd)**
* **[Tarun Kumar Yadav](http://github.com/tarunyadav452)**

