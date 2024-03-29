﻿#pragma once

#include "default.defines.h"

#ifndef _IMAGE_PROCESSOR_AS_DLL
#	define _IMAGE_PROCESSOR_AS_DLL 1
#endif

#if (_IMAGE_PROCESSOR_AS_DLL)

#	ifdef _EXPORTS_IMAGE_PROCESSOR
#		define AFX_EXT_CLASS_IMAGE_PROCESSOR	AFX_CLASS_EXPORT
#		define AFX_EXT_API_IMAGE_PROCESSOR		AFX_API_EXPORT
#		define AFX_EXT_DATA_IMAGE_PROCESSOR		AFX_DATA_EXPORT
#	else 
#		define AFX_EXT_CLASS_IMAGE_PROCESSOR	AFX_CLASS_IMPORT
#		define AFX_EXT_API_IMAGE_PROCESSOR		AFX_API_IMPORT
#		define AFX_EXT_DATA_IMAGE_PROCESSOR		AFX_DATA_IMPORT
		__IMPORT_MOCHA_LIB__(ImageProcessor)
#	endif

#else	// _IMAGE_PROCESSOR_AS_DLL

#	define AFX_EXT_CLASS_IMAGE_PROCESSOR
#	define AFX_EXT_API_IMAGE_PROCESSOR
#	define AFX_EXT_DATA_IMAGE_PROCESSOR

#endif
