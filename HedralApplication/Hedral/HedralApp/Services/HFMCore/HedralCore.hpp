#ifndef HEDRALCORE_HPP
#define HEDRALCORE_HPP

#include <QObject>

#include <type_traits>
#include <string_view>
#include <memory>
#include <any>

#include "HedralCoreMacros.hpp"

using INTERFACEID = const std::string_view;
using AnyPtr = std::unique_ptr<std::any>;
using ulong = unsigned long;
using Any = std::any;

namespace Hedral
{
    namespace Core
    {
        enum class ErrorCode
        {
            Success,
            NoInterface
        };


        struct IContract
        {
            HEDRAL_DECLARE_INTERFACE(IContract, "IContract");

            virtual ErrorCode QueryInterface(const INTERFACEID& iid, void** outInterface) = 0;
            virtual ulong AddRef() = 0;
            virtual ulong Release() = 0;
        };

        struct IQtObjectSupport : IContract
        {
            HEDRAL_DECLARE_INTERFACE(IQtObjectSupport, "IQtObjectSupport");

            virtual QObject* AsQtObject() = 0;
            virtual const QMetaObject* MetaObject() = 0;
        };

        template<typename ...Interfaces>
        class Implements : public Interfaces...
        {
        protected:
            Implements() noexcept {}
            virtual ~Implements() noexcept {}

        public:
            virtual ulong AddRef() noexcept override
            {
                return ++m_references;
            }

            virtual ulong Release() noexcept override
            {
                const ulong remaining = --m_references;
                if (remaining == 0)
                {
                    delete this;
                }
                return remaining;
            }

        protected:
            virtual ErrorCode QueryInterface(const INTERFACEID& id, void** object) noexcept override
            {
                *object = QueryBaseInterface<Interfaces...>(id);
                if (*object == nullptr)
                {
                    return ErrorCode::NoInterface;
                }
                static_cast<IContract*>(*object)->AddRef();
                return ErrorCode::Success;
            }

            template<typename First, typename ...Rest>
            void* QueryBaseInterface(const INTERFACEID& id) noexcept
            {
                if (id.compare(First::IID()) == 0 || id.compare(IContract::IID()) == 0)
                {
                    return static_cast<First*>(this);
                }
                return FindInterface<Rest...>(id);
            }

            template<typename First, typename ...Rest>
            void* FindInterface(const INTERFACEID& id) noexcept
            {
                if (id.compare(First::IID()) == 0)
                {
                    return static_cast<First*>(this);
                }
                return FindInterface<Rest...>(id);
            }

            template<int = 0>
            void* FindInterface(const INTERFACEID&) noexcept
            {
                return nullptr;
            }

        protected:
            unsigned long m_references = 0;
        };

        template<typename T>
        struct ComPtr
        {
            ComPtr(T* lComPtr = nullptr) : m_ComPtr(lComPtr)
            {
                static_assert(std::is_base_of<IContract, T>::value, "T needs to be IContract based");
                if (m_ComPtr)
                {
                    m_ComPtr->AddRef();
                }
            }

            ComPtr(const ComPtr<T>& lComPtrObj)
            {
                static_assert(std::is_base_of<IContract, T>::value, "T needs to be IContract based");
                m_ComPtr = lComPtrObj.m_ComPtr;

                if (m_ComPtr)
                {
                    m_ComPtr->AddRef();
                }
            }

            ComPtr(ComPtr<T>&& lComPtrObj)
            {
                m_ComPtr = lComPtrObj.m_ComPtr;
                lComPtrObj.m_ComPtr = nullptr;
            }

            ComPtr(IContract* pUnkown)
            {
                pUnkown->QueryInterface(T::IID(), reinterpret_cast<void**>(&m_ComPtr));
            }

            T* operator=(T* lComPtr)
            {
                if (m_ComPtr)
                {
                    m_ComPtr->Release();
                }

                m_ComPtr = lComPtr;

                if (m_ComPtr)
                {
                    m_ComPtr->AddRef();
                }

                return m_ComPtr;
            }

            T* operator=(const ComPtr<T>& lComPtrObj)
            {
                if (m_ComPtr)
                {
                    m_ComPtr->Release();
                }

                m_ComPtr = lComPtrObj.m_ComPtr;

                if (m_ComPtr)
                {
                    m_ComPtr->AddRef();
                }

                return m_ComPtr;
            }

            ~ComPtr()
            {
                if (m_ComPtr)
                {
                    m_ComPtr->Release();
                    m_ComPtr = nullptr;
                }
            }

            operator T* () const
            {
                return m_ComPtr;
            }

            T* GetInterface() const
            {
                return m_ComPtr;
            }

            T& operator*() const
            {
                return *m_ComPtr;
            }

            T** operator&()
            {
                //The assert on operator& usually indicates a bug. Could be a potential memory leak.
                // If this really what is needed, however, use GetInterface() explicitly.
                assert(nullptr == m_ComPtr);
                return &m_ComPtr;
            }

            T* operator->() const
            {
                return m_ComPtr;
            }

            bool operator!() const
            {
                return (nullptr == m_ComPtr);
            }

            bool operator<(T* lComPtr) const
            {
                return m_ComPtr < lComPtr;
            }

            bool operator!=(T* lComPtr) const
            {
                return !operator==(lComPtr);
            }

            bool operator==(T* lComPtr) const
            {
                return m_ComPtr == lComPtr;
            }

            template <typename I>
            ComPtr<I> As()
            {
                return ComPtr<I>(m_ComPtr);
            }

            template <typename I>
            ErrorCode QueryInterface(I** interfacePtr)
            {
                return m_ComPtr->QueryInterface(I::IID(), reinterpret_cast<void**>(interfacePtr));
            }

        protected:
            T* m_ComPtr;
        };
    }
}

#endif // HEDRALCORE_HPP
