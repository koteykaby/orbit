# Ubisoft Orbit DLL emulator

This project is an implementation of the Ubisoft Orbit DLL that is required in many old games, such as: 

- Assassin's Creed Brotherhood
- Assassin's Creed Revelations 
- Tom Clancy's Ghost Recon Future Soldier

And other Ubisoft titles released in year 2010-2012.

Note that in some cases you also need other uplay emulator, for example `uplay_r1_loader` is required in ACR.

## Usage

To run the game with emu, you need to replace original `ubiorbitapi_r2_loader.dll` with project one and paste `orbit.ini` from the `configurations` folder of the repo near it.

In the `orbit.ini` you need to change product ID to your game ID from uplay. After it you're able to run the game.

## Build

To build on Windows, you need [premake5](https://premake.github.io/download) and the latest [MSVC build tools](https://visualstudio.microsoft.com/downloads/?q=build+tools). Use the `build_windows.bat` script in the repository to generate build scripts and build the solution automatically.
