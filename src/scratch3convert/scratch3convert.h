/**
 * 
 * scratch3convert
 * 
 * Copyright (c) 2019 Alex Cui. All rights reserved.
 * 
 * This is a library for you to convert scratch3 project
 * (*.sb3 file) to scratch2 project(*.sb2 file). You can
 * call function "sc3convert_convert", the first argument
 * is your project path, like "aaa/bbb/cc.sb3" or "aa.sb3".
 * The output file is your file's name plus ".sb2", if
 * your file name is "aaa.sb3", then the output file is
 * "aaa.sb3.sb2". During converting the project, the program
 * need a temp directory for save some data or extract the
 * data from project, the temp directory name must be your
 * project name plus "t", and your project name plus "t/e".
 * 
 */

#ifndef SCRATCH3CONVERT_H
#define SCRATCH3CONVERT_H

#define SCRATCH3CONVERT_VER 20190218l

#ifdef __cplusplus
	#define CAPI extern "C"
#else
	#define CAPI
#endif

#ifdef _MSC_VER
	#define SC3CONVERT_LIBAPI CAPI __declspec(dllimport)
#else
	#define SC3CONVERT_LIBAPI CAPI extern
#endif

#define SC3CONVERT_SUCCESS						+0x01

#define SC3CONVERT_EXCEPTION_UNZIPOPENZIP		-0x01
#define SC3CONVERT_EXCEPTION_UNZIPGLOBALINFO	-0x02
#define SC3CONVERT_EXCEPTION_UNZIPFILEINFO		-0x03
#define SC3CONVERT_EXCEPTION_UNZIPOPENFILE		-0x04
#define SC3CONVERT_EXCEPTION_UNZIPCREATEFILE	-0x05
#define SC3CONVERT_EXCEPTION_UNZIPREADFILE		-0x06
#define SC3CONVERT_EXCEPTION_UNZIPREADNEXTFILE	-0x07

#define SC3CONVERT_EXCEPTION_ZIPCREATEZIP		-0x01

#define SC3CONVERT_EXCEPTION_CONVOPENFILE		-0x21

SC3CONVERT_LIBAPI int sc3convert_convert(const char *name);

#endif
