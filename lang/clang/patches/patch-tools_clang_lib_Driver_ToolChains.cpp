$NetBSD$

Solaris support.

--- tools/clang/lib/Driver/ToolChains.cpp.orig	2015-07-13 23:27:56.000000000 +0000
+++ tools/clang/lib/Driver/ToolChains.cpp
@@ -2833,7 +2833,7 @@ Tool *Minix::buildLinker() const { retur
 
 Solaris::Solaris(const Driver &D, const llvm::Triple &Triple,
                  const ArgList &Args)
-    : Generic_GCC(D, Triple, Args) {
+    : Generic_ELF(D, Triple, Args) {
 
   getProgramPaths().push_back(getDriver().getInstalledDir());
   if (getDriver().getInstalledDir() != getDriver().Dir)
@@ -2849,6 +2849,50 @@ Tool *Solaris::buildAssembler() const {
 
 Tool *Solaris::buildLinker() const { return new tools::solaris::Linker(*this); }
 
+ToolChain::CXXStdlibType Solaris::GetCXXStdlibType(const ArgList &Args) const {
+  if (Arg *A = Args.getLastArg(options::OPT_stdlib_EQ)) {
+    StringRef Value = A->getValue();
+    if (Value == "libstdc++")
+      return ToolChain::CST_Libstdcxx;
+    if (Value == "libc++")
+      return ToolChain::CST_Libcxx;
+
+    getDriver().Diag(diag::err_drv_invalid_stdlib_name) << A->getAsString(Args);
+  }
+  return ToolChain::CST_Libstdcxx;
+}
+
+void Solaris::AddClangCXXStdlibIncludeArgs(const ArgList &DriverArgs,
+                                          ArgStringList &CC1Args) const {
+  if (DriverArgs.hasArg(options::OPT_nostdlibinc) ||
+      DriverArgs.hasArg(options::OPT_nostdincxx))
+    return;
+
+  switch (GetCXXStdlibType(DriverArgs)) {
+  case ToolChain::CST_Libcxx:
+    break;
+  case ToolChain::CST_Libstdcxx:
+    addSystemInclude(DriverArgs, CC1Args,
+                     getDriver().SysRoot + "@GCCINCLUDEPATH@");
+    break;
+  }
+}
+
+void Solaris::AddCXXStdlibLibArgs(const ArgList &Args,
+                                 ArgStringList &CmdArgs) const {
+  switch (GetCXXStdlibType(Args)) {
+  case ToolChain::CST_Libcxx:
+    CmdArgs.push_back("-lc++");
+    CmdArgs.push_back("-lc++abi");
+    CmdArgs.push_back("-lpthread");
+    break;
+  case ToolChain::CST_Libstdcxx:
+    CmdArgs.push_back("-lstdc++");
+    break;
+  }
+}
+
+
 /// Distribution (very bare-bones at the moment).
 
 enum Distro {
