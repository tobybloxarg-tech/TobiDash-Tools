# TobiDash Tools

Experimental Geode mod source for Geometry Dash on Android32. Target metadata is **GD 2.209** (not 2.2091).

## Current implementation

Controls are exposed through Geode's touch-friendly in-game mod settings:

- Speed hack toggle (off by default) and 0.5x–2.0x multiplier (default 1.0x).
- Noclip toggle (off by default). It skips player-object collisions, including pads/orbs/portals, while enabled.
- Visual icon-unlock toggle (off by default). It changes local unlock checks only; it does not write or sync online progress.

Speed uses the global Cocos scheduler, so animations can be affected too. The game scheduler is restored to 1x when leaving a level.

## Compatibility / build status — important

This is source code, **not a tested/installable release**. The official `geode-sdk/build-geode-mod` Android32 workflow was attempted. Current Geode SDK v6.0.0 installs bindings for GD **2.2091**, and the build explicitly rejects this project metadata (`android: 2.209`) with: “Mod … is made for Geometry Dash version 2.209 but this version of Geode is for GD version 2.2091.” There is no 2.209 bindings set available in the current official bindings repository, so the C++ compile did not begin and no `.geode` artifact was produced. The workflow was deliberately not changed to 2.2091 because that target has not been verified against Tobi's requested game version.

Do not install the source/build against GD 2.2091 or assume it works on GD 2.209 until a matching official Geode SDK/bindings build becomes available and the mod is compiled and tested. Phone testing has not been done.

## Build

The workflow in `.github/workflows/android32.yml` uses the official Geode build action for Android32. It will become buildable once the official SDK offers bindings matching the declared GD 2.209 target.

## Credits / licensing

Built against the Geode SDK and its official build action. No OpenHack/EclipseMenu source was copied. The repository currently has no license grant; ask the owner before reusing its code.
