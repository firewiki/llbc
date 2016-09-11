/**
 * @file    ServiceNative.cs
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    --/--/--
 * @version 1.0
 *
 * @brief   llbc library native code wrapper.
 *          auto generated by tool, do not try to modify it!
 */

using System;
using System.Runtime.InteropServices;

namespace llbc
{

    /// <summary>
    /// Wrap comm/_Service.h file defined c functions
    /// </summary>
    internal partial class LLBCNative
    {
        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr csllbc_Service_Create(int svcType,
                                                          Deleg_Service_EncodePacket encodeDeleg,
                                                          Deleg_Service_DecodePacket decodeDeleg,
                                                          Deleg_Service_PacketHandler handlerDeleg,
                                                          Deleg_Service_PacketPreHandler preHandlerDeleg,
                                                          Deleg_Service_PacketUnifyPreHandler unifyPreHandlerDeleg,
                                                          Deleg_Service_NativeCouldNotFoundDecoderReport notFoundDecoderDeleg);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static void csllbc_Service_Delete(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetType(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetId(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetDriveMode(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SetDriveMode(IntPtr svc, int driveMode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Start(IntPtr svc, int pollerCount);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static void csllbc_Service_Stop(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_IsStarted(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetFPS(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SetFPS(IntPtr svc, int fps);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetFrameInterval(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Listen(IntPtr svc, IntPtr ip, int port);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Connect(IntPtr svc, IntPtr ip, int port);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_AsyncConn(IntPtr svc, IntPtr ip, int port);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_RemoveSession(IntPtr svc, int sessionId, IntPtr reason, int reasonLen);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_IsSessionValidate(IntPtr svc, int sessionId);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SendBytes(IntPtr svc,
                                                          int sessionId,
                                                          int opcode,
                                                          IntPtr data,
                                                          int dataLen,
                                                          int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SendPacket(IntPtr svc,
                                                           int sessionId,
                                                           int opcode,
                                                           long packetId,
                                                           int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Multicast(IntPtr svc,
                                                          IntPtr sessionIds,
                                                          int sessionIdCount,
                                                          int opcode,
                                                          IntPtr data,
                                                          int dataLen,
                                                          int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Broadcast(IntPtr svc,
                                                          int opcode,
                                                          IntPtr data,
                                                          int dataLen,
                                                          int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_RegisterFacade(IntPtr svc,
                                                               Deleg_Facade_OnInit initDeleg,
                                                               Deleg_Facade_OnDestroy destroyDeleg,
                                                               Deleg_Facade_OnStart startDeleg,
                                                               Deleg_Facade_OnStop stopDeleg,
                                                               Deleg_Facade_OnUpdate updateDeleg,
                                                               Deleg_Facade_OnIdle idleDeleg,
                                                               Deleg_Facade_OnSessionCreate sessionCreateDeleg,
                                                               Deleg_Facade_OnSessionDestroy sessionDestroyDeleg,
                                                               Deleg_Facade_OnAsyncConnResult asyncConnResultDeleg,
                                                               Deleg_Facade_OnProtoReport protoReportDeleg,
                                                               Deleg_Facade_OnUnHandledPacket unHandledPacketDeleg);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_RegisterCoder(IntPtr svc, int opcode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Subscribe(IntPtr svc, int opcode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_PreSubscribe(IntPtr svc, int opcode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_UnifyPreSubscribe(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static void csllbc_Service_OnSvc(IntPtr svc, int fullStack);
    }
}
