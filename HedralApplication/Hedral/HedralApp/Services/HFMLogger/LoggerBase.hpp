#ifndef LOGGERBASE_HPP
#define LOGGERBASE_HPP

#include "../HFMCore/HedralCore.hpp"
#include <QString>

namespace Hedral
{
    namespace Log
    {
        struct ILogger : Hedral::Core::IContract
        {
            HEDRAL_DECLARE_INTERFACE(ILogger, "ILogger");

            virtual void WriteError(const QString& message) = 0;
            virtual void WriteWarning(const QString& message) = 0;
            virtual void WriteInfo(const QString& message) = 0;
        };
        HEDRAL_DECLARE_CLASSFACTORY(Logger, ILogger);

        struct GlobalLogger
        {
            static void SetInstance(Hedral::Core::ComPtr<ILogger> logger);
            static ILogger* Instance();
        };
    }
}

#endif
