$NetBSD$

--- Source/ThirdParty/ANGLE/src/common/debug.h.orig	2016-01-28 08:55:08.000000000 +0000
+++ Source/ThirdParty/ANGLE/src/common/debug.h
@@ -79,9 +79,9 @@ bool DebugAnnotationsActive();
 
 // A macro to output a function call and its arguments to the debugging log, in case of error.
 #if defined(ANGLE_TRACE_ENABLED)
-#define ERR(message, ...) gl::trace(false, gl::MESSAGE_ERR, "err: %s(%d): " message "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
+#define MYERR(message, ...) gl::trace(false, gl::MESSAGE_ERR, "err: %s(%d): " message "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
 #else
-#define ERR(message, ...) (void(0))
+#define MYERR(message, ...) (void(0))
 #endif
 
 // A macro to log a performance event around a scope.
@@ -103,7 +103,7 @@ bool DebugAnnotationsActive();
 #if !defined(NDEBUG)
 #define ASSERT(expression) do { \
     if(!(expression)) \
-        ERR("\t! Assert failed in %s(%d): "#expression"\n", __FUNCTION__, __LINE__); \
+        MYERR("\t! Assert failed in %s(%d): "#expression"\n", __FUNCTION__, __LINE__); \
         assert(expression); \
     } while(0)
 #define UNUSED_ASSERTION_VARIABLE(variable)
@@ -142,11 +142,11 @@ bool DebugAnnotationsActive();
 // A macro for code which is not expected to be reached under valid assumptions
 #if !defined(NDEBUG)
 #define UNREACHABLE() do { \
-    ERR("\t! Unreachable reached: %s(%d)\n", __FUNCTION__, __LINE__); \
+    MYERR("\t! Unreachable reached: %s(%d)\n", __FUNCTION__, __LINE__); \
     assert(false); \
     } while(0)
 #else
-    #define UNREACHABLE() ERR("\t! Unreachable reached: %s(%d)\n", __FUNCTION__, __LINE__)
+    #define UNREACHABLE() MYERR("\t! Unreachable reached: %s(%d)\n", __FUNCTION__, __LINE__)
 #endif
 
 #endif   // COMMON_DEBUG_H_
