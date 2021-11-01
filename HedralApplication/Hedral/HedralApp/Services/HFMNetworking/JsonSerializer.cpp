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
    return QJsonDocument::fromJson(jsonByteArray);
}

QVariant JsonSerializerImpl::JsonAsMap(const QJsonDocument& jsonDocument)
{
    return jsonDocument.toVariant();
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
