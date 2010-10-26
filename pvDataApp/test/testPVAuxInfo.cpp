/* testPVAuxInfo.cpp */
/* Author:  Marty Kraimer Date: 2010.09.21 */

#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "pvData.h"

using namespace epics::pvData;

static FieldCreate * fieldCreate = 0;
static PVDataCreate *pvDataCreate = 0;
static String buffer("");

void testDouble() {
    printf("\ntestDouble\n");
    String valueName("value");
    ScalarConstPtr pscalar = fieldCreate->createScalar(valueName,pvDouble);
    PVScalar *pvScalar = pvDataCreate->createPVScalar(0,pscalar);
    PVDouble *pvValue = dynamic_cast<PVDouble *>(pvScalar);
    double value = 2;
    pvValue->put(value);
    double getValue = pvValue->get();
    if(value!=getValue) {
        fprintf(stderr,"ERROR getValue put %f get %f\n",value,getValue);
    }
    PVAuxInfo *auxInfo = pvValue->getPVAuxInfo();
    String stringName("string");
    PVScalar *pvAux = auxInfo->createInfo(stringName,pvDouble);
    PVDouble *doubleInfo = dynamic_cast<PVDouble *>(pvAux);
    doubleInfo->put(100.0);
    pvAux = auxInfo->getInfo(stringName);
    buffer.clear();
    buffer += "auxInfo ";
    printf("\ncalling toString\n");
    printf("%s\n",buffer.c_str());
    buffer.clear();
    buffer += "pvScalar ";
    pvScalar->toString(&buffer);
    printf("%s\n",buffer.c_str());
    delete pvValue;
}

int main(int argc,char *argv[])
{
    fieldCreate = getFieldCreate();
    pvDataCreate = getPVDataCreate();
    testDouble();
    return(0);
}
