/* testConvert.cpp */
/**
 * Copyright - See the COPYRIGHT that is included with this distribution.
 * EPICS pvDataCPP is distributed subject to a Software License Agreement found
 * in file LICENSE that is included with this distribution.
 */
/* Author:  Marty Kraimer Date: 2010.11 */

#include <cstddef>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <cstdio>

#include <epicsAssert.h>
#include <epicsExit.h>

#include <pv/requester.h>
#include <pv/pvIntrospect.h>
#include <pv/pvData.h>
#include <pv/convert.h>
#include <pv/standardField.h>
#include <pv/standardPVField.h>

using namespace epics::pvData;
using std::tr1::static_pointer_cast;

static FieldCreatePtr fieldCreate;
static PVDataCreatePtr pvDataCreate;
static StandardFieldPtr standardField;
static StandardPVFieldPtr standardPVField;
static ConvertPtr convert;
static String builder("");

static void testConvertScalar(FILE *fd) {
    PVScalarPtr pvBytePtr = pvDataCreate->createPVScalar(pvByte);
    PVScalarPtr pvUBytePtr = pvDataCreate->createPVScalar(pvUByte);
    PVScalarPtr pvShortPtr = pvDataCreate->createPVScalar(pvShort);
    PVScalarPtr pvUShortPtr = pvDataCreate->createPVScalar(pvUShort);
    PVScalarPtr pvIntPtr = pvDataCreate->createPVScalar(pvInt);
    PVScalarPtr pvUIntPtr = pvDataCreate->createPVScalar(pvUInt);
    PVScalarPtr pvLongPtr = pvDataCreate->createPVScalar(pvLong);
    PVScalarPtr pvULongPtr = pvDataCreate->createPVScalar(pvULong);
    PVScalarPtr pvFloatPtr = pvDataCreate->createPVScalar(pvFloat);
    PVScalarPtr pvDoublePtr = pvDataCreate->createPVScalar(pvDouble);

    fprintf(fd,"\nfromByte\n");
    int8 bval = 127;
    for(int i=0; i<3; i++) {
        convert->fromByte(pvBytePtr, bval);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromByte(pvUBytePtr, bval);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromByte(pvShortPtr, bval);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromByte(pvUShortPtr, bval);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromByte(pvIntPtr, bval);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromByte(pvUIntPtr, bval);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromByte(pvLongPtr, bval);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromByte(pvULongPtr, bval);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromByte(pvFloatPtr, bval);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromByte(pvDoublePtr, bval);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvUBytePtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvUBytePtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        bval++;
    }

    fprintf(fd,"\nfromShort\n");
    int16 sval = 0x7fff;
    for(int i=0; i<3; i++) {
        convert->fromShort(pvBytePtr, sval);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromShort(pvUBytePtr, sval);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromShort(pvShortPtr, sval);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromShort(pvUShortPtr, sval);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromShort(pvIntPtr, sval);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromShort(pvUIntPtr, sval);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromShort(pvLongPtr, sval);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromShort(pvULongPtr, sval);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromShort(pvFloatPtr, sval);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromShort(pvDoublePtr, sval);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvUShortPtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvUShortPtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        sval++;
    }

    fprintf(fd,"\nfromInt\n");
    int32 ival = 0x7fffffff;
    for(int i=0; i<3; i++) {
        convert->fromInt(pvBytePtr, ival);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromInt(pvUBytePtr, ival);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromInt(pvShortPtr, ival);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromInt(pvUShortPtr, ival);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromInt(pvIntPtr, ival);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromInt(pvUIntPtr, ival);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromInt(pvLongPtr, ival);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromInt(pvULongPtr, ival);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromInt(pvFloatPtr, ival);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromInt(pvDoublePtr, ival);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvUIntPtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvUIntPtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        ival++;
    }

    fprintf(fd,"\nfromLong\n");
    int64 lval = 0x7fffffffffffffffL;
    for(int i=0; i<3; i++) {
        convert->fromLong(pvBytePtr, lval);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromLong(pvUBytePtr, lval);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromLong(pvShortPtr, lval);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromLong(pvUShortPtr, lval);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromLong(pvIntPtr, lval);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromLong(pvUIntPtr, lval);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromLong(pvLongPtr, lval);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromLong(pvULongPtr, lval);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromLong(pvFloatPtr, lval);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromLong(pvDoublePtr, lval);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvULongPtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvULongPtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        lval++;
    }

    fprintf(fd,"\nfromUByte\n");
    uint8 ubval = 127;
    for(int i=0; i<3; i++) {
        convert->fromUByte(pvBytePtr, ubval);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromUByte(pvUBytePtr, ubval);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromUByte(pvShortPtr, ubval);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromUByte(pvUShortPtr, ubval);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromUByte(pvIntPtr, ubval);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromUByte(pvUIntPtr, ubval);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromUByte(pvLongPtr, ubval);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromUByte(pvULongPtr, ubval);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromUByte(pvFloatPtr, ubval);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromUByte(pvDoublePtr, ubval);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvUBytePtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvUBytePtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        ubval++;
    }

    fprintf(fd,"\nfromUShort\n");
    uint16 usval = 0x7fff;
    for(int i=0; i<3; i++) {
        convert->fromUShort(pvBytePtr, usval);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromUShort(pvUBytePtr, usval);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromUShort(pvShortPtr, usval);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromUShort(pvUShortPtr, usval);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromUShort(pvIntPtr, usval);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromUShort(pvUIntPtr, usval);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromUShort(pvLongPtr, usval);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromUShort(pvULongPtr, usval);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromUShort(pvFloatPtr, usval);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromUShort(pvDoublePtr, usval);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvUShortPtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvUShortPtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        usval++;
    }

    fprintf(fd,"\nfromUInt\n");
    uint32 uival = 0x7fffffff;
    for(int i=0; i<3; i++) {
        convert->fromUInt(pvBytePtr, uival);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromUInt(pvUBytePtr, uival);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromUInt(pvShortPtr, uival);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromUInt(pvUShortPtr, uival);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromUInt(pvIntPtr, uival);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromUInt(pvUIntPtr, uival);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromUInt(pvLongPtr, uival);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromUInt(pvULongPtr, uival);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromUInt(pvFloatPtr, uival);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromUInt(pvDoublePtr, uival);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvUIntPtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvUIntPtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        uival++;
    }

    fprintf(fd,"\nfromULong\n");
    uint64 ulval = 0x7fffffffffffffffL;
    for(int i=0; i<3; i++) {
        convert->fromULong(pvBytePtr, ulval);
        builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
        convert->fromULong(pvUBytePtr, ulval);
        builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
        convert->fromULong(pvShortPtr, ulval);
        builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
        convert->fromULong(pvUShortPtr, ulval);
        builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
        convert->fromULong(pvIntPtr, ulval);
        builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
        convert->fromULong(pvUIntPtr, ulval);
        builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
        convert->fromULong(pvLongPtr, ulval);
        builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
        convert->fromULong(pvULongPtr, ulval);
        builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
        convert->fromULong(pvFloatPtr, ulval);
        builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
        convert->fromULong(pvDoublePtr, ulval);
        builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
        convert->copyScalar(pvULongPtr, pvFloatPtr);
        builder.clear(); pvFloatPtr->toString(&builder);
        fprintf(fd,"float from unsigned %s\n",builder.c_str());
        convert->copyScalar(pvULongPtr, pvDoublePtr);
        builder.clear(); pvDoublePtr->toString(&builder);
        fprintf(fd,"double from unsigned %s\n",builder.c_str());
        ulval++;
    }

}

