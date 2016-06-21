$NetBSD$

--- Source/WebCore/platform/FileSystem.cpp.orig	2016-01-28 08:55:09.000000000 +0000
+++ Source/WebCore/platform/FileSystem.cpp
@@ -164,6 +164,9 @@ MappedFileData::MappedFileData(const Str
         return;
     }
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
     void* data = mmap(0, size, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
     close(fd);
 
