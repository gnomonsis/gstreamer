// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst.ControllerSharp {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[UnmanagedFunctionPointer (CallingConvention.Cdecl)]
	internal delegate void DirectControlBindingConvertGValueNative(IntPtr self, double src_value, IntPtr dest_value);

	internal class DirectControlBindingConvertGValueInvoker {

		DirectControlBindingConvertGValueNative native_cb;
		IntPtr __data;
		GLib.DestroyNotify __notify;

		~DirectControlBindingConvertGValueInvoker ()
		{
			if (__notify == null)
				return;
			__notify (__data);
		}

		internal DirectControlBindingConvertGValueInvoker (DirectControlBindingConvertGValueNative native_cb) : this (native_cb, IntPtr.Zero, null) {}

		internal DirectControlBindingConvertGValueInvoker (DirectControlBindingConvertGValueNative native_cb, IntPtr data) : this (native_cb, data, null) {}

		internal DirectControlBindingConvertGValueInvoker (DirectControlBindingConvertGValueNative native_cb, IntPtr data, GLib.DestroyNotify notify)
		{
			this.native_cb = native_cb;
			__data = data;
			__notify = notify;
		}

		internal Gst.Controller.DirectControlBindingConvertGValue Handler {
			get {
				return new Gst.Controller.DirectControlBindingConvertGValue(InvokeNative);
			}
		}

		void InvokeNative (Gst.Controller.DirectControlBinding self, double src_value, GLib.Value dest_value)
		{
			IntPtr native_dest_value = GLib.Marshaller.StructureToPtrAlloc (dest_value);
			native_cb (self == null ? IntPtr.Zero : self.Handle, src_value, native_dest_value);
			Marshal.FreeHGlobal (native_dest_value);
		}
	}

	internal class DirectControlBindingConvertGValueWrapper {

		public void NativeCallback (IntPtr self, double src_value, IntPtr dest_value)
		{
			try {
				managed (GLib.Object.GetObject(self) as Gst.Controller.DirectControlBinding, src_value, (GLib.Value) Marshal.PtrToStructure (dest_value, typeof (GLib.Value)));
				if (release_on_call)
					gch.Free ();
			} catch (Exception e) {
				GLib.ExceptionManager.RaiseUnhandledException (e, false);
			}
		}

		bool release_on_call = false;
		GCHandle gch;

		public void PersistUntilCalled ()
		{
			release_on_call = true;
			gch = GCHandle.Alloc (this);
		}

		internal DirectControlBindingConvertGValueNative NativeDelegate;
		Gst.Controller.DirectControlBindingConvertGValue managed;

		public DirectControlBindingConvertGValueWrapper (Gst.Controller.DirectControlBindingConvertGValue managed)
		{
			this.managed = managed;
			if (managed != null)
				NativeDelegate = new DirectControlBindingConvertGValueNative (NativeCallback);
		}

		public static Gst.Controller.DirectControlBindingConvertGValue GetManagedDelegate (DirectControlBindingConvertGValueNative native)
		{
			if (native == null)
				return null;
			DirectControlBindingConvertGValueWrapper wrapper = (DirectControlBindingConvertGValueWrapper) native.Target;
			if (wrapper == null)
				return null;
			return wrapper.managed;
		}
	}
#endregion
}