#define ICALL_TABLE_corlib 1

static int corlib_icall_indexes [] = {
216,
229,
230,
231,
232,
233,
234,
235,
236,
237,
240,
241,
242,
416,
417,
418,
446,
447,
448,
475,
476,
477,
594,
595,
596,
599,
636,
637,
638,
639,
640,
644,
646,
648,
650,
656,
664,
665,
666,
667,
668,
669,
670,
671,
672,
673,
674,
675,
676,
677,
678,
679,
680,
682,
683,
684,
685,
686,
687,
688,
785,
786,
787,
788,
789,
790,
791,
792,
793,
794,
795,
796,
797,
798,
799,
800,
801,
803,
804,
805,
806,
807,
808,
809,
871,
880,
881,
951,
958,
961,
963,
969,
970,
972,
973,
977,
980,
981,
983,
984,
987,
988,
989,
992,
994,
997,
999,
1001,
1008,
1013,
1088,
1090,
1092,
1102,
1103,
1104,
1106,
1112,
1113,
1114,
1115,
1116,
1124,
1125,
1126,
1130,
1131,
1134,
1138,
1139,
1140,
1437,
1647,
1648,
10037,
10038,
10040,
10041,
10042,
10043,
10044,
10046,
10047,
10048,
10049,
10067,
10069,
10076,
10078,
10080,
10082,
10085,
10135,
10136,
10138,
10139,
10140,
10141,
10142,
10144,
10146,
11282,
11286,
11288,
11289,
11290,
11291,
11744,
11745,
11746,
11747,
11765,
11766,
11767,
11812,
11886,
11889,
11897,
11898,
11899,
11900,
11901,
12233,
12234,
12239,
12240,
12276,
12319,
12326,
12333,
12344,
12348,
12374,
12457,
12459,
12470,
12472,
12473,
12474,
12481,
12496,
12516,
12517,
12525,
12527,
12534,
12535,
12538,
12540,
12545,
12551,
12552,
12559,
12561,
12573,
12576,
12577,
12578,
12589,
12599,
12605,
12606,
12607,
12609,
12610,
12627,
12629,
12644,
12667,
12668,
12669,
12694,
12699,
12729,
12730,
13369,
13383,
13470,
13471,
13693,
13694,
13702,
13703,
13704,
13710,
13781,
14293,
14294,
14687,
14692,
14702,
15673,
15694,
15696,
15698,
};
void ves_icall_System_Array_InternalCreate (int,int,int,int,int);
int ves_icall_System_Array_GetCorElementTypeOfElementTypeInternal (int);
int ves_icall_System_Array_IsValueOfElementTypeInternal (int,int);
int ves_icall_System_Array_CanChangePrimitive (int,int,int);
int ves_icall_System_Array_FastCopy (int,int,int,int,int);
int ves_icall_System_Array_GetLengthInternal_raw (int,int,int);
int ves_icall_System_Array_GetLowerBoundInternal_raw (int,int,int);
void ves_icall_System_Array_GetGenericValue_icall (int,int,int);
void ves_icall_System_Array_GetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_SetGenericValue_icall (int,int,int);
void ves_icall_System_Array_SetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_InitializeInternal_raw (int,int);
void ves_icall_System_Array_SetValueRelaxedImpl_raw (int,int,int,int);
void ves_icall_System_Runtime_RuntimeImports_ZeroMemory (int,int);
void ves_icall_System_Runtime_RuntimeImports_Memmove (int,int,int);
void ves_icall_System_Buffer_BulkMoveWithWriteBarrier (int,int,int,int);
int ves_icall_System_Delegate_AllocDelegateLike_internal_raw (int,int);
int ves_icall_System_Delegate_CreateDelegate_internal_raw (int,int,int,int,int);
int ves_icall_System_Delegate_GetVirtualMethod_internal_raw (int,int);
void ves_icall_System_Enum_GetEnumValuesAndNames_raw (int,int,int,int);
int ves_icall_System_Enum_InternalGetCorElementType (int);
void ves_icall_System_Enum_InternalGetUnderlyingType_raw (int,int,int);
int ves_icall_System_Environment_get_ProcessorCount ();
int ves_icall_System_Environment_get_TickCount ();
int64_t ves_icall_System_Environment_get_TickCount64 ();
void ves_icall_System_Environment_FailFast_raw (int,int,int,int);
int ves_icall_System_GC_GetCollectionCount (int);
int ves_icall_System_GC_GetMaxGeneration ();
void ves_icall_System_GC_register_ephemeron_array_raw (int,int);
int ves_icall_System_GC_get_ephemeron_tombstone_raw (int);
int64_t ves_icall_System_GC_GetTotalAllocatedBytes_raw (int,int);
void ves_icall_System_GC_SuppressFinalize_raw (int,int);
void ves_icall_System_GC_ReRegisterForFinalize_raw (int,int);
void ves_icall_System_GC_GetGCMemoryInfo (int,int,int,int,int,int);
int ves_icall_System_GC_AllocPinnedArray_raw (int,int,int);
int ves_icall_System_Object_MemberwiseClone_raw (int,int);
double ves_icall_System_Math_Acos (double);
double ves_icall_System_Math_Acosh (double);
double ves_icall_System_Math_Asin (double);
double ves_icall_System_Math_Asinh (double);
double ves_icall_System_Math_Atan (double);
double ves_icall_System_Math_Atan2 (double,double);
double ves_icall_System_Math_Atanh (double);
double ves_icall_System_Math_Cbrt (double);
double ves_icall_System_Math_Ceiling (double);
double ves_icall_System_Math_Cos (double);
double ves_icall_System_Math_Cosh (double);
double ves_icall_System_Math_Exp (double);
double ves_icall_System_Math_Floor (double);
double ves_icall_System_Math_Log (double);
double ves_icall_System_Math_Log10 (double);
double ves_icall_System_Math_Pow (double,double);
double ves_icall_System_Math_Sin (double);
double ves_icall_System_Math_Sinh (double);
double ves_icall_System_Math_Sqrt (double);
double ves_icall_System_Math_Tan (double);
double ves_icall_System_Math_Tanh (double);
double ves_icall_System_Math_FusedMultiplyAdd (double,double,double);
double ves_icall_System_Math_Log2 (double);
double ves_icall_System_Math_ModF (double,int);
float ves_icall_System_MathF_Acos (float);
float ves_icall_System_MathF_Acosh (float);
float ves_icall_System_MathF_Asin (float);
float ves_icall_System_MathF_Asinh (float);
float ves_icall_System_MathF_Atan (float);
float ves_icall_System_MathF_Atan2 (float,float);
float ves_icall_System_MathF_Atanh (float);
float ves_icall_System_MathF_Cbrt (float);
float ves_icall_System_MathF_Ceiling (float);
float ves_icall_System_MathF_Cos (float);
float ves_icall_System_MathF_Cosh (float);
float ves_icall_System_MathF_Exp (float);
float ves_icall_System_MathF_Floor (float);
float ves_icall_System_MathF_Log (float);
float ves_icall_System_MathF_Log10 (float);
float ves_icall_System_MathF_Pow (float,float);
float ves_icall_System_MathF_Sin (float);
float ves_icall_System_MathF_Sinh (float);
float ves_icall_System_MathF_Sqrt (float);
float ves_icall_System_MathF_Tan (float);
float ves_icall_System_MathF_Tanh (float);
float ves_icall_System_MathF_FusedMultiplyAdd (float,float,float);
float ves_icall_System_MathF_Log2 (float);
float ves_icall_System_MathF_ModF (float,int);
int ves_icall_RuntimeMethodHandle_GetFunctionPointer_raw (int,int);
void ves_icall_RuntimeMethodHandle_ReboxFromNullable_raw (int,int,int);
void ves_icall_RuntimeMethodHandle_ReboxToNullable_raw (int,int,int,int);
int ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw (int,int,int);
void ves_icall_RuntimeType_make_array_type_raw (int,int,int,int);
void ves_icall_RuntimeType_make_byref_type_raw (int,int,int);
void ves_icall_RuntimeType_make_pointer_type_raw (int,int,int);
void ves_icall_RuntimeType_MakeGenericType_raw (int,int,int,int);
int ves_icall_RuntimeType_GetMethodsByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetPropertiesByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetConstructors_native_raw (int,int,int);
void ves_icall_RuntimeType_GetPacking_raw (int,int,int,int);
int ves_icall_System_RuntimeType_CreateInstanceInternal_raw (int,int);
void ves_icall_RuntimeType_GetDeclaringMethod_raw (int,int,int);
void ves_icall_System_RuntimeType_getFullName_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetGenericArgumentsInternal_raw (int,int,int,int);
int ves_icall_RuntimeType_GetGenericParameterPosition (int);
int ves_icall_RuntimeType_GetEvents_native_raw (int,int,int,int);
int ves_icall_RuntimeType_GetFields_native_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetInterfaces_raw (int,int,int);
int ves_icall_RuntimeType_GetNestedTypes_native_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetDeclaringType_raw (int,int,int);
void ves_icall_RuntimeType_GetName_raw (int,int,int);
void ves_icall_RuntimeType_GetNamespace_raw (int,int,int);
int ves_icall_RuntimeType_IsUnmanagedFunctionPointerInternal (int);
int ves_icall_RuntimeType_FunctionPointerReturnAndParameterTypes_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetAttributes (int);
int ves_icall_RuntimeTypeHandle_GetMetadataToken_raw (int,int);
void ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_GetCorElementType (int);
int ves_icall_RuntimeTypeHandle_HasInstantiation (int);
int ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_HasReferences_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetArrayRank_raw (int,int);
void ves_icall_RuntimeTypeHandle_GetAssembly_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetElementType_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetModule_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetBaseType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition (int);
int ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw (int,int);
int ves_icall_RuntimeTypeHandle_is_subclass_of_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsByRefLike_raw (int,int);
void ves_icall_System_RuntimeTypeHandle_internal_from_name_raw (int,int,int,int,int,int);
int ves_icall_System_String_FastAllocateString_raw (int,int);
int ves_icall_System_String_InternalIsInterned_raw (int,int);
int ves_icall_System_String_InternalIntern_raw (int,int);
int ves_icall_System_Type_internal_from_handle_raw (int,int);
int ves_icall_System_ValueType_InternalGetHashCode_raw (int,int,int);
int ves_icall_System_ValueType_Equals_raw (int,int,int,int);
int ves_icall_System_Threading_Interlocked_CompareExchange_Int (int,int,int);
void ves_icall_System_Threading_Interlocked_CompareExchange_Object (int,int,int,int);
int ves_icall_System_Threading_Interlocked_Decrement_Int (int);
int ves_icall_System_Threading_Interlocked_Increment_Int (int);
int64_t ves_icall_System_Threading_Interlocked_Increment_Long (int);
int ves_icall_System_Threading_Interlocked_Exchange_Int (int,int);
void ves_icall_System_Threading_Interlocked_Exchange_Object (int,int,int);
int64_t ves_icall_System_Threading_Interlocked_CompareExchange_Long (int,int64_t,int64_t);
int64_t ves_icall_System_Threading_Interlocked_Exchange_Long (int,int64_t);
int ves_icall_System_Threading_Interlocked_Add_Int (int,int);
int64_t ves_icall_System_Threading_Interlocked_Add_Long (int,int64_t);
void ves_icall_System_Threading_Monitor_Monitor_Enter_raw (int,int);
void mono_monitor_exit_icall_raw (int,int);
void ves_icall_System_Threading_Monitor_Monitor_pulse_raw (int,int);
void ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw (int,int);
int ves_icall_System_Threading_Monitor_Monitor_wait_raw (int,int,int,int);
void ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw (int,int,int,int,int);
int64_t ves_icall_System_Threading_Monitor_Monitor_get_lock_contention_count ();
void ves_icall_System_Threading_Thread_InitInternal_raw (int,int);
int ves_icall_System_Threading_Thread_GetCurrentThread ();
void ves_icall_System_Threading_InternalThread_Thread_free_internal_raw (int,int);
int ves_icall_System_Threading_Thread_GetState_raw (int,int);
void ves_icall_System_Threading_Thread_SetState_raw (int,int,int);
void ves_icall_System_Threading_Thread_ClrState_raw (int,int,int);
void ves_icall_System_Threading_Thread_SetName_icall_raw (int,int,int,int);
int ves_icall_System_Threading_Thread_YieldInternal ();
void ves_icall_System_Threading_Thread_SetPriority_raw (int,int,int);
void ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw (int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw (int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw (int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw (int,int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw (int,int,int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalGetLoadedAssemblies_raw (int);
int ves_icall_System_GCHandle_InternalAlloc_raw (int,int,int);
void ves_icall_System_GCHandle_InternalFree_raw (int,int);
int ves_icall_System_GCHandle_InternalGet_raw (int,int);
void ves_icall_System_GCHandle_InternalSet_raw (int,int,int);
int ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError ();
void ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError (int);
void ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw (int,int,int,int);
int ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw (int,int,int,int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetObjectValue_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw (int,int);
void ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw (int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw (int,int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack ();
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalBox_raw (int,int,int);
int ves_icall_System_Reflection_Assembly_GetExecutingAssembly_raw (int,int);
int ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw (int);
int ves_icall_System_Reflection_Assembly_InternalLoad_raw (int,int,int,int);
int ves_icall_System_Reflection_Assembly_InternalGetType_raw (int,int,int,int,int,int);
int ves_icall_System_Reflection_AssemblyName_GetNativeName (int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw (int,int,int,int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw (int,int);
int ves_icall_MonoCustomAttrs_IsDefinedInternal_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw (int,int);
int ves_icall_System_Reflection_LoaderAllocatorScout_Destroy (int);
void ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceNames_raw (int,int,int);
void ves_icall_System_Reflection_RuntimeAssembly_GetExportedTypes_raw (int,int,int);
void ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw (int,int,int,int);
int ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceInternal_raw (int,int,int,int,int);
void ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw (int,int,int);
void ves_icall_System_Reflection_RuntimeAssembly_GetModulesInternal_raw (int,int,int);
void ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw (int,int,int,int,int,int,int);
void ves_icall_RuntimeEventInfo_get_event_info_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_ResolveType_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetParentType_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_GetFieldOffset_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetValueInternal_raw (int,int,int);
void ves_icall_RuntimeFieldInfo_SetValueInternal_raw (int,int,int,int);
int ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw (int,int);
int ves_icall_reflection_get_token_raw (int,int);
void ves_icall_get_method_info_raw (int,int,int);
int ves_icall_get_method_attributes (int);
int ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw (int,int,int);
int ves_icall_System_MonoMethodInfo_get_retval_marshal_raw (int,int);
int ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw (int,int,int,int);
int ves_icall_RuntimeMethodInfo_get_name_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_base_method_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
void ves_icall_RuntimeMethodInfo_GetPInvoke_raw (int,int,int,int,int);
int ves_icall_RuntimeMethodInfo_MakeGenericMethod_impl_raw (int,int,int);
int ves_icall_RuntimeMethodInfo_GetGenericArguments_raw (int,int);
int ves_icall_RuntimeMethodInfo_GetGenericMethodDefinition_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw (int,int);
void ves_icall_InvokeClassConstructor_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_RuntimeModule_InternalGetTypes_raw (int,int);
void ves_icall_System_Reflection_RuntimeModule_GetGuidInternal_raw (int,int,int);
int ves_icall_System_Reflection_RuntimeModule_ResolveMethodToken_raw (int,int,int,int,int,int);
int ves_icall_RuntimeParameterInfo_GetTypeModifiers_raw (int,int,int,int,int,int);
void ves_icall_RuntimePropertyInfo_get_property_info_raw (int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_CustomAttributeBuilder_GetBlob_raw (int,int,int,int,int,int,int,int);
void ves_icall_DynamicMethod_create_dynamic_method_raw (int,int,int,int,int);
void ves_icall_AssemblyBuilder_basic_init_raw (int,int);
void ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw (int,int);
void ves_icall_ModuleBuilder_basic_init_raw (int,int);
void ves_icall_ModuleBuilder_set_wrappers_type_raw (int,int,int);
int ves_icall_ModuleBuilder_getUSIndex_raw (int,int,int);
int ves_icall_ModuleBuilder_getToken_raw (int,int,int,int);
int ves_icall_ModuleBuilder_getMethodToken_raw (int,int,int,int);
void ves_icall_ModuleBuilder_RegisterToken_raw (int,int,int,int);
int ves_icall_TypeBuilder_create_runtime_class_raw (int,int);
int ves_icall_System_IO_Stream_HasOverriddenBeginEndRead_raw (int,int);
int ves_icall_System_IO_Stream_HasOverriddenBeginEndWrite_raw (int,int);
int ves_icall_System_Diagnostics_Debugger_IsAttached_internal ();
int ves_icall_System_Diagnostics_StackFrame_GetFrameInfo (int,int,int,int,int,int,int,int);
void ves_icall_System_Diagnostics_StackTrace_GetTrace (int,int,int,int);
int ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass (int);
void ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree (int);
int ves_icall_Mono_SafeStringMarshal_StringToUtf8 (int);
void ves_icall_Mono_SafeStringMarshal_GFree (int);
static void *corlib_icall_funcs [] = {
// token 216,
ves_icall_System_Array_InternalCreate,
// token 229,
ves_icall_System_Array_GetCorElementTypeOfElementTypeInternal,
// token 230,
ves_icall_System_Array_IsValueOfElementTypeInternal,
// token 231,
ves_icall_System_Array_CanChangePrimitive,
// token 232,
ves_icall_System_Array_FastCopy,
// token 233,
ves_icall_System_Array_GetLengthInternal_raw,
// token 234,
ves_icall_System_Array_GetLowerBoundInternal_raw,
// token 235,
ves_icall_System_Array_GetGenericValue_icall,
// token 236,
ves_icall_System_Array_GetValueImpl_raw,
// token 237,
ves_icall_System_Array_SetGenericValue_icall,
// token 240,
ves_icall_System_Array_SetValueImpl_raw,
// token 241,
ves_icall_System_Array_InitializeInternal_raw,
// token 242,
ves_icall_System_Array_SetValueRelaxedImpl_raw,
// token 416,
ves_icall_System_Runtime_RuntimeImports_ZeroMemory,
// token 417,
ves_icall_System_Runtime_RuntimeImports_Memmove,
// token 418,
ves_icall_System_Buffer_BulkMoveWithWriteBarrier,
// token 446,
ves_icall_System_Delegate_AllocDelegateLike_internal_raw,
// token 447,
ves_icall_System_Delegate_CreateDelegate_internal_raw,
// token 448,
ves_icall_System_Delegate_GetVirtualMethod_internal_raw,
// token 475,
ves_icall_System_Enum_GetEnumValuesAndNames_raw,
// token 476,
ves_icall_System_Enum_InternalGetCorElementType,
// token 477,
ves_icall_System_Enum_InternalGetUnderlyingType_raw,
// token 594,
ves_icall_System_Environment_get_ProcessorCount,
// token 595,
ves_icall_System_Environment_get_TickCount,
// token 596,
ves_icall_System_Environment_get_TickCount64,
// token 599,
ves_icall_System_Environment_FailFast_raw,
// token 636,
ves_icall_System_GC_GetCollectionCount,
// token 637,
ves_icall_System_GC_GetMaxGeneration,
// token 638,
ves_icall_System_GC_register_ephemeron_array_raw,
// token 639,
ves_icall_System_GC_get_ephemeron_tombstone_raw,
// token 640,
ves_icall_System_GC_GetTotalAllocatedBytes_raw,
// token 644,
ves_icall_System_GC_SuppressFinalize_raw,
// token 646,
ves_icall_System_GC_ReRegisterForFinalize_raw,
// token 648,
ves_icall_System_GC_GetGCMemoryInfo,
// token 650,
ves_icall_System_GC_AllocPinnedArray_raw,
// token 656,
ves_icall_System_Object_MemberwiseClone_raw,
// token 664,
ves_icall_System_Math_Acos,
// token 665,
ves_icall_System_Math_Acosh,
// token 666,
ves_icall_System_Math_Asin,
// token 667,
ves_icall_System_Math_Asinh,
// token 668,
ves_icall_System_Math_Atan,
// token 669,
ves_icall_System_Math_Atan2,
// token 670,
ves_icall_System_Math_Atanh,
// token 671,
ves_icall_System_Math_Cbrt,
// token 672,
ves_icall_System_Math_Ceiling,
// token 673,
ves_icall_System_Math_Cos,
// token 674,
ves_icall_System_Math_Cosh,
// token 675,
ves_icall_System_Math_Exp,
// token 676,
ves_icall_System_Math_Floor,
// token 677,
ves_icall_System_Math_Log,
// token 678,
ves_icall_System_Math_Log10,
// token 679,
ves_icall_System_Math_Pow,
// token 680,
ves_icall_System_Math_Sin,
// token 682,
ves_icall_System_Math_Sinh,
// token 683,
ves_icall_System_Math_Sqrt,
// token 684,
ves_icall_System_Math_Tan,
// token 685,
ves_icall_System_Math_Tanh,
// token 686,
ves_icall_System_Math_FusedMultiplyAdd,
// token 687,
ves_icall_System_Math_Log2,
// token 688,
ves_icall_System_Math_ModF,
// token 785,
ves_icall_System_MathF_Acos,
// token 786,
ves_icall_System_MathF_Acosh,
// token 787,
ves_icall_System_MathF_Asin,
// token 788,
ves_icall_System_MathF_Asinh,
// token 789,
ves_icall_System_MathF_Atan,
// token 790,
ves_icall_System_MathF_Atan2,
// token 791,
ves_icall_System_MathF_Atanh,
// token 792,
ves_icall_System_MathF_Cbrt,
// token 793,
ves_icall_System_MathF_Ceiling,
// token 794,
ves_icall_System_MathF_Cos,
// token 795,
ves_icall_System_MathF_Cosh,
// token 796,
ves_icall_System_MathF_Exp,
// token 797,
ves_icall_System_MathF_Floor,
// token 798,
ves_icall_System_MathF_Log,
// token 799,
ves_icall_System_MathF_Log10,
// token 800,
ves_icall_System_MathF_Pow,
// token 801,
ves_icall_System_MathF_Sin,
// token 803,
ves_icall_System_MathF_Sinh,
// token 804,
ves_icall_System_MathF_Sqrt,
// token 805,
ves_icall_System_MathF_Tan,
// token 806,
ves_icall_System_MathF_Tanh,
// token 807,
ves_icall_System_MathF_FusedMultiplyAdd,
// token 808,
ves_icall_System_MathF_Log2,
// token 809,
ves_icall_System_MathF_ModF,
// token 871,
ves_icall_RuntimeMethodHandle_GetFunctionPointer_raw,
// token 880,
ves_icall_RuntimeMethodHandle_ReboxFromNullable_raw,
// token 881,
ves_icall_RuntimeMethodHandle_ReboxToNullable_raw,
// token 951,
ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw,
// token 958,
ves_icall_RuntimeType_make_array_type_raw,
// token 961,
ves_icall_RuntimeType_make_byref_type_raw,
// token 963,
ves_icall_RuntimeType_make_pointer_type_raw,
// token 969,
ves_icall_RuntimeType_MakeGenericType_raw,
// token 970,
ves_icall_RuntimeType_GetMethodsByName_native_raw,
// token 972,
ves_icall_RuntimeType_GetPropertiesByName_native_raw,
// token 973,
ves_icall_RuntimeType_GetConstructors_native_raw,
// token 977,
ves_icall_RuntimeType_GetPacking_raw,
// token 980,
ves_icall_System_RuntimeType_CreateInstanceInternal_raw,
// token 981,
ves_icall_RuntimeType_GetDeclaringMethod_raw,
// token 983,
ves_icall_System_RuntimeType_getFullName_raw,
// token 984,
ves_icall_RuntimeType_GetGenericArgumentsInternal_raw,
// token 987,
ves_icall_RuntimeType_GetGenericParameterPosition,
// token 988,
ves_icall_RuntimeType_GetEvents_native_raw,
// token 989,
ves_icall_RuntimeType_GetFields_native_raw,
// token 992,
ves_icall_RuntimeType_GetInterfaces_raw,
// token 994,
ves_icall_RuntimeType_GetNestedTypes_native_raw,
// token 997,
ves_icall_RuntimeType_GetDeclaringType_raw,
// token 999,
ves_icall_RuntimeType_GetName_raw,
// token 1001,
ves_icall_RuntimeType_GetNamespace_raw,
// token 1008,
ves_icall_RuntimeType_IsUnmanagedFunctionPointerInternal,
// token 1013,
ves_icall_RuntimeType_FunctionPointerReturnAndParameterTypes_raw,
// token 1088,
ves_icall_RuntimeTypeHandle_GetAttributes,
// token 1090,
ves_icall_RuntimeTypeHandle_GetMetadataToken_raw,
// token 1092,
ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw,
// token 1102,
ves_icall_RuntimeTypeHandle_GetCorElementType,
// token 1103,
ves_icall_RuntimeTypeHandle_HasInstantiation,
// token 1104,
ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw,
// token 1106,
ves_icall_RuntimeTypeHandle_HasReferences_raw,
// token 1112,
ves_icall_RuntimeTypeHandle_GetArrayRank_raw,
// token 1113,
ves_icall_RuntimeTypeHandle_GetAssembly_raw,
// token 1114,
ves_icall_RuntimeTypeHandle_GetElementType_raw,
// token 1115,
ves_icall_RuntimeTypeHandle_GetModule_raw,
// token 1116,
ves_icall_RuntimeTypeHandle_GetBaseType_raw,
// token 1124,
ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw,
// token 1125,
ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition,
// token 1126,
ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw,
// token 1130,
ves_icall_RuntimeTypeHandle_is_subclass_of_raw,
// token 1131,
ves_icall_RuntimeTypeHandle_IsByRefLike_raw,
// token 1134,
ves_icall_System_RuntimeTypeHandle_internal_from_name_raw,
// token 1138,
ves_icall_System_String_FastAllocateString_raw,
// token 1139,
ves_icall_System_String_InternalIsInterned_raw,
// token 1140,
ves_icall_System_String_InternalIntern_raw,
// token 1437,
ves_icall_System_Type_internal_from_handle_raw,
// token 1647,
ves_icall_System_ValueType_InternalGetHashCode_raw,
// token 1648,
ves_icall_System_ValueType_Equals_raw,
// token 10037,
ves_icall_System_Threading_Interlocked_CompareExchange_Int,
// token 10038,
ves_icall_System_Threading_Interlocked_CompareExchange_Object,
// token 10040,
ves_icall_System_Threading_Interlocked_Decrement_Int,
// token 10041,
ves_icall_System_Threading_Interlocked_Increment_Int,
// token 10042,
ves_icall_System_Threading_Interlocked_Increment_Long,
// token 10043,
ves_icall_System_Threading_Interlocked_Exchange_Int,
// token 10044,
ves_icall_System_Threading_Interlocked_Exchange_Object,
// token 10046,
ves_icall_System_Threading_Interlocked_CompareExchange_Long,
// token 10047,
ves_icall_System_Threading_Interlocked_Exchange_Long,
// token 10048,
ves_icall_System_Threading_Interlocked_Add_Int,
// token 10049,
ves_icall_System_Threading_Interlocked_Add_Long,
// token 10067,
ves_icall_System_Threading_Monitor_Monitor_Enter_raw,
// token 10069,
mono_monitor_exit_icall_raw,
// token 10076,
ves_icall_System_Threading_Monitor_Monitor_pulse_raw,
// token 10078,
ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw,
// token 10080,
ves_icall_System_Threading_Monitor_Monitor_wait_raw,
// token 10082,
ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw,
// token 10085,
ves_icall_System_Threading_Monitor_Monitor_get_lock_contention_count,
// token 10135,
ves_icall_System_Threading_Thread_InitInternal_raw,
// token 10136,
ves_icall_System_Threading_Thread_GetCurrentThread,
// token 10138,
ves_icall_System_Threading_InternalThread_Thread_free_internal_raw,
// token 10139,
ves_icall_System_Threading_Thread_GetState_raw,
// token 10140,
ves_icall_System_Threading_Thread_SetState_raw,
// token 10141,
ves_icall_System_Threading_Thread_ClrState_raw,
// token 10142,
ves_icall_System_Threading_Thread_SetName_icall_raw,
// token 10144,
ves_icall_System_Threading_Thread_YieldInternal,
// token 10146,
ves_icall_System_Threading_Thread_SetPriority_raw,
// token 11282,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw,
// token 11286,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw,
// token 11288,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw,
// token 11289,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw,
// token 11290,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw,
// token 11291,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalGetLoadedAssemblies_raw,
// token 11744,
ves_icall_System_GCHandle_InternalAlloc_raw,
// token 11745,
ves_icall_System_GCHandle_InternalFree_raw,
// token 11746,
ves_icall_System_GCHandle_InternalGet_raw,
// token 11747,
ves_icall_System_GCHandle_InternalSet_raw,
// token 11765,
ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError,
// token 11766,
ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError,
// token 11767,
ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw,
// token 11812,
ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw,
// token 11886,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw,
// token 11889,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetObjectValue_raw,
// token 11897,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw,
// token 11898,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw,
// token 11899,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw,
// token 11900,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack,
// token 11901,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalBox_raw,
// token 12233,
ves_icall_System_Reflection_Assembly_GetExecutingAssembly_raw,
// token 12234,
ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw,
// token 12239,
ves_icall_System_Reflection_Assembly_InternalLoad_raw,
// token 12240,
ves_icall_System_Reflection_Assembly_InternalGetType_raw,
// token 12276,
ves_icall_System_Reflection_AssemblyName_GetNativeName,
// token 12319,
ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw,
// token 12326,
ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw,
// token 12333,
ves_icall_MonoCustomAttrs_IsDefinedInternal_raw,
// token 12344,
ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw,
// token 12348,
ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw,
// token 12374,
ves_icall_System_Reflection_LoaderAllocatorScout_Destroy,
// token 12457,
ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceNames_raw,
// token 12459,
ves_icall_System_Reflection_RuntimeAssembly_GetExportedTypes_raw,
// token 12470,
ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw,
// token 12472,
ves_icall_System_Reflection_RuntimeAssembly_GetManifestResourceInternal_raw,
// token 12473,
ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw,
// token 12474,
ves_icall_System_Reflection_RuntimeAssembly_GetModulesInternal_raw,
// token 12481,
ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw,
// token 12496,
ves_icall_RuntimeEventInfo_get_event_info_raw,
// token 12516,
ves_icall_reflection_get_token_raw,
// token 12517,
ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw,
// token 12525,
ves_icall_RuntimeFieldInfo_ResolveType_raw,
// token 12527,
ves_icall_RuntimeFieldInfo_GetParentType_raw,
// token 12534,
ves_icall_RuntimeFieldInfo_GetFieldOffset_raw,
// token 12535,
ves_icall_RuntimeFieldInfo_GetValueInternal_raw,
// token 12538,
ves_icall_RuntimeFieldInfo_SetValueInternal_raw,
// token 12540,
ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw,
// token 12545,
ves_icall_reflection_get_token_raw,
// token 12551,
ves_icall_get_method_info_raw,
// token 12552,
ves_icall_get_method_attributes,
// token 12559,
ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw,
// token 12561,
ves_icall_System_MonoMethodInfo_get_retval_marshal_raw,
// token 12573,
ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw,
// token 12576,
ves_icall_RuntimeMethodInfo_get_name_raw,
// token 12577,
ves_icall_RuntimeMethodInfo_get_base_method_raw,
// token 12578,
ves_icall_reflection_get_token_raw,
// token 12589,
ves_icall_InternalInvoke_raw,
// token 12599,
ves_icall_RuntimeMethodInfo_GetPInvoke_raw,
// token 12605,
ves_icall_RuntimeMethodInfo_MakeGenericMethod_impl_raw,
// token 12606,
ves_icall_RuntimeMethodInfo_GetGenericArguments_raw,
// token 12607,
ves_icall_RuntimeMethodInfo_GetGenericMethodDefinition_raw,
// token 12609,
ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw,
// token 12610,
ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw,
// token 12627,
ves_icall_InvokeClassConstructor_raw,
// token 12629,
ves_icall_InternalInvoke_raw,
// token 12644,
ves_icall_reflection_get_token_raw,
// token 12667,
ves_icall_System_Reflection_RuntimeModule_InternalGetTypes_raw,
// token 12668,
ves_icall_System_Reflection_RuntimeModule_GetGuidInternal_raw,
// token 12669,
ves_icall_System_Reflection_RuntimeModule_ResolveMethodToken_raw,
// token 12694,
ves_icall_RuntimeParameterInfo_GetTypeModifiers_raw,
// token 12699,
ves_icall_RuntimePropertyInfo_get_property_info_raw,
// token 12729,
ves_icall_reflection_get_token_raw,
// token 12730,
ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw,
// token 13369,
ves_icall_CustomAttributeBuilder_GetBlob_raw,
// token 13383,
ves_icall_DynamicMethod_create_dynamic_method_raw,
// token 13470,
ves_icall_AssemblyBuilder_basic_init_raw,
// token 13471,
ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw,
// token 13693,
ves_icall_ModuleBuilder_basic_init_raw,
// token 13694,
ves_icall_ModuleBuilder_set_wrappers_type_raw,
// token 13702,
ves_icall_ModuleBuilder_getUSIndex_raw,
// token 13703,
ves_icall_ModuleBuilder_getToken_raw,
// token 13704,
ves_icall_ModuleBuilder_getMethodToken_raw,
// token 13710,
ves_icall_ModuleBuilder_RegisterToken_raw,
// token 13781,
ves_icall_TypeBuilder_create_runtime_class_raw,
// token 14293,
ves_icall_System_IO_Stream_HasOverriddenBeginEndRead_raw,
// token 14294,
ves_icall_System_IO_Stream_HasOverriddenBeginEndWrite_raw,
// token 14687,
ves_icall_System_Diagnostics_Debugger_IsAttached_internal,
// token 14692,
ves_icall_System_Diagnostics_StackFrame_GetFrameInfo,
// token 14702,
ves_icall_System_Diagnostics_StackTrace_GetTrace,
// token 15673,
ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass,
// token 15694,
ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree,
// token 15696,
ves_icall_Mono_SafeStringMarshal_StringToUtf8,
// token 15698,
ves_icall_Mono_SafeStringMarshal_GFree,
};
static uint8_t corlib_icall_flags [] = {
0,
0,
0,
0,
0,
4,
4,
0,
4,
0,
4,
4,
4,
0,
0,
0,
4,
4,
4,
4,
0,
4,
0,
0,
0,
4,
0,
0,
4,
4,
4,
4,
4,
0,
4,
4,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
0,
4,
0,
4,
4,
0,
0,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
4,
4,
4,
4,
4,
4,
0,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
0,
0,
0,
0,
0,
};
