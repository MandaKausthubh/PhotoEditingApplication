# Photo Editing Application:

## Team members and their contributions:

- Jinesh Pagaria (Implemented Logs Completely, C++ & Java: Sepia, Invert )
- Manda Kausthubh (C++ and Java: Rotation, GrayScale, Gaussian Blur and preparing documentation )
- Rohan Rajesh (Implemented Contrast Java & C++)
- Sourav Dileep M (Implemented Brightness Java & C++)
- Aryan Mishra (Implemented Flip Java & C++)

## Effects that have been implemented:

- Brightness
- Contrast
- Flip
- Rotate
- Invert
- Sepia
- Gray Scale

## Explanation about how to use the Effects:
How the effect works :

1. In the Backend the actual Backend which contains the functions that are used is Effect.cpp, located at ImageEffectBackend/src/Libraries/EffectLibrary. These functions are called using the Effect.h header file that is used in com_iiit_imageEffectApplication_libraryinterface_EffectInterface.cpp which has the `jni.h` header which is used to call these functions in the java files.

2. Now the directory: main/java/com/iiitb/imageEffectApplication contains sub-directories that define the usage of Java in this project. The important ones are baseEffects, effectImplementations, exception and service. In this, we have:
    - baseEffects: we define interfaces which are used to define/categorize the effects based on the kind of inputs that are required to implement these effects.
    - effectImplementations: Here we implement the interfaces that were created in the baseEffects directory.
    - exception: Here we define the set of exceptions like IllegalParameterException which are triggered during the execution of the program.
    - libraryInterfaces: here we use jni to call the above-defined C++ functions to implement the effects.
    - service: This contains the java file that is executed. We call the above-defined classes and assign parameters to them and execute the effect using methods defined in effectImplementations. We also trigger the exceptions when necessary.

3. These above-defined java interacts with the front-end written in Angular to implement the effects.
