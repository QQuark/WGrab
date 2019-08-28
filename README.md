
## What is WGrab ?

A temporary per-window X11 mouse jail. 
1. Start WGrab and it will change the current cursor to an X-shaped cursor, 
2. Click on the window you want the mouse pointer constrained in
3. Use the target software
4. When you are done, kill WGrab and your mouse pointer is free again.

This is a better implementation than the "poll the position and move back the cursor inside the window manually"-implementation: you won't see the cursor jumping with WGrab.

[![Actions Status](https://github.com/QQuark/WGrab/workflows/C/C++%20CI/badge.svg)](https://github.com/QQuark/WGrab/actions)

## How is this useful ?

This is particularly useful when using a single-screen GUI on a multiple screen setup and the target program does not originally implement a X11-compatible pointer grabbing feature. 
A simple practical example would be running a game that uses the edges of the screen to scroll its view (e.g. RTS game). 
Depending on the program, wine sometimes won't grab the pointer, but you can now force this behavior with this program.
	
## How to use it ?

- make to build.
- copy WGrab.sh and WGrab to a directory in your PATH.
- Bind WGrab.sh to a keyboard shortcut (e.g. in you window manager configuration).
- Press your keyboard binding once, click on the target window: the mouse now can't exit the window.
- Press again, WGrab is killed: the mouse can now move freely.

## Known bugs

- When the target program dies while WGrab is running, the mouse will be freed, however, WGrab will not be killed, you still have to press the keyboard binding
- Theoretically, WGrab should bind itself to the correct keyboard shortcut and not have to be killed to stop or redefine the window being pointer-grabbed, but this is IMO too much work for too little gain.

## Authors

- clientwin/dsimple code is copied from the xprop code (allows window targetting)
- WGrab implementation PsiZzZ <psizzz+wgrab@gmail.com>

	
