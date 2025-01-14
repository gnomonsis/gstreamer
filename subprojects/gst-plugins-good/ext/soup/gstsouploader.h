/* GStreamer
 * Copyright (C) 2021 Igalia S.L.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more
 */

#ifndef __GST_SOUP_LOADER_H__
#define __GST_SOUP_LOADER_H__

#ifdef STATIC_SOUP
#include <libsoup/soup.h>
#else
#include "stub/soup.h"
#endif

#include <gst/gst.h>
#include <gio/gio.h>

G_BEGIN_DECLS

gboolean gst_soup_load_library (void);
guint gst_soup_loader_get_api_version (void);

SoupSession *_soup_session_new_with_options (const char *optname1, ...) G_GNUC_NULL_TERMINATED;

SoupLogger *_soup_logger_new (SoupLoggerLogLevel);

void _soup_logger_set_printer (SoupLogger *logger, SoupLoggerPrinter printer,
                               gpointer printer_data, GDestroyNotify destroy);

void _soup_session_add_feature (SoupSession *session,
                                SoupSessionFeature *feature);
void _soup_session_add_feature_by_type (SoupSession *session, GType feature_type);

typedef struct _GstSoupUri {
#if (defined(STATIC_SOUP) && STATIC_SOUP == 3) || (!defined(STATIC_SOUP) && GLIB_CHECK_VERSION(2, 66, 0))
  GUri *uri;
#endif
#if (defined(STATIC_SOUP) && STATIC_SOUP == 2) || !defined(STATIC_SOUP)
  SoupURI *soup_uri;
#endif
} GstSoupUri;

GstSoupUri *gst_soup_uri_new (const char *uri_string);
void gst_soup_uri_free (GstSoupUri *uri);
char *gst_soup_uri_to_string (GstSoupUri *uri);

char *gst_soup_message_uri_to_string (SoupMessage* msg);

guint _soup_get_major_version (void);
guint _soup_get_minor_version (void);
guint _soup_get_micro_version (void);

void _soup_message_set_request_body_from_bytes (SoupMessage *msg,
                                                const char *content_type,
                                                GBytes *bytes);

GType _soup_session_get_type (void);
GType _soup_logger_log_level_get_type (void);
GType _soup_content_decoder_get_type (void);
GType _soup_cookie_jar_get_type (void);

void _soup_session_abort (SoupSession * session);
SoupMessage *_soup_message_new (const char *method, const char *uri_string);
SoupMessageHeaders *_soup_message_get_request_headers (SoupMessage *msg);
SoupMessageHeaders *_soup_message_get_response_headers (SoupMessage *msg);

void _soup_message_headers_remove (SoupMessageHeaders *hdrs, const char *name);
void _soup_message_headers_append (SoupMessageHeaders *hdrs, const char *name,
                                   const char *value);
void _soup_message_set_flags (SoupMessage *msg, SoupMessageFlags flags);

void _soup_message_headers_foreach (SoupMessageHeaders *hdrs,
                                    SoupMessageHeadersForeachFunc func,
                                    gpointer user_data);

SoupEncoding _soup_message_headers_get_encoding (SoupMessageHeaders *hdrs);

goffset _soup_message_headers_get_content_length (SoupMessageHeaders *hdrs);

SoupStatus _soup_message_get_status (SoupMessage *msg);
const char *_soup_message_get_reason_phrase (SoupMessage *msg);

const char *_soup_message_headers_get_one (SoupMessageHeaders *hdrs,
                                           const char *name);
void _soup_message_disable_feature (SoupMessage *msg, GType feature_type);

const char *_soup_message_headers_get_content_type (SoupMessageHeaders *hdrs,
                                                    GHashTable **params);

#ifdef BUILDING_ADAPTIVEDEMUX2
gboolean _soup_message_headers_get_content_range (SoupMessageHeaders *hdrs,
                                                   goffset *start, goffset *end,
                                                   goffset *total_length);

void _soup_message_headers_set_range (SoupMessageHeaders *hdrs, goffset start, goffset end);
#endif

void _soup_auth_authenticate (SoupAuth *auth, const char *username,
                              const char *password);

const char *_soup_message_get_method (SoupMessage *msg);

void _soup_session_send_async (SoupSession *session,
                               SoupMessage *msg,
                               GCancellable *cancellable,
                               GAsyncReadyCallback callback,
                               gpointer user_data);

GInputStream *_soup_session_send_finish (SoupSession *session,
                                         GAsyncResult *result, GError **error);

GInputStream *_soup_session_send (SoupSession *session, SoupMessage *msg,
                                  GCancellable *cancellable,
                                  GError **error) G_GNUC_WARN_UNUSED_RESULT;

void gst_soup_session_cancel_message (SoupSession *session, SoupMessage *msg, GCancellable *cancellable);

G_END_DECLS

#endif /* __GST_SOUP_LOADER_H__ */
