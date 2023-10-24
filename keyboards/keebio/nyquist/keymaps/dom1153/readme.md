# Setup QMK home if needed

`qmk setup -H <qmk_home>`

# Compile QMK firmware

`qmk compile -kb keebio/nyquist/rev3 -km dom1153`

## Setup VS Code

`qmk generate-compilation-database -kb keebio/nyquist/rev3 -km dom1153`

Will generate `compile_commands.json` at root.

# Notes

-   Vial does **not** work due to lack of EEPROM / memory issues (AVR chip)

-   'Backlights' are controlled from `RGBLIGHT_ENABLE`, not `BACKLIGHT_ENABLE`

-   Reset switch works, OR reset switch between the main usb c port

-   Flashing both sides if in doubt. No need to config/define left/right sides.

# Settings

```
Custom Keys:
    DFWIN - default layer to windows (persistant)
    DFMAC - default layer to mac (persistant)
```

# Resources

## Convert QMK config json into keymap.c

[QMK Json Converter](https://jhelvy.shinyapps.io/qmkjsonconverter/)

## Setting up VSCode for QMK

[Link to docs](../../../../../docs/other_vscode.md)

## QMK RGB Docs

https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md

## RGB custom code (rgb usb sleep and timeout)

[Link to docs](../../../../../docs/custom_quantum_functions.md)
