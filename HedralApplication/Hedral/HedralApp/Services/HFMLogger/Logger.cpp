#include "Logger.hpp"

using namespace Hedral::Log;

HEDRAL_IMPLEMENT_CLASSFACTORY(Logger, LoggerImpl, ILogger);

LoggerImpl::LoggerImpl()
{

}

LoggerImpl::~LoggerImpl()
{

}

void LoggerImpl::WriteError(const QString& message)
{
    qDebug() << "ERROR: " << message;
}

void LoggerImpl::WriteWarning(const QString& message)
{
    qDebug() << "WARNING: " << message;
}

void LoggerImpl::WriteInfo(const QString& message)
{
    qDebug() << "INFO: " << message;
}

QObject* LoggerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* LoggerImpl::MetaObject()
{
    return this->metaObject();
}
