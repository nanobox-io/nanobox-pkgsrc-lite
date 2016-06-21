$NetBSD$

Use pkgsrc GCC includes.

--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	2015-07-02 04:45:27.000000000 +0000
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -215,6 +215,7 @@ void InitHeaderSearch::AddDefaultCInclud
     case llvm::Triple::OpenBSD:
     case llvm::Triple::Bitrig:
     case llvm::Triple::NaCl:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
@@ -405,8 +406,8 @@ AddDefaultCPlusPlusIncludePaths(const ll
                                 "", "", "", triple);
     break;
   case llvm::Triple::Solaris:
-    AddGnuCPlusPlusIncludePaths("/usr/gcc/4.5/include/c++/4.5.2/",
-                                "i386-pc-solaris2.11", "", "", triple);
+    AddGnuCPlusPlusIncludePaths("@GCCINCLUDEPATH@",
+                                "x86_64-sun-solaris2.11", "", "", triple);
     break;
   default:
     break;
