$NetBSD$

Only specify __STDC__VERSION__ when using -std= to match GCC.

--- tools/clang/include/clang/Frontend/FrontendOptions.h.orig	2015-06-22 23:07:51.000000000 +0000
+++ tools/clang/include/clang/Frontend/FrontendOptions.h
@@ -128,6 +128,7 @@ public:
   unsigned ShowTimers : 1;                 ///< Show timers for individual
                                            /// actions.
   unsigned ShowVersion : 1;                ///< Show the -version text.
+  unsigned SpecifyStd : 1;                 ///< Specified -std=
   unsigned FixWhatYouCan : 1;              ///< Apply fixes even if there are
                                            /// unfixable errors.
   unsigned FixOnlyWarnings : 1;            ///< Apply fixes only for warnings.
