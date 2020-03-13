#!/bin/bash
# $1: debug level

CURRENT_DIR=$(readlink -f $(dirname $0))

if [ -z ${NEUWARE_HOME} ]; then
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${NEUWARE_HOME}/lib64
else
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/neuware/lib64
fi

export GST_DEBUG=$1
export GST_PLUGIN_PATH=$GST_PLUGIN_PATH:${CURRENT_DIR}/../../lib
gst-launch-1.0 uridecodebin uri="file://$(pwd)/../data/videos/jpeg_500x500.avi" caps=image/jpeg ! \
               jpegparse ! cndecode device-id=0 ! \
               videoconvert ! videoscale ! autovideosink
