#!/bin/bash

CLASS=$1
UPPER=$(echo ${CLASS} | tr "a-z" "A-Z")

cat <<- +++ > ${1}.h
#ifndef ${UPPER}_H
#define ${UPPER}_H

class ${CLASS} {

public:
   ${CLASS}();
   ~${CLASS}();

private:

};

#endif
+++

cat <<- +++ > ${1}.cc
#include "Trace.h"
#include "${CLASS}.h"

CLASS("${CLASS}");

${CLASS}::${CLASS}() {
   METHOD("${CLASS}()");

}

${CLASS}::~${CLASS}() {
   METHOD("~${CLASS}()");

}

+++
