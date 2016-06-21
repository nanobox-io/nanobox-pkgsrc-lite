$NetBSD$

Don't enable the network cache on SunOS, requires DT_DIR.

--- Source/WebKit2/config.h.orig	2016-01-29 16:29:33.000000000 +0000
+++ Source/WebKit2/config.h
@@ -88,7 +88,7 @@
 #endif
 
 #ifndef ENABLE_NETWORK_CACHE
-#if ENABLE(NETWORK_PROCESS) && (PLATFORM(COCOA) || PLATFORM(GTK))
+#if ENABLE(NETWORK_PROCESS) && (PLATFORM(COCOA) || PLATFORM(GTK)) && !defined(__sun)
 #define ENABLE_NETWORK_CACHE 1
 #else
 #define ENABLE_NETWORK_CACHE 0
