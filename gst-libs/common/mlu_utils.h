/* 
 *  Copyright (C) [2019-2020] by Cambricon, Inc.
 * 
 *  This file is part of CNStream-Gst.
 *
 *  CNStream-Gst is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  CNStream-Gst is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 * 
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with CNStream-Gst.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MLU_UTILS_H_
#define MLU_UTILS_H_

#include <gst/gst.h>
#include "easyinfer/mlu_context.h"

static inline gboolean
set_cnrt_env(GstElement* self, int device_id)
{
  try {
    edk::MluContext context;
    context.SetDeviceId(device_id);
    context.ConfigureForThisThread();
  } catch (edk::MluContextError& err) {
    GST_ELEMENT_ERROR(self, LIBRARY, SETTINGS, ("set mlu environment failed"), ("%s", err.what()));
    return FALSE;
  }
  return TRUE;
}

#endif // MLU_UTILS_H_
