/*
Copyright 2011 PsiZzZ

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include "dsimple.h"

void usage(void) {}

int main(int argc, char *argv[])
{
	/* Handle display name, opening the display */
	Setup_Display_And_Screen(&argc, argv);

	Window win = 0;

	/* Handle selecting the window to display properties for */
	win = Select_Window_Args(&argc, argv);

	printf("Display ptr: %p\n", dpy);
	if (win == None)
		win = Select_Window(dpy, 0);

	printf("%p\n", (void *)win);

	unsigned event_mask = 
		ButtonPressMask
		|ButtonReleaseMask
		|EnterWindowMask
		|LeaveWindowMask
		|PointerMotionMask
		|Button1MotionMask
		|Button2MotionMask
		|Button3MotionMask
		|Button4MotionMask
		|Button5MotionMask
		|ButtonMotionMask
		|VisibilityChangeMask
		|StructureNotifyMask
		|ResizeRedirectMask
		|SubstructureNotifyMask
		|SubstructureRedirectMask
		|FocusChangeMask
		|PropertyChangeMask
		|ColormapChangeMask
		|OwnerGrabButtonMask
		;

	int RRR = 0;
	if (win)
	{
		RRR = XGrabPointer(dpy, win, True, event_mask, GrabModeAsync, GrabModeAsync, win, None, CurrentTime);
	}
	printf("%d\n", RRR);

	XEvent event;

	while (1)
	{
		while ( !XNextEvent(dpy, &event) )
		{
			if (XSendEvent(dpy, win, True, event_mask, &event) == BadWindow)
			{
				return 0;
			}
		}
	}

	return 0;
}

