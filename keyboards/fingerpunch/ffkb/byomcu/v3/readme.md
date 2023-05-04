# ffkb

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Faux fox keyboard (ffkb)

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/ffkb_byomcu:default RGBLIGHT_ENABLE=yes FP_EC11=yes CIRQUE_ENABLE=yes
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

Options are:
```
    CIRQUE_ENABLE=yes
    FP_TRACKBALL_ENABLE=yes
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=yes
    FP_EC11=yes
    FP_EVQ=yes
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
