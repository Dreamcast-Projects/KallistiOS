# Tetris-RayLib4DC
A simple recreation of Tetris using raylib and kallistios that runs on the sega dreamcast.

![tetrisDC](https://github.com/user-attachments/assets/b2e70248-a426-476f-a259-4701653918df)

Anyone is free to do whatever they want with the code in this project as long as it respects the licenses of the assets you use.

## Purpose of this Repository
This is a simple recreation of tetris created using raylib following [this tutorial](https://www.youtube.com/watch?v=wVYKG_ch4yM) by youtuber "[Programming With Nick](https://www.youtube.com/@programmingwithnick)". I wanted to create a game for the sega dreamcast and get it running on actual hardware, but don't actually have any real experience with dreamcast homebrew development or C/C++ development, so this repository is going to show my whole learning process.

I have decided to continue past the tutorial in order to further develop my skills and make a nicer tetris experience. If you are here _just_ to see what the tutorial looks like on kallistios, [please check the branch titled "TutorialCompletion"](https://github.com/Niisoks/Tetris-RayLib4DC/tree/TutorialCompletion).

## Ball example
At the start of the tutorial, Nick [shows off a template repository](https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2/tree/main). I ported this over first and it might be a good place to get started with Raylib development on the dreamcast. 

This template Ball Example is stored in the [BallTemplate branch](https://github.com/Niisoks/Tetris-RayLib4DC/tree/BallTemplate) in this repository

![lxdreamball](https://github.com/user-attachments/assets/db12df31-a8cc-416d-8ef8-4d4bad9c2823)

## Learning goals in this repository
- [x] Understand and use C/C++
- [x] Get a grasp of RayLib4DC
- [x] General use of WSL
- [ ] Make a responsive dreamcast game
- [x] Get to grips with KallistiOS' apis
    - [ ] Efficiently use the debugger
    - [x] Understand the controller api (shouldn't be too hard tho)
- [ ] Become a better more organised developer
- [x] Get a running self-booting cdi

## Tools and references used
- [KallistiOS (KOS)](https://github.com/KallistiOS/KallistiOS)
    - [Simulant Discord Server](https://discord.gg/NtBGReCtBT)
- [raylib4Dreamcast](https://github.com/raylib4Consoles/raylib4Dreamcast)
    - [raylib](https://github.com/raysan5/raylib)
    - [raylib examples](https://www.raylib.com/examples.html)
- [Dreamcast Wiki](https://dreamcast.wiki/Dreamcast.wiki)
- [Creating Tetris in C++ with raylib - Beginner Tutorial (OOP)](https://www.youtube.com/watch?v=wVYKG_ch4yM)

## Assets Used
### Music
- [Too hot to sleep](https://pixabay.com/music/video-games-too-hot-to-sleep-soundtrack-electronic-puzzle-game-computer-141571/) by [melodyayresgriffiths](https://pixabay.com/users/melodyayresgriffiths-27269767/)

### Sound effects
- [Sound effects from the tutorial](https://www.youtube.com/watch?v=wVYKG_ch4yM)

## Thanks and credits
- Everyone who made and maintain kos
- Everyone who helped port raylib to kos
- Raysan5 for making raylib
- Falco Girgis for pointing me to the right people when i needed help
- Ian Michael for explaining what/why i should use certain audio
- BBHoodsta for showing me where the audio examples are
- Programming with nick for making a nice and easy to follow tutorials
- Everyone else who helped me who i forgot about
