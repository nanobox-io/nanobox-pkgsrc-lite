$NetBSD$

Pull in the correct GCC libraries.

--- tools/clang/lib/Driver/Tools.cpp.orig	2015-07-30 22:47:41.000000000 +0000
+++ tools/clang/lib/Driver/Tools.cpp
@@ -6719,18 +6719,19 @@ void solaris::Linker::ConstructJob(Compi
                                    const ArgList &Args,
                                    const char *LinkingOutput) const {
   // FIXME: Find a real GCC, don't hard-code versions here
-  std::string GCCLibPath = "/usr/gcc/4.5/lib/gcc/";
+  std::string GCCLibPath = "@GCCLIBPATH@";
+  std::string GCCObjectPath = "@GCCLIBPATH@";
   const llvm::Triple &T = getToolChain().getTriple();
   std::string LibPath = "/usr/lib/";
   const llvm::Triple::ArchType Arch = T.getArch();
   switch (Arch) {
   case llvm::Triple::x86:
-    GCCLibPath +=
-        ("i386-" + T.getVendorName() + "-" + T.getOSName()).str() + "/4.5.2/";
+    GCCLibPath += "lib";
+    GCCObjectPath += "lib/32/";
     break;
   case llvm::Triple::x86_64:
-    GCCLibPath += ("i386-" + T.getVendorName() + "-" + T.getOSName()).str();
-    GCCLibPath += "/4.5.2/amd64/";
+    GCCLibPath += "lib/amd64";
+    GCCObjectPath += "lib/";
     LibPath += "amd64/";
     break;
   default:
@@ -6774,17 +6775,18 @@ void solaris::Linker::ConstructJob(Compi
       CmdArgs.push_back(Args.MakeArgString(LibPath + "crt1.o"));
       CmdArgs.push_back(Args.MakeArgString(LibPath + "crti.o"));
       CmdArgs.push_back(Args.MakeArgString(LibPath + "values-Xa.o"));
-      CmdArgs.push_back(Args.MakeArgString(GCCLibPath + "crtbegin.o"));
+      CmdArgs.push_back(Args.MakeArgString(GCCObjectPath + "crtbegin.o"));
     } else {
       CmdArgs.push_back(Args.MakeArgString(LibPath + "crti.o"));
       CmdArgs.push_back(Args.MakeArgString(LibPath + "values-Xa.o"));
-      CmdArgs.push_back(Args.MakeArgString(GCCLibPath + "crtbegin.o"));
+      CmdArgs.push_back(Args.MakeArgString(GCCObjectPath + "crtbegin.o"));
     }
     if (getToolChain().getDriver().CCCIsCXX())
       CmdArgs.push_back(Args.MakeArgString(LibPath + "cxa_finalize.o"));
   }
 
   CmdArgs.push_back(Args.MakeArgString("-L" + GCCLibPath));
+  CmdArgs.push_back(Args.MakeArgString("-R" + GCCLibPath));
 
   Args.AddAllArgs(CmdArgs, options::OPT_L);
   Args.AddAllArgs(CmdArgs, options::OPT_T_Group);
@@ -6798,8 +6800,14 @@ void solaris::Linker::ConstructJob(Compi
     if (getToolChain().getDriver().CCCIsCXX())
       getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
     CmdArgs.push_back("-lgcc_s");
+    if (Args.hasArg(options::OPT_fstack_protector) ||
+        Args.hasArg(options::OPT_fstack_protector_strong) ||
+        Args.hasArg(options::OPT_fstack_protector_all)) {
+      CmdArgs.push_back("-lssp_nonshared");
+      CmdArgs.push_back("-lssp");
+    }
     if (!Args.hasArg(options::OPT_shared)) {
-      CmdArgs.push_back("-lgcc");
+      CmdArgs.push_back(Args.MakeArgString(GCCObjectPath + "libgcc.a"));
       CmdArgs.push_back("-lc");
       CmdArgs.push_back("-lm");
     }
@@ -6807,7 +6815,7 @@ void solaris::Linker::ConstructJob(Compi
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-    CmdArgs.push_back(Args.MakeArgString(GCCLibPath + "crtend.o"));
+    CmdArgs.push_back(Args.MakeArgString(GCCObjectPath + "crtend.o"));
   }
   CmdArgs.push_back(Args.MakeArgString(LibPath + "crtn.o"));
 
