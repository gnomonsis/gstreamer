// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace GstSharp {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[UnmanagedFunctionPointer (CallingConvention.Cdecl)]
	internal delegate bool BusFuncNative(IntPtr bus, IntPtr message, IntPtr user_data);

	internal class BusFuncInvoker {

		BusFuncNative native_cb;
		IntPtr __data;
		GLib.DestroyNotify __notify;

		~BusFuncInvoker ()
		{
			if (__notify == null)
				return;
			__notify (__data);
		}

		internal BusFuncInvoker (BusFuncNative native_cb) : this (native_cb, IntPtr.Zero, null) {}

		internal BusFuncInvoker (BusFuncNative native_cb, IntPtr data) : this (native_cb, data, null) {}

		internal BusFuncInvoker (BusFuncNative native_cb, IntPtr data, GLib.DestroyNotify notify)
		{
			this.native_cb = native_cb;
			__data = data;
			__notify = notify;
		}

		internal Gst.BusFunc Handler {
			get {
				return new Gst.BusFunc(InvokeNative);
			}
		}

		bool InvokeNative (Gst.Bus bus, Gst.Message message)
		{
			bool __result = native_cb (bus == null ? IntPtr.Zero : bus.Handle, message == null ? IntPtr.Zero : message.Handle, __data);
			return __result;
		}
	}

	internal class BusFuncWrapper {

		public bool NativeCallback (IntPtr bus, IntPtr message, IntPtr user_data)
		{
			try {
				bool __ret = managed (GLib.Object.GetObject(bus) as Gst.Bus, message == IntPtr.Zero ? null : (Gst.Message) GLib.Opaque.GetOpaque (message, typeof (Gst.Message), false));
				if (release_on_call)
					gch.Free ();
				return __ret;
			} catch (Exception e) {
				GLib.ExceptionManager.RaiseUnhandledException (e, false);
				return false;
			}
		}

		bool release_on_call = false;
		GCHandle gch;

		public void PersistUntilCalled ()
		{
			release_on_call = true;
			gch = GCHandle.Alloc (this);
		}

		internal BusFuncNative NativeDelegate;
		Gst.BusFunc managed;

		public BusFuncWrapper (Gst.BusFunc managed)
		{
			this.managed = managed;
			if (managed != null)
				NativeDelegate = new BusFuncNative (NativeCallback);
		}

		public static Gst.BusFunc GetManagedDelegate (BusFuncNative native)
		{
			if (native == null)
				return null;
			BusFuncWrapper wrapper = (BusFuncWrapper) native.Target;
			if (wrapper == null)
				return null;
			return wrapper.managed;
		}
	}
#endregion
}