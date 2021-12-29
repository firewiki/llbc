// The MIT License (MIT)

// Copyright (c) 2013 lailongwei<lailongwei@126.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of 
// this software and associated documentation files (the "Software"), to deal in 
// the Software without restriction, including without limitation the rights to 
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
// the Software, and to permit persons to whom the Software is furnished to do so, 
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifdef __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_H__

__LLBC_NS_BEGIN

template <typename ObjectType>
LLBC_FORCE_INLINE bool LLBC_PoolObjectReflection::IsSupportedPoolObjectReflection()
{
    return IsSupportedPoolObjectReflectionInl<ObjectType>(nullptr);
}

template <typename ObjectType>
bool LLBC_PoolObjectReflection::IsSupportedPoolObjectReflectionInl(
    __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF *)
{
    return true;
}

template <typename ObjectType>
typename std::enable_if<std::is_base_of<
    LLBC_PoolObject, ObjectType>::value, bool>::type
LLBC_FORCE_INLINE LLBC_PoolObjectReflection::IsSupportedPoolObjectReflectionInl(std::nullptr_t)
{
    return true;
}

template <typename ObjectType>
bool LLBC_PoolObjectReflection::IsSupportedPoolObjectReflectionInl(...)
{
    return false;
}

template <typename ObjectType>
LLBC_FORCE_INLINE void LLBC_PoolObjectReflection::MarkPoolObject(ObjectType *&obj,
                                                                 LLBC_IObjectPoolInst *poolInst)
{
    MarkPoolObjectInl<ObjectType>(obj, poolInst, nullptr);
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::MarkPoolObjectInl(ObjectType *&obj,
                                                  LLBC_IObjectPoolInst *poolInst,
                                                  __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF *)
{
    obj->MarkPoolObject(*poolInst);
}

template <typename ObjectType>
typename std::enable_if<std::is_base_of<LLBC_PoolObject, ObjectType>::value, void>::type
LLBC_PoolObjectReflection::MarkPoolObjectInl(ObjectType *&obj,
                                             LLBC_IObjectPoolInst *poolInst,
                                             std::nullptr_t)
{
    obj->MarkPoolObject(*poolInst);
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::MarkPoolObjectInl(ObjectType *&obj,
                                                  LLBC_IObjectPoolInst *poolInst,
                                                  ...)
{
    // Do nothing
}

template <typename ObjectType>
LLBC_FORCE_INLINE bool LLBC_PoolObjectReflection::IsPoolObject(ObjectType *&obj)
{
    return IsPoolObjectInl<ObjectType>(obj, nullptr);
}

template <typename ObjectType>
bool LLBC_PoolObjectReflection::IsPoolObjectInl(ObjectType *&obj,
                                                __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF *)
{
    return obj->IsPoolObject();
}

template <typename ObjectType>
typename std::enable_if<std::is_base_of<
    LLBC_PoolObject, ObjectType>::value, bool>::type
LLBC_PoolObjectReflection::IsPoolObjectInl(ObjectType *&obj,
                                           std::nullptr_t)
{
    return obj->IsPoolObject();
}

template <typename ObjectType>
bool LLBC_PoolObjectReflection::IsPoolObjectInl(ObjectType *&obj,
                                                ...)
{
    return false;
}

template <typename ObjectType>
LLBC_FORCE_INLINE LLBC_IObjectPoolInst *LLBC_PoolObjectReflection::GetPoolInst(ObjectType *&obj)
{
    return GetPoolInstInl<ObjectType>(obj, nullptr);
}

template <typename ObjectType>
LLBC_IObjectPoolInst *LLBC_PoolObjectReflection::GetPoolInstInl(ObjectType *&obj,
                                                                __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF *)
{
    return obj->GetPoolInst();
}

template <typename ObjectType>
typename std::enable_if<std::is_base_of<
    LLBC_PoolObject, ObjectType>::value, LLBC_IObjectPoolInst *>::type
LLBC_PoolObjectReflection::GetPoolInstInl(ObjectType *&obj,
                                          std::nullptr_t)
{
    return obj->GetPoolInst();
}

template <typename ObjectType>
LLBC_IObjectPoolInst *LLBC_PoolObjectReflection::GetPoolInstInl(ObjectType *&obj,
                                                                ...)
{
    return nullptr;
}

template <typename ObjectType>
LLBC_FORCE_INLINE void LLBC_PoolObjectReflection::GiveBackToPool(ObjectType *&obj)
{
    GiveBackToPoolInl<ObjectType>(obj, nullptr);
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::GiveBackToPoolInl(ObjectType *&obj,
                                                  __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF *)
{
    obj->GiveBackToPool();
}

template <typename ObjectType>
typename std::enable_if<std::is_base_of<
    LLBC_PoolObject, ObjectType>::value, void>::type
LLBC_PoolObjectReflection::GiveBackToPoolInl(ObjectType *&obj,
                                             std::nullptr_t)
{
    obj->GiveBackToPool();
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::GiveBackToPoolInl(ObjectType *&obj,
                                                  ...)
{
    // Do nothing.
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::Recycle(ObjectType *obj)
{
    RecycleInl<ObjectType>(obj, nullptr);
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::RecycleX(ObjectType *&obj)
{
    if (obj)
    {
        RecycleInl<ObjectType>(obj, nullptr);
        obj = nullptr;
    }
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::RecycleInl(ObjectType *&obj,
                                           __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF *)
{
    if (obj)
    {
        if (obj->IsPoolObject())
            obj->GiveBackToPool();
        else
            LLBC_Delete(obj);
    }
}

template <typename ObjectType>
typename std::enable_if<std::is_base_of<
    LLBC_PoolObject, ObjectType>::value, void>::type
LLBC_PoolObjectReflection::RecycleInl(ObjectType *&obj,
                                      std::nullptr_t)
{
    if (obj)
    {
        if (obj->IsPoolObject())
            obj->GiveBackToPool();
        else
            LLBC_Delete(obj);
    }
}

template <typename ObjectType>
void LLBC_PoolObjectReflection::RecycleInl(ObjectType *&obj,
                                           ...)
{
    LLBC_Delete(obj);
}

// Undefine pool object reflection detect type definition macro.
#undef __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_DETECT_TYPE_DEF

__LLBC_NS_END

#endif // __LLBC_CORE_OBJECT_POOL_POOL_OBJECT_REFLECTION_H__