static void testConvertScalarArray(FILE *fd) {
    PVScalarArrayPtr pvBytePtr = pvDataCreate->createPVScalarArray(pvByte);
    PVScalarArrayPtr pvUBytePtr = pvDataCreate->createPVScalarArray(pvUByte);
    PVScalarArrayPtr pvShortPtr = pvDataCreate->createPVScalarArray(pvShort);
    PVScalarArrayPtr pvUShortPtr = pvDataCreate->createPVScalarArray(pvUShort);
    PVScalarArrayPtr pvIntPtr = pvDataCreate->createPVScalarArray(pvInt);
    PVScalarArrayPtr pvUIntPtr = pvDataCreate->createPVScalarArray(pvUInt);
    PVScalarArrayPtr pvLongPtr = pvDataCreate->createPVScalarArray(pvLong);
    PVScalarArrayPtr pvULongPtr = pvDataCreate->createPVScalarArray(pvULong);
    PVScalarArrayPtr pvFloatPtr = pvDataCreate->createPVScalarArray(pvFloat);
    PVScalarArrayPtr pvDoublePtr = pvDataCreate->createPVScalarArray(pvDouble);

    fprintf(fd,"\nfromByte\n");
    size_t length = 4;
    int8 barray[length];
    int8 bval = 127;
    barray[0] = bval;
    for(size_t i=1; i<length; i++) barray[i] = barray[i-1] + 1;
    convert->fromByteArray(pvBytePtr,0,length,barray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromByteArray(pvUBytePtr,0,length,barray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromByteArray(pvShortPtr,0,length,barray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromByteArray(pvUShortPtr,0,length,barray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromByteArray(pvIntPtr,0,length,barray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromByteArray(pvUIntPtr,0,length,barray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromByteArray(pvLongPtr,0,length,barray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromByteArray(pvULongPtr,0,length,barray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromByteArray(pvFloatPtr,0,length,barray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromByteArray(pvDoublePtr,0,length,barray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvUBytePtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvUBytePtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromShort\n");
    int16 sarray[length];
    int16 sval = 0x7fff;
    sarray[0] = sval;
    for(size_t i=1; i<length; i++) sarray[i] = sarray[i-1] + 1;
    convert->fromShortArray(pvBytePtr,0,length,sarray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromShortArray(pvUBytePtr,0,length,sarray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromShortArray(pvShortPtr,0,length,sarray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromShortArray(pvUShortPtr,0,length,sarray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromShortArray(pvIntPtr,0,length,sarray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromShortArray(pvUIntPtr,0,length,sarray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromShortArray(pvLongPtr,0,length,sarray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromShortArray(pvULongPtr,0,length,sarray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromShortArray(pvFloatPtr,0,length,sarray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromShortArray(pvDoublePtr,0,length,sarray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvUShortPtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvUShortPtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromInt\n");
    int32 iarray[length];
    int32 ival = 0x7fffffff;
    iarray[0] = ival;
    for(size_t i=1; i<length; i++) iarray[i] = iarray[i-1] + 1;
    convert->fromIntArray(pvBytePtr,0,length,iarray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromIntArray(pvUBytePtr,0,length,iarray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromIntArray(pvShortPtr,0,length,iarray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromIntArray(pvUShortPtr,0,length,iarray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromIntArray(pvIntPtr,0,length,iarray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromIntArray(pvUIntPtr,0,length,iarray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromIntArray(pvLongPtr,0,length,iarray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromIntArray(pvULongPtr,0,length,iarray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromIntArray(pvFloatPtr,0,length,iarray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromIntArray(pvDoublePtr,0,length,iarray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvUIntPtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvUIntPtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromLong\n");
    int64 larray[length];
    int64 lval = 0x7fffffffffffffff;
    larray[0] = lval;
    for(size_t i=1; i<length; i++) larray[i] = larray[i-1] + 1;
    convert->fromLongArray(pvBytePtr,0,length,larray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromLongArray(pvUBytePtr,0,length,larray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromLongArray(pvShortPtr,0,length,larray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromLongArray(pvUShortPtr,0,length,larray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromLongArray(pvIntPtr,0,length,larray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromLongArray(pvUIntPtr,0,length,larray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromLongArray(pvLongPtr,0,length,larray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromLongArray(pvULongPtr,0,length,larray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromLongArray(pvFloatPtr,0,length,larray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromLongArray(pvDoublePtr,0,length,larray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvULongPtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvULongPtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromUByte\n");
    uint8 ubarray[length];
    uint8 ubval = 127;
    ubarray[0] = ubval;
    for(size_t i=1; i<length; i++) ubarray[i] = ubarray[i-1] + 1;
    convert->fromUByteArray(pvBytePtr,0,length,ubarray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromUByteArray(pvUBytePtr,0,length,ubarray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromUByteArray(pvShortPtr,0,length,ubarray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromUByteArray(pvUShortPtr,0,length,ubarray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromUByteArray(pvIntPtr,0,length,ubarray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromUByteArray(pvUIntPtr,0,length,ubarray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromUByteArray(pvLongPtr,0,length,ubarray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromUByteArray(pvULongPtr,0,length,ubarray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromUByteArray(pvFloatPtr,0,length,ubarray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromUByteArray(pvDoublePtr,0,length,ubarray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvUBytePtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvUBytePtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromUShort\n");
    uint16 usarray[length];
    uint16 usval = 0x7fff;
    usarray[0] = usval;
    for(size_t i=1; i<length; i++) usarray[i] = usarray[i-1] + 1;
    convert->fromUShortArray(pvBytePtr,0,length,usarray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromUShortArray(pvUBytePtr,0,length,usarray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromUShortArray(pvShortPtr,0,length,usarray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromUShortArray(pvUShortPtr,0,length,usarray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromUShortArray(pvIntPtr,0,length,usarray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromUShortArray(pvUIntPtr,0,length,usarray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromUShortArray(pvLongPtr,0,length,usarray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromUShortArray(pvULongPtr,0,length,usarray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromUShortArray(pvFloatPtr,0,length,usarray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromUShortArray(pvDoublePtr,0,length,usarray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvUShortPtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvUShortPtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromUInt\n");
    uint32 uiarray[length];
    uint32 uival = 0x7fffffff;
    uiarray[0] = uival;
    for(size_t i=1; i<length; i++) uiarray[i] = uiarray[i-1] + 1;
    convert->fromUIntArray(pvBytePtr,0,length,uiarray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromUIntArray(pvUBytePtr,0,length,uiarray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromUIntArray(pvShortPtr,0,length,uiarray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromUIntArray(pvUShortPtr,0,length,uiarray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromUIntArray(pvIntPtr,0,length,uiarray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromUIntArray(pvUIntPtr,0,length,uiarray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromUIntArray(pvLongPtr,0,length,uiarray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromUIntArray(pvULongPtr,0,length,uiarray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromUIntArray(pvFloatPtr,0,length,uiarray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromUIntArray(pvDoublePtr,0,length,uiarray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvUIntPtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvUIntPtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());

    fprintf(fd,"\nfromULong\n");
    uint64 ularray[length];
    uint64 ulval = 0x7fffffffffffffff;
    ularray[0] = ulval;
    for(size_t i=1; i<length; i++) ularray[i] = ularray[i-1] + 1;
    convert->fromULongArray(pvBytePtr,0,length,ularray,0);
    builder.clear(); pvBytePtr->toString(&builder); fprintf(fd,"byte %s\n",builder.c_str());
    convert->fromULongArray(pvUBytePtr,0,length,ularray,0);
    builder.clear(); pvUBytePtr->toString(&builder); fprintf(fd,"ubyte %s\n",builder.c_str());
    convert->fromULongArray(pvShortPtr,0,length,ularray,0);
    builder.clear(); pvShortPtr->toString(&builder); fprintf(fd,"short %s\n",builder.c_str());
    convert->fromULongArray(pvUShortPtr,0,length,ularray,0);
    builder.clear(); pvUShortPtr->toString(&builder); fprintf(fd,"ushort %s\n",builder.c_str());
    convert->fromULongArray(pvIntPtr,0,length,ularray,0);
    builder.clear(); pvIntPtr->toString(&builder); fprintf(fd,"int %s\n",builder.c_str());
    convert->fromULongArray(pvUIntPtr,0,length,ularray,0);
    builder.clear(); pvUIntPtr->toString(&builder); fprintf(fd,"uint %s\n",builder.c_str());
    convert->fromULongArray(pvLongPtr,0,length,ularray,0);
    builder.clear(); pvLongPtr->toString(&builder); fprintf(fd,"long %s\n",builder.c_str());
    convert->fromULongArray(pvULongPtr,0,length,ularray,0);
    builder.clear(); pvULongPtr->toString(&builder); fprintf(fd,"ulong %s\n",builder.c_str());
    convert->fromULongArray(pvFloatPtr,0,length,ularray,0);
    builder.clear(); pvFloatPtr->toString(&builder); fprintf(fd,"float %s\n",builder.c_str());
    convert->fromULongArray(pvDoublePtr,0,length,ularray,0);
    builder.clear(); pvDoublePtr->toString(&builder); fprintf(fd,"double %s\n",builder.c_str());
    convert->copyScalarArray(pvULongPtr,0, pvFloatPtr,0,length);
    builder.clear(); pvFloatPtr->toString(&builder);
    fprintf(fd,"float from unsigned %s\n",builder.c_str());
    convert->copyScalarArray(pvULongPtr,0, pvDoublePtr,0,length);
    builder.clear(); pvDoublePtr->toString(&builder);
    fprintf(fd,"double from unsigned %s\n",builder.c_str());
ULongArrayData arrayData = ULongArrayData();
PVULongArrayPtr xxx = static_pointer_cast<PVULongArray>(pvULongPtr);
xxx->get(0,length,arrayData);
uint64 * data = get(arrayData.data);
printf("data %p %lli %lli %lli %lli\n",data,data[0],data[1],data[2],data[3]);
uint64 val = arrayData.data[0];
printf("val %p %lli\n",&(arrayData.data[0]),val);
}

int main(int argc,char *argv[])
{
    char *fileName = 0;
    if(argc>1) fileName = argv[1];
    FILE * fd = stdout;
    if(fileName!=0 && fileName[0]!=0) {
        fd = fopen(fileName,"w+");
    }
    fieldCreate = getFieldCreate();
    pvDataCreate = getPVDataCreate();
    standardField = getStandardField();
    standardPVField = getStandardPVField();
    convert = getConvert();
    testConvertScalar(fd);
    testConvertScalarArray(fd);
    return(0);
}

