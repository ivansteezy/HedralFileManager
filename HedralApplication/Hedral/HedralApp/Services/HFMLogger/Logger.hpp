#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <qDebug>
#include <QFile>
#include <QString>
#include <QDateTime>

#include "LoggerBase.hpp"

namespace Hedral
{
    namespace Log
    {
        const QString logFilePath = "HedralLog.txt";
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

        private:
            void SetFilePath();

        private:
            QFile m_file;
        };
    }
}

#endif
