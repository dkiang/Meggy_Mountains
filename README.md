Meggy_Mountains
===============

Side scrolling mountains

This provides sample code that generates random mountains that scroll from right to left across the Meggy screen. You can incorporate this code into your own projects and add collision detection.

This works be creating an array of ints, each of which tells the Meggy how high to draw each column of dots.

There are two different UpdateMountains methods. One of them just generates random heights which leads to a very jagged landscape. Maybe a skyline?

The other one generates random heights that are no more than two dots higher or lower than the previous height. This leads to smoother, more "mountain-y" peaks. You can experiment with the SLOPE constant to change this.
