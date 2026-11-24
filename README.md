# TobiDash Tools

Experimental Geode mod source for Geometry Dash on **Android32 / GD 2.2091**.

## Current implementation

Controls are exposed through Geode's touch-friendly in-game mod settings:

- **Speed hack** (off by default) with a 0.5x–2.0x multiplier (default 1.0x). It changes the global Cocos scheduler, so other scheduled game animations may also be affected. The scheduler is reset to 1x when leaving a level.
- **Noclip** (off by default). It skips player-object collision handling while enabled. This also skips interactions with pads, orbs and portals; turn it off for normal gameplay. Selective collision bypass that preserves gameplay objects has not been implemented or verified.
- **Unlock icons (visual)** (off by default). It makes local icon-unlock checks return true; it does not grant or sync online progress.

## Compatibility and testing

`mod.json` targets Android Geometry Dash **2.2091**, matching the user's confirmed installed version and the version in the official Geode v6.0.0 Android32 bindings. The `.github/workflows/android32.yml` workflow builds with the official `geode-sdk/build-geode-mod` action. Check the repository's Actions tab for the current build result and artifact.

A successful CI build only confirms compilation and packaging; it is **not** an install or runtime test. The mod has not been tested on a physical device. Treat the features as experimental and keep the toggles off if they cause problems.

## Credits / licensing

Built against the Geode SDK and its official build action. No OpenHack/EclipseMenu source was copied. The repository currently has no license grant; ask the owner before reusing its code.
