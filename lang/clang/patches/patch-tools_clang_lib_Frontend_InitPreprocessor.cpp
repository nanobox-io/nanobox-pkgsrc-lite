$NetBSD$

Only specify __STDC__VERSION__ when using -std= to match GCC.

--- tools/clang/lib/Frontend/InitPreprocessor.cpp.orig	2015-07-17 20:25:46.000000000 +0000
+++ tools/clang/lib/Frontend/InitPreprocessor.cpp
@@ -365,12 +365,14 @@ static void InitializeStandardPredefined
     Builder.defineMacro("__STDC_HOSTED__");
 
   if (!LangOpts.CPlusPlus) {
+   if (FEOpts.SpecifyStd) {
     if (LangOpts.C11)
       Builder.defineMacro("__STDC_VERSION__", "201112L");
     else if (LangOpts.C99)
       Builder.defineMacro("__STDC_VERSION__", "199901L");
     else if (!LangOpts.GNUMode && LangOpts.Digraphs)
       Builder.defineMacro("__STDC_VERSION__", "199409L");
+   }
   } else {
     // FIXME: Use correct value for C++17.
     if (LangOpts.CPlusPlus1z)
