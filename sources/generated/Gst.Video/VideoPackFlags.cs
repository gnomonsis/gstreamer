// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst.Video {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[Flags]
	[GLib.GType (typeof (Gst.Video.VideoPackFlagsGType))]
	public enum VideoPackFlags {

		None = 0,
		TruncateRange = 1,
		Interlaced = 2,
	}

	internal class VideoPackFlagsGType {
		[DllImport ("gstvideo-1.0-0.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_video_pack_flags_get_type ();

		public static GLib.GType GType {
			get {
				return new GLib.GType (gst_video_pack_flags_get_type ());
			}
		}
	}
#endregion
}