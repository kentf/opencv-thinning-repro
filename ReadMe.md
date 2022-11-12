# Clone OpenCV

```
git clone https://github.com/microsoft/vcpkg
git clone https://github.com/opencv/opencv
git clone https://github.com/opencv/opencv_contrib
pwsh configure_opencv.ps1


cd opencv-build-gcc/
make -j20 install
cd ..

cmake -Ssrc -Bgithub-test-gcc
cmake -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake -S. -Bvcpkg-test-gcc


cd github-test-gcc
make -j
./github-test



cd ../vcpkg-test-gcc
make -j
./vcpkg-test


```

# Timings

```
opencv-thinning/github-test-gcc $ ./github-test
Opening file: ../gabor/thinning.png
Thinning on [1036 x 591]... Used 1846ms
```

```
opencv-thinning/vcpkg-test-gcc $ ./vcpkg-test
Opening file: ../gabor/thinning.png
Thinning on [1036 x 591]... Used 23342ms
```



