# Program called 'Volume Calculator'
#  A program that computes the volume of different shapes inputted.

print("")
print("Hello, welcome to my program 'Volume Calculator' for assignmnet #2 in CS1026.")
print("")
print("")

# Allows the use of pi.
import math

# -----------------------------------------------------Input Ordering Section-------------------------------------------------- :

# Variable setup - Setting up the initial empty arrays, original false values, and empty shape option.
Cube = []
Pyramid = []
Ellipsoid = []
UseCheck = "f"
ShapeType = "Empty"
# While the ShapeType value (originally "Empty") does not equal any of the correct shape options it will run this while loop.
while (ShapeType != "cube") and (ShapeType != "pyramid") and (ShapeType != "ellipsoid")and (ShapeType != "quit"):
    # While the ShapeType is not equal to quit it will run this loop. This is in order to allow number imput for shapes.
    while ShapeType != "quit":
        print("")
        print("What shape are you interested in finding the volume of?")
        ShapeType = str(input("Your options are (Cube), (Pyramid), (ellipsoid) or type 'quit':  ")).lower()
        print("")
        # Quitting the program without having used it gives a specific end message.
        if (ShapeType == "quit") and (UseCheck == "f"):
            print("You have come to the end of the session.")
            print("You did not perform any volume calculations.")
        # Error Check - If none of the shapes were put as an answer you must repeat till correct.
        if (ShapeType != "cube") and (ShapeType != "pyramid") and (ShapeType != "ellipsoid")and (ShapeType != "quit"):
            print("I'm sorry that was not a valid option, please try again.")
        if ShapeType == "cube":
            CubeLength = int(input("Please give the length of a side for the cube: "))
            CubeVolume = float(round(CubeLength**3, 1))
            # Adds the value to the cube array and then sorts it. Using float so that the decimal isn't removed.
            Cube.append(CubeVolume)
            Cube.sort(key=float)
            UseCheck = "t"
            print("The volume of the cube is: ",CubeVolume)
        elif ShapeType == "pyramid":
            PyramidBase = int(input("Please give the base length of a side for the pyramid: "))
            PyramidHeight = int(input("Please give the height of a side for the pyramid: "))
            PyramidVolume = round(PyramidHeight*(PyramidBase**2)*(1/3), 1)
            # Adds the value to the pyramid array and then sorts it. Using float so that the decimal isn't removed.
            Pyramid.append(PyramidVolume)
            Pyramid.sort(key=float)
            UseCheck = "t"
            print("The volume of the pyramid is: .",PyramidVolume)
        elif ShapeType == "ellipsoid":
            EllipsoidRadius1 = int(input("Please give the 1st radius: "))
            EllipsoidRadius2 = int(input("Please give the 2nd radius: "))
            EllipsoidRadius3 = int(input("Please give the 3d radius: "))
            EllipsoidVolume = round((4/3)*(EllipsoidRadius1*EllipsoidRadius2*EllipsoidRadius3)*math.pi, 1)
            # Adds the value to the ellipsoid array and then sorts it. Using float so that the decimal isn't removed.
            Ellipsoid.append(EllipsoidVolume)
            Ellipsoid.sort(key=float)
            UseCheck = "t"
            print("The volume of the ellipsoid is: ",EllipsoidVolume)
        # Quitting the program after having obtained at least one volume calculation brings you this end screen message.
        elif (ShapeType == "quit") and (UseCheck == "t"):
            print("You have come to the end of the session.")
            print("The volumes calculated for each shape are shown below:")
            if sum(Cube) == 0:
                print("Cube:          No computations for this shape.")
            else:
                print("Cube:        ", Cube)
            if sum(Pyramid) == 0:
                print("Pyramid:       No computations for this shape.")
            else:
                print("Pyramid:     ", Pyramid)
            if sum(Ellipsoid) == 0:
                print("Ellipsoid:     No computations for this shape.")
            else:
                print("Ellipsoid:   ", Ellipsoid)

