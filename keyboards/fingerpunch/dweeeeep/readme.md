# dweeeeep

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

# Descripiton

This was created after both of the other variations. It was created as an alternative to the sweeeeep. It's a sweeeeep with diodes. I know the principle of the original sweep was to have no diodes. I apologize, this was a special request to allow people to use a pro micro compatible controller, as they're much cheaper.

# Firmware

To build the firmware for this keyboard (after setting up your build environment):
```
    make fingerpunch/dweeeeep:default
    # or
    qmk compile --clean --keyboard fingerpunch/dweeeeep --keymap default
```

Example of flashing this keyboard:

```
    make fingerpunch/dweeeeep/no-features:default:flash
    qmk flash --clean --keyboard fingerpunch/dweeeeep --keymap default
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
