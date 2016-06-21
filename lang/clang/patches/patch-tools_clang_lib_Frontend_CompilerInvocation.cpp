$NetBSD$

Only specify __STDC__VERSION__ when using -std= to match GCC.

--- tools/clang/lib/Frontend/CompilerInvocation.cpp.orig	2015-07-30 22:47:41.000000000 +0000
+++ tools/clang/lib/Frontend/CompilerInvocation.cpp
@@ -930,6 +930,7 @@ static InputKind ParseFrontendArgs(Front
   Opts.ShowStats = Args.hasArg(OPT_print_stats);
   Opts.ShowTimers = Args.hasArg(OPT_ftime_report);
   Opts.ShowVersion = Args.hasArg(OPT_version);
+  Opts.SpecifyStd = Args.hasArg(OPT_std_EQ);
   Opts.ASTMergeFiles = Args.getAllArgValues(OPT_ast_merge);
   Opts.LLVMArgs = Args.getAllArgValues(OPT_mllvm);
   Opts.FixWhatYouCan = Args.hasArg(OPT_fix_what_you_can);
