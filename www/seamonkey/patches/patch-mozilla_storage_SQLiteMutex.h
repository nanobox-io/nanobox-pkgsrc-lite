$NetBSD: patch-mozilla_storage_SQLiteMutex.h,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/storage/SQLiteMutex.h.orig	2015-09-25 07:34:55.000000000 +0000
+++ mozilla/storage/SQLiteMutex.h
@@ -107,15 +107,19 @@ public:
   void assertCurrentThreadOwns()
   {
     NS_ASSERTION(mMutex, "No mutex associated with this wrapper!");
+#if 0
     NS_ASSERTION(sqlite3_mutex_held(mMutex),
                  "Mutex is not held, but we expect it to be!");
+#endif
   }
 
   void assertNotCurrentThreadOwns()
   {
     NS_ASSERTION(mMutex, "No mutex associated with this wrapper!");
+#if 0
     NS_ASSERTION(sqlite3_mutex_notheld(mMutex),
                  "Mutex is held, but we expect it to not be!");
+#endif
   }
 #endif // ifndef DEBUG
 
