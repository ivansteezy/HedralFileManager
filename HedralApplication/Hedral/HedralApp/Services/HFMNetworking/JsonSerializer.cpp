#include "JsonSerializer.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_CLASSFACTORY(JsonSerializer, JsonSerializerImpl, IJsonSerializer);

JsonSerializerImpl::JsonSerializerImpl()
{

}

JsonSerializerImpl::~JsonSerializerImpl()
{

}

QJsonDocument JsonSerializerImpl::ByteArrayToJson(const QByteArray& jsonByteArray)
{
    return QJsonDocument();
}

QVariantMap JsonSerializerImpl::JsonAsMap(const QJsonDocument& jsonDocument)
{
    return QVariantMap();
}

QByteArray JsonSerializerImpl::JsonByteArray(const QJsonDocument& jsonDocument)
{
    return QByteArray();
}

QObject* JsonSerializerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* JsonSerializerImpl::MetaObject()
{
    return this->metaObject();
}
