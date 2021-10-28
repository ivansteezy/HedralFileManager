#include "Logger.hpp"

using namespace Hedral::Log;

HEDRAL_IMPLEMENT_CLASSFACTORY(Logger, LoggerImpl, ILogger);

LoggerImpl::LoggerImpl()
{
    SetFilePath();
}

LoggerImpl::~LoggerImpl()
{

}

void LoggerImpl::SetFilePath()
{
    m_file.setFileName(logFilePath);
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
    if(m_file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream out(&m_file);
        QString logtext = "[" + QDateTime::currentDateTime().toString() + ": HEDRAL INFO]: " + message;
        out << logtext;
    }

    m_file.close();
}

QObject* LoggerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* LoggerImpl::MetaObject()
{
    return this->metaObject();
}
