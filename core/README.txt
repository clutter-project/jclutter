JClutter Core
=============

This is the preview distribution of JClutter, the java binding for the Clutter toolkit project.

INTRODUCTION
============

The clutter project (http://www.clutter-project.org/) is a scene graph engine for mobile devices based on opengl and written in C using the glib, pango and cairo libraries.
Several bindings already exist such as python, c++, c#, vala and ruby.
JClutter is an effort to expose this framework to Java (SE 1.5+).


DIFFERENCES BETWEEN JCLUTTER AND CLUTTER
========================================

What is not really bound
------------------------

- The scripting api (org.jclutter.script) is written in java to preserve synchronization between gobjects and java GObjects.
- The key binding is also entirely written in Java to avoid more native to java callbacks.

What is missing in jclutter
---------------------------

- Animations only use predefined modes (see org.jclutter.anomation.Mode), not custom functions.
- Model api is not there. Widgets are too primitive at the moment and dont use anything from this api.

Other details:

- setColor and getColor are added in Actor. setColor returns false if it s not supported.





