# Settings for Linux.
ifeq ($(TARGET), linux)
  CXXFLAGS += \
    -fPIC \
    -DGEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK \
    -pthread

  CFLAGS += \
    -fPIC \
    -DGEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK \
    -pthread    

  LIBS += -ldl

  ifeq ($(TARGET_ARCH),ivybridge)
    CXXFLAGS += \
      -mtune=ivybridge -march=ivybridge -msse4.2 -mavx

    CFLAGS += \
      -mtune=ivybridge -march=ivybridge -msse4.2 -mavx
  endif
endif
