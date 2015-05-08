$NetBSD: patch-src_libjasper_jpc_jpc__cs.c,v 1.1 2015/01/01 14:15:27 he Exp $

Add fixes for CVE-2011-4516 and CVE-2011-4517.

--- src/libjasper/jpc/jpc_cs.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_cs.c
@@ -744,6 +744,10 @@ static int jpc_cox_getcompparms(jpc_ms_t
 		return -1;
 	}
 	compparms->numrlvls = compparms->numdlvls + 1;
+	if (compparms->numrlvls > JPC_MAXRLVLS) {
+		jpc_cox_destroycompparms(compparms);
+		return -1;
+	}
 	if (prtflag) {
 		for (i = 0; i < compparms->numrlvls; ++i) {
 			if (jpc_getuint8(in, &tmp)) {
@@ -982,7 +986,10 @@ static int jpc_qcx_getcompparms(jpc_qcxc
 		compparms->numstepsizes = (len - n) / 2;
 		break;
 	}
-	if (compparms->numstepsizes > 0) {
+	if (compparms->numstepsizes > 3 * JPC_MAXRLVLS + 1) {
+		jpc_qcx_destroycompparms(compparms);
+                return -1;
+        } else if (compparms->numstepsizes > 0) {
 		compparms->stepsizes = jas_malloc(compparms->numstepsizes *
 		  sizeof(uint_fast16_t));
 		assert(compparms->stepsizes);
@@ -1328,7 +1335,7 @@ static int jpc_crg_getparms(jpc_ms_t *ms
 	jpc_crgcomp_t *comp;
 	uint_fast16_t compno;
 	crg->numcomps = cstate->numcomps;
-	if (!(crg->comps = jas_malloc(cstate->numcomps * sizeof(uint_fast16_t)))) {
+	if (!(crg->comps = jas_malloc(cstate->numcomps * sizeof(jpc_crgcomp_t)))) {
 		return -1;
 	}
 	for (compno = 0, comp = crg->comps; compno < cstate->numcomps;
