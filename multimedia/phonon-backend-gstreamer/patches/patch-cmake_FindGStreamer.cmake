$NetBSD: patch-cmake_FindGStreamer.cmake,v 1.1 2015/11/30 08:36:36 markd Exp $

Newer versions of GStreamer put gst-config.h under
lib/gstreamer-1.0/include, so we need to make sure that directory will
be added to the include path as well.

REVIEW: 125690

--- cmake/FindGStreamer.cmake.orig	2015-11-30 08:02:28.000000000 +0000
+++ cmake/FindGStreamer.cmake
@@ -36,6 +36,27 @@ FIND_PATH(GSTREAMER_INCLUDE_DIR gst/gst.
    PATH_SUFFIXES gstreamer-1.0
    )
 
+IF (NOT GSTREAMER_INCLUDE_DIR)
+   MESSAGE(STATUS "GStreamer: WARNING: include dir not found")
+ENDIF (NOT GSTREAMER_INCLUDE_DIR)
+
+# Newer versions of GStreamer put gst-config.h under lib/gstreamer-1.0/include
+FIND_PATH(GSTREAMER_CONF_INCLUDE_DIR gst/gstconfig.h
+   PATHS
+   ${PKG_GSTREAMER_INCLUDE_DIRS}
+   PATH_SUFFIXES gstreamer-1.0
+   )
+
+IF (NOT GSTREAMER_CONF_INCLUDE_DIR)
+   MESSAGE(STATUS "GStreamer: WARNING: gstconfig.h not found")
+ENDIF (NOT GSTREAMER_CONF_INCLUDE_DIR)
+
+IF (GSTREAMER_INCLUDE_DIR AND GSTREAMER_CONF_INCLUDE_DIR)
+   IF (NOT GSTREAMER_CONF_INCLUDE_DIR STREQUAL GSTREAMER_INCLUDE_DIR)
+      LIST(APPEND GSTREAMER_INCLUDE_DIR "${GSTREAMER_CONF_INCLUDE_DIR}")
+   ENDIF()
+ENDIF (GSTREAMER_INCLUDE_DIR AND GSTREAMER_CONF_INCLUDE_DIR)
+
 FIND_LIBRARY(GSTREAMER_LIBRARIES NAMES gstreamer-1.0
    PATHS
    ${PKG_GSTREAMER_LIBRARY_DIRS}
@@ -51,11 +72,6 @@ FIND_LIBRARY(GSTREAMER_APP_LIBRARY NAMES
    ${PKG_GSTREAMER_LIBRARY_DIRS}
    )
 
-IF (GSTREAMER_INCLUDE_DIR)
-ELSE (GSTREAMER_INCLUDE_DIR)
-   MESSAGE(STATUS "GStreamer: WARNING: include dir not found")
-ENDIF (GSTREAMER_INCLUDE_DIR)
-
 IF (GSTREAMER_LIBRARIES)
 ELSE (GSTREAMER_LIBRARIES)
    MESSAGE(STATUS "GStreamer: WARNING: library not found")