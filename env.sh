
export DAJO_ROOT=$(readlink -f $(pwd))
echo "root=${DAJO_ROOT}"

export DAJO_BUILD=${DAJO_ROOT}/build
export DAJO_OUT=${DAJO_ROOT}/out
mkdir -p ${DAJO_OUT}

m() {
	make -f build.mk all
}
