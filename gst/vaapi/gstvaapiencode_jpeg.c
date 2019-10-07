/*
 *  gstvaapiencode_jpeg.c - VA-API JPEG encoder
 *
 *  Copyright (C) 2015 Intel Corporation
 *    Author: Sreerenj Balachandran <sreerenj.balachandran@intel.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1
 *  of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301 USA
 */

/**
 * SECTION:element-vaapijpegenc
 * @short_description: A VA-API based JPEG image encoder
 *
 * Encodes raw images into JPEG images.
 *
 * ## Example launch line
 *
 * |[
 *  gst-launch-1.0 -ev videotestsrc num-buffers=1 ! timeoverlay ! vaapijpegenc ! filesink location=test.jpg
 * ]|
 */

#include "gstcompat.h"
#include <gst/vaapi/gstvaapidisplay.h>
#include <gst/vaapi/gstvaapiencoder_jpeg.h>
#include "gstvaapiencode_jpeg.h"
#include "gstvaapipluginutil.h"
#include "gstvaapivideomemory.h"

#define GST_PLUGIN_NAME "vaapijpegenc"
#define GST_PLUGIN_DESC "A VA-API based JPEG video encoder"

GST_DEBUG_CATEGORY_STATIC (gst_vaapi_jpeg_encode_debug);
#define GST_CAT_DEFAULT gst_vaapi_jpeg_encode_debug

#define GST_CODEC_CAPS                          \
  "image/jpeg"

/* *INDENT-OFF* */
static const char gst_vaapiencode_jpeg_sink_caps_str[] =
  GST_VAAPI_MAKE_SURFACE_CAPS ", "
  GST_CAPS_INTERLACED_FALSE "; "
  GST_VIDEO_CAPS_MAKE (GST_VIDEO_FORMATS_ALL) ", "
  GST_CAPS_INTERLACED_FALSE ";"
  GST_VAAPI_MAKE_DMABUF_CAPS ","
  GST_CAPS_INTERLACED_FALSE;
/* *INDENT-ON* */

/* *INDENT-OFF* */
static const char gst_vaapiencode_jpeg_src_caps_str[] =
  GST_CODEC_CAPS;
/* *INDENT-ON* */

/* *INDENT-OFF* */
static GstStaticPadTemplate gst_vaapiencode_jpeg_sink_factory =
  GST_STATIC_PAD_TEMPLATE ("sink",
      GST_PAD_SINK,
      GST_PAD_ALWAYS,
      GST_STATIC_CAPS (gst_vaapiencode_jpeg_sink_caps_str));
/* *INDENT-ON* */

/* *INDENT-OFF* */
static GstStaticPadTemplate gst_vaapiencode_jpeg_src_factory =
  GST_STATIC_PAD_TEMPLATE ("src",
      GST_PAD_SRC,
      GST_PAD_ALWAYS,
      GST_STATIC_CAPS (gst_vaapiencode_jpeg_src_caps_str));
/* *INDENT-ON* */

/* jpeg encode */
G_DEFINE_TYPE (GstVaapiEncodeJpeg, gst_vaapiencode_jpeg, GST_TYPE_VAAPIENCODE);

static void
gst_vaapiencode_jpeg_init (GstVaapiEncodeJpeg * encode)
{
  /* nothing to do here */
}

static void
gst_vaapiencode_jpeg_finalize (GObject * object)
{
  G_OBJECT_CLASS (gst_vaapiencode_jpeg_parent_class)->finalize (object);
}

static GstCaps *
gst_vaapiencode_jpeg_get_caps (GstVaapiEncode * base_encode)
{
  GstCaps *caps;

  caps = gst_caps_from_string (GST_CODEC_CAPS);

  return caps;
}

static GstVaapiEncoder *
gst_vaapiencode_jpeg_alloc_encoder (GstVaapiEncode * base,
    GstVaapiDisplay * display)
{
  return gst_vaapi_encoder_jpeg_new (display);
}

static void
gst_vaapiencode_jpeg_class_init (GstVaapiEncodeJpegClass * klass)
{
  GObjectClass *const object_class = G_OBJECT_CLASS (klass);
  GstElementClass *const element_class = GST_ELEMENT_CLASS (klass);
  GstVaapiEncodeClass *const encode_class = GST_VAAPIENCODE_CLASS (klass);
  gpointer encoder_class;

  GST_DEBUG_CATEGORY_INIT (gst_vaapi_jpeg_encode_debug,
      GST_PLUGIN_NAME, 0, GST_PLUGIN_DESC);

  object_class->finalize = gst_vaapiencode_jpeg_finalize;
  object_class->set_property = gst_vaapiencode_set_property_subclass;
  object_class->get_property = gst_vaapiencode_get_property_subclass;

  encode_class->get_caps = gst_vaapiencode_jpeg_get_caps;
  encode_class->alloc_encoder = gst_vaapiencode_jpeg_alloc_encoder;

  gst_element_class_set_static_metadata (element_class,
      "VA-API JPEG encoder",
      "Codec/Encoder/Image/Hardware",
      GST_PLUGIN_DESC,
      "Sreerenj Balachandran <sreerenj.balachandran@intel.com>");

  /* sink pad */
  gst_element_class_add_static_pad_template (element_class,
      &gst_vaapiencode_jpeg_sink_factory);

  /* src pad */
  gst_element_class_add_static_pad_template (element_class,
      &gst_vaapiencode_jpeg_src_factory);

  encoder_class = g_type_class_ref (GST_TYPE_VAAPI_ENCODER_JPEG);
  g_assert (encoder_class);
  gst_vaapiencode_class_install_properties (encode_class, encoder_class);
  g_type_class_unref (encoder_class);
}