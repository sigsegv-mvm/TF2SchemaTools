#!/bin/bash

HL2SDK="$1"

$HL2SDK/gcsdk/bin/linux/protoc -I "$HL2SDK/thirdparty/protobuf-2.3.0/src" -I . --cpp_out=../proto-cxx *.proto
