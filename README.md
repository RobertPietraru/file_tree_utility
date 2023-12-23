# File tree utility
It just creates a file tree with the folder passed as parameter. It's not really that complex. It basically does the same thing as "tree"

! This is my first C project

## Usage
Just run the compiled code with a


```
./build/structer (No parameters means current directory)
```

```
./build/structer .
```

```
./build/structer path/to/your/thing
```

```
./build/structer ~/paths/work/too
```

```
./build/structer /absolute/paths/as/well
```

## Project file structure
Created using the program

### Without -a 
```
file_structure_maker
  ├─ Makefile
  ├─ README.md
  ├─ src/
  | └─ main.c
  ├─ build/
  | ├─ structer
  | ├─ bookthing
  | └─ main.o
  └─ include/
    └─ main.h
```
### With -a
```
file_structure_maker
  ├─ Makefile
  ├─ README.md
  ├─ .git/
  | ├─ branches/
  | ├─ description
  | ├─ info/
  | | └─ exclude
  | ├─ HEAD
  | ├─ hooks/
  | | ├─ commit-msg.sample
  | | ├─ fsmonitor-watchman.sample
  | | ├─ pre-commit.sample
  | | ├─ pre-rebase.sample
  | | ├─ update.sample
  | | ├─ post-update.sample
  | | ├─ pre-receive.sample
  | | ├─ pre-push.sample
  | | ├─ prepare-commit-msg.sample
  | | ├─ applypatch-msg.sample
  | | ├─ pre-merge-commit.sample
  | | └─ pre-applypatch.sample
  | ├─ logs/
  | | ├─ HEAD
  | | └─ refs/
  | |   ├─ heads/
  | |   | └─ master
  | |   └─ remotes/
  | |     └─ origin/
  | |       └─ master
  | ├─ config
  | ├─ ORIG_HEAD
  | ├─ refs/
  | | ├─ heads/
  | | | └─ master
  | | ├─ tags/
  | | └─ remotes/
  | |   └─ origin/
  | |     └─ master
  | ├─ index
  | ├─ COMMIT_EDITMSG
  | ├─ FETCH_HEAD
  | └─ objects/
  |   ├─ 6f/
  |   | └─ 1631402d93d94c12deea3b21ac169469ba68cb
  |   ├─ 68/
  |   | └─ a0cd996e1474d4157aec1aabae1e5717bf16b8
  |   ├─ 69/
  |   | └─ 0b2d9b1e0eb2470b3d4cfd8a02655e8d0e5c17
  |   ├─ info/
  |   ├─ d3/
  |   | └─ 7ccdabb309b2ee3835b180b9a4402726c1eb9a
  |   ├─ f0/
  |   | └─ 57ca7cedb2c2acb33057fe6f3dc033e5a500f7
  |   ├─ 89/
  |   | └─ 64e6a7c57a2d7c08073e4b341856342994c75c
  |   ├─ 01/
  |   | └─ 72b844078544305f66dfa96e32b39c333979c9
  |   ├─ 60/
  |   | └─ e3fbfd0cd6cf74ea9aa3fbde7b50b7c9a6f97c
  |   ├─ 6a/
  |   | └─ d8d3d32bb41186041cb93f4790405e99a45c9e
  |   ├─ e1/
  |   | └─ 0377fcc66c5baf32f32e774186a472a256d8aa
  |   ├─ fc/
  |   | └─ ec1f3bae615d5c8246af985cfffd8446ddcbe6
  |   ├─ a4/
  |   | └─ 1e6c76ea1e82a584b04276cdfa1efaf6d04353
  |   ├─ 45/
  |   | └─ 0b00a482b275e368af4bb9d052b6e4d084a038
  |   ├─ 14/
  |   | └─ 8960194c87fd5d6917653731626e732459db0a
  |   ├─ 10/
  |   | └─ b67c77ed9b39d848f796d22f873bc93cd4d0f5
  |   ├─ c6/
  |   | └─ 9d94b4df8ecf32b1b02310a90d2c80c565ba7c
  |   ├─ 8e/
  |   | └─ c8b063652a4e8a0876f9580fcdd44a7437ab2f
  |   ├─ 48/
  |   | └─ 274b5b7f44635b3407273f21461fceaf51cf53
  |   ├─ 38/
  |   | └─ 57e1d52b671c18700b3232ef7ad70b7d6832f0
  |   ├─ f1/
  |   | └─ 4963f26c9b76e8840da48fb2cbf79fb7e925b9
  |   ├─ bc/
  |   | └─ a5cc9c77bce73577778817c61564caadaedee1
  |   ├─ 42/
  |   | ├─ 81918245347c3e1ffee22d91381194aad67e38
  |   | └─ 7d6a9ab28ba1807fa98cf62e3071fa2668ab19
  |   ├─ 17/
  |   | └─ 8a303855cf84f5e1d5990b29950fcac6381bdb
  |   ├─ 22/
  |   | └─ 3fd0d0df2d639d423d525085f86988a4718b8b
  |   ├─ 54/
  |   | └─ d1a4f1693ff4fcfeccb623509be0e1ed10f620
  |   ├─ pack/
  |   ├─ 77/
  |   | └─ 1341892a6bd863fc74fa8b68dbdaa7a800230f
  |   ├─ 57/
  |   | └─ 633f52e53aac3f1c622a2ff4417b0ab50fe2b6
  |   ├─ b9/
  |   | ├─ bedcf5126c785c288842394604d9d7ed933b03
  |   | └─ 61982c74c07b5bace2a4183f030145417abb9e
  |   ├─ 59/
  |   | └─ dc1df4426c08d4d6a2f3bb94fdc4d2ae5ef3b7
  |   ├─ c7/
  |   | └─ bca09c20aebed4c2bad69269f73bcfc329a564
  |   ├─ 79/
  |   | └─ fbd906cc680fde83de15cbde2e638ca8e1e169
  |   ├─ bf/
  |   | └─ ab76d9ad8043fc659736081ace9968ee3944e8
  |   ├─ fa/
  |   | └─ df8d61cd98b829753af52452a1773cc8dc2681
  |   ├─ 8c/
  |   | └─ 4b1f767b8cde7a0006b2bbde225d9125918836
  |   ├─ 7e/
  |   | └─ 9e54d4fd803045241f8ed278949292d9538f6f
  |   ├─ d2/
  |   | ├─ 31ea1185cf21522c0ce310cb0ed4cc42dbdd4f
  |   | ├─ f7071e2d527cda61c31f29e8e846a6431d4d9b
  |   | └─ 0a836d94e1765173e7f478d49266cc10d76bd9
  |   ├─ 49/
  |   | └─ 2167f676fe92c9afef88b71abc51fc4104a723
  |   ├─ c4/
  |   | └─ 80472c52b2c99d6fa14280907b43117c2db6e9
  |   ├─ 28/
  |   | └─ 9d8091f039464e8aab25ec0974ca31f86e27ee
  |   ├─ cc/
  |   | └─ b051498026332240313ac43dc0dedc4cea1cd3
  |   ├─ fb/
  |   | └─ 1461df4505cf924c86d6fd542df607ab1fa060
  |   ├─ b7/
  |   | ├─ be206294dc80fc24767df891ccba24b110bd21
  |   | └─ 20b87d1dc8d6931fc24f3ce4d405999a30d0e4
  |   ├─ 25/
  |   | ├─ 2e118d8f4c93b0fdf44726c7c592980e04d3ae
  |   | └─ 89236d5beae86730adcbbbadafc44d1dbf8ae7
  |   ├─ 21/
  |   | └─ c35f796330a3ad51ef6270bb3a2dccad5b91e9
  |   ├─ 95/
  |   | └─ a80ef115a1bf1215113878ec93ec6d4ed45536
  |   ├─ 2f/
  |   | └─ 80ff06e3de5e66293089bbe4fdccbd37a7f490
  |   ├─ e6/
  |   | └─ 9de29bb2d1d6434b8b29ae775ad8c2e48c5391
  |   ├─ ff/
  |   | └─ 41d2cca8c7eae2fec846c5b5e2d7ac21bd3b16
  |   ├─ 23/
  |   | └─ b0f249dac8c32a7ed9ce5f91f39a08fc9c6f52
  |   ├─ ec/
  |   | └─ c323b2643498776a35c19de2519bf3f57b2f2f
  |   ├─ 81/
  |   | └─ 9a1c77badec1691da586c73099bde1dfe04ce4
  |   ├─ 61/
  |   | ├─ 168febbdb1e2fa5532eb78d307c1d8810a7568
  |   | └─ d0020f33195de1ebb0c995ff671eac9c51349f
  |   ├─ dc/
  |   | └─ c3b9938d839b6c86f91f7ae983a0dd1c7fa595
  |   ├─ ad/
  |   | └─ 67f3516c0ed83c5fc728ef88ae46b1f08a8496
  |   ├─ 9d/
  |   | └─ 545705655853ec7a6598c6e49c65d18e3d9bbb
  |   ├─ 4a/
  |   | ├─ 67cf920ccffd615c29cef11bb77323f6a6a9b8
  |   | └─ 76e43e0ff4fb0f9522fb8be8f55b9aae5f65c1
  |   ├─ c8/
  |   | └─ 67377a9dd2198a4b8b577e6c2ec32ea7a54eef
  |   ├─ 86/
  |   | └─ 3a63961ccd4fd1635a880825b3691c349ae992
  |   ├─ a0/
  |   | ├─ b3825fcd95fc06c76f1f9e67ce380749a60b0f
  |   | └─ bef7c2af0359b16bd4161edfa7f2648babafb0
  |   ├─ 05/
  |   | ├─ 85c13efb39868823a8ecfc83a17c46282fc705
  |   | └─ 3f31e286513f836f0a9dc57b95193ff5179fdd
  |   ├─ e7/
  |   | └─ accba9295f7a9ef548d4c96af5d44e31a0a89d
  |   └─ a9/
  |     └─ d2124ec6c868be693189ae0aae6c2949d9df98
  ├─ src/
  | └─ main.c
  ├─ build/
  | ├─ structer
  | ├─ bookthing
  | └─ main.o
  └─ include/
    └─ main.h
```
