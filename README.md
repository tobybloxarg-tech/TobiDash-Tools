# TobiDash Tools

Experimental Geode mod source for Geometry Dash **2.2091 on Android32**.

## Features

Settings are available in Geode's in-game mod settings:

- **Speed hack** (off by default): sets the global Cocos scheduler scale to the configured 0.5x–2.0x multiplier during play. This affects other scheduled game animations too; it is reset to 1x when leaving a level.
- **Noclip** (off by default): skips `PlayerObject` collision handling for ordinary, internal, rotated-object, and slope collision paths while enabled. This is a broad collision bypass: pads, orbs, portals, and other object interactions may not trigger. It does not grant progress or guarantee immunity to deaths caused by non-collision/scripted or out-of-bounds logic. Disable it for normal gameplay.
- **Unlock icons & colors (visual)** (off by default): locally makes `GameManager` icon-unlock and color-unlock checks succeed, so locked icon/color choices can appear selectable in the client. This only changes local checks; it does not unlock, save, or sync account progress and does not bypass server-side restrictions.

## Compatibility and testing

`mod.json` targets Android Geometry Dash **2.2091** and Geode **v6.0.0**. The Android32 GitHub Actions workflow builds/packages the mod. A successful CI run confirms compilation and packaging only, **not** installation or runtime behavior. This project has not been tested on a physical phone; treat the features as experimental and leave the toggles off if they cause problems.

## Credits / licensing

See the repository's license and Geode SDK documentation for build/runtime details.
