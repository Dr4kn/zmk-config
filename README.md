# zmk-config

## Keyboard

A custom keymap for the [corne](https://github.com/foostan/crkbd) keyboard.
The corne is a split staggered keyboard. I dowloaded all the files and ordered all the parts, PCB and acrylic which I soldered and lasercut. It is hot swap and you can therefore use and change every MX style switch into it. The battery life on the left half is around a week and the right (slave) one 3 months or so. It runs on a small 110mAh battery that is placed under the microcontrollers. The keycap set is GMK Dots.

<br/>

## Software

It is running [ZMK](https://zmk.dev/) which is an open source firmware for wireless keyboards. This config defines the keymap for this software only and is building it with github actions as described in the docs.

<br/>

![corne_keyboard](doc/assets/corne.jpg)

## How can you type on that

doesn't it have to little keys? Yesn't
You use layers which work like the FN on your laptop. You hold it and while / after doing that some or all keys get different functions. On a laptop it only changes a few keys maybe let you change your brightness etc.

Here you can use any key for that. You can have a navigation layer with arrow keys. change one halve to a numpad or whatever you can think of. The main benefit of using layers is that you don't have to move your fingers that much from the home row, which makes you type faster something like symbols and numbers and is more ergonomical. You can game on it but depending on what you play you might want fast access to the number and / or function row which this can't give you. For programming and overall writing it is great, because all your brackets can be on the home row and easily accessed. Some often used, but complex shortcuts can just be hard coded in and executed with one button press.
