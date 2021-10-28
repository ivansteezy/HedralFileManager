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
    QDir dir("../../Hedral/");
    m_file.setFileName(dir.absoluteFilePath("HedralLog.txt"));
}

void LoggerImpl::WriteError(const QString& message)
{
    if(m_file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&m_file);
        QString logtext = "[" + QDateTime::currentDateTime().toString() + ": HEDRAL ERROR]: " + message + "\n";
        out << logtext;
    }

    m_file.close();
}

void LoggerImpl::WriteWarning(const QString& message)
{
    if(m_file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&m_file);
        QString logtext = "[" + QDateTime::currentDateTime().toString() + ": HEDRAL WARNING]: " + message + "\n";
        out << logtext;
    }

    m_file.close();
}

void LoggerImpl::WriteInfo(const QString& message)
{
    if(m_file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&m_file);
        QString logtext = "[" + QDateTime::currentDateTime().toString() + ": HEDRAL INFO]: " + message + "\n";
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
