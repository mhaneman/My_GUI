# Rambling

Just a document where ideas are written down before implementation.

### 07/23/2025

#### How should the GUI system be implemented?

Before doing any research, the goto idea is to use an ECS (Entity Component System).

Reasons why:
1. seperate the drawing logic from functionality
2. a lot of widgets are going to be using the same systems (signals?, graphics, actions)
3. ECS has great performance for lots of entities (widgets)
