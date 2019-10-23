/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#include "usbg/usbg.h"
#include "usbg/usbg_internal.h"
//#include "usbg/function/scm.h"

#ifdef HAS_GADGET_SCHEMES
#include <libconfig.h>
#endif

struct usbg_f_scm {
	struct usbg_function func;
};

GENERIC_ALLOC_INST(scm, struct usbg_f_scm, func);

GENERIC_FREE_INST(scm, struct usbg_f_scm, func);

static int scm_set_attrs(struct usbg_function *f, void *f_attrs)
{
	return USBG_SUCCESS;
}

static int scm_get_attrs(struct usbg_function *f, void *f_attrs)
{
	return USBG_SUCCESS;
}

static int scm_libconfig_import(struct usbg_function *f,
				  config_setting_t *root)
{
	return USBG_SUCCESS;
}

static int scm_libconfig_export(struct usbg_function *f,
				  config_setting_t *root)
{
	return USBG_SUCCESS;
}

#define SCM_FUNCTION_OPTS			\
	.alloc_inst = scm_alloc_inst,		\
	.free_inst = scm_free_inst,	        \
	.set_attrs = scm_set_attrs,	        \
	.get_attrs = scm_get_attrs,	        \
	.export = scm_libconfig_export,	\
	.import = scm_libconfig_import

struct usbg_function_type usbg_f_type_scm = {
	.name = "scm",
	SCM_FUNCTION_OPTS,
};
