$NetBSD$

--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2016-01-29 16:29:32.000000000 +0000
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -417,8 +417,8 @@ size_t MachineThreads::Thread::getRegist
     return sizeof(CONTEXT);
 #elif USE(PTHREADS)
     pthread_attr_init(&regs);
-#if HAVE(PTHREAD_NP_H) || OS(NETBSD)
-#if !OS(OPENBSD)
+#if HAVE(PTHREAD_NP_H) || OS(NETBSD) || OS(SOLARIS)
+#if !OS(OPENBSD) && !OS(SOLARIS)
     // e.g. on FreeBSD 5.4, neundorf@kde.org
     pthread_attr_get_np(platformThread, &regs);
 #endif
