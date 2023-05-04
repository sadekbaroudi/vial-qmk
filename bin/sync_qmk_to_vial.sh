#!/bin/bash

rsync -av --exclude '*vial*' ../qmk_firmware/keyboards/fingerpunch/ keyboards/fingerpunch/
rsync -av --exclude '*vial*' ../qmk_firmware/users/sadekbaroudi/ users/sadekbaroudi/
rsync -av --exclude '*vial*' ../qmk_firmware/bin/fp_build.sh bin/fp_build.sh

# keep this list updated as vial support is added for these boards
rm -rf keyboards/fingerpunch/arachnophobe/
rm -rf keyboards/fingerpunch/bgkeeb/
rm -rf keyboards/fingerpunch/bigbarobord/
rm -rf keyboards/fingerpunch/euclid36/
rm -rf keyboards/fingerpunch/euclid36proto/
rm -rf keyboards/fingerpunch/ffkb_byomcu/v3/kle-via.json
rm -rf keyboards/fingerpunch/fpm101/
rm -rf keyboards/fingerpunch/halfdash/
rm -rf keyboards/fingerpunch/handwired/
rm -rf keyboards/fingerpunch/luakeeb/
rm -rf keyboards/fingerpunch/osprette/
rm -rf keyboards/fingerpunch/stemcell_jumper_tester/
rm -rf keyboards/fingerpunch/stenogaraphobe/
rm -rf keyboards/fingerpunch/tenbit/
rm -rf keyboards/fingerpunch/ximi/
rm -rf keyboards/fingerpunch/personal/
