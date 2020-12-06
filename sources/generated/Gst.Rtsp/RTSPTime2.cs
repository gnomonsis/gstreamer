// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst.Rtsp {

	using System;
	using System.Collections;
	using System.Collections.Generic;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[StructLayout(LayoutKind.Sequential)]
	public partial struct RTSPTime2 : IEquatable<RTSPTime2> {

		public double Frames;
		public uint Year;
		public uint Month;
		public uint Day;

		public static Gst.Rtsp.RTSPTime2 Zero = new Gst.Rtsp.RTSPTime2 ();

		public static Gst.Rtsp.RTSPTime2 New(IntPtr raw) {
			if (raw == IntPtr.Zero)
				return Gst.Rtsp.RTSPTime2.Zero;
			return (Gst.Rtsp.RTSPTime2) Marshal.PtrToStructure (raw, typeof (Gst.Rtsp.RTSPTime2));
		}

		public bool Equals (RTSPTime2 other)
		{
			return true && Frames.Equals (other.Frames) && Year.Equals (other.Year) && Month.Equals (other.Month) && Day.Equals (other.Day);
		}

		public override bool Equals (object other)
		{
			return other is RTSPTime2 && Equals ((RTSPTime2) other);
		}

		public override int GetHashCode ()
		{
			return this.GetType ().FullName.GetHashCode () ^ Frames.GetHashCode () ^ Year.GetHashCode () ^ Month.GetHashCode () ^ Day.GetHashCode ();
		}

		private static GLib.GType GType {
			get { return GLib.GType.Pointer; }
		}
#endregion
	}
}