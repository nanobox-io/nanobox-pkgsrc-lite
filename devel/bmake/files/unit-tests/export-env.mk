# $Id: export-env.mk,v 1.2 2015/05/19 22:01:19 joerg Exp $

# our normal .export, subsequent changes affect the environment
UT_TEST=this
.export UT_TEST
UT_TEST:= ${.PARSEFILE}

# not so with .export-env
UT_ENV=exported
.export-env UT_ENV
UT_ENV=not-exported

# gmake style export goes further; affects nothing but the environment
UT_EXP=before-export
export UT_EXP=exported
UT_EXP=not-exported

all:
	@echo make:; ${UT_TEST UT_ENV UT_EXP:L:@v@echo $v=${$v};@}
	@echo env:; ${UT_TEST UT_ENV UT_EXP:L:@v@echo $v=$${$v};@}




