$NetBSD$

Mimic GCC behaviour with respect to default defines.

--- tools/clang/lib/Basic/Targets.cpp.orig	2015-08-20 22:03:38.000000000 +0000
+++ tools/clang/lib/Basic/Targets.cpp
@@ -604,20 +604,13 @@ protected:
     Builder.defineMacro("__ELF__");
     Builder.defineMacro("__svr4__");
     Builder.defineMacro("__SVR4");
-    // Solaris headers require _XOPEN_SOURCE to be set to 600 for C99 and
-    // newer, but to 500 for everything else.  feature_test.h has a check to
-    // ensure that you are not using C99 with an old version of X/Open or C89
-    // with a new version.
-    if (Opts.C99)
+    if (Opts.CPlusPlus) {
+      Builder.defineMacro("__EXTENSIONS__");
+      Builder.defineMacro("__STDC_VERSION__", "199901L");
       Builder.defineMacro("_XOPEN_SOURCE", "600");
-    else
-      Builder.defineMacro("_XOPEN_SOURCE", "500");
-    if (Opts.CPlusPlus)
-      Builder.defineMacro("__C99FEATURES__");
-    Builder.defineMacro("_LARGEFILE_SOURCE");
-    Builder.defineMacro("_LARGEFILE64_SOURCE");
-    Builder.defineMacro("__EXTENSIONS__");
-    Builder.defineMacro("_REENTRANT");
+    }
+    if (Opts.POSIXThreads)
+      Builder.defineMacro("_REENTRANT");
   }
 public:
   SolarisTargetInfo(const llvm::Triple &Triple) : OSTargetInfo<Target>(Triple) {
