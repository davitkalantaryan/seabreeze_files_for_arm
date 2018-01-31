/***************************************************//**
 * @file    RS232.h
 * @date    April 2011
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2014, Ocean Optics Inc
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *******************************************************/

#ifndef SEABREEZE_RS232_H
#define SEABREEZE_RS232_H

#include "native/rs232/NativeRS232.h"
#if defined(_WIN32) & defined( _MSC_VER)// DK added
#include <tchar.h>						// DK added
typedef TCHAR	NTCHAR;					// DK added
#define	nfprintf	_ftprintf			// DK added
#define	TEXT2		_T					// DK added
#else									// DK added
typedef	char	NTCHAR;					// DK added
#define	nfprintf	fprintf				// DK added
#define	TEXT2(_str_)	_str_			// DK added
#endif									// DK added

namespace seabreeze {

    class RS232 {
    public:
        RS232(const char *devicePath, int baudRate);
        virtual ~RS232();

        bool open();
        bool close();
        int write(void *data, unsigned int length_bytes);
        int read(void *data, unsigned int length_bytes);

        //void setVerbose(bool v); // DK commented
        bool isOpened();

    protected:

        /* These methods are primarily for debugging. */
        void rs232HexDump(void *x, int length, bool out);
        void hexDump(void *x, int length);
        void describeTransfer(int length, bool out);

        void *descriptor;
        bool opened;
        bool verbose;
        //char *devicePath; // DK commented
		NTCHAR*	devicePath;	// DK modified
        int baudRate;
    };

}

#endif
