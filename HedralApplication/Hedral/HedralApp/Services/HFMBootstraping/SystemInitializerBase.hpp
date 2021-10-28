#ifndef HEDRALFACTORYBASE_HPP
#define HEDRALFACTORYBASE_HPP

#include "../HFMCore/HedralCore.hpp"

namespace Hedral
{
    namespace Bootstraping
    {
        struct ISystemInitializer : Hedral::Core::IContract
        {
            HEDRAL_DECLARE_INTERFACE(ISystemInitializer, "ISystemInitializer")

            virtual void Initialize() = 0;
        };
        HEDRAL_DECLARE_CLASSFACTORY(SystemInitializer, ISystemInitializer)
    }
}

#endif
