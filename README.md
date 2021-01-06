# microcontroller_az

## Cloning this repository
This repo uses [Git Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) to bring in dependent components.

**Note:** If you download the ZIP file provided by the GitHub UI, you will not get the contents of the submodules. (The ZIP file is also not a valid git repository)

To clone using HTTPS:
```
git clone https://github.com/votuananhs/microcontroller_az.git --recurse-submodules
```
Using SSH:
```
git clone git@github.com:votuananhs/microcontroller_az.git --recurse-submodules
```

If you have downloaded the repo without using the `--recurse-submodules` argument, you need to run:
```
git submodule update --init --recursive
```

|
|- kit
--|- stm32f051r8
--|- stm32f103c8t6
--|- kl46z
|- demo
|- c_language
|- makefile
| -svd
