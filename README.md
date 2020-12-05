## OpenCV C++ Stereo Camera Calibration

This repository contains some sources to calibrate the intrinsics of individual cameras and also the extrinsics of a stereo pair.

### Dependencies

- OpenCV
- popt

### Compilation

Compile all the files using the following commands.

```bash
mkdir build && cd build
cmake ..
make
```

Make sure your are in the `build` folder to run the executables.

### Get images from webcams

This is a small helper tool to grab frames from two webcams operating as a stereo pair. Run the following command to use it.

```bash
./read -w [img_width] -h [img_height] -d [imgs_directory] -e [file_extension]
```

Once it is running, hit any key to grab frames. Images are saved with prefixes `left` and `right` in the desired directory.

### Intrinsic calibration of a single camera

This is only for lenses which follow the pinhole model. If you have fisheye lenses with a very wide field of view then see [this](https://github.com/sourishg/fisheye_stereo_calibration) repository. The calibration saves the camera matrix and the distortion coefficients in a YAML file. The datatype for these matrices is `Mat`.

Once you have compiled the sources run the following command to calibrate the intrinsics.

```bash
./calibrate -w [board_width] -h [board_height] -n [num_imgs] -s [square_size] -d [imgs_directory] -i [imgs_filename] -o [file_extension] -e [output_filename]
```

For example, the command for the test images in `calib_imgs/1/` would be

```bash
./calibrate -w 9 -h 6 -n 27 -s 0.02423 -d "../calib_imgs/1/" -i "left" -o "cam_left.yml" -e "jpg"
```


