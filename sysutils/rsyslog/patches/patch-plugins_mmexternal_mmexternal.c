$NetBSD: patch-plugins_mmexternal_mmexternal.c,v 1.5 2017/02/13 19:59:36 fhajny Exp $

Fix build on BSD.
--- plugins/mmexternal/mmexternal.c.orig	2017-01-10 09:00:04.000000000 +0000
+++ plugins/mmexternal/mmexternal.c
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#if defined(_AIX) || defined(__FreeBSD__) 
+#if defined(_AIX) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFlyBSD__) || defined(__APPLE__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
