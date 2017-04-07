# Vizwl

Vizwl is a simple Qt app which accepts commands in a text protocol and draws them in a window.
It solves the problem that in most languages it is really difficult to just draw something on the screen.

Currently Vizwl accepts commands over unix domain sockets but I hope to add a simple command line wrapper
that allows you to just pipe the output of your program to vizwl to draw it.

## Example commands

These may not all be implemented yet, but this is the plan:

```
line 0 10 100 4 red
rect 0 0 100 100 blue
circle 100 100 5
frame
text 40 20 "Hello World"
```
