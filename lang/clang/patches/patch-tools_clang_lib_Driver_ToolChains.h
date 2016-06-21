$NetBSD$

Solaris support.

--- tools/clang/lib/Driver/ToolChains.h.orig	2015-07-27 20:42:22.000000000 +0000
+++ tools/clang/lib/Driver/ToolChains.h
@@ -514,13 +514,21 @@ protected:
   Tool *buildLinker() const override;
 };
 
-class LLVM_LIBRARY_VISIBILITY Solaris : public Generic_GCC {
+class LLVM_LIBRARY_VISIBILITY Solaris : public Generic_ELF {
 public:
   Solaris(const Driver &D, const llvm::Triple &Triple,
           const llvm::opt::ArgList &Args);
 
   bool IsIntegratedAssemblerDefault() const override { return true; }
 
+  CXXStdlibType GetCXXStdlibType(const llvm::opt::ArgList &Args) const override;
+
+  void AddClangCXXStdlibIncludeArgs(
+      const llvm::opt::ArgList &DriverArgs,
+      llvm::opt::ArgStringList &CC1Args) const override;
+  void AddCXXStdlibLibArgs(const llvm::opt::ArgList &Args,
+                           llvm::opt::ArgStringList &CmdArgs) const override;
+
 protected:
   Tool *buildAssembler() const override;
   Tool *buildLinker() const override;
