# ASCII CAM

Uses camera input from the user, and outputs an ASCII converted live image. Logic in CPP, UX/UI in '*UNDECIDED*'. 

## Requirements

- Computer Vision (C++)
- cMake


```bash
## How to Run (Debian Distros)

1. sudo apt install libopencv-dev build-essential cmake   

2. pkg-config --modversion opencv4   


IF YOU'RE NOT USING VSCODE/AUTO CONFIG IDE, YOU'LL NEED TO COMPILE LIKE THIS (makefile will be done soon):
g++ -std=c++17 cam.cpp cam_logic.cpp -o cam_app `pkg-config --cflags --libs opencv4` -lpthread   
g++ -std=c++17 front.cpp -o my_app -lpthread

```
