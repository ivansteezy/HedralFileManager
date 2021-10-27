#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "LoggerBase.hpp"
#include <qDebug>

namespace Hedral
{
    namespace Log
    {
        class LoggerImpl : public QObject, public Core::Implements<ILogger, Hedral::Core::IQtObjectSupport>
        {
            Q_OBJECT;

        public:
            LoggerImpl();
            virtual ~LoggerImpl();

            virtual void WriteError(const QString& message) override;
            virtual void WriteWarning(const QString& message) override;
            virtual void WriteInfo(const QString& message) override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;
        };
    }
}

#endif
