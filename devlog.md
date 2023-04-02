# The Development Log for the 2D City Simulator Game
> Note that this will serve as the basis for my 2D city building game

## Notes on the Future Game
The idea is to develop a 2D city building game.
The game will be isometric, with a person building on a randomly generated world,
or have the choice to build their own world by placing randomly generated tiles on a board.

The basis of the game is that:
- You start with 10 citizens in your world
- You build up your world, manage trade routes etc.

There are multiple modes for the game, the 2 i want to support right now are:
- Randomly generated tile based world of X x Y size
  - In this system players will have a pregenerated world to build on.
- Single starting tile on the centre of the board, with a deck of "Tiles" they can place alongside the starting tile
such that they can build up their own world before building a city on top of it.
  - The idea here is that the player can generate their own world from the "tile deck" availabe to them before building
   their city on top of it.
  - This will be the default game mode to play on, and will probably be more fun.

Such a system encourages developing new and unique worlds everytime you play, encourages further replayability and allows
the user more freedom when building their cities.

Also allows for more strategy and planning to occur with regards to how players build their worlds up.


## Rendering

For this iteration it seems prudent to use SDL to just visualize whats happening on the board and making sure that
the world is being generated correctly, otherwise it would be extremely annoying to use terminal commands to check
if everything is working correctly. So an SDL visualization would work well but would definetly not be used in the 
end product.

