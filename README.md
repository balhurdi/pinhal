# Pinhal 

Pinhal is very minimalistic Alpine based distro I am building for myself. The goal is to have something that is tailored to my workflow, thought, if anyone comes across this and likes it, then, please feel free to use it

## Current state

The project is still very early in development, the only feature being worked on at the moment is a custom TUI installer. There are some things I plan to add in the future, but first I want to see how this code base evolves.

## Principles to follow

- The project must be able to generate a valid ISO file with minimal external dependencies from code only, no using other ISO's as a base for the generated one.

- Build times must be optimized and kept to a minimum. This is obviously quite a hard task since the processes such as squashing the filesystem take a significant amount of time and there is not much to be done, however, through the usage of tools such as docker containers, some steps may be cached to help save time

## Todo list

[ ] Custom TUI installer  