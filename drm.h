#pragma once

#include "kmsvnc.h"

#define KMSVNC_FOURCC_TO_INT(a,b,c,d) (((a) << 0) + ((b) << 8) + ((c) << 16) + ((d) << 24))

#define DRM_FATAL(...) { fprintf(stderr, __VA_ARGS__); return 1; }
#define DRM_IOCTL_MUST(...) { int e; if (e = drmIoctl(__VA_ARGS__)) DRM_FATAL("DRM ioctl error %d on line %d\n", e, __LINE__) }
#define DRM_IOCTL_MAY(...) { int e; if (e = drmIoctl(__VA_ARGS__)) fprintf(stderr, "DRM ioctl error %d on line %d\n", e, __LINE__); }

void drm_cleanup();
int drm_open();
int drm_vendors();
