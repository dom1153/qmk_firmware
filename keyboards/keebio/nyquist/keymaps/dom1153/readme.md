# Setup QMK home if needed

`qmk setup -H <qmk_home>`

# Compile QMK firmware

`qmk compile -kb keebio/nyquist/rev3 -km dom1153 --compiledb`

`--compiledb` should let clang do most the work

Will generate `compile_commands.json` at root.

# More on vscode

```
CompileFlags:
  Add: [-Wno-unknown-attributes, -Wno-maybe-uninitialized, -Wno-unknown-warning-option]
  Remove: [-W*, -mcall-prologues, -m*, -f*]
  Compiler: clang
Diagnostics:
  UnusedIncludes: None
  Suppress: pp_hash_error
```

`UnusedIncludes` should suppress some warnings as well as `-m*` and

# Notes

-   Vial does **not** work due to lack of EEPROM / memory issues (AVR chip)

-   'Backlights' are controlled from `RGBLIGHT_ENABLE`, not `BACKLIGHT_ENABLE`

-   Reset qmk key works, OR reset switch between the main usb c port

-   Flashing both sides if in doubt. No need to config/define left/right sides.

-   If using a nix environment, run all shell commands (including editor) with `nix-shell`

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

## Clangd suppression

[Docs](https://clangd.llvm.org/config.html#suppress)
