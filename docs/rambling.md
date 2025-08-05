# Rambling

Just a document where ideas are written down before implementation.

## 07/23/2025

### How should the GUI system be implemented?

Before doing any research, the goto idea is to use an ECS (Entity Component System).

Reasons why:
1. seperate the drawing logic from functionality
2. a lot of widgets are going to be using the same systems (signals?, graphics, actions)
3. ECS has great performance for lots of entities (widgets)

### Things I like about other software that I want to Implement

#### Godot

1. control nodes can position relative to the screen based on percentages
2. global color/style pallet
3. signals for widget callbacks
4. HBox / Vbox

#### Hyprland

1. css like config file to control styles


## 08/04/2025
I think I have a pretty good idea on how to do a basic button now.
First I need to fix the shader class
  1. save the shaderProgramID and create getter for it.
  2. cleanup duplicate code

Now that I have a decent understanding of VBOs and VBAs, I feel I can draw a simple button. Hopefully that commit will come soon
