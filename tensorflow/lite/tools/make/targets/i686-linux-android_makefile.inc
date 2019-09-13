# Settings for Atom Silvermont Android.
ifeq ($(TARGET),i686-linux-android)
  # Default to the architecture used on Atom Silvermont x86
  TARGET_ARCH := silvermont
  TARGET_TOOLCHAIN_PREFIX := /opt/ndk/toolchains/x86-4.9/prebuilt/linux-x86_64/bin/i686-linux-android-
  # Default to API Level 21
  API_LEVEL := 21
  
  # Add cpu-features.c to TF_LITE_CC_SRCS. Needed to find reference to android_getCpuFamily
  TF_LITE_CC_SRCS += \
    /opt/ndk/sources/android/cpufeatures/cpu-features.c

  CXXFLAGS += \
    -DANDROID \
    -fPIC \
    --target=i686-none-linux-android${API_LEVEL} \
    --gcc-toolchain=/opt/ndk/toolchains/x86-4.9/prebuilt/linux-x86_64 \
    --sysroot=/opt/ndk/platforms/android-${API_LEVEL}/arch-x86 \
    -isystem /opt/ndk/sysroot/usr/include \
    -isystem /opt/ndk/sysroot/usr/include/i686-linux-android \
    -I/opt/ndk/sources/cxx-stl/llvm-libc++/include \
    -I/opt/ndk/sources/cxx-stl/llvm-libc++abi/include \
    -I/opt \
    -ftree-vectorize -fvectorize -fslp-vectorize
    

  CCFLAGS += \
    -DANDROID \
    -fPIC \
    --target=i686-none-linux-android${API_LEVEL} \
    --gcc-toolchain=/opt/ndk/toolchains/x86-4.9/prebuilt/linux-x86_64 \
    --sysroot=/opt/ndk/platforms/android-${API_LEVEL}/arch-x86 \
    -isystem /opt/ndk/sysroot/usr/include \
    -isystem /opt/ndk/sysroot/usr/include/i686-linux-android \
    -I/opt/ndk/sources/cxx-stl/llvm-libc++/include \
    -I/opt/ndk/sources/cxx-stl/llvm-libc++abi/include \
    -I/opt \
    -ftree-vectorize -fvectorize -fslp-vectorize
    

  ifeq ($(TARGET_ARCH),silvermont)
    CXXFLAGS += \
      -mtune=silvermont -march=silvermont -msse4.2

    CCFLAGS += \
      -mtune=silvermont -march=silvermont -msse4.2
  endif

  LDFLAGS := \
    -Wl,--no-export-dynamic \
    -Wl,--gc-sections \
    -Wl,--as-needed \
    -L/opt/ndk/platforms/android-${API_LEVEL}/arch-x86/usr/lib \
    -L/opt/ndk/sources/cxx-stl/llvm-libc++/libs/x86

  LIBS := \
    -lstdc++ \
    -lc++_shared \
    -lm \
    -ldl \
    -llog

endif
