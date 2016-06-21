$NetBSD$

--- Source/bmalloc/bmalloc/VMAllocate.h.orig	2016-01-28 08:55:09.000000000 +0000
+++ Source/bmalloc/bmalloc/VMAllocate.h
@@ -156,6 +156,8 @@ inline void vmDeallocatePhysicalPages(vo
     vmValidate(p, vmSize);
 #if BOS(DARWIN)
     SYSCALL(madvise(p, vmSize, MADV_FREE_REUSABLE));
+#elif defined(__sun)
+    SYSCALL(posix_madvise(p, vmSize, POSIX_MADV_DONTNEED));
 #else
     SYSCALL(madvise(p, vmSize, MADV_DONTNEED));
 #endif
@@ -166,6 +168,8 @@ inline void vmAllocatePhysicalPages(void
     vmValidate(p, vmSize);
 #if BOS(DARWIN)
     SYSCALL(madvise(p, vmSize, MADV_FREE_REUSE));
+#elif defined(__sun)
+    SYSCALL(posix_madvise(p, vmSize, POSIX_MADV_NORMAL));
 #else
     SYSCALL(madvise(p, vmSize, MADV_NORMAL));
 #endif
